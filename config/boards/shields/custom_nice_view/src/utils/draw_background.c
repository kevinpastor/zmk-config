#include "../../include/utils/draw_background.h"

#include <lvgl.h>
#include "../../include/images/background_0.h"
#include "../../include/images/background_1.h"
#include "../../include/images/background_2.h"
#include "../../include/images/background_3.h"
#include "../../include/images/background_4.h"
#include "../../include/images/background_5.h"
#include "../../include/images/background_6.h"

void draw_background(lv_obj_t* canvas, unsigned index) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    switch (index % 5) {
        case 0: {
            lv_canvas_draw_img(canvas, 0, 0, &background_0, &img_dsc);
            break;
        }
        case 1: {
            lv_canvas_draw_img(canvas, 0, 0, &background_1, &img_dsc);
            break;
        }
        case 2: {
            lv_canvas_draw_img(canvas, 0, 0, &background_2, &img_dsc);
            break;
        }
        case 3: {
            lv_canvas_draw_img(canvas, 0, 0, &background_3, &img_dsc);
            break;
        }
        case 4: {
            lv_canvas_draw_img(canvas, 0, 0, &background_4, &img_dsc);
            break;
        }
        case 5: {
            lv_canvas_draw_img(canvas, 0, 0, &background_5, &img_dsc);
            break;
        }
        case 6: {
            lv_canvas_draw_img(canvas, 0, 0, &background_6, &img_dsc);
            break;
        }
    }
}
