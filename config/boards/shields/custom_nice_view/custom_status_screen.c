#include "./fonts/custom_font_22.h"
#include "./fonts/custom_font_44.h"
#include "./images/bluetooth_logo.h"
#include "./images/bluetooth_logo_outlined.h"
#include "./images/bluetooth_logo_outline.h"
#include "./images/usb_logo.h"
#include "./images/background_1.h"
#include "./images/background_2.h"
#include "./images/background_3.h"
#include "./images/background_4.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/battery.h>
#include <zmk/display.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/events/endpoint_changed.h>
#include <zmk/events/wpm_state_changed.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/usb.h>
#include <zmk/ble.h>
#include <zmk/endpoints.h>
#include <zmk/keymap.h>
#include <zmk/wpm.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 68

#define INFO_CANVAS_WIDTH (SCREEN_HEIGHT)
#define INFO_CANVAS_HEIGHT 25

#define MAIN_CANVAS_WIDTH (SCREEN_WIDTH - INFO_CANVAS_HEIGHT)
#define MAIN_CANVAS_HEIGHT (SCREEN_HEIGHT)

#define FOREGROUND_COLOR lv_color_black()
#define BACKGROUND_COLOR lv_color_white()

lv_obj_t* info_canvas;
lv_color_t info_canvas_buffer[LV_CANVAS_BUF_SIZE_TRUE_COLOR(SCREEN_HEIGHT, SCREEN_HEIGHT)];

lv_obj_t* main_canvas;
lv_color_t main_canvas_buffer[LV_CANVAS_BUF_SIZE_TRUE_COLOR(MAIN_CANVAS_WIDTH, MAIN_CANVAS_HEIGHT)];

struct connectivity_state {
    struct zmk_endpoint_instance selected_endpoint;
    int active_profile_index;
    bool active_profile_connected;
    bool active_profile_bonded;
};

struct layer_state {
    zmk_keymap_layer_index_t index;
    const char* name;
};

struct battery_state {
    uint8_t level;
    bool usb_present;
};

struct states {
    struct connectivity_state connectivity;
    struct layer_state layer;
    struct battery_state battery;
    uint8_t background_index;
};

struct states states;

static void render_bluetooth_logo() {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    
    if (states.connectivity.active_profile_bonded) {
        if (states.connectivity.active_profile_connected) {
            lv_canvas_draw_img(info_canvas, 52, 4, &bluetooth_logo, &img_dsc);
        } else {
            lv_canvas_draw_img(info_canvas, 52, 4, &bluetooth_logo_outlined, &img_dsc);
        }
    } else {
        lv_canvas_draw_img(info_canvas, 52, 4, &bluetooth_logo_outline, &img_dsc);
    }
}

static void render_bluetooth_connectivity() {
    lv_draw_label_dsc_t label_dsc;
    lv_draw_label_dsc_init(&label_dsc);
    label_dsc.color = FOREGROUND_COLOR;
    label_dsc.font = &custom_font_22;
    label_dsc.align = LV_TEXT_ALIGN_RIGHT;

    const int custom_font_22_height = 19;
    const int padding_y = (INFO_CANVAS_HEIGHT - custom_font_22_height) / 2;
    char label[2];
    snprintf(label, sizeof(label), "%d", states.connectivity.active_profile_index + 1);
    lv_canvas_draw_text(info_canvas, INFO_CANVAS_WIDTH / 2, padding_y, INFO_CANVAS_WIDTH / 2 - 18, &label_dsc, label);

    render_bluetooth_logo();
}

static void render_usb_logo() {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    lv_canvas_draw_img(info_canvas, 45, 8, &usb_logo, &img_dsc);
}

static void render_usb_connectivity() {
    render_usb_logo();
}

static void render_connectivity() {
    switch (states.connectivity.selected_endpoint.transport) {
        case ZMK_TRANSPORT_BLE: {
            render_bluetooth_connectivity();
            break;
        }
        case ZMK_TRANSPORT_USB: {
            render_usb_connectivity();
            break;
        }
    }
}

static void render_battery_outline() {
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = FOREGROUND_COLOR;

    lv_canvas_draw_rect(info_canvas, 7, 7, 19, 1, &rect_dsc); // Top
    lv_canvas_draw_rect(info_canvas, 27, 9, 1, 7, &rect_dsc); // Right
    lv_canvas_draw_rect(info_canvas, 7, 17, 19, 1, &rect_dsc); // Bottom
    lv_canvas_draw_rect(info_canvas, 5, 9, 1, 7, &rect_dsc); // Left

    lv_canvas_set_px_color(info_canvas, 6, 8, FOREGROUND_COLOR); // Top left
    lv_canvas_set_px_color(info_canvas, 26, 8, FOREGROUND_COLOR); // Top right
    lv_canvas_set_px_color(info_canvas, 26, 16, FOREGROUND_COLOR); // Bottom right
    lv_canvas_set_px_color(info_canvas, 6, 16, FOREGROUND_COLOR); // Bottom left

    lv_canvas_draw_rect(info_canvas, 28, 11, 1, 3, &rect_dsc); // Right-side terminal
}

