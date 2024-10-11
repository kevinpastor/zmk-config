#pragma once

#include "./initialize_listeners.h"

#include <lvgl.h>
#include <zmk/battery.h>
#include <zmk/ble.h>
#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/events/split_peripheral_status_changed.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/usb.h>
#include "./utils/draw_battery.h"

struct peripheral_connectivity_state {
    bool connected;
};

struct states {
    struct peripheral_connectivity_state connectivity;
    struct battery_state battery;
    uint8_t background_index;
};

extern struct states states;
