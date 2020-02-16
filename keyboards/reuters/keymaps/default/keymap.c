/* Copyright 2020 Tony
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};
  
  
/*
* ,----------------------------------------------------.
* |               |  F7  |  F8  |  F9  |               | 
* |      YOURS    |------+------+------|     MINE      |
* |               |  F10 |  F11 |  F12 |               |
* |--------+------+------+------+------+------+--------|         
* |       BID     | HOLD | DEAL |  REL |     OFFER     |             
* |--------+------+------+------+------+------+--------|                
* |   UP   |  DN  |   7  |   8  |   9  | LEND |  REND  |           
* |--------+------+------+------+------+------+--------|     
* |  LEFT  |RIGHT |   4  |   5  |   6  | CHGP |  SPCE  |      
* |--------+------+------+------+------+------+--------+
* | CXL Instrument|   1  |   2  |   3  | QUIT |  MENU  |  
* |--------+------+------+------+------+------+--------|                 
* |     CXL ALL   |   0  |   .  | SPCE |   Transmit    |                 
* `----------------------------------------------------'   
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
      KC_A,      KC_B, KC_C, KC_D,      KC_E,
	             KC_F, KC_G, KC_H,               
	  KC_I,      KC_J, KC_K, KC_L,      KC_M,    
	KC_N, KC_O,  KC_P, KC_Q, KC_R,   KC_S, KC_T, 
	KC_U, KC_V,  KC_W, KC_X, KC_Y,   KC_Z, KC_0, 
	  KC_1,      KC_2, KC_3, KC_4,   KC_5, KC_6, 
	  KC_7,      KC_8, KC_9, KC_A,      KC_B     
	),
    [_FN] = LAYOUT(
      KC_A,      KC_B, KC_C, KC_D,      KC_E,
	             KC_F, KC_G, KC_H,               
	  KC_I,      KC_J, KC_K, KC_L,      KC_M,    
	KC_N, KC_O,  KC_P, KC_Q, KC_R,   KC_S, KC_T, 
	KC_U, KC_V,  KC_W, KC_X, KC_Y,   KC_Z, KC_0, 
	  KC_1,      KC_2, KC_3, KC_4,   KC_5, KC_6, 
	  KC_7,      KC_8, KC_9, KC_A,      KC_B     
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
