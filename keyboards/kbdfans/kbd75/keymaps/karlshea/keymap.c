#include QMK_KEYBOARD_H

// Enable raw hid
#include "raw_hid.h"

// Needed for hid command structure
#include "via.h"

// KBD75 layer indices
enum custom_layers {
    _QWERTY,
    _FL,
};

void keyboard_post_init_user(void) {
  // Disable rgb.
  rgblight_disable();
}

// Custom macros
#define KC_CAP_CMD  MT(MOD_LGUI, KC_CAPS)       // Tap for Caps, hold for Command


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /********************* 0: QWERTY Base Layer ************************
   *  PSN: Print Screen
   *  PUP: Page Up
   *  PDN: Page Down
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │ESC│ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│PSN│SLK│DEL│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │BKSPACE│HOM│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │END│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │CAP/OS│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │PUP│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │SHIFT │UP │PDN│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │CTL │ ALT│ OS │          SPACE         │OS │CTL│FN │LFT│DWN│RT │
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   *******************************************************************/

  [_QWERTY] = LAYOUT_ansi_1u(
    KC_ESC,      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SLCK,  KC_DEL,
    KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
    KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_END,
    KC_CAP_CMD,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGUP,
    KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_PGDN,
    KC_LCTL,     KC_LALT,  KC_LGUI,                      KC_SPC,                                           KC_RGUI,  KC_RCTL,  MO(_FL),  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  /********************* 1: FN Momentary Layer ***********************
   *  PRV   - Media Previous
   *  NXT   - Media Next
   *  PLY   - Media Play/Stop
   *  RESET - Put PCB into Bootstrap mode
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┼───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │ RESET │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │DEC│TOG│INC│STP│   │   │   │   │      │PLY│   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │                        │   │   │   │PRV│   │NXT│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   *******************************************************************/

  [_FL] = LAYOUT_ansi_1u(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET ,           _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    _______,          _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______,          KC_MPLY, _______,
    _______, _______, _______,                   _______,                                     _______, _______, _______, KC_MPRV, _______, KC_MNXT
  ),
};

/**
 * Handle setting backlight over raw HID without VIA enabled.
 */

#ifndef VIA_ENABLE

#ifdef BACKLIGHT_ENABLE
#    if BACKLIGHT_LEVELS == 0
#        error BACKLIGHT_LEVELS == 0
#    endif

void via_qmk_backlight_set_value(uint8_t *data) {
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_backlight_brightness: {
            // level / 255 * BACKLIGHT_LEVELS
            backlight_level_noeeprom(((uint16_t)value_data[0]) * BACKLIGHT_LEVELS / 255);
            break;
        }
    }
}
#endif  // BACKLIGHT_ENABLE

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command_id   = &(data[0]);
    uint8_t *command_data = &(data[1]);
    switch (*command_id) {

        case id_lighting_set_value: {
#if defined(BACKLIGHT_ENABLE)
            via_qmk_backlight_set_value(command_data);
#endif
#if !defined(BACKLIGHT_ENABLE)
            // Return the unhandled state
            *command_id = id_unhandled;
#endif
            break;
        }

        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

#endif // not VIA_ENABLE



