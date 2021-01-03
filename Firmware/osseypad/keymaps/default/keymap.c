/* Copyright 2021 Osku Väyrynen
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

// Function key we are 'wrapping' usual key presses in
#define KC_WRAP KC_F24


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
	      KC_A, KC_B, KC_C, KC_D, KC_Q, 
    KC_E, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_F, 
    KC_G, KC_KP_7, KC_KP_8, KC_KP_9, KC_H, 
    KC_I, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_J,
	KC_K, KC_KP_1, KC_KP_2, KC_KP_3, KC_L, 
    KC_N, KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_M
  ),

  [1] = LAYOUT(
	      ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____
  ),
  
  [2] = LAYOUT(
	      ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____
  ),
  
  [3] = LAYOUT(
	      ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____, ____,
	____, ____, ____, ____, ____, 
    ____, ____, ____, ____, ____
  ),
};

// Keyboard is setup to 'wrap' the pressed key with an unused Fxx key,
// allowing for easy differentiation from a real keyboard.
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left Encoder */
        if (clockwise) {
            register_code(KC_WRAP);
            tap_code(KC_O);
            unregister_code(KC_WRAP);
        } else {
            register_code(KC_WRAP);
            tap_code(KC_P);
            unregister_code(KC_WRAP);
        }
    } 
}

// Below stolen from TaranVH (https://github.com/TaranVH/2nd-keyboard/blob/master/HASU_USB/F24/keymap.c)
// Shoutout to drashna on the QMK discord for basically writing this for me.... :P
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t f24_tracker;
    switch (keycode) {
        case KC_A ... KC_F23:
        case KC_EXECUTE ... KC_EXSEL:
            if (record->event.pressed) {
                register_code(KC_WRAP);
                f24_tracker++;
                register_code(keycode);
            } else {
                unregister_code(keycode);
                f24_tracker--;
                if (!f24_tracker) {
                    unregister_code(KC_WRAP);
                }
            }
            return false;
            break;
    }
    return true;
}
