#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty
#define L1 1 // Base qwerty

#define TAPPING_TOGGLE 10 //basically turn it off

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_LEAD, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           MT(MOD_LSFT, KC_ESC),KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                    LT(L1,KC_HOME),
                           KC_BSPC,KC_DEL ,KC_END ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_MUTE  ,KC_VOLD, KC_VOLU, KC_1, RESET,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,MT(MOD_RCTL, KC_F3),
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),
[L1] = LAYOUT(
           KC_TRNS, KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS,
           KC_TRNS, KC_F1  ,KC_F2  ,KC_F3,  KC_F4  ,KC_F5   ,
           KC_TRNS, KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10   ,
           KC_TRNS,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,
           KC_TRNS,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,
                   KC_TRNS ,KC_TRNS ,KC_TRNS,KC_TRNS,
			   KC_TRNS,KC_TRNS,
                                    KC_TRNS,
                           KC_TRNS,KC_TRNS ,KC_TRNS ,
    KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS,KC_TRNS ,KC_TRNS,KC_TRNS,
		KC_TRNS  ,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,
           KC_TRNS,
           KC_TRNS,KC_TRNS ,KC_TRNS
    )
	
};

void matrix_init_user(void) {

}

LEADER_EXTERNS();

void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_1) {
      tap_code(KC_F13);
    }
	SEQ_ONE_KEY(KC_2) {
      tap_code(KC_F14);
    }
	SEQ_ONE_KEY(KC_3) {
      tap_code(KC_F15);
    }
	SEQ_ONE_KEY(KC_4) {
      tap_code(KC_F16);
    }
	SEQ_ONE_KEY(KC_5) {
      tap_code(KC_F17);
    }
	
	

    SEQ_ONE_KEY(KC_Q) {
      tap_code(KC_F18);
    }
	SEQ_ONE_KEY(KC_W) {
      tap_code(KC_F19);
    }
	SEQ_ONE_KEY(KC_E) {
      tap_code(KC_F20);
    }
	SEQ_ONE_KEY(KC_R) {
      tap_code(KC_F21);
    }
	SEQ_ONE_KEY(KC_T) {
      tap_code(KC_F22);
    }
	
	SEQ_ONE_KEY(KC_A) {
      tap_code(KC_F23);
    }
	SEQ_ONE_KEY(KC_S) {
      tap_code(KC_F24);
    }
	SEQ_ONE_KEY(KC_D) {
      register_code(KC_LCTRL);
      register_code(KC_F13);
      unregister_code(KC_F13);
      unregister_code(KC_LCTRL);
    }
	SEQ_ONE_KEY(KC_F) {
      register_code(KC_LCTRL);
      register_code(KC_F14);
      unregister_code(KC_F14);
      unregister_code(KC_LCTRL);    
	  }
	SEQ_ONE_KEY(KC_G) {
      register_code(KC_LCTRL);
      register_code(KC_F15);
      unregister_code(KC_F15);
      unregister_code(KC_LCTRL);    
	  }
	
	SEQ_ONE_KEY(KC_Z) {
      register_code(KC_LCTRL);
      register_code(KC_F16);
      unregister_code(KC_F16);
      unregister_code(KC_LCTRL);    
	  }
	SEQ_ONE_KEY(KC_X) {
      register_code(KC_LCTRL);
      register_code(KC_F17);
      unregister_code(KC_F17);
      unregister_code(KC_LCTRL);    
	  }
	SEQ_ONE_KEY(KC_C) {
      register_code(KC_LCTRL);
      register_code(KC_F18);
      unregister_code(KC_F18);
      unregister_code(KC_LCTRL);    
	  }
	SEQ_ONE_KEY(KC_V) {
      register_code(KC_LCTRL);
      register_code(KC_F19);
      unregister_code(KC_F19);
      unregister_code(KC_LCTRL);    
	  }
	SEQ_ONE_KEY(KC_B) {
      register_code(KC_LCTRL);
      register_code(KC_F20);
      unregister_code(KC_F20);
      unregister_code(KC_LCTRL);    
	  }
	 

//left and right arrow keys, change workspace	 
	 SEQ_ONE_KEY(KC_RGHT) {
      register_code(KC_RCTRL);
	  register_code(KC_RGUI);
	  register_code(KC_RGHT);
	  unregister_code(KC_RGHT);
      unregister_code(KC_RGUI);
      unregister_code(KC_RCTRL);    
	  }
	SEQ_ONE_KEY(KC_LEFT) {
      register_code(KC_RCTRL);
	  register_code(KC_RGUI);
	  register_code(KC_LEFT);
	  unregister_code(KC_LEFT);
      unregister_code(KC_RGUI);
      unregister_code(KC_RCTRL);   
	  }

  }

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
