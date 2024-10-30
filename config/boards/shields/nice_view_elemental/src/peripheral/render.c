#include "../../include/peripheral/render.h"

#include <lvgl.h>
#include <zephyr/sys/util.h>
#include "../../include/colors.h"
#include "../../include/main.h"
#include "../../include/peripheral/initialize_listeners.h"
#include "../../include/utils/draw_battery.h"
#include "../../include/utils/draw_background.h"
#include "../../include/utils/draw_bluetooth_logo_outlined.h"
#include "../../include/utils/draw_bluetooth_logo.h"
#include "../../include/utils/rotate_info_canvas.h"

void render_battery() {
    lv_canvas_fill_bg(battery_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    draw_battery(battery_canvas, 7, 4, states.battery);
}

void render_connectivity() {
    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);

    if (states.connectivity.connected) {
        draw_bluetooth_logo(info_canvas, 18, 4);
    } else {
        draw_bluetooth_logo_outlined(info_canvas, 18, 4);
    }

    rotate_info_canvas();
}

void render_main() {
#if IS_ENABLED(CONFIG_NICE_VIEW_ELEMENTAL_BACKGROUND)
    draw_background(main_canvas, states.background_index);
#endif
}
