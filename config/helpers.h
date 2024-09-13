/**
 * None behaviour alias for improved readability.
 */
#define XXX &none

/**
 * Transparent behaviour alias for improved readability.
 */
#define ___ &trans

/**
 * Tap or long press a key.
 *
 * @example
 * ```cpp
 * ZMK_HELD(bt_0, &bt BT_SEL 0, &bt BT_SEL 0 &bt BT_CLR)
 * ```
 */
#define ZMK_HELD(NAME, HELD_BINDING, BINDING) \
    ZMK_MACRO(NAME ## _macro_0, \
        bindings = <HELD_BINDING>; \
    ) \
    ZMK_MACRO(NAME ## _macro_1, \
        bindings = <BINDING>; \
    ) \
    ZMK_HOLD_TAP(NAME, \
        flavor = "tap-preferred"; \
        tapping-term-ms = <5000>; \
        bindings = \
            <&NAME ## _macro_0>, \
            <&NAME ## _macro_1>; \
    )

#define HRM_TAPPING_TERM 400 // 280 in urob's config, but found that "s" and "t" caused too often CTRL + T.

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
    ZMK_HOLD_TAP(NAME, \
        flavor = "balanced"; \
        tapping-term-ms = <HRM_TAPPING_TERM>; \
        quick-tap-ms = <175>; \
        require-prior-idle-ms = <150>; \
        bindings = <HOLD>, <TAP>; \
        hold-trigger-key-positions = <TRIGGER_POS>; \
        hold-trigger-on-release; \
    )
