#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "util.h"
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

extern keymap_config_t keymap_config;

#define DEFAULT_LAYER 0
#define LOWER_LAYER 1
#define RAISE_LAYER 2
#define MIDI_LAYER 4
#define GAMING_LAYER 8
#define GAMING_NUMPAD_LAYER 9
#define SETUP_LAYER 12
#define NUMPAD_LAYER 13

enum custom_keycodes {
  CK_BACK = TO(DEFAULT_LAYER),
  CK_LOW = MO(LOWER_LAYER),
  CK_RAS = MO(RAISE_LAYER),
  CK_MIDI = TG(MIDI_LAYER),
  CK_GAME = TG(GAMING_LAYER),
  CK_GNUM = OSL(GAMING_NUMPAD_LAYER),
  CK_SET = OSL(SETUP_LAYER),
  CK_NUM = TG(NUMPAD_LAYER),
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[DEFAULT_LAYER] = KEYMAP( \
  CK_BACK, _______, CK_MIDI, CK_GAME, CK_SET,  _______, _______, CK_NUM, _______, _______, _______, _______, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_CLCK, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, _______, CK_LOW,  KC_ENT,  KC_SPC,  CK_RAS,  _______, KC_RALT, KC_RGUI, KC_RCTL  \
),

[LOWER_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PAUS, KC_PSCR, KC_SLCK, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[RAISE_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[MIDI_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
 MI_ALLOFF,MI_Gs,   MI_A,    MI_As,   MI_B,    MI_OCTU, _______, _______, _______, _______, _______, _______, \
  _______, MI_E,    MI_F,    MI_Fs,   MI_G,    MI_TRNSU,_______, _______, _______, _______, _______, _______, \
  _______, MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_TRNSD,_______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, MI_SUS,  MI_OCTD, _______, _______, _______, _______, _______, _______  \
),

[GAMING_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,  \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   \
  KC_LCTL, XXXXXXX, KC_LALT, CK_GNUM, KC_BSLS, KC_SPC,  KC_SPC,  XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT, KC_DOWN  \
),

[GAMING_NUMPAD_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[SETUP_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[NUMPAD_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______, \
  _______, _______, _______, _______, _______, _______, KC_NLCK, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PEQL, \
  _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PENT, \
  _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS, _______ \
),

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {


  rgblight_enable();
}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
      case DEFAULT_LAYER:
        rgblight_setrgb(0x00, 0x00, 0xFF);
        break;
      case NUMPAD_LAYER:
        rgblight_setrgb(0x00, 0xA0, 0xFF);
        break;
      case MIDI_LAYER:
        rgblight_setrgb(0xFF, 0x00, 0x00);
        break;
      case GAMING_LAYER:
        rgblight_setrgb(0xFF, 0x20, 0x00);
        break;
      case SETUP_LAYER:
        rgblight_setrgb(0xFF, 0x00, 0xFF);
        break;
    }

    old_layer = new_layer;
  }

  #endif //RGBLIGHT_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
