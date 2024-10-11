#pragma once

#include <lvgl.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 68

#define INFO_CANVAS_WIDTH (SCREEN_HEIGHT)
#define INFO_CANVAS_HEIGHT 25

#define MAIN_CANVAS_WIDTH (SCREEN_WIDTH - INFO_CANVAS_HEIGHT)
#define MAIN_CANVAS_HEIGHT (SCREEN_HEIGHT)

extern lv_obj_t* info_canvas;
extern lv_color_t info_canvas_buffer[];

extern lv_obj_t* main_canvas;
extern lv_color_t main_canvas_buffer[];
