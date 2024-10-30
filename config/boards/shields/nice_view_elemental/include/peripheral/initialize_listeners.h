#pragma once

#include "../initialize_listeners.h"

#include <stdbool.h>
#include "../utils/draw_battery.h"

struct connectivity_state {
    bool connected;
};

struct states {
    unsigned background_index;
    struct battery_state battery;
    struct connectivity_state connectivity;
};

extern struct states states;

void initialize_listeners();
