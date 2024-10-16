#include "../../include/utils/draw_battery.h"

#include <lvgl.h>
#include "../../include/colors.h"

static void draw_battery_outline(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y) {
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = FOREGROUND_COLOR;

    lv_canvas_draw_rect(canvas, x + 10, y + 2, 1, 19, &rect_dsc); // Top
    lv_canvas_draw_rect(canvas, x + 2, y + 22, 7, 1, &rect_dsc); // Right
    lv_canvas_draw_rect(canvas, x, y + 2, 1, 19, &rect_dsc); // Bottom
    lv_canvas_draw_rect(canvas, x + 2, y, 7, 1, &rect_dsc); // Left

    lv_canvas_set_px_color(canvas, x + 9, y + 1, FOREGROUND_COLOR); // Top left
    lv_canvas_set_px_color(canvas, x + 9, y + 21, FOREGROUND_COLOR); // Top right
    lv_canvas_set_px_color(canvas, x + 1, y + 21, FOREGROUND_COLOR); // Bottom right
    lv_canvas_set_px_color(canvas, x + 1, y + 1, FOREGROUND_COLOR); // Bottom left

    lv_canvas_draw_rect(canvas, x + 4, y + 23, 3, 1, &rect_dsc); // Right-side terminal
}

// The lightning bolt is drawn line by line.
static void draw_battery_lightning_bolt(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y) {
    lv_canvas_set_px_color(canvas, x + 8, y + 11, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 8, y + 12, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 8, y + 13, BACKGROUND_COLOR);
   
    lv_canvas_set_px_color(canvas, x + 7, y + 10, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 7, y + 11, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 7, y + 12, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 6, y + 9, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 6, y + 10, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 6, y + 11, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 6, y + 12, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 5, y + 9, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 5, y + 10, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 5, y + 11, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 5, y + 12, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 5, y + 13, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 4, y + 10, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 4, y + 11, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 4, y + 12, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 4, y + 13, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 3, y + 10, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 3, y + 11, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 3, y + 12, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 2, y + 9, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 2, y + 10, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 2, y + 11, BACKGROUND_COLOR);
}

void draw_battery(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y, struct battery_state state) {
    draw_battery_outline(canvas, x, y);

    // Draw the main part of the battery
    const int width = 19 * (state.level / 100.0);
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = FOREGROUND_COLOR;
    lv_canvas_draw_rect(canvas, x + 2, y + 2, 7, width, &rect_dsc);

    // Round the corners
    lv_canvas_set_px_color(canvas, x + 8, y + 2, BACKGROUND_COLOR); // Top left
    lv_canvas_set_px_color(canvas, x + 8, y + 20, BACKGROUND_COLOR); // Top right
    lv_canvas_set_px_color(canvas, x + 2, y + 20, BACKGROUND_COLOR); // Bottom right
    lv_canvas_set_px_color(canvas, x + 2, y + 2, BACKGROUND_COLOR); // Bottom left

    if (state.is_charging) {
        draw_battery_lightning_bolt(canvas, x, y);
    }
}
