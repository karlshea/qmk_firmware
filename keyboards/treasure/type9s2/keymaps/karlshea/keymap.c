#include QMK_KEYBOARD_H

// Define three custom keycodes
enum custom_keycodes {
    MY_CUT = SAFE_RANGE,
    MY_CPY,
    MY_PST,
};

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        MO(1),   KC_MPLY, BL_STEP,
        KC_MPRV, KC_MUTE, KC_MNXT,
        MY_CUT,  MY_CPY,  MY_PST
    ),

    [1] = LAYOUT_ortho_3x3(
        _______, _______, MO(2),
        _______, _______, _______,
        _______, _______, _______
    ),

    [2] = LAYOUT_ortho_3x3(
        _______, _______, _______,
        _______, _______, _______,
        _______, _______, MO(3)
    ),

    [3] = LAYOUT_ortho_3x3(
        _______, _______, _______,
        _______, _______, _______,
        QK_BOOT, _______, _______
    )
};


// Custom keycode handler
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // Cut
        case MY_CUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("x")); // Left cmd + x
            }
            return false;

        // Copy
        case MY_CPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("c")); // Left cmd + c
            }
            return false;

        // Paste
        case MY_PST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("v")); // Left cmd + v
            }
            return false;

    }
    return true;
}
