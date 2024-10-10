#include "../include/fonts/custom_font_22.h"
#include "../include/fonts/custom_font_44.h"

#include "../include/images/usb_logo.h"

#include "../include/utils.h"
#include "../include/utils/draw_battery.h"
#include "../include/utils/draw_background.h"

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

struct peripheral_connectivity_state {
    bool connected;
};

struct states {
    struct peripheral_connectivity_state connectivity;
    struct battery_state battery;
    uint8_t background_index;
};

struct states states;

static void render_bluetooth_logo() {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    
    if (states.connectivity.connected) {
        draw_bluetooth_logo(info_canvas, 52, 4);
    } else {
        draw_bluetooth_logo_outlined(info_canvas, 52, 4);
    }
}

static void render_bluetooth_connectivity() {
    render_bluetooth_logo();
}

static void render_connectivity() {
    render_bluetooth_connectivity();
}

static void render_info() {
    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    // Debug
    // lv_canvas_set_px_color(info_canvas, 0, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, INFO_CANVAS_WIDTH - 1, 0, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, 0, INFO_CANVAS_HEIGHT - 1, FOREGROUND_COLOR);
    // lv_canvas_set_px_color(info_canvas, INFO_CANVAS_WIDTH - 1, INFO_CANVAS_HEIGHT - 1, FOREGROUND_COLOR);

    render_connectivity();
    draw_battery(info_canvas, 5, 7, states.battery);
 
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

static void render_main() {
    lv_draw_rect_dsc_t background_dsc;
    lv_draw_rect_dsc_init(&background_dsc);
    background_dsc.bg_color = BACKGROUND_COLOR;
    lv_canvas_draw_rect(main_canvas, 0, 0, MAIN_CANVAS_WIDTH, MAIN_CANVAS_HEIGHT, &background_dsc);

    draw_background(main_canvas, states.background_index);
    states.background_index = states.background_index + 1;
}

static void render() {
    render_info();
    render_main();
}

static void peripheral_connectivity_state_update_callback(struct peripheral_connectivity_state state) {
    states.connectivity = state;

    render();
}

static struct peripheral_connectivity_state get_peripheral_connectivity_state(const zmk_event_t *_eh) {
    const bool connected = zmk_split_bt_peripheral_is_connected();

    struct peripheral_connectivity_state state = {
        .connected = connected,
    };

    return state;
}

ZMK_DISPLAY_WIDGET_LISTENER(
    widget_peripheral_connectivity_state_update,
    struct peripheral_connectivity_state,
    peripheral_connectivity_state_update_callback,
    get_peripheral_connectivity_state
)

#include <zmk/events/split_peripheral_status_changed.h>
ZMK_SUBSCRIPTION(
    widget_peripheral_connectivity_state_update,
    zmk_split_peripheral_status_changed
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
    widget_peripheral_connectivity_state_update_init();
    widget_battery_state_update_init();

    return screen;
}
