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
  FUNCTION_MAP,
  GAMING_MAP,
  NUMBER_MAP,
  SETUP_MAP
};

enum planck_keycodes {
  CK_FN = MO(FUNCTION_MAP),
  CK_NUM = MO(NUMBER_MAP),
  CK_DFLT = TO(DEFAULT_MAP),
  CK_GAME = TO(GAMING_MAP),
  CK_LOW = SAFE_RANGE,
  CK_RAS
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  | Game |Lower |    Space    |Raise | Func | Alt  |Super | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[DEFAULT_MAP] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_CLCK, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, CK_GAME, CK_LOW,  KC_SPC,  KC_SPC,  CK_RAS,  CK_FN,   KC_RALT, KC_RGUI, KC_RCTL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      | Ins  | Home |  Up  | End  | PgUp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Del  | Left | Down |Right | PgDn |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Pause |PrtSc |ScrLk |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER_MAP] = {
  {KC_ESC,  _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______},
  {_______, _______, _______, _______, _______, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_PSCR, KC_SLCK, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   -  |   =  |   [  |   ]  |   \  |      |   4  |   5  |   6  |   '  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE_MAP] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_4,    KC_5,    KC_6,    KC_QUOT, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_DOT,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | Mute |VolUp |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |VolDn |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[FUNCTION_MAP] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_MUTE, KC_VOLU, _______, _______, _______, _______},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_VOLD, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  | Home |  Up  | End  | PgUp | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  | Left | Down |Right | PgDn |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  |Defalt| Num  |Space |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[GAMING_MAP] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TILD},
  {KC_LCTL, XXXXXXX, KC_LALT, CK_DFLT, CK_NUM,  KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Gaming numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  1   |  2   |  3   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  7   |  8   |  9   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NUMBER_MAP] = {
  {_______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Setup (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |BLInc |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |BLDec |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SETUP_MAP] = {
  {RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, BL_INC,  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, BL_DEC,  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


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
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
