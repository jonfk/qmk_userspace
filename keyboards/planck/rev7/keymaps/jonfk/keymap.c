/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {_DVORAK, _QWERTY, _COLEMAK, _LOWER, _RAISE, _PLOVER, _ADJUST, _NAV};

enum planck_keycodes { QWERTY = SAFE_RANGE, COLEMAK, DVORAK, PLOVER, BACKLIT, EXT_PLV, MT_TILD, MT_DQUO, MA_WI_COPY, MA_WI_CUT, MA_WI_PSTE };

// Dvorak: Left-hand home row mods
#define HR_A LGUI_T(KC_A)
#define HR_O LALT_T(KC_O)
#define HR_E LSFT_T(KC_E)
#define HR_U LCTL_T(KC_U)

// Dvorak: Right-hand home row mods
#define HR_H RCTL_T(KC_H)
#define HR_T RSFT_T(KC_T)
#define HR_N LALT_T(KC_N)
#define HR_S RGUI_T(KC_S)

// Dvorak: Left-hand home row mods
#define BR_SCLN LGUI_T(KC_SCLN)
#define BR_Q LALT_T(KC_Q)
#define BR_J LSFT_T(KC_J)
#define BR_K LCTL_T(KC_K)

// Dvorak: Right-hand bottom row mods
#define BR_M RCTL_T(KC_M)
#define BR_W RSFT_T(KC_W)
#define BR_V LALT_T(KC_V)
#define BR_Z RGUI_T(KC_Z)

/*
Note that KP keys are used because of Mod Tap caveats not working with keycodes past a certain level.
    See: https://docs.qmk.fm/mod_tap#caveats
*/
// LOWER: Left-hand home row mods
#define HR_GRV LGUI_T(KC_GRV)
#define HR_ASTR LALT_T(KC_KP_ASTERISK)
#define HR_PLUS LSFT_T(KC_KP_PLUS)
#define HR_EQL LCTL_T(KC_EQL)

// LOWER: Right-hand home row mods
#define HR_SLSH RCTL_T(KC_SLSH)
#define HR_LCBR RSFT_T(KC_LCBR)
#define HR_RCBR LALT_T(KC_RCBR)
#define HR_BSLS RGUI_T(KC_BSLS)

// LOWER: Left-hand bottom row mods
// MT_TILD defined as custom keycode Unsupported because not basic keycode
// See https://precondition.github.io/home-row-mods#using-non-basic-keycodes-in-mod-taps
#define BR_TILD LGUI_T(MT_TILD)
//#define BR_ASTR LALT_T(KC_KP_ASTERISK) // Defined on base layer, pass through
#define BR_DQUO LSFT_T(MT_DQUO)
#define BR_QUOT LCTL_T(KC_QUOT)

// LOWER: Right-hand bottom row mods
// First finger not necessary, pass through
#define BR_LBRC RSFT_T(KC_LBRC)
#define BR_RBRC RALT_T(KC_RBRC)
// last finger not necessary, pass through

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV MO(_NAV)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| GUI  | Ctrl | Nav  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, BR_SCLN, BR_Q,    BR_J,    BR_K,    KC_X,    KC_B,    BR_M,    BR_W,    BR_V,    BR_Z,    KC_ENT,
    BACKLIT, KC_LGUI, KC_LCTL, NAV,     LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| GUI  | Ctrl | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LGUI, KC_LCTL, NAV,     LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|  GUI | Ctrl | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LGUI, KC_LCTL, NAV,     LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   (  |   )  |   ?  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   `  |   *  |   +  |   =  |      |   |  |   /  |   {  |   }  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |      |   "  |   '  |      |      |      |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_planck_grid(
//|-----------------------------------------------------------------------------------------------------------------------.
    _______,  KC_EXLM,   KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_LPRN,  KC_RPRN,  KC_QUES, KC_BSPC,
//|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------+----------|
    KC_DEL,   KC_GRV,   KC_ASTR,  KC_PLUS,  KC_EQL,   _______,  KC_PIPE,  KC_SLSH,  KC_LCBR,  KC_RCBR,  KC_BSLS, _______,
//|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------+----------|
    _______,  BR_TILD,  _______,  BR_DQUO,  BR_QUOT,  _______,  _______,  _______,  BR_LBRC,  BR_RBRC,  _______, _______,
//|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------+----------|
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MNXT,  KC_VOLD,  KC_VOLU, KC_MPLY
//|-----------------------------------------------------------------------------------------------------------------------.
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Cut  | Copy |Paste |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      | Home | Left |Right |Pg Up |      | Ctrl |Shift | Alt  | GUI  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | End  | Down |  Up  |Pg Dn |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = LAYOUT_planck_grid(
//|-----------------------------------------------------------------------------------------------------------------------.
    _______,  _______, MA_WI_CUT,MA_WI_COPY, MA_WI_PSTE,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BSPC,
//|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------+----------|
    KC_DEL,   _______,  KC_HOME,  KC_LEFT,  KC_RIGHT, KC_PGUP,  _______,  _______,  _______,  _______,  _______,  _______,
//|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------+----------|
    _______,  _______,  KC_END,  KC_DOWN,   KC_UP,   KC_PGDN,  _______,  OSM(MOD_RCTL),  OSM(MOD_RSFT),  OSM(MOD_RALT),  OSM(MOD_RGUI),  _______,
//|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+--------+----------|
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY
//|-----------------------------------------------------------------------------------------------------------------------.
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Workaround for caveats of Mod-Taps on non-basic keycodes
        case BR_TILD:
            if (record->event.pressed && record->tap.count > 0) {
                // send keycode
                // the 16 bit version of the `tap_code` function is used here
                // because KC_TILD is a non-basic keycode.
                tap_code16(KC_TILD);
                // do not continue with default tap action
                // if the MT was pressed or released, but not held
                return false;
            }
            break;
        case BR_DQUO:
            if (record->event.pressed && record->tap.count > 0) {
                // send keycode
                // the 16 bit version of the `tap_code` function is used here
                // because KC_TILD is a non-basic keycode.
                tap_code16(KC_DQUO);
                // do not continue with default tap action
                // if the MT was pressed or released, but not held
                return false;
            }
            break;
        // Macros
        case MA_WI_COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
            break;
        case MA_WI_CUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("x"));
            }
            break;
        case MA_WI_PSTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
            break;
        // End Macros
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307	

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     cancel_deferred_exec(tokens[index]);
//     if (clockwise) {
//         melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
//         melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
//         audio_play_melody(&melody[index], 2, false);
//     } else {
//         melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
//         melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
//         audio_play_melody(&melody[index], 2, false);
//     }
//     tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
//     return false;
// }

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}

const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {BR_J, BR_W, COMBO_END};

enum combo_events {
  ESC_COMBO,
  CAPS_COMBO,
  // Other combos...
  COMBO_LENGTH
};
combo_t key_combos[] = {
    [ESC_COMBO] = COMBO(combo_jk, KC_ESC),
    [CAPS_COMBO] = COMBO_ACTION(caps_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_on();  // Activate Caps Word!
      }
      break;
  }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DVORAK] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_QWERTY] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_COLEMAK] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_NAV] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_LOWER] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_PLOVER] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_RAISE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
