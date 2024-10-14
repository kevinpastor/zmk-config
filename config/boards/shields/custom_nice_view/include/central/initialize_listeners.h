#pragma once

#include "../initialize_listeners.h"

#include <stdbool.h>
#include <zmk/endpoints.h>
#include <zmk/keymap.h>
#include "../utils/draw_battery.h"

struct central_connectivity_state {
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
    struct central_connectivity_state connectivity;
    struct layer_state layer;
    struct battery_state battery;
    unsigned background_index;
};

extern struct states states;

void initialize_listeners();
