#pragma once

#include <zmk/display/status_screen.h>

#include <lvgl.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 68

#define TOP_WIDTH 25

#define CONNECTIVITY_CANVAS_WIDTH (SCREEN_HEIGHT / 2)
#define CONNECTIVITY_CANVAS_HEIGHT (CONNECTIVITY_CANVAS_WIDTH)
#define CONNECTIVITY_CANVAS_AVAILABLE_HEIGHT (TOP_WIDTH)

#define BATTERY_CANVAS_WIDTH (TOP_WIDTH)
#define BATTERY_CANVAS_HEIGHT (SCREEN_HEIGHT / 2)

#define MAIN_CANVAS_WIDTH (SCREEN_WIDTH - TOP_WIDTH)
#define MAIN_CANVAS_HEIGHT (SCREEN_HEIGHT)

extern lv_obj_t* info_canvas;
extern lv_color_t info_canvas_buffer[];

extern lv_obj_t* battery_canvas;
extern lv_color_t battery_canvas_buffer[];

extern lv_obj_t* layer_canvas;
extern lv_color_t layer_canvas_buffer[];

extern lv_obj_t* main_canvas;
extern lv_color_t main_canvas_buffer[];
