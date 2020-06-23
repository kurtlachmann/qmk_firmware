/* Copyright 2015-2017 Jack Humbert
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

extern keymap_config_t keymap_config;

// Layer shorthand
enum layers {
    _COLEMAK,
    _GAMING,
    _NAV,
    _NUM,
    _ADJUST,
    _FN,
    _RESET
};

enum custom_keycodes {
  MY_CIRC = SAFE_RANGE,
  MY_GRV,
  MY_1,
  MY_2,
  MY_3,
  MY_4,
  MY_5,
  MY_6,
  MY_7,
  MY_8,
  MY_9,
  MY_0,
  ALT_TAB,
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


[_COLEMAK] = LAYOUT_planck_grid(
    KC_ESC,  DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,    DE_J,    DE_L,    DE_U,    DE_Y,    KC_BSPC, KC_DEL,
    KC_TAB,  DE_A,    DE_R,    DE_S,    DE_T,    DE_G,    DE_M,    DE_N,    DE_E,    DE_I,    DE_O,    KC_ENT,
    KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,    DE_K,    DE_H,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
    FN,      KC_LALT, KC_APP,  KC_LGUI, NUM,     KC_LCTL, KC_SPC,  NAV,     DE_AE,   DE_OE,   DE_UE,   DE_SS
),


[_GAMING] = LAYOUT_planck_grid(
    KC_ESC,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
    KC_TAB,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_QUOT, KC_ENT,
    KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
    FN,      KC_LALT, KC_LGUI, NUM,     KC_SPC,  KC_LCTL, KC_SPC,  NAV,     DE_AE,   DE_OE,   DE_UE,   DE_SS
),


// Navigation
[_NAV] = LAYOUT_planck_grid(
    _______, DE_LESS, DE_MORE, DE_LCBR, DE_RCBR, XXXXXXX, XXXXXXX, KC_APP,  KC_UP,   CTLPGUP, CTLPGDN, _______,
    _______, DE_LBRC, DE_RBRC, DE_LPRN, DE_RPRN, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
    _______, DE_PIPE, DE_BSLS, DE_AMPR, DE_TILD, XXXXXXX, XXXXXXX, KC_HOME, KC_BSPC, KC_DEL,  KC_SPC,  _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


// Numbers
[_NUM] = LAYOUT_planck_grid(
    _______, DE_AT,   DE_QUOT, DE_DQOT, DE_CIRC, DE_PARA, XXXXXXX, MY_7,    MY_8,    MY_9,    DE_ASTR, _______,
    ALT_TAB, DE_DLR,  DE_EXLM, DE_QST,  DE_PERC, DE_RING, DE_PLUS, MY_4,    MY_5,    MY_6,    DE_EQL,  _______,
    _______, DE_EURO, DE_GRV,  DE_ACUT, ALT_TAB, ALT_F4,  DE_HASH, MY_1,    MY_2,    MY_3,    DE_SLSH, _______,
    XXXXXXX, _______, _______, _______, _______, _______, MY_0,    _______, _______, _______, _______, _______
),


[_ADJUST] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______,
    _______, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, _______,
    XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


[_FN] = LAYOUT_planck_grid(
    KC_VOLU, KC_MPRV, GAMING,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
    KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
    _______, _______, _______, _______, KC_NLCK, _______, _______, _______, _______, _______, _______, MO(_RESET)
  ),


  [_RESET] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _NUM, _NAV, _ADJUST);
}


void press_key(uint16_t key) {
    register_code(key);
    unregister_code(key);
}


// Initialization on startup
void keyboard_post_init_user(void) {
    // Set default layer
    default_layer_set(1U<<_COLEMAK);
}


bool handle_custom_number(int regular_key, int keypad_key, keyrecord_t *record) {
    if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
        if (record->event.pressed) {
            register_code(keypad_key);
        } else {
            unregister_code(keypad_key);
        }
    } else {
        if (record->event.pressed) {
            register_code(regular_key);
        } else {
            unregister_code(regular_key);
        }
    }
    return false;
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
        case MY_1:
            return handle_custom_number(DE_1, KC_P1, record);
        case MY_2:
            return handle_custom_number(DE_2, KC_P2, record);
        case MY_3:
            return handle_custom_number(DE_3, KC_P3, record);
        case MY_4:
            return handle_custom_number(DE_4, KC_P4, record);
        case MY_5:
            return handle_custom_number(DE_5, KC_P5, record);
        case MY_6:
            return handle_custom_number(DE_6, KC_P6, record);
        case MY_7:
            return handle_custom_number(DE_7, KC_P7, record);
        case MY_8:
            return handle_custom_number(DE_8, KC_P8, record);
        case MY_9:
            return handle_custom_number(DE_9, KC_P9, record);
        case MY_0:
            return handle_custom_number(DE_0, KC_P0, record);
    }
    return true;
}
