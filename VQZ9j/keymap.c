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

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_L);
        } else {
          unregister_code16(KC_L);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_LABK);
        } else {
          unregister_code16(NRW_LABK);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_G);
        } else {
          unregister_code16(KC_G);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_RABK);
        } else {
          unregister_code16(NRW_RABK);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_W);
        } else {
          unregister_code16(KC_W);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_SLSH);
        } else {
          unregister_code16(NRW_SLSH);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_N);
        } else {
          unregister_code16(KC_N);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_MINS);
        } else {
          unregister_code16(NRW_MINS);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_R);
        } else {
          unregister_code16(KC_R);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_LPRN);
        } else {
          unregister_code16(NRW_LPRN);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_T);
        } else {
          unregister_code16(KC_T);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_RPRN);
        } else {
          unregister_code16(NRW_RPRN);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_S);
        } else {
          unregister_code16(KC_S);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_EQL);
        } else {
          unregister_code16(NRW_EQL);
        }  
      }  
      return false;
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
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_X);
        } else {
          unregister_code16(KC_X);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_PERC);
        } else {
          unregister_code16(NRW_PERC);
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_M);
        } else {
          unregister_code16(KC_M);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_UNDS);
        } else {
          unregister_code16(NRW_UNDS);
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_C);
        } else {
          unregister_code16(KC_C);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_HASH);
        } else {
          unregister_code16(NRW_HASH);
        }  
      }  
      return false;
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
    case DUAL_FUNC_12:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_F);
        } else {
          unregister_code16(KC_F);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_EXLM);
        } else {
          unregister_code16(NRW_EXLM);
        }  
      }  
      return false;
    case DUAL_FUNC_13:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_O);
        } else {
          unregister_code16(KC_O);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_LBRC);
        } else {
          unregister_code16(NRW_LBRC);
        }  
      }  
      return false;
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
    case DUAL_FUNC_16:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_D);
        } else {
          unregister_code16(KC_D);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_DQUO);
        } else {
          unregister_code16(NRW_DQUO);
        }  
      }  
      return false;
    case DUAL_FUNC_17:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_A);
        } else {
          unregister_code16(KC_A);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_LCBR);
        } else {
          unregister_code16(NRW_LCBR);
        }  
      }  
      return false;
    case DUAL_FUNC_18:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_E);
        } else {
          unregister_code16(KC_E);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_RCBR);
        } else {
          unregister_code16(NRW_RCBR);
        }  
      }  
      return false;
    case DUAL_FUNC_19:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_I);
        } else {
          unregister_code16(KC_I);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_PLUS);
        } else {
          unregister_code16(NRW_PLUS);
        }  
      }  
      return false;
    case DUAL_FUNC_20:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_K);
        } else {
          unregister_code16(KC_K);
        }
      } else {
        if (record->event.pressed) {
          register_code16(NRW_DLR);
        } else {
          unregister_code16(NRW_DLR);
        }  
      }  
      return false;
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
