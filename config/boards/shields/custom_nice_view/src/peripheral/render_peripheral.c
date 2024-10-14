#include "../../include/peripheral/render_peripheral.h"

#include <lvgl.h>
#include "../../include/colors.h"
#include "../../include/main.h"
#include "../../include/peripheral/initialize_listeners.h"
#include "../../include/utils/draw_battery.h"
#include "../../include/utils/draw_background.h"
#include "../../include/utils/draw_bluetooth_logo_outlined.h"
#include "../../include/utils/draw_bluetooth_logo.h"
#include "../../include/utils/rotate_info_canvas.h"

static void render_connectivity() {
    if (states.connectivity.connected) {
        draw_bluetooth_logo(info_canvas, 52, 4);
    } else {
        draw_bluetooth_logo_outlined(info_canvas, 52, 4);
    }
}

static void render_info() {
    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    render_connectivity();
    draw_battery(info_canvas, 5, 7, states.battery);
 
    rotate_info_canvas();
}

static void render_main() {
    lv_draw_rect_dsc_t background_dsc;
    lv_draw_rect_dsc_init(&background_dsc);
    background_dsc.bg_color = BACKGROUND_COLOR;
    lv_canvas_draw_rect(main_canvas, 0, 0, MAIN_CANVAS_WIDTH, MAIN_CANVAS_HEIGHT, &background_dsc);

    draw_background(main_canvas, states.background_index);
}

void render_peripheral() {
    render_info();
    render_main();
}
