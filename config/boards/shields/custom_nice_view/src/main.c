#include "../include/main.h"

#include <lvgl.h>
#include "../include/initialize_listeners.h"

lv_obj_t* info_canvas;
lv_color_t info_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        CONNECTIVITY_CANVAS_WIDTH,
        CONNECTIVITY_CANVAS_HEIGHT
    )
];

lv_obj_t* battery_canvas;
lv_color_t battery_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        BATTERY_CANVAS_WIDTH,
        BATTERY_CANVAS_HEIGHT
    )
];

lv_obj_t* main_canvas;
lv_color_t main_canvas_buffer[
    LV_CANVAS_BUF_SIZE_TRUE_COLOR(
        MAIN_CANVAS_WIDTH,
        MAIN_CANVAS_HEIGHT
    )
];

// ZMK calls this function directly in `app/src/display/main.c` of its source
// code.
lv_obj_t* zmk_display_status_screen() {
    // Setup the base screen.
    lv_obj_t* screen = lv_obj_create(NULL);
    lv_obj_set_size(screen, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Create the info canvas to be used in the `render` function.
    info_canvas = lv_canvas_create(screen);
    lv_obj_align(info_canvas, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_canvas_set_buffer(
        info_canvas,
        info_canvas_buffer,
        CONNECTIVITY_CANVAS_WIDTH,
        CONNECTIVITY_CANVAS_HEIGHT,
        LV_IMG_CF_TRUE_COLOR
    );

    // Create the info canvas to be used in the `render` function.
    battery_canvas = lv_canvas_create(screen);
    lv_obj_align(battery_canvas, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_canvas_set_buffer(
        battery_canvas,
        battery_canvas_buffer,
        BATTERY_CANVAS_WIDTH,
        BATTERY_CANVAS_HEIGHT,
        LV_IMG_CF_TRUE_COLOR
    );

    // Create the main canvas to be used in the `render` function.
    main_canvas = lv_canvas_create(screen);
    lv_obj_align(main_canvas, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_canvas_set_buffer(
        main_canvas,
        main_canvas_buffer,
        MAIN_CANVAS_WIDTH,
        MAIN_CANVAS_HEIGHT,
        LV_IMG_CF_TRUE_COLOR
    );

    // Depending on which half the build is for, the implementation will differ.
    initialize_listeners();

    return screen;
}
