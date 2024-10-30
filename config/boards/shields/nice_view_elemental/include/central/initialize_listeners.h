#pragma once

#include "../initialize_listeners.h"

#include <stdbool.h>
#include <zmk/endpoints.h>
#include <zmk/keymap.h>
#include "../utils/draw_battery.h"

struct connectivity_state {
    struct zmk_endpoint_instance selected_endpoint;
    int active_profile_index;
    bool active_profile_connected;
    bool active_profile_bonded;
};

struct layer_state {
    zmk_keymap_layer_index_t index;
    const char* name;
};

struct states {
    unsigned background_index;
    struct battery_state battery;
    struct connectivity_state connectivity;
    struct layer_state layer;
};

extern struct states states;

void initialize_listeners();
