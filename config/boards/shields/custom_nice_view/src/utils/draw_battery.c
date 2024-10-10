#include "../../include/utils/draw_battery.h"

#define FOREGROUND_COLOR lv_color_black()
#define BACKGROUND_COLOR lv_color_white()

static void draw_battery_outline(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y) {
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = FOREGROUND_COLOR;

    lv_canvas_draw_rect(canvas, x + 2, y, 19, 1, &rect_dsc); // Top
    lv_canvas_draw_rect(canvas, x + 22, y + 2, 1, 7, &rect_dsc); // Right
    lv_canvas_draw_rect(canvas, x + 2, y + 10, 19, 1, &rect_dsc); // Bottom
    lv_canvas_draw_rect(canvas, x, y + 2, 1, 7, &rect_dsc); // Left

    lv_canvas_set_px_color(canvas, x + 1, y + 1, FOREGROUND_COLOR); // Top left
    lv_canvas_set_px_color(canvas, x + 21, y + 1, FOREGROUND_COLOR); // Top right
    lv_canvas_set_px_color(canvas, x + 21, y + 9, FOREGROUND_COLOR); // Bottom right
    lv_canvas_set_px_color(canvas, x + 1, y + 9, FOREGROUND_COLOR); // Bottom left

    lv_canvas_draw_rect(canvas, x + 23, y + 4, 1, 3, &rect_dsc); // Right-side terminal
}

// The lightning bolt is drawn line by line.
static void draw_battery_lightning_bolt(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y) {
    lv_canvas_set_px_color(canvas, x + 11, y + 2, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 12, y + 2, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 13, y + 2, BACKGROUND_COLOR);
    
    lv_canvas_set_px_color(canvas, x + 10, y + 3, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 11, y + 3, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 12, y + 3, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 9, y + 4, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 10, y + 4, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 11, y + 4, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 12, y + 4, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 9, y + 5, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 10, y + 5, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 11, y + 5, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 12, y + 5, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 13, y + 5, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 10, y + 6, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 11, y + 6, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 12, y + 6, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 13, y + 6, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 10, y + 7, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 11, y + 7, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 12, y + 7, BACKGROUND_COLOR);

    lv_canvas_set_px_color(canvas, x + 9, y + 8, BACKGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 10, y + 8, FOREGROUND_COLOR);
    lv_canvas_set_px_color(canvas, x + 11, y + 8, BACKGROUND_COLOR);
}

void draw_battery(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y, struct battery_state state) {
    draw_battery_outline(canvas, x, y);

    // Draw the main part of the battery
    const int width = 19 * (state.level / 100.0);
    lv_draw_rect_dsc_t rect_dsc;
    lv_draw_rect_dsc_init(&rect_dsc);
    rect_dsc.bg_color = FOREGROUND_COLOR;
    lv_canvas_draw_rect(canvas, x + 2, y + 2, width, 7, &rect_dsc);

    // Round the corners
    lv_canvas_set_px_color(canvas, x + 2, y + 2, BACKGROUND_COLOR); // Top left
    lv_canvas_set_px_color(canvas, x + 20, y + 2, BACKGROUND_COLOR); // Top right
    lv_canvas_set_px_color(canvas, x + 20, y + 8, BACKGROUND_COLOR); // Bottom right
    lv_canvas_set_px_color(canvas, x + 2, y + 8, BACKGROUND_COLOR); // Bottom left

    if (state.usb_present) {
        draw_battery_lightning_bolt(canvas, x, y);
    }
}