// The lightning bolt is drawn line by line.
static void render_battery_lightning_bolt() {
    lv_canvas_set_px_color(info_canvas, 16, 9, BACKGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 17, 9, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 18, 9, BACKGROUND_COLOR);
    
    lv_canvas_set_px_color(info_canvas, 15, 10, BACKGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 16, 10, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 17, 10, BACKGROUND_COLOR);

    lv_canvas_set_px_color(info_canvas, 14, 11, BACKGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 15, 11, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 16, 11, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 17, 11, BACKGROUND_COLOR);

    lv_canvas_set_px_color(info_canvas, 14, 12, BACKGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 15, 12, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 16, 12, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 17, 12, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 18, 12, BACKGROUND_COLOR);

    lv_canvas_set_px_color(info_canvas, 15, 13, BACKGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 16, 13, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 17, 13, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 18, 13, BACKGROUND_COLOR);

    lv_canvas_set_px_color(info_canvas, 15, 14, BACKGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 16, 14, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 17, 14, BACKGROUND_COLOR);

    lv_canvas_set_px_color(info_canvas, 14, 15, BACKGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 15, 15, FOREGROUND_COLOR);
    lv_canvas_set_px_color(info_canvas, 16, 15, BACKGROUND_COLOR);
}

static void render_battery() {
    render_battery_outline();

    // Draw the main part of the battery
    const int width = 19 / (states.battery.level / 100.0);
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = FOREGROUND_COLOR;
    lv_canvas_draw_rect(info_canvas, 7, 9, width, 7, &rect_dsc);

    // Round the corners
    lv_canvas_set_px_color(info_canvas, 7, 9, BACKGROUND_COLOR); // Top left
    lv_canvas_set_px_color(info_canvas, 25, 9, BACKGROUND_COLOR); // Top right
    lv_canvas_set_px_color(info_canvas, 25, 15, BACKGROUND_COLOR); // Bottom right
    lv_canvas_set_px_color(info_canvas, 7, 15, BACKGROUND_COLOR); // Bottom left

    if (states.battery.usb_present) {
        render_battery_lightning_bolt();
    }
}

static void render_info() {
    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    // Debug
    // lv_canvas_set_px_color(info_canvas, 0, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, INFO_CANVAS_WIDTH - 1, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 0, INFO_CANVAS_HEIGHT - 1, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, INFO_CANVAS_WIDTH - 1, INFO_CANVAS_HEIGHT - 1, FOREGROUND_COLOR);

    render_connectivity();
    render_battery();
 
    // Debug
    // lv_canvas_set_px_color(info_canvas, 48, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 49, 1, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 48, 2, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 49, 3, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 48, 4, FOREGROUND_COLOR);

    // lv_canvas_set_px_color(info_canvas, 56, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 57, 1, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 56, 2, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 57, 3, FOREGROUND_COLOR);

    // Rotate 90 degrees.
    static lv_color_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR(SCREEN_HEIGHT, SCREEN_HEIGHT)];
    memcpy(cbuf_tmp, info_canvas_buffer, sizeof(cbuf_tmp));
    lv_img_dsc_t img;
    img.data = (void *)cbuf_tmp;
    img.header.cf = LV_IMG_CF_TRUE_COLOR;
    img.header.w = SCREEN_HEIGHT;
    img.header.h = SCREEN_HEIGHT;

    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);
    lv_canvas_transform(
        info_canvas,
        &img,
        900, LV_IMG_ZOOM_NONE,
        -1, 0,
        SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2,
        false
    );
}

#include <zephyr/random/random.h>

static void render_noise() {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    switch (states.background_index % 4) {
        case 0: {
            lv_canvas_draw_img(main_canvas, 0, 0, &background_1, &img_dsc);
            break;
        }
        case 1: {
            lv_canvas_draw_img(main_canvas, 0, 0, &background_2, &img_dsc);
            break;
        }
        case 2: {
            lv_canvas_draw_img(main_canvas, 0, 0, &background_3, &img_dsc);
            break;
        }
        case 3: {
            lv_canvas_draw_img(main_canvas, 0, 0, &background_4, &img_dsc);
            break;
        }
    }

    states.background_index = states.background_index % 4 + 1;
}

