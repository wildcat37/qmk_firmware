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
   // _TEST,
    _BASE,
	_ENABLE,
	_TRADING
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
	/*
    [_TEST] = LAYOUT(
      KC_A,      KC_B, KC_C, KC_D,      KC_E,
	             KC_F, KC_G, KC_H,               
	  KC_I,      KC_J, KC_K, KC_L,      KC_M,    
	KC_N, KC_O,  KC_P, KC_Q, KC_R,   KC_S, KC_T, 
	KC_U, KC_V,  KC_W, KC_X, KC_Y,   KC_Z, KC_0, 
	  KC_1,      KC_2, KC_3, KC_4,   KC_5, KC_6, 
	  KC_7,      KC_8, KC_9, KC_A,      KC_B     
	),
	*/
    [_BASE] = LAYOUT(
      KC_NO,       KC_NO, KC_NO, KC_NO,      KC_NO,
	               KC_NO, KC_NO, KC_NO,               
	  KC_NO,       KC_NO, KC_NO, KC_NO,      KC_NO,    
	KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, 
	KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, 
	  KC_NO,       KC_NO, KC_NO, KC_NO,   MO(_ENABLE), KC_NO, 
	  KC_NO,       KC_NO, KC_NO, KC_NO,      KC_NO     
	),
	[_ENABLE] = LAYOUT(
      KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,
	                   KC_TRNS, KC_TRNS, KC_TRNS,               
	  KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,    
	KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, 
	KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, 
	  TO(_TRADING),    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, 
	  KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS     
	),
	[_TRADING] = LAYOUT(
              LCTL(KC_F1),        LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4),       LCTL(KC_F5),
	                              LCTL(KC_F6), LCTL(KC_F7), LCTL(KC_F8),               
	          LCTL(KC_F9),        LCTL(KC_F10), LCTL(KC_F11), LCTL(KC_F12),    LCA(KC_F1),    
	  LCA(KC_F2),  LCA(KC_F3),     MEH(KC_F1),          MEH(KC_F2),          MEH(KC_F3),    LCA(KC_F4), LCA(KC_F5), 
	  LCA(KC_F6),  LCA(KC_F7),     MEH(KC_F4),          MEH(KC_F5),          MEH(KC_F6),    LCA(KC_F8), LCA(KC_F9), 
	  LCA(KC_F10),                 MEH(KC_F7),          MEH(KC_F8),          MEH(KC_F9),    TO(_BASE),  LCA(KC_F11), 
	  LCA(KC_F12),                 MEH(KC_F10),          MEH(KC_F11),       MEH(KC_F12),      LALT(KC_F1)     
	)
};


void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Alarm LED high signal is pin F4
  // Set our LED pins as output
  setPinOutput(F4);

}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

    // INSERT CODE HERE: turn off all leds

    switch (layer) {
        case _TRADING:
            //code to turn on led
			PORTF |= (1 << 4);
            break;
        default:
            //code to turn off led
			PORTF &= ~(1 << 4);
            break;
    }
	
	
	
}

/*
bool led_update_user(led_t led_state) {
    return true;
}
*/
