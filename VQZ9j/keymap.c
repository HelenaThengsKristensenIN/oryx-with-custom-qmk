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


// Tracks what was registered per dual-func, so we can release it cleanly
static uint16_t df_held[24] = {0};

// Handles a DUAL_FUNC numpad key: tap=letter, hold=symbol, shift+hold=digit
static void handle_shifted_df(keyrecord_t *record, uint8_t idx,
                             uint16_t tap_kc, uint16_t hold_kc, uint16_t digit_kc) {
  if (record->tap.count > 0) {
    // Tap path — unchanged behavior
    if (record->event.pressed) {
      register_code16(tap_kc);
      df_held[idx] = tap_kc;
    } else {
      unregister_code16(df_held[idx]);
      df_held[idx] = 0;
    }
  } else {
    // Hold path — check if Shift is active
    if (record->event.pressed) {
      uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
      if (shift_mods) {
        // Temporarily drop Shift, send digit, restore Shift
        unregister_mods(shift_mods);
        send_keyboard_report();
        register_code16(digit_kc);
        df_held[idx] = digit_kc;
        register_mods(shift_mods);
      } else {
        register_code16(hold_kc);
        df_held[idx] = hold_kc;
      }
    } else {
      if (df_held[idx]) {
        unregister_code16(df_held[idx]);
        df_held[idx] = 0;
      }
    }
  }
}

#define DUAL_FUNC_0 LT(4, KC_4)
#define DUAL_FUNC_1 LT(11, KC_0)
#define DUAL_FUNC_2 LT(3, KC_F19)
#define DUAL_FUNC_3 LT(11, KC_K)
#define DUAL_FUNC_4 LT(2, KC_U)
#define DUAL_FUNC_5 LT(12, KC_5)
#define DUAL_FUNC_6 LT(10, KC_F17)
#define DUAL_FUNC_7 LT(8, KC_6)
#define DUAL_FUNC_8 LT(1, KC_F20)
#define DUAL_FUNC_9 LT(10, KC_6)
#define DUAL_FUNC_10 LT(5, KC_F9)
#define DUAL_FUNC_11 LT(7, KC_X)
#define DUAL_FUNC_12 LT(1, KC_F16)
#define DUAL_FUNC_13 LT(7, KC_F11)
#define DUAL_FUNC_14 LT(4, KC_F1)
#define DUAL_FUNC_15 LT(2, KC_P)
#define DUAL_FUNC_16 LT(15, KC_F24)
#define DUAL_FUNC_17 LT(1, KC_S)
#define DUAL_FUNC_18 LT(8, KC_F17)
#define DUAL_FUNC_19 LT(3, KC_F15)
#define DUAL_FUNC_20 LT(7, KC_R)
#define DUAL_FUNC_21 LT(3, KC_T)
#define DUAL_FUNC_22 LT(7, KC_6)
#define DUAL_FUNC_23 LT(1, KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_B,           DUAL_FUNC_0,    DUAL_FUNC_1,    DUAL_FUNC_2,    KC_Z,                                           NRW_QUOT,       DUAL_FUNC_12,   DUAL_FUNC_13,   DUAL_FUNC_14,   KC_J,           KC_TRANSPARENT, 
    KC_COMMA,       DUAL_FUNC_3,    DUAL_FUNC_4,    DUAL_FUNC_5,    DUAL_FUNC_6,    DUAL_FUNC_7,                                    DUAL_FUNC_15,   DUAL_FUNC_16,   DUAL_FUNC_17,   DUAL_FUNC_18,   DUAL_FUNC_19,   KC_DOT,         
    KC_TRANSPARENT, KC_Q,           DUAL_FUNC_8,    DUAL_FUNC_9,    DUAL_FUNC_10,   DUAL_FUNC_11,                                   DUAL_FUNC_20,   DUAL_FUNC_21,   DUAL_FUNC_22,   DUAL_FUNC_23,   NRW_AE,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LGUI, KC_MS_BTN3),KC_UP,          KC_DOWN,        MT(MOD_LALT, KC_ESCAPE),                                MT(MOD_LALT, KC_DELETE),KC_LEFT,        KC_RIGHT,       MO(1),          KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    MT(MOD_LSFT, KC_SPACE),MT(MOD_LCTL, KC_ENTER),                                MT(MOD_LCTL, KC_H),KC_BSPC
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F10,         KC_F11,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_0,           KC_4,           KC_5,           KC_6,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F2,          KC_F7,          KC_F9,          KC_F12,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT,                                 KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};





extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {0,0,0}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {32,255,255}, {0,0,0}, {0,0,0}, {0,249,255}, {32,255,255}, {32,255,255}, {80,218,204}, {80,218,204}, {80,218,204}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {0,0,0}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {139,205,228}, {0,0,0}, {80,218,204}, {32,255,255}, {32,255,255}, {201,218,204}, {0,0,0}, {0,0,0}, {139,205,228}, {80,218,204} },

    [1] = { {0,0,0}, {0,0,0}, {165,255,225}, {165,255,225}, {165,255,225}, {0,0,0}, {0,0,0}, {165,255,225}, {165,255,225}, {165,255,225}, {165,255,225}, {0,0,0}, {0,0,0}, {0,0,0}, {165,255,225}, {165,255,225}, {165,255,225}, {0,0,0}, {0,0,0}, {0,0,0}, {201,218,204}, {201,218,204}, {201,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {165,255,225}, {165,255,225}, {0,0,0}, {0,0,0}, {0,0,0}, {165,255,225}, {165,255,225}, {165,255,225}, {165,255,225}, {0,0,0}, {165,255,225}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    
    case DUAL_FUNC_0:  handle_shifted_df(record, 0,  KC_L, NRW_LABK, KC_7); return false;
    case DUAL_FUNC_1:  handle_shifted_df(record, 1,  KC_G, NRW_RABK, KC_8); return false;
    case DUAL_FUNC_2:  handle_shifted_df(record, 2,  KC_W, NRW_SLSH, KC_9); return false;
    case DUAL_FUNC_3:  handle_shifted_df(record, 3,  KC_N, NRW_MINS, KC_0); return false;
    case DUAL_FUNC_4:  handle_shifted_df(record, 4,  KC_R, NRW_LPRN, KC_4); return false;
    case DUAL_FUNC_5:  handle_shifted_df(record, 5,  KC_T, NRW_RPRN, KC_5); return false;
    case DUAL_FUNC_6:  handle_shifted_df(record, 6,  KC_S, NRW_EQL,  KC_6); return false; 
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_V);
        } else {
          unregister_code16(KC_V);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_QUES);
        } else {
          unregister_code16(NRW_QUES);
        }  
      }  
      return false;
    
case DUAL_FUNC_8:  handle_shifted_df(record, 8,  KC_X, NRW_PERC, KC_1); return false;
case DUAL_FUNC_9:  handle_shifted_df(record, 9,  KC_M, NRW_UNDS, KC_2); return false;
case DUAL_FUNC_10: handle_shifted_df(record, 10, KC_C, NRW_HASH, KC_3); return false;

    case DUAL_FUNC_11:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_TAB);
        } else {
          unregister_code16(KC_TAB);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_F5);
        } else {
          unregister_code16(KC_F5);
        }  
      }  
      return false;
    case DUAL_FUNC_12: handle_shifted_df(record, 12, KC_F, NRW_EXLM, KC_F10); return false;
    case DUAL_FUNC_13: handle_shifted_df(record, 13, KC_O, NRW_LBRC, KC_F11); return false; 
    case DUAL_FUNC_14:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_U);
        } else {
          unregister_code16(KC_U);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_RBRC);
        } else {
          unregister_code16(NRW_RBRC);
        }  
      }  
      return false;
    case DUAL_FUNC_15:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_Y);
        } else {
          unregister_code16(KC_Y);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_AMPR);
        } else {
          unregister_code16(NRW_AMPR);
        }  
      }  
      return false;
    case DUAL_FUNC_16: handle_shifted_df(record, 16, KC_D, NRW_DQUO, KC_F2);  return false;
    case DUAL_FUNC_17: handle_shifted_df(record, 17, KC_A, NRW_LCBR, KC_F7);  return false;
    case DUAL_FUNC_18: handle_shifted_df(record, 18, KC_E, NRW_RCBR, KC_F9);  return false;
    case DUAL_FUNC_19: handle_shifted_df(record, 19, KC_I, NRW_PLUS, KC_F12); return false;
    case DUAL_FUNC_20: handle_shifted_df(record, 20, KC_K, NRW_DLR,  KC_F4);  return false; 
    case DUAL_FUNC_21:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_P);
        } else {
          unregister_code16(KC_P);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_PIPE);
        } else {
          unregister_code16(NRW_PIPE);
        }  
      }  
      return false;
    case DUAL_FUNC_22:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(NRW_ARNG);
        } else {
          unregister_code16(NRW_ARNG);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_BSLS);
        } else {
          unregister_code16(NRW_BSLS);
        }  
      }  
      return false;
    case DUAL_FUNC_23:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(NRW_OSTR);
        } else {
          unregister_code16(NRW_OSTR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_AT);
        } else {
          unregister_code16(NRW_AT);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
    const key_override_t override_to_7 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_LABK, KC_7); 
    const key_override_t override_to_8 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_RABK, KC_8); 
    const key_override_t override_to_9 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_SLSH, KC_9); 
    const key_override_t override_to_4 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_LPRN, KC_4); 
    const key_override_t override_to_5 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_RPRN, KC_5); 
    const key_override_t override_to_6 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_EQL, KC_6);
    const key_override_t override_to_1 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_PERC, KC_1);
    const key_override_t override_to_2 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_UNDS, KC_2);
    const key_override_t override_to_3 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_HASH, KC_3);
    const key_override_t override_to_0 =
        ko_make_basic(MOD_MASK_SHIFT, NRW_MINS, KC_0);    

    const key_override_t *key_overrides[] = {
        &override_to_7,
        &override_to_8,
        &override_to_9,
        &override_to_4,
        &override_to_5,
        &override_to_6,
        &override_to_1,
        &override_to_2,
        &override_to_3,
        &override_to_0,
        NULL  // Null-terminated list
    };