#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty
#define L1 1 // 
#define L2 2 // 
#define L3 3 // progm layer
#define STENO 4 

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
           KC_ESC, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT, KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                    LT(L1,KC_HOME),
                           KC_BSPC,KC_DEL ,LT(L2,KC_END) ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_MUTE  ,KC_VOLD, KC_VOLU, MO(STENO), MO(L3),
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,MT(MOD_RSFT, KC_F3),
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),
	
[L1] = LAYOUT(
           KC_TRNS, KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS,
           KC_TRNS, KC_TRNS  ,KC_TRNS  ,KC_TRNS,  KC_TRNS  ,KC_TRNS   ,
           KC_TRNS, LCA(KC_F16)   ,LCA(KC_F17)   ,LCA(KC_F18)   ,LCA(KC_F19)   ,LCA(KC_F20)   ,
           KC_TRNS,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,
           KC_TRNS,LCA(KC_F13)   ,LCA(KC_F14),LCA(KC_F15)   ,KC_TRNS   ,KC_TRNS   ,
                   KC_TRNS ,KC_TRNS ,KC_TRNS,KC_TRNS,
			   KC_TRNS,KC_TRNS,
                                    KC_TRNS,
                           KC_TRNS,KC_TRNS ,KC_TRNS ,
    KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS ,KC_TRNS,KC_TRNS,
		KC_TRNS  ,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,
           KC_TRNS,
           KC_TRNS,KC_TRNS ,KC_TRNS
    ),
	
//uses F13-F24, C-F13 to C-F22
[L2] = LAYOUT(
           KC_TRNS, KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS,
           KC_TRNS, KC_F13  ,KC_F14  ,KC_F15,  KC_F16  ,KC_F17   ,
           KC_TRNS, KC_F18   ,KC_F19   ,KC_F20   ,KC_F21   ,KC_F22   ,
           KC_TRNS,KC_F23   ,KC_F24   ,LCTL(KC_F13)   ,LCTL(KC_F14)   ,LCTL(KC_F15)   ,
           KC_TRNS,LCTL(KC_F16)   ,LCTL(KC_F17)   ,LCTL(KC_F18)   ,LCTL(KC_F19)   ,LCTL(KC_F20)   ,
                   KC_TRNS ,KC_TRNS ,LCTL(KC_F21),LCTL(KC_F22),
			   KC_TRNS,KC_TRNS,
                                    KC_TRNS,
                           KC_TRNS,KC_TRNS ,KC_TRNS ,
    KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS, KC_TRNS, KC_TRNS, RESET,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,KC_TRNS,KC_TRNS,
	KC_TRNS   ,KC_TRNS   ,KC_TRNS,KC_TRNS ,KC_TRNS,KC_TRNS,
		KC_TRNS  ,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,
           KC_TRNS,
           KC_TRNS,KC_TRNS ,KC_TRNS
    ),
[L3] = LAYOUT(
           KC_NO, KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO,
           KC_NO, KC_NO  ,KC_NO  ,KC_NO,  KC_NO  ,KC_NO   ,
           KC_NO, KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
           KC_NO,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
           KC_NO,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
                   KC_NO ,KC_NO ,KC_NO,KC_NO,
			   KC_NO,KC_NO,
                                    KC_NO,
                           KC_NO,KC_NO ,KC_NO ,
    RESET  ,DYN_REC_STOP ,DYN_REC_START1 ,DYN_MACRO_PLAY1 ,KC_NO  ,KC_NO, KC_NO, KC_NO, KC_NO,
	KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO,
	KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO,
	KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO,KC_NO,
	KC_NO   ,KC_NO   ,KC_NO,KC_NO ,KC_NO,KC_NO,
		KC_NO  ,KC_NO,KC_NO,KC_NO,
           KC_NO,KC_NO,
           KC_NO,
           KC_NO,KC_NO ,KC_NO
    ),
	
[STENO] = LAYOUT(
           KC_NO, KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO,
           KC_NO, KC_NO  ,KC_NO  ,KC_NO,  KC_NO  ,KC_NO   ,
           KC_NO, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_NO   ,
           KC_NO, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_NO   ,
           KC_NO,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
                   KC_NO ,KC_NO ,KC_NO,KC_NO,
			   KC_NO,KC_NO,
                                    KC_NO,
                           KC_C ,KC_V ,MO(QWERTY) ,
    KC_NO  ,KC_NO ,KC_NO ,KC_NO ,KC_NO  ,KC_NO, KC_NO, MO(QWERTY), KC_NO,
	KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_NO   ,KC_NO   ,KC_NO,KC_NO ,KC_NO,KC_NO,
		KC_NO  ,KC_NO,KC_NO,KC_NO,
           KC_NO,KC_NO,
           KC_NO,
           KC_NO,KC_N  ,KC_M
    )	
	

};



void matrix_init_user(void) {

}


void matrix_scan_user(void) {
	
  

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
