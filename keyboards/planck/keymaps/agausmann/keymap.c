#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  DEFAULT_MAP,
  LOWER_MAP,
  RAISE_MAP,
  NUMPAD_MAP,
  GAMING_MAP,
  NUMBER_MAP,
  PLOVER_MAP,
  SETUP_MAP
};

enum planck_keycodes {
  CK_NUM = MO(NUMBER_MAP),
  CK_DFLT = TO(DEFAULT_MAP),
  CK_GAME = TO(GAMING_MAP),
  CK_PLV = TO(PLOVER_MAP),
  CK_RSE = SFT_T(KC_ENTER),
  CK_RCR = CTL_T(KC_RIGHT),
  CK_RGU = GUI_T(KC_UP),
  CK_RAD = ALT_T(KC_DOWN),
  CK_NPL = LT(NUMPAD_MAP, KC_LEFT),
  CK_SET = MO(SETUP_MAP),
  CK_LOW = SAFE_RANGE,
  CK_RAS
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DEFAULT_MAP] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_CLCK, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, CK_RSE },
  {KC_LCTL, KC_LGUI, KC_LALT, _______, CK_LOW,  KC_SPC,  KC_SPC,  CK_RAS,  CK_NPL,  CK_RAD,  CK_RGU,  CK_RCR }
},

[LOWER_MAP] = {
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PAUS, KC_PSCR, KC_SLCK, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[RAISE_MAP] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[NUMPAD_MAP] = {
  {KC_NLCK, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_PCMM, KC_P4,   KC_P5,   KC_P6,   KC_P0  },
  {_______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_P1,   KC_P2,   KC_P3,   _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[GAMING_MAP] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TILD},
  {KC_LCTL, XXXXXXX, KC_LALT, CK_SET,  CK_NUM,  KC_SPC,  KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[NUMBER_MAP] = {
  {_______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[PLOVER_MAP] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {CK_SET,  XXXXXXX, XXXXXXX, XXXXXXX, KC_C,    KC_V,    KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[SETUP_MAP] = {
  {RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, BL_INC,  _______, _______, CK_DFLT, CK_GAME, CK_PLV,  _______, _______},
  {_______, _______, _______, _______, BL_DEC,  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

void persistent_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_GAME:
      if (record->event.pressed) {
        backlight_set(2);
      }
      break;
    case CK_DFLT:
      if (record->event.pressed) {
        backlight_set(0);
      }
      break;
    case CK_LOW:
      if (record->event.pressed) {
        layer_on(LOWER_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, SETUP_MAP);
      } else {
        layer_off(LOWER_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, SETUP_MAP);
      }
      return false;
      break;
    case CK_RAS:
      if (record->event.pressed) {
        layer_on(RAISE_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, SETUP_MAP);
      } else {
        layer_off(RAISE_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, SETUP_MAP);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {

}
