#include QMK_KEYBOARD_H
#include "quantum\keymap_extras\keymap_russian.h"
bool russian = false;


#define _COLEMAK 0
#define _QWERTY 1
#define _RU 2
#define _SYMBOL 3
#define _SYMBOL_RU 4
#define _NUM 5
#define _FN 6


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK = SAFE_RANGE,
  RU = SAFE_RANGE,
  SYMBOL,
  SYMBOL_RU,
  NUM,
  FN,
  CLIPBOARD,  
  MAKE,    
  LANG,    //switch the language by LANG button only, NOT by holding key combinations!!! Changes base layout
  PASS,
  TO_COLEMAK,
  TO_QWERTY
};

uint8_t colourDefault[] = {204, 107, 4};   //default underglow colour
//uint8_t colourDefault[] = {176,95,33};
uint8_t colourSymbol[] = {219, 76, 76};    //symbol layer underglow colour
uint8_t colourNum[] = {54, 204, 31};       //numpad layer underglow colour

int underglowLED[6] = {28, 29, 30, 31, 32, 33};
int backlightLEDinner[15] = {6, 7, 8, 9, 10, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
int backlightLEDall[27] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_NO,   CLIPBOARD,PASS,    KC_NO,   KC_F5,                               MAKE,  LANG, TO_COLEMAK,TO_QWERTY,  KC_NO,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     MEH_T(
        KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSL(_FN), LGUI_T(
                KC_A), LALT_T(
                        KC_S),  LSFT_T(
                                KC_D),  LCTL_T(KC_F),    KC_G,                        KC_H,    RCTL_T(
                                                                                                KC_J), RSFT_T(
                                                                                                        KC_K),  RALT_T(
                                                                                                                 KC_L),   RGUI_T(
                                                                                                                          KC_SCLN), KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL_T(
        KC_GRV),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG(_NUM),            TG(
                                                                             _SYMBOL),KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, RCTL_T(KC_GRV),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(
                                        KC_ENT), LT(
                                                _NUM,
                                                KC_SPC), LSFT_T(
                                                        KC_CAPS),               KC_SFTENT, LT(
                                                                                            _SYMBOL,
                                                                                            KC_SPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_NO,   CLIPBOARD,PASS,    KC_NO,   KC_F5,                               MAKE,  LANG,TO_COLEMAK,TO_QWERTY,  KC_NO,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     MEH_T(
        KC_TAB), KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,  KC_SCLN,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSL(_FN), LGUI_T(
                KC_A), LALT_T(
                        KC_R),  LSFT_T(
                                KC_S),  LCTL_T(KC_T),    KC_G,                        KC_M,    RCTL_T(
                                                                                                KC_N), RSFT_T(
                                                                                                        KC_E),  RALT_T(
                                                                                                                 KC_I),   RGUI_T(
                                                                                                                          KC_O), KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL_T(
        KC_GRV),KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    TG(_NUM),            TG(
                                                                             _SYMBOL),KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, RCTL_T(KC_GRV),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(
                                        KC_CAPS), LT(
                                                _NUM,
                                                KC_SPC), LSFT_T(
                                                        KC_ENT),               KC_SFTENT, LT(
                                                                                            _SYMBOL,
                                                                                            KC_SPC), KC_RALT 
),

[_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_NO,   CLIPBOARD,PASS,   KC_DLR,  KC_F5,                             KC_CIRC,   LANG,  KC_NO,   KC_NO,    KC_NO, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_DQUO, KC_LPRN, KC_RPRN, KC_BSLS,                            KC_PERC,  KC_HOME,  KC_UP,  KC_END,  KC_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, 
                KC_AT,   
                       LALT_T(
                       KC_QUOT), LSFT_T(
                                KC_LBRC), LCTL_T(
                                         KC_RBRC), KC_SLSH,                           KC_AMPR,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_COLN,  KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TO(0),   KC_HASH, 
                       KC_QUES, KC_LCBR, KC_RCBR, KC_PIPE, _______,          _______,KC_ASTR,  KC_PLUS, KC_PDOT, KC_MINS,  KC_UNDS,  KC_RCTL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, KC_PSCR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RU] = LAYOUT(  //Ёё и Ъъ в _FN слое на месте Eе и Ьь, точка на правом CTRL
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_NO,   CLIPBOARD,PASS,    KC_NO,   KC_F5,                               MAKE,    LANG,TO_COLEMAK,TO_QWERTY,KC_NO, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     MEH_T(
        KC_TAB),RU_SHTI,RU_TSE,    RU_U,  RU_KA,   RU_IE,                              RU_EN,  RU_GHE,  RU_SHA,  RU_SHCH,   RU_ZE,  RU_HA,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSL(_FN), LGUI_T(
                RU_EF), LALT_T(
                        RU_YERU),LSFT_T(
                                  RU_VE),LCTL_T(
                                         RU_A),  RU_PE,                               RU_ER,   RCTL_T(
                                                                                                RU_O),  RSFT_T(
                                                                                                         RU_EL), RALT_T(
                                                                                                                  RU_DE), RGUI_T(
                                                                                                                           RU_ZHE),  RU_E,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL_T(
    KC_GRV),  RU_YA, RU_CHE,   RU_ES,  RU_EM,    RU_I,    TG(_NUM),         TG(
                                                                            _SYMBOL_RU), RU_TE, RU_SOFT, RU_BE,  RU_YU,  RU_COMM,  RCTL_T(
                                                                                                                                    RU_DOT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(
                                        KC_CAPS), LT(
                                                _NUM,
                                                KC_SPC),LSFT_T(
                                                        KC_ENT),             KC_SFTENT, LT(
                                                                                        _SYMBOL_RU,
                                                                                           KC_SPC), KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    [_SYMBOL_RU] = LAYOUT(  //в русской раскладке нет многих символов вроде квадратных скобок, поэтому вместо них пусто
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, RU_RUBL, CLIPBOARD, PASS,  KC_NO,    KC_F5,                             KC_NO,    LANG,   RU_ASTR, RU_MINS, RU_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, RU_DQUO, RU_LPRN, RU_RPRN, KC_BSLS,                             RU_PERC,KC_HOME,  KC_UP,  KC_END,  RU_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LGUI,   
                       KC_LALT, KC_LSFT, KC_LCTL, RU_SLSH,                             KC_NO,  KC_LEFT, KC_DOWN, KC_RIGHT,RU_COLN,  RU_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TO(0),   RU_NUM,   RU_QUES, KC_NO,   KC_NO,   KC_NO,   _______,          _______,RU_ASTR,  RU_PLUS, RU_DOT, RU_MINS, RU_UNDS, KC_RCTL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, KC_PSCR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  KC_1  , KC_2,      KC_3,    KC_4,   KC_5,                               KC_6,   KC_7,     KC_8,    KC_9,   KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_NO,   KC_HOME,  KC_UP,  KC_END,  KC_NO,                              KC_PDOT, KC_P7,    KC_P8,   KC_P9,  KC_EQL, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,                              KC_COMM,RCTL_T(
                                                                                                KC_P4), RSFT_T(
                                                                                                        KC_P5),  RALT_T(
                                                                                                                 KC_P6),   KC_PSLS, KC_PMNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TO(0),   KC_NO,   KC_LBRC, KC_NO,    KC_RBRC, KC_NO,  _______,          _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PAST, RCTL_T(
                                                                                                                                   KC_PPLS),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_PSCR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


    [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,  KC_F7,    KC_F8,   KC_F9,  KC_F10,  BL_TOGG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  KC_F11,   KC_F12,  KC_NO,  KC_NO,  RU_YO,                              KC_NO,   KC_NO,   KC_BRIU,   KC_NO,   KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RGB_MOD, RGB_HUI, RGB_SAI,  RGB_VAI,RGB_SPD,                            KC_MUTE, KC_VOLD, KC_BRID, KC_VOLU, KC_MPRV, KC_MNXT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TO(0),  RGB_M_G,   KC_NO,  KC_NO,    KC_NO,   KC_NO, KC_PSCR,          KC_PSCR, KC_PSCR,  RU_HARD,  KC_NO,   KC_NO,  KC_MSTP, KC_MPLY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    RESET,   KC_NUM,  _______,                   KC_LGUI, _______,   KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {  //macros examples
    switch (keycode) {
        case CLIPBOARD:  //windows clipboard
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("v"));
            } 
            break;
        case MAKE:  //qmk build
            if (record->event.pressed) { 
                if (!russian) {
                    SEND_STRING("qmk compile -kb keebio/iris/rev6 -km Eva808\n");
                } else {
                    SEND_STRING(SS_LALT(SS_LSFT()));
                    SEND_STRING("qmk compile -kb keebio/iris/rev6 -km Eva808\n");
                    SEND_STRING(SS_LALT(SS_LSFT()));
                }
            }
            break;
        case LANG:  //switch language
            if (record->event.pressed) {
                if (!russian) {
                    russian = true;
                    set_single_persistent_default_layer(_RU);
                    SEND_STRING(SS_LALT(SS_LSFT()));
                } else {
                    russian = false;
                    set_single_persistent_default_layer(_COLEMAK);
                    SEND_STRING(SS_LALT(SS_LSFT()));
                }
            }
            break;
        case TO_COLEMAK:
            if (record->event.pressed) {
                if (russian) {
                    russian = false;
                    SEND_STRING(SS_LALT(SS_LSFT()));
                    set_single_persistent_default_layer(_COLEMAK);
                } else {
                    set_single_persistent_default_layer(_COLEMAK);
                }
            }
            break;
        case TO_QWERTY:
            if (record->event.pressed) {
                if (russian) {
                    russian = false;
                    SEND_STRING(SS_LALT(SS_LSFT()));
                    set_single_persistent_default_layer(_QWERTY);
                } else {
                    set_single_persistent_default_layer(_QWERTY);
                }
            }
            break;
        case PASS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LALT("z")));
            } 
            break;
    }
    return true;
};


void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {   //RGB
    if (host_keyboard_led_state().caps_lock) {                                 //caps lock backlight
        rgb_matrix_set_color(24, RGB_CYAN);
    }

    for (uint8_t i = led_min; i <= led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {           //layers backlight
            case _NUM:
                /*for (int j = 0; j < 15; ++j) {
                    rgb_matrix_set_color(backlightLEDall[j], colourNum[0], colourNum[1], colourNum[2]);
                }*/
                for (int j = 0; j < 6; ++j) {
                    rgb_matrix_set_color(underglowLED[j], colourNum[0], colourNum[1], colourNum[2]);
                }
                break;
            case _SYMBOL:
                for (int j = 0; j < 6; ++j) {
                    rgb_matrix_set_color(underglowLED[j], colourSymbol[0], colourSymbol[1], colourSymbol[2]);
                }
                break;
            case _SYMBOL_RU: 
                for (int j = 0; j < 6; ++j) {
                    rgb_matrix_set_color(underglowLED[j], colourSymbol[0], colourSymbol[1], colourSymbol[2]);
                }
                break;
            default:
                for (int j = 0; j < 6; ++j) {
                    rgb_matrix_set_color(underglowLED[j], colourDefault[0], colourDefault[1], colourDefault[2]);
                }
                break;
        }
    }
}
