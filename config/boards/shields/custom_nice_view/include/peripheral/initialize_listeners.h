#pragma once

#include "../initialize_listeners.h"

#include <stdbool.h>
#include "../utils/draw_battery.h"

struct peripheral_connectivity_state {
    bool connected;
};

struct states {
    struct peripheral_connectivity_state connectivity;
    struct battery_state battery;
    unsigned background_index;
};

extern struct states states;

void initialize_listeners();
