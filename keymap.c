#include QMK_KEYBOARD_H
#include "keymap_russian.h"


#define _QWERTY 0
#define _SYMBOL 1
#define _NUM 2
#define _FN 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
  NUM,
  FN,
  REOPEN,
  MAKE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_NO, REOPEN,   KC_NO,    KC_NO,   KC_NO,                               KC_NO,    KC_NO,  KC_NO,    KC_NO,  MAKE,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     MEH_T(
        KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSL(3),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL_T(
        KC_GRV),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG(2),            TG(1),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_RCTL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(
                                        KC_ENT), LT(2,
                                                KC_SPC
                                                ),      LSFT_T(
                                                        KC_CAPS),                KC_SFTENT, LT(1,
                                                                                            KC_SPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
    [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_EXLM,   KC_AT, KC_HASH, KC_DLR, KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_NO,   KC_QUOT, KC_LCBR, KC_RCBR, KC_BSLS,                             KC_NO,  KC_HOME,  KC_UP,  KC_PGUP, KC_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_NO,   KC_DQUO, KC_LBRC, KC_RBRC, KC_SLSH,                             KC_NO,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_COLN,  KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TO(0),   KC_QUES, KC_LPRN, KC_RPRN, KC_PIPE, _______,          _______,KC_PSCR,  KC_END,  KC_NO,  KC_PGDN, KC_UNDS,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  KC_NO  , KC_NO,   KC_NO,    KC_NO,  KC_NO,                              KC_NO,  KC_P7,    KC_P8,    KC_P9, KC_PSLS,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_NO,   KC_LPRN,  KC_UP,  KC_RPRN,  KC_NO,                            KC_NO,   KC_P4,    KC_P5,    KC_P6,  KC_PAST, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,                              KC_NO,   KC_P1,   KC_P2,   KC_P3,  KC_PMNS, KC_PEQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TO(0),   KC_LBRC, KC_NO,    KC_RBRC, KC_NO,  _______,          _______, KC_PSCR,  KC_NO,   KC_P0,   KC_PDOT, KC_PPLS, KC_PCMM,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,  KC_F7,    KC_F8,   KC_F9,  KC_F10,  BL_TOGG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_F11,   KC_F12,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,   KC_NO,   KC_BRIU,   KC_NO,   KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RGB_MOD, RGB_HUI, RGB_SAI,  RGB_VAI,RGB_SPD,                            KC_MUTE, KC_VOLD, KC_BRID, KC_VOLU, KC_MPRV, KC_MNXT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_M_G,  TO(0),   KC_NO,  KC_NO,    KC_NO,   KC_NO, KC_PSCR,          KC_PSCR, KC_PSCR,  KC_NO,   KC_NO,   KC_NO,  KC_MSTP, KC_MPLY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    RESET,   _______, _______,                   KC_LGUI, _______,   KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {  //macros
    switch (keycode) {
        case REOPEN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("t")));
            } 
            break;
        case MAKE:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb keebio/iris/rev6 -km Eva808"SS_TAP(X_ENT));
            }
            break;
    }
    return true;
};

      
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {   //RGB
    if (host_keyboard_led_state().caps_lock) {                                 //caps lock backlight
        rgb_matrix_set_color(26, RGB_CYAN);
    }

    for (uint8_t i = led_min; i <= led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {           //layers backlight
            case _SYMBOL:                                                      //0-27 keys, 28-33 underglow 
            /*  rgb_matrix_set_color(6, 54,204,31); 
                rgb_matrix_set_color(7, 54,204,31);
                rgb_matrix_set_color(8, 54,204,31);
                rgb_matrix_set_color(9, 54,204,31);
                rgb_matrix_set_color(10, 54,204,31);
                rgb_matrix_set_color(13, 54,204,31);
                rgb_matrix_set_color(14, 54,204,31);
                rgb_matrix_set_color(15, 54,204,31);
                rgb_matrix_set_color(16, 54,204,31);
                rgb_matrix_set_color(17, 54,204,31);
                rgb_matrix_set_color(18, 54,204,31);
                rgb_matrix_set_color(19, 54,204,31);
                rgb_matrix_set_color(20, 54,204,31);
                rgb_matrix_set_color(21, 54,204,31);
                rgb_matrix_set_color(22, 54,204,31); */
                rgb_matrix_set_color(28, 54,204,31);
                rgb_matrix_set_color(29, 54,204,31);
                rgb_matrix_set_color(30, 54,204,31);
                rgb_matrix_set_color(31, 54,204,31);
                rgb_matrix_set_color(32, 54,204,31);
                rgb_matrix_set_color(33, 54,204,31);
                break;
            case _NUM: 
             /*   rgb_matrix_set_color(6, 219,76,76);
                rgb_matrix_set_color(7, 219,76,76);
                rgb_matrix_set_color(8, 219,76,76);
                rgb_matrix_set_color(9, 219,76,76);
                rgb_matrix_set_color(10, 219,76,76);
                rgb_matrix_set_color(13, 219,76,76);
                rgb_matrix_set_color(14, 219,76,76);
                rgb_matrix_set_color(15, 219,76,76);
                rgb_matrix_set_color(16, 219,76,76);
                rgb_matrix_set_color(17, 219,76,76);
                rgb_matrix_set_color(18, 219,76,76);
                rgb_matrix_set_color(19, 219,76,76);
                rgb_matrix_set_color(20, 219,76,76);
                rgb_matrix_set_color(21, 219,76,76);
                rgb_matrix_set_color(22, 219,76,76); */
                rgb_matrix_set_color(28, 219,76,76);
                rgb_matrix_set_color(29, 219,76,76);
                rgb_matrix_set_color(30, 219,76,76);
                rgb_matrix_set_color(31, 219,76,76);
                rgb_matrix_set_color(32, 219,76,76);
                rgb_matrix_set_color(33, 219,76,76);
                break;
            default:
                break;
        }
    }
}
