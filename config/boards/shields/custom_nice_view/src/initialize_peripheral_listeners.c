#include "../include/initialize_peripheral_listeners.h"

#include <zmk/battery.h>
#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/events/split_peripheral_status_changed.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/usb.h>
#include <zmk/ble.h>
#include "../include/render_peripheral.h"

struct states states;

static void peripheral_connectivity_state_update_callback(struct peripheral_connectivity_state state) {
    states.connectivity = state;

    render_peripheral();
}

static struct peripheral_connectivity_state get_peripheral_connectivity_state(const zmk_event_t *_eh) {
    const bool connected = zmk_split_bt_peripheral_is_connected();

    struct peripheral_connectivity_state state = {
        .connected = connected,
    };

    return state;
}

// Create a listener named `widget_peripheral_connectivity_state_update`. This
// name is then used to create a subscription.
ZMK_DISPLAY_WIDGET_LISTENER(
    widget_peripheral_connectivity_state_update,
    struct peripheral_connectivity_state,
    // Called after `get_peripheral_connectivity_state` with the value it returned.
    peripheral_connectivity_state_update_callback,
    get_peripheral_connectivity_state
)

// Subscribe the `widget_peripheral_connectivity_state_update` listener to the
// `zmk_split_peripheral_status_changed` event dispatched by ZMK.
ZMK_SUBSCRIPTION(
    widget_peripheral_connectivity_state_update,
    // Triggered when the peripheral was connected or disconnected from the
    // central.
    zmk_split_peripheral_status_changed
);

static void battery_state_update_callback(struct battery_state state) {
    states.battery = state;

    render_peripheral();
}

static struct battery_state get_battery_state(const zmk_event_t *eh) {
    // `as_zmk_battery_state_changed(event)->state_of_charge` seems to be
    // usually used but the same value can be retrieved from the following.
    const uint8_t level = zmk_battery_state_of_charge();
    const bool is_charging = zmk_usb_is_powered();

    struct battery_state state = {
        .level = level,
        .is_charging = is_charging,
    };

    return state;
}

// Create a listener named `widget_battery_state_update`. This name is then
// used to create a subscription.
ZMK_DISPLAY_WIDGET_LISTENER(
    widget_battery_state_update,
    struct battery_state,
    // Called after `get_battery_state` with the value it returned.
    battery_state_update_callback,
    get_battery_state
)

// Subscribe the `widget_battery_state_update` listener to the
// `zmk_battery_state_changed` event dispatched by ZMK.
ZMK_SUBSCRIPTION(
    widget_battery_state_update,
    // Triggered when the computed battery percentage has changed.
    zmk_battery_state_changed
);

// Subscribe the `widget_battery_state_update` listener to the
// `zmk_usb_conn_state_changed` event dispatched by ZMK.
ZMK_SUBSCRIPTION(
    widget_battery_state_update,
    // Triggered when connected or disconnected from USB.
    zmk_usb_conn_state_changed
);

void initialize_listeners() {
    widget_peripheral_connectivity_state_update_init();
    widget_battery_state_update_init();
}
