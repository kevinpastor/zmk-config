#include "../../include/utils/draw_bluetooth_logo_outlined.h"

#include <lvgl.h>
#include "../../include/images/bluetooth_logo_outlined.h"

void draw_bluetooth_logo_outlined(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
   
    lv_canvas_draw_img(canvas, x, y, &bluetooth_logo_outlined, &img_dsc);
}
