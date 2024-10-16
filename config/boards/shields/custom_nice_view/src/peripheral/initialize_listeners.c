#include "../../include/peripheral/initialize_listeners.h"

#include <zmk/battery.h>
#include <zmk/ble.h>
#include <zmk/split/bluetooth/peripheral.h>
#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/events/split_peripheral_status_changed.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/usb.h>
#include "../../include/peripheral/render.h"

struct states states;

static void battery_state_update_callback(struct battery_state state) {
    states.battery = state;

    render_battery();
}

static struct battery_state get_battery_state(const zmk_event_t* event) {
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

static void connectivity_state_update_callback(struct connectivity_state state) {
    states.connectivity = state;

    render_connectivity();
}

static struct connectivity_state get_connectivity_state(const zmk_event_t* event) {
    const bool connected = zmk_split_bt_peripheral_is_connected();

    struct connectivity_state state = {
        .connected = connected,
    };

    return state;
}

// Create a listener named `widget_connectivity_state_update`. This
// name is then used to create a subscription.
ZMK_DISPLAY_WIDGET_LISTENER(
    widget_connectivity_state_update,
    struct connectivity_state,
    // Called after `get_connectivity_state` with the value it returned.
    connectivity_state_update_callback,
    get_connectivity_state
)

// Subscribe the `widget_connectivity_state_update` listener to the
// `zmk_split_peripheral_status_changed` event dispatched by ZMK.
ZMK_SUBSCRIPTION(
    widget_connectivity_state_update,
    // Triggered when the peripheral was connected or disconnected from the
    // central.
    zmk_split_peripheral_status_changed
);

void background_update_timer(lv_timer_t* timer)
{
    states.background_index = (states.background_index + 1) % UINT_MAX;

    render_main();
}

void initialize_listeners() {
    widget_connectivity_state_update_init();
    widget_battery_state_update_init();

    // We are calling this one during the initialization since no state is bound
    // to it.
    render_main();

    // Call the `background_update_timer` function every 250ms.
    lv_timer_create(background_update_timer, 250, NULL);
}
