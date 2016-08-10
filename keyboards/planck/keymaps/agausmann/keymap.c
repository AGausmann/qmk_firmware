/* Custom keymap with gaming layer.
 * Modified by Adam Gausmann (original file: /keyboards/planck/keymaps/default/keymap.c)
 */

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _MAIN 0
#define _LOWER 1
#define _RAISE 2
#define _GAMING 3
#define _NUMBER 4
#define _SETUP 16

enum planck_keycodes {
  MAIN = SAFE_RANGE,
  GAMING,
  LOWER,
  RAISE,
  NUMBER,
  SETUP,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Main (Qwerty)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  |      |Lower |Space |Space |Raise |      | Alt  |Super | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_MAIN] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, KC_RALT, KC_RGUI, KC_RCTL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |      | PgUp | Home |  Up  | End  | Ins  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F5  |  F6  |  F7  |  F8  |      | PgDn | Left | Down |Right | Del  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |  F9  | F10  | F11  | F12  |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  |      | Lower |Space |Space |Raise |      | Alt  |Super | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_BSPC},
  {KC_TAB,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_PGDN, KC_UNDS, KC_DOWN, KC_RGHT, KC_DEL,  KC_ENT },
  {KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER,    KC_SPC,  KC_SPC,  RAISE,   _______, KC_RALT, KC_RGUI, KC_RCTL}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |      |  `   |  -   |  =   |  '   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |      |      |  [   |  ]   |  \   |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  |      |Lower |Space |Space | Raise |      | Alt  |Super | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  _______, _______, _______, _______, _______, _______, KC_GRV,  KC_MINS, KC_EQL,  KC_QUOT, KC_ENT },
  {KC_LSFT, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, KC_RALT, KC_RGUI, KC_RCTL}
},

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |Setup |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  `   |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |   L  |  ;   |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  |      |Number|Space |  \   |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SETUP  },
  {KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, _______, KC_LALT, _______, NUMBER,  KC_SPC,  KC_BSLS, _______, _______, _______, _______, _______}
},

/* Number (only on Gaming layer)
 * ,-----------------------------------------------------------------------------------.
 * |      |  0   |  1   |  2   |  3   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  7   |  8   |  9   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Number|      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = {
  {_______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, NUMBER,  _______, _______, _______, _______, _______, _______, _______}
},

/* Setup (Lower+Raise on most layouts)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Main |Gaming|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | BLDe | BLIn |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SETUP] = {
  {RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, MAIN,    GAMING,  _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,  _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAIN:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_MAIN);
      }
      return false;

    case GAMING:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_GAMING);
      }
      return false;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      update_tri_layer(_LOWER, _RAISE, _SETUP);
      return false;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      update_tri_layer(_LOWER, _RAISE, _SETUP);
      return false;

    case NUMBER:
      if (record->event.pressed) {
        layer_on(_NUMBER);
      } else {
        layer_off(_NUMBER);
      }
      return false;

    case SETUP:
      if (record->event.pressed) {
        layer_on(_SETUP);
      }
      return false;

    case BL_INC:
      if (record->event.pressed) {
        backlight_increase();
      }
      return false;

    case BL_DEC:
      if (record->event.pressed) {
        backlight_decrease();
      }
      return false;
  }
  return true;
}
