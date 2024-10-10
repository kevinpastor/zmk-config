#include <lvgl.h>

struct battery_state {
    uint8_t level;
    bool usb_present;
};

void draw_battery(lv_obj_t* canvas, lv_coord_t x, lv_coord_t y, struct battery_state state);
