/**
 * None behaviour alias for improved readability.
 */
#define XXX &none

/**
 * Transparent behaviour alias for improved readability.
 */
#define ___ &trans

/**
 * Press a key, or execute a macro when Shift is held.
 *
 * @example
 * ```cpp
 * ZMK_HELD(bt_0, &bt BT_SEL 0, &bt BT_SEL 0 &bt BT_CLR)
 * ```
 */
#define ZMK_HELD(NAME, BINDING, HELD_BINDING) \
    ZMK_BEHAVIOR(NAME ## _macro_0, macro, \
        wait-ms = <0>; \
        bindings = <BINDING>; \
    ) \
    ZMK_BEHAVIOR(NAME ## _macro_1, macro, \
        wait-ms = <0>; \
        bindings = <HELD_BINDING>; \
    ) \
    ZMK_BEHAVIOR(NAME, hold_tap, \
        flavor = "tap-preferred"; \
        tapping-term-ms = <5000>; \
        bindings = \
            <&NAME ## _macro_0>, \
            <&NAME ## _macro_1>; \
    )

#define HRM_TAPPING_TERM 450 // 280 in urob's config, but found that "s" and "t" caused too often CTRL + T.

/**
 * Create a timer-less home row mods behaviour.
 *
 * @example
 * ```cpp
 * #define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4
 * #define THUMBS LH2 LH1 LH0 RH0 RH1 RH2
 * MAKE_HRM(home_row_mods_left, &kp, &kp, KEYS_R THUMBS)
 * ```
 */
#define MAKE_HRM(NAME, HOLD, TAP, TRIGGER_POS) \
    ZMK_BEHAVIOR(NAME, hold_tap, \
        flavor = "balanced"; \
        tapping-term-ms = <HRM_TAPPING_TERM>; \
        quick-tap-ms = <175>; \
        require-prior-idle-ms = <150>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-key-positions = <TRIGGER_POS>; \
        hold-trigger-on-release; \
    )
