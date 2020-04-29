/* Copyright 2019 Kurt Lachmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Layer shorthand
enum layers {
    _COLEMAK,
    _COLEMAK_FKEYS,
    _GAMING,
    _NAV,
    _NUM,
    _ADJUST,
    _FN,
    _RESET
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MY_CIRC = SAFE_RANGE,
  MY_GRV,
  ALT_TAB,
  FKEYLCK,
};

// Layer switching
#define NUM    MO(_NUM)
#define NAV    MO(_NAV)
#define ADJUST MO(_ADJUST)
#define FN     MO(_FN)
#define GAMING TG(_GAMING)

// Aliases for key combinations
#define ALT_F4  LALT(KC_F4)
#define CTLPGUP LCTL(KC_PGUP)
#define CTLPGDN LCTL(KC_PGDN)

// Track if we are in the Alt-Tab mode
// (i.e. Alt-Tab was pressed and Alt is still pressed)
bool is_alt_tabbing = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  // Base layer (COLEMAK)
  [_COLEMAK] = LAYOUT_ortho_5x15(
    DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_EQL,  DE_SLSH, DE_PLUS, DE_QUOT, DE_DQOT,
    KC_ESC,  DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,    KC_PGUP, KC_DEL,  KC_HOME, DE_J,    DE_L,    DE_U,    DE_Y,    KC_BSPC, KC_DEL,
    KC_TAB,  DE_A,    DE_R,    DE_S,    DE_T,    DE_G,    KC_PGDN, KC_UP,   KC_END,  DE_M,    DE_N,    DE_E,    DE_I,    DE_O,    KC_ENT,
    KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,    KC_LEFT, KC_DOWN, KC_RGHT, DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
    FN,      KC_LALT, KC_LCTL, KC_LGUI, NUM,     KC_LCTL, KC_LSFT, KC_PSCR, KC_RSFT, KC_SPC,  NAV,     DE_AE,   DE_OE,   DE_UE,   DE_SS
  ),


  // Alternate Base layer with F-keys instead of a number row
  [_COLEMAK_FKEYS] = LAYOUT_ortho_5x15(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DE_PLUS, DE_QUOT, DE_DQOT,
    KC_ESC,  DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,    KC_PGUP, KC_DEL,  KC_HOME, DE_J,    DE_L,    DE_U,    DE_Y,    KC_BSPC, KC_DEL,
    KC_TAB,  DE_A,    DE_R,    DE_S,    DE_T,    DE_G,    KC_PGDN, KC_UP,   KC_END,  DE_M,    DE_N,    DE_E,    DE_I,    DE_O,    KC_ENT,
    KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,    KC_LEFT, KC_DOWN, KC_RGHT, DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
    FN,      KC_LALT, KC_LCTL, KC_LGUI, NUM,     KC_LCTL, KC_LSFT, KC_PSCR, KC_RSFT, KC_SPC,  NAV,     DE_AE,   DE_OE,   DE_UE,   DE_SS
  ),


  // Gaming layer (QWERTZ)
  [_GAMING] = LAYOUT_ortho_5x15(
    DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SLSH, DE_EQL,  DE_PLUS, DE_QUOT, KC_DEL,
    KC_ESC,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    KC_CAPS, KC_PSCR, KC_INS,  DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
    KC_TAB,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    KC_PGUP, KC_DEL,  KC_HOME, DE_H,    DE_J,    DE_K,    DE_L,    DE_QUOT, KC_ENT,
    KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    KC_PGDN, KC_UP,   KC_END,  DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
    FN,      KC_LALT, KC_LGUI, NUM,     KC_SPC,  KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  NAV,     DE_AE,   DE_OE,   DE_UE,   DE_SS
  ),


  // Navigation
  [_NAV] = LAYOUT_ortho_5x15(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, _______,
    _______, DE_LESS, DE_MORE, DE_LCBR, DE_RCBR, XXXXXXX, KC_CAPS, KC_PSCR, KC_INS,  XXXXXXX, KC_APP,  KC_UP,   CTLPGUP, CTLPGDN, _______,
    _______, DE_LBRC, DE_RBRC, DE_LPRN, DE_RPRN, XXXXXXX, _______, KC_NLCK, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
    _______, DE_PIPE, DE_BSLS, DE_AMPR, DE_TILD, XXXXXXX, _______, _______, _______, XXXXXXX, KC_HOME, KC_BSPC, KC_DEL,  KC_SPC,  _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


  // Numbers
  [_NUM] = LAYOUT_ortho_5x15(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, _______,
    _______, DE_AT,   DE_QUOT, DE_DQOT, DE_CIRC, DE_PARA, KC_CAPS, KC_PSCR, KC_INS,  XXXXXXX, KC_P7,   KC_P8,   KC_P9,   DE_ASTR, _______,
    ALT_TAB, DE_DLR,  DE_EXLM, DE_QST,  DE_PERC, DE_RING, _______, KC_NLCK, _______, DE_PLUS, KC_P4,   KC_P5,   KC_P6,   DE_EQL,  _______,
    _______, DE_EURO, DE_GRV,  DE_ACUT, ALT_TAB, ALT_F4,  _______, _______, _______, DE_HASH, KC_P1,   KC_P2,   KC_P3,   DE_SLSH, _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   _______, _______, _______, _______, _______
  ),


  // Adjust
  [_ADJUST] = LAYOUT_ortho_5x15(
    KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, _______, _______, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______,
    XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, _______, _______, _______, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


  // Function layer
  [_FN] = LAYOUT_ortho_5x15(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    KC_VOLU, KC_MPRV, GAMING,  XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_PSCR, KC_INS,  XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
    KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
    _______, FKEYLCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_RESET)
  ),


  [_RESET] = LAYOUT_ortho_5x15(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),
};


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _NUM, _NAV, _ADJUST);
}


void press_key(uint16_t key) {
    register_code(key);
    unregister_code(key);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_CIRC:
            if (record->event.pressed) {
                press_key(DE_CIRC);
                press_key(DE_CIRC);
            }
            return false;
        case MY_GRV:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                register_code(DE_ACUT);
                unregister_code(DE_ACUT);
                register_code(DE_ACUT);
                unregister_code(DE_ACUT);
                unregister_code(KC_LSHIFT);
            }
            return false;
        case NUM:
            // Ensure Numlock is activated
            if (IS_HOST_LED_OFF(USB_LED_NUM_LOCK)) {
                press_key(KC_NUMLOCK);
            }
            // Was the key released?
            if (!record->event.pressed) {
                if (is_alt_tabbing) {
                    unregister_code(KC_LALT);
                    is_alt_tabbing = false;
                }
            }
            // Allow further processing
            return true;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tabbing) {
                    register_code(KC_LALT);
                    is_alt_tabbing = true;
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return true;
        case FKEYLCK:
            // Switch between a number row and F-Keys
            // Toggle between two base layers and persist them
            if (record->event.pressed) {
                uint8_t default_layer = eeconfig_read_default_layer();
                if (default_layer & (1UL << _COLEMAK)) {
                    set_single_persistent_default_layer(_COLEMAK_FKEYS);
                } else {
                    set_single_persistent_default_layer(_COLEMAK);
                }
            }
            return false;
        case KC_LSFT:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
                    // Enable Capslock by pressing both Shift keys
                    press_key(KC_CAPS);
                    return false;
                }
            }
            return true;
        case KC_RSFT:
            if (record->event.pressed) {
                if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
                    // Enable Capslock by pressing both Shift keys
                    press_key(KC_CAPS);
                    return false;
                }
            }
            return true;
    }
    return true;
}


// Initialization on startup
void keyboard_post_init_user(void) {
}


void matrix_scan_user(void) {

}
