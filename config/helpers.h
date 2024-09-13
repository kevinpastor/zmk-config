/**
 * None behaviour alias for improved readability.
 */
#define XXX &none

/**
 * Transparent behaviour alias for improved readability.
 */
#define ___ &trans

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