static void render_main() {
    lv_draw_rect_dsc_t background_dsc;
    lv_draw_rect_dsc_init(&background_dsc);
    background_dsc.bg_color = BACKGROUND_COLOR;
    lv_canvas_draw_rect(main_canvas, 0, 0, MAIN_CANVAS_WIDTH, MAIN_CANVAS_HEIGHT, &background_dsc);

    render_noise();
    
    // Debug
    // lv_canvas_set_px_color(main_canvas, 0, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(main_canvas, MAIN_CANVAS_WIDTH - 1, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(main_canvas, 0, MAIN_CANVAS_HEIGHT - 1, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(main_canvas, MAIN_CANVAS_WIDTH - 1, MAIN_CANVAS_HEIGHT - 1, FOREGROUND_COLOR);

    lv_draw_label_dsc_t layer_name_dsc;
    lv_draw_label_dsc_init(&layer_name_dsc);
    layer_name_dsc.color = FOREGROUND_COLOR;
    layer_name_dsc.font = &custom_font_44;
    layer_name_dsc.align = LV_TEXT_ALIGN_CENTER;
    const int actual_font_height = 38;
    int padding = (MAIN_CANVAS_HEIGHT - actual_font_height) / 2;
    lv_canvas_draw_text(main_canvas, 0, padding, MAIN_CANVAS_WIDTH, &layer_name_dsc, states.layer.name);
}

static void render() {
    render_info();
    render_main();
}

static void connectivity_state_update_callback(struct connectivity_state state) {
    states.connectivity = state;

    render();
}

static struct connectivity_state get_connectivity_state(const zmk_event_t *_eh) {
    const struct zmk_endpoint_instance selected_endpoint = zmk_endpoints_selected();
    const int active_profile_index = zmk_ble_active_profile_index();
    const bool active_profile_connected = zmk_ble_active_profile_is_connected();
    const bool active_profile_bonded = !zmk_ble_active_profile_is_open();

    struct connectivity_state state = {
        .selected_endpoint = selected_endpoint,
        .active_profile_index = active_profile_index,
        .active_profile_connected = active_profile_connected,
        .active_profile_bonded = active_profile_bonded,
    };

    return state;
}

ZMK_DISPLAY_WIDGET_LISTENER(
    widget_connectivity_state_update,
    struct connectivity_state,
    connectivity_state_update_callback,
    get_connectivity_state
)

ZMK_SUBSCRIPTION(
    widget_connectivity_state_update,
    zmk_endpoint_changed
);

ZMK_SUBSCRIPTION(
    widget_connectivity_state_update,
    zmk_usb_conn_state_changed
);

ZMK_SUBSCRIPTION(
    widget_connectivity_state_update,
    zmk_ble_active_profile_changed
);

static void layer_state_update_callback(struct layer_state state) {
    states.layer = state;

    render();
}

// Retrieve the data we want from the event
static struct layer_state get_layer_state(const zmk_event_t *eh) {
    const zmk_keymap_layer_index_t index = zmk_keymap_highest_layer_active();
    const char* name = zmk_keymap_layer_name(zmk_keymap_layer_index_to_id(index));

    struct layer_state state = {
        .index = index,
        .name = name
    };

    return state;
}

// Creates widget_layer_state_update_init
ZMK_DISPLAY_WIDGET_LISTENER(
    widget_layer_state_update,
    struct layer_state,
    layer_state_update_callback,
    get_layer_state
)

ZMK_SUBSCRIPTION(
    widget_layer_state_update,
    zmk_layer_state_changed
);

static void battery_state_update_callback(struct battery_state state) {
    states.battery = state;

    render();
}

static struct battery_state get_battery_state(const zmk_event_t *eh) {
    const struct zmk_battery_state_changed *ev = as_zmk_battery_state_changed(eh);
    const uint8_t level = (ev != NULL) ? ev->state_of_charge : zmk_battery_state_of_charge();
    const bool usb_present = zmk_usb_is_powered();

    struct battery_state state = {
        .level = level,
        .usb_present = usb_present,
    };

    return state;
}

ZMK_DISPLAY_WIDGET_LISTENER(
    widget_battery_state_update,
    struct battery_state,
    battery_state_update_callback,
    get_battery_state
)

ZMK_SUBSCRIPTION(
    widget_battery_state_update,
    zmk_battery_state_changed
);

ZMK_SUBSCRIPTION(
    widget_battery_state_update,
    zmk_usb_conn_state_changed
);

// ZMK calls this function directly.
lv_obj_t* zmk_display_status_screen() {
    lv_obj_t* screen = lv_obj_create(NULL);
    lv_obj_set_size(screen, SCREEN_WIDTH, SCREEN_HEIGHT);
        
    lv_draw_rect_dsc_t background_dsc;
    lv_draw_rect_dsc_init(&background_dsc);
    background_dsc.bg_color = BACKGROUND_COLOR;

    // Info
    info_canvas = lv_canvas_create(screen);
    lv_obj_align(info_canvas, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_canvas_set_buffer(info_canvas, info_canvas_buffer, SCREEN_HEIGHT, SCREEN_HEIGHT, LV_IMG_CF_TRUE_COLOR);

    // Main
    main_canvas = lv_canvas_create(screen);
    lv_obj_align(main_canvas, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_canvas_set_buffer(main_canvas, main_canvas_buffer, MAIN_CANVAS_WIDTH, MAIN_CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);

    // Initialize listeners
    widget_layer_state_update_init();
    widget_connectivity_state_update_init();
    widget_battery_state_update_init();

    return screen;
}