#include "../../include/central/render_central.h"

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

static void render_bluetooth_logo() {
    if (states.connectivity.active_profile_bonded) {
        if (states.connectivity.active_profile_connected) {
            draw_bluetooth_logo(info_canvas, 52, 4);
        } else {
            draw_bluetooth_logo_outlined(info_canvas, 52, 4);
        }
    } else {
        draw_bluetooth_logo_outline(info_canvas, 52, 4);
    }
}

static void render_bluetooth_profile_index() {
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
}

static void render_bluetooth_connectivity() {
    render_bluetooth_profile_index();
    render_bluetooth_logo();
}

static void render_usb_connectivity() {
    draw_usb_logo(info_canvas, 45, 8);
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

static void render_info() {
    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    render_connectivity();
    draw_battery(info_canvas, 5, 7, states.battery);

    rotate_info_canvas();
}

static void draw_layer_name() {
    lv_draw_label_dsc_t layer_name_dsc;
    lv_draw_label_dsc_init(&layer_name_dsc);
    layer_name_dsc.color = FOREGROUND_COLOR;
    layer_name_dsc.font = &custom_font_44;
    layer_name_dsc.align = LV_TEXT_ALIGN_CENTER;

    const int actual_font_height = 38;
    int padding = (MAIN_CANVAS_HEIGHT - actual_font_height) / 2;

    char* upperCasedName = malloc((strlen(states.layer.name) + 1) * sizeof(char));
    for (int i = 0; states.layer.name[i] != '\0'; i++) {
        upperCasedName[i] = toupper(states.layer.name[i]);
    }
    upperCasedName[strlen(states.layer.name)] = '\0';

    lv_canvas_draw_text(main_canvas, 0, padding, MAIN_CANVAS_WIDTH, &layer_name_dsc, upperCasedName);
    free(upperCasedName);
}

static void render_main() {
    draw_background(main_canvas, states.background_index);
    
    draw_layer_name();
}

void render_central() {
    render_info();
    render_main();
}
