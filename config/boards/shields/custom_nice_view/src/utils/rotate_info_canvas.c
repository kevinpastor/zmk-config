#include "../../include/utils/rotate_info_canvas.h"

#include "../../include/main.h"
#include "../../include/colors.h"

void rotate_info_canvas() {
    static lv_color_t cbuf_tmp[LV_CANVAS_BUF_SIZE_TRUE_COLOR(SCREEN_HEIGHT, SCREEN_HEIGHT)];
    memcpy(cbuf_tmp, info_canvas_buffer, sizeof(cbuf_tmp));

    lv_img_dsc_t img;
    img.data = (void*)cbuf_tmp;
    img.header.cf = LV_IMG_CF_TRUE_COLOR;
    img.header.w = SCREEN_HEIGHT;
    img.header.h = SCREEN_HEIGHT;

    lv_canvas_fill_bg(info_canvas, BACKGROUND_COLOR, LV_OPA_COVER);
    lv_canvas_transform(
        info_canvas,
        &img,
        900, LV_IMG_ZOOM_NONE,
        -1, 0,
        SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2,
        false
    );
}
