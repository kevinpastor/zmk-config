#include "../../include/central/render.h"

#include <ctype.h>
#include <lvgl.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/colors.h"
#include "../../include/central/initialize_listeners.h"
#include "../../include/fonts/custom_font_22.h"
#include "../../include/fonts/custom_font_44.h"
#include "../../include/main.h"
#include "../../include/utils/draw_battery.h"
#include "../../include/utils/draw_background.h"
#include "../../include/utils/draw_bluetooth_logo_outline.h"
#include "../../include/utils/draw_bluetooth_logo_outlined.h"
#include "../../include/utils/draw_bluetooth_logo.h"
#include "../../include/utils/draw_usb_logo.h"
#include "../../include/utils/rotate_info_canvas.h"

void render_battery() {
    lv_canvas_fill_bg(battery_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    draw_battery(battery_canvas, 7, 4, states.battery);
}

static void render_bluetooth_logo() {
    if (states.connectivity.active_profile_bonded) {
        if (states.connectivity.active_profile_connected) {
            draw_bluetooth_logo(info_canvas, 18, 4);
        } else {
            draw_bluetooth_logo_outlined(info_canvas, 18, 4);
        }
    } else {
        draw_bluetooth_logo_outline(info_canvas, 18, 4);
    }
}

static void render_bluetooth_profile_index() {
    lv_draw_label_dsc_t label_dsc;
    lv_draw_label_dsc_init(&label_dsc);
    label_dsc.color = FOREGROUND_COLOR;
    label_dsc.font = &custom_font_22;
    label_dsc.align = LV_TEXT_ALIGN_RIGHT;

    static const unsigned custom_font_22_height = 19;
    static const unsigned padding_y = (CONNECTIVITY_CANVAS_AVAILABLE_HEIGHT - custom_font_22_height) / 2;
    static const unsigned width = CONNECTIVITY_CANVAS_WIDTH - 18;
    static const char bluetooth_profile_label[5][2] = {"1", "2", "3", "4", "5"};
    const char* label = bluetooth_profile_label[states.connectivity.active_profile_index];
    
    lv_canvas_draw_text(info_canvas, 0, padding_y, width, &label_dsc, label);
}

static void render_bluetooth_connectivity() {
    render_bluetooth_logo();
    render_bluetooth_profile_index();
}

static void render_usb_connectivity() {
    draw_usb_logo(info_canvas, 11, 8);
}

void render_connectivity() {
    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

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

    rotate_info_canvas();
}

void render_main() {
    // Unfortunately, text transparent does not seem to work in LVGL 8.3. This
    // forces us to redraw the background on every render instead of having it
    // on a layer underneath.
    draw_background(main_canvas, states.background_index);

    lv_draw_label_dsc_t layer_name_dsc;
    lv_draw_label_dsc_init(&layer_name_dsc);
    layer_name_dsc.color = FOREGROUND_COLOR;
    layer_name_dsc.font = &custom_font_44;
    layer_name_dsc.align = LV_TEXT_ALIGN_CENTER;

    static const unsigned actual_font_height = 38;
    static const unsigned padding_y = (MAIN_CANVAS_HEIGHT - actual_font_height) / 2;

    // Capitalize the layer name if given or use the layer number otherwise.
    char* text = NULL;
    if (states.layer.name == NULL) {
        text = malloc(10 * sizeof(char));
        sprintf(text, "LAYER %i", states.layer.index);
    }
    else {
        text = malloc((strlen(states.layer.name) + 1) * sizeof(char));
        for (unsigned i = 0; states.layer.name[i] != '\0'; i++) {
            text[i] = toupper(states.layer.name[i]);
        }
        text[strlen(states.layer.name)] = '\0';
    }

    lv_canvas_draw_text(
        main_canvas,
        0,
        padding_y,
        MAIN_CANVAS_WIDTH,
        &layer_name_dsc,
        text
    );

    free(text);
    text = NULL;
}
