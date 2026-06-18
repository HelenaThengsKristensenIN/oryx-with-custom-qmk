#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_B,           KC_L,           KC_G,           KC_W,           KC_Z,                                           NRW_QUOT,       KC_F,           KC_O,           KC_U,           KC_J,           KC_TRANSPARENT, 
    KC_COMMA,       KC_N,           KC_R,           KC_T,           KC_S,           KC_V,                                           KC_Y,           KC_D,           KC_A,           KC_E,           KC_I,           KC_DOT,         
    KC_TRANSPARENT, KC_Q,           KC_X,           KC_M,           KC_C,           KC_TRANSPARENT,                                 KC_K,           KC_P,           NRW_ARNG,       NRW_OSTR,       NRW_AE,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_RIGHT,       MT(MOD_LGUI, KC_TAB),                                MT(MOD_LALT, KC_DELETE),KC_DOWN,        KC_UP,          MT(MOD_LGUI, KC_ESCAPE),KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    MT(MOD_LSFT, KC_SPACE),MT(MOD_LCTL, KC_ENTER),                                MT(MOD_LCTL, KC_H),KC_BSPC
  ),
};









bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
