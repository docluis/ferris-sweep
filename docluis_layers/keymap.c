#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

static uint16_t timer;

enum custom_keycodes {
    LT1_S   = SAFE_RANGE,
    LT2_E   = SAFE_RANGE + 1,
    LT3_T   = SAFE_RANGE + 2,
    LT4_N   = SAFE_RANGE + 3,
    LT5_R   = SAFE_RANGE + 4,
    LT6_I   = SAFE_RANGE + 5,
    LT7_SPC = SAFE_RANGE + 6,
};

void tap_layer_code(uint16_t code) {
    register_code(KC_LALT);
    register_code(code);
    unregister_code(code);
    unregister_code(KC_LALT);
    return;
}

bool handle_custom_key(uint16_t base_keycode, uint16_t layer_keycode, uint16_t layer, keyrecord_t *record) {
    if (record->event.pressed) {
        // Key is pressed
        layer_on(layer);
        tap_layer_code(layer_keycode);
        timer = timer_read();
    } else {
        if (timer_elapsed(timer) < TAPPING_TERM) {
            layer_off(layer);
            tap_layer_code(KC_F12); // Return to layer 0
            tap_code(base_keycode);
        } else {
            layer_off(layer);
            tap_layer_code(KC_F12); // Return to layer 0
        }
    }
    return false;
}

// Implement the custom key behavior
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT1_S:
            return handle_custom_key(KC_S, KC_F1, 1, record);
        case LT2_E:
            return handle_custom_key(KC_E, KC_F2, 2, record);
        case LT3_T:
            return handle_custom_key(KC_T, KC_F3, 3, record);
        case LT4_N:
            return handle_custom_key(KC_N, KC_F4, 4, record);
        case LT5_R:
            return handle_custom_key(KC_R, KC_F5, 5,record);
        case LT6_I:
            return handle_custom_key(KC_I, KC_F6, 6,record);
        case LT7_SPC:
            return handle_custom_key(KC_SPC, KC_F12, 7,record);
        default:
            return true;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, LSFT_T(KC_A), LT5_R, LT1_S, LT3_T, KC_G, KC_M, LT4_N, LT2_E, LT6_I, LSFT_T(KC_O), LCTL_T(KC_Z), LGUI_T(KC_X), LALT_T(KC_C), KC_D, KC_V, KC_K, KC_H, LALT_T(KC_COMM), LGUI_T(KC_DOT), LCTL_T(KC_SLSH), KC_P0, KC_BSPC, LT7_SPC, KC_ENT),
                                                              [1] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_BTN2, KC_NO, KC_BTN1, KC_TRNS, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_TRNS, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [2] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_QUOT, KC_TRNS, KC_CIRC, KC_ASTR, KC_SLSH, KC_AMPR, KC_TRNS, KC_HASH, KC_TILD, KC_NO, KC_DQUO, KC_DLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_BSLS, KC_GRV, KC_TRNS, RGB_RMOD, KC_TRNS, KC_TRNS, RGB_MOD),
                                                              [3] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [4] = LAYOUT_split_3x5_2(KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC, KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_VOLU),
                                                              [5] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [6] = LAYOUT_split_3x5_2(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [7] = LAYOUT_split_3x5_2(KC_ESC, KC_TRNS, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_EXLM, KC_TRNS, DF(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT, KC_TRNS, KC_TAB, KC_NO, KC_TRNS)};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
