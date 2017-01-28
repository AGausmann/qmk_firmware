// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM 1
#include "rgblight.h"
#endif

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define DEFAULT_MAP 0
#define LOWER_MAP 1
#define RAISE_MAP 2
#define DEFAULT_NUMPAD_MAP 3
#define GAMING_MAP 10
#define GAMING_NUMPAD_MAP 11
#define ADJUST_MAP 20

enum planck_keycodes {
  CK_DFLT = TO(DEFAULT_MAP),
  CK_GAME = TO(GAMING_MAP),
  CK_DNUM = MO(DEFAULT_NUMPAD_MAP),
  CK_GNUM = MO(GAMING_NUMPAD_MAP),
  CK_ADJ = MO(ADJUST_MAP),
  CK_LOW = SAFE_RANGE,
  CK_RAS,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DEFAULT_MAP] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, CK_DNUM, CK_LOW,  KC_SPC,  KC_SPC,  CK_RAS,  XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL}
},

[LOWER_MAP] = {
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[RAISE_MAP] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, _______, _______, _______, _______, _______, KC_BSLS, KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_EQL,  _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[DEFAULT_NUMPAD_MAP] = {
  {_______, _______, _______, _______, _______, _______, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   _______, _______},
  {_______, _______, KC_PAST, KC_PPLS, _______, _______, KC_PDOT, KC_P4,   KC_P5,   KC_P6,   _______, _______},
  {_______, _______, KC_PSLS, KC_PMNS, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[GAMING_MAP] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP  },
  {KC_LCTL, XXXXXXX, KC_LALT, XXXXXXX, CK_GNUM, KC_SPC,  KC_B,    CK_ADJ,  KC_GRV,  KC_LEFT, KC_RGHT, KC_DOWN}
},
[GAMING_NUMPAD_MAP] = {
  {_______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_0,    KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[ADJUST_MAP] = {
  {RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, BL_DEC,  BL_INC,  _______, _______, CK_DFLT, CK_GAME, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_LOW:
      if (record->event.pressed) {
        layer_on(LOWER_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, ADJUST_MAP);
      } else {
        layer_off(LOWER_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, ADJUST_MAP);
      }
      return false;
      break;
    case CK_RAS:
      if (record->event.pressed) {
        layer_on(RAISE_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, ADJUST_MAP);
      } else {
        layer_off(RAISE_MAP);
        update_tri_layer(LOWER_MAP, RAISE_MAP, ADJUST_MAP);
      }
      return false;
      break;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

#ifdef RGBLIGHT_ENABLE
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        r = 255;
    }
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        g = 255;
    }
    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        b = 255;
    }

    rgblight_indicator_setrgb(0, r, g, b);
    rgblight_set();
#endif
}

void matrix_init_user(void) {

}
