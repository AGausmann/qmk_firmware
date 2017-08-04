#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

extern keymap_config_t keymap_config;

#define DEFAULT_LAYER 0
#define LOWER_LAYER 3
#define RAISE_LAYER 4
#define SETUP_LAYER 16

enum custom_keycodes {
  CK_LOW = SAFE_RANGE,
  CK_RAS,
  CK_SET,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  |      |Lower |Space |Space |Raise |      | Alt  |Super | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[DEFAULT_LAYER] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
  KC_CLCK, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, _______, CK_LOW,  KC_SPC,  KC_SPC,  CK_RAS,  _______, KC_RALT, KC_RGUI, KC_RCTL  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      | Ins  | Home |  Up  | End  | PgUp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | Del  | Left | Down |Right | PgDn |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |Pause |PrtSc |ScrLk |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER_LAYER] = KEYMAP( \
  KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PAUS, KC_PSCR, KC_SLCK, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   *  |   =  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |NumLk |   -  |   =  |   [  |   ]  |   \  |      |   1  |   2  |   3  |   -  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   ,  |  .   |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, \
  KC_NLCK, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PENT, \
  _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PCMM, KC_PDOT, KC_PPLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Setup (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | BLUp |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | BLDn |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SETUP_LAYER] =  KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, BL_INC,  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, BL_DEC,  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

uint8_t topmost_layer_get(void) {
  for (int i = 0; i < 32; i++) {
    if (layer_state >> i == 1) {
      return i;
    }
  }

  return 0;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 0;
  uint8_t new_layer = topmost_layer_get();

  if (old_layer != new_layer) {
    switch (new_layer) {
      case DEFAULT_LAYER:
        rgblight_setrgb(0x00, 0x00, 0xFF);
        break;
      case LOWER_LAYER:
        rgblight_setrgb(0x7F, 0x00, 0xFF);
        break;
      case RAISE_LAYER:
        rgblight_setrgb(0x00, 0x7F, 0xFF);
        break;
      case SETUP_LAYER:
        rgblight_setrgb(0xFF, 0x00, 0xFF);
        break;
    }
  }

  old_layer = new_layer;

  #endif //RGBLIGHT_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_LOW:
      if (record->event.pressed) {
        layer_on(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, SETUP_LAYER);
      } else {
        layer_off(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, SETUP_LAYER);
      }
      return false;
      break;
    case CK_RAS:
      if (record->event.pressed) {
        layer_on(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, SETUP_LAYER);
      } else {
        layer_off(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, SETUP_LAYER);
      }
      return false;
      break;
    case CK_SET:
      if (record->event.pressed) {
        layer_on(SETUP_LAYER);
      } else {
        layer_off(SETUP_LAYER);
      }
      return false;
      break;
  }
  return true;
}
