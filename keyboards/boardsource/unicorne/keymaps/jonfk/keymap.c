#include QMK_KEYBOARD_H

enum unicorne_layers {_DVORAK, _QWERTY, _SYM, _NUM, _ADJUST, _NAV};

enum unicorne_keycodes { QWERTY = SAFE_RANGE,  DVORAK, MT_TILD, MT_DQUO, MA_WI_COPY, MA_WI_CUT, MA_WI_PSTE };

#define SYM MO(_SYM)
#define NUM MO(_NUM)
#define NAV MO(_NAV)


// Dvorak: Left-hand bottom row mods
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
Note that custom keycodes are used because of Mod Tap caveats not working with keycodes past a certain level.
    See: https://docs.qmk.fm/mod_tap#caveats
*/
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	  KC_ESC,  KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,							KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  KC_TAB,	  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,							KC_D,    KC_H,    KC_T,    KC_N,   KC_S,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  KC_LSFT, BR_SCLN,    BR_Q,    BR_J,    BR_K,    KC_X,                         KC_B,    BR_M,    BR_W,    BR_V,   BR_Z,  KC_ENT, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      NAV,       SYM,   KC_ENT,     KC_SPC,   NUM,    KC_RALT
                                      //`--------------------------'  `--------------------------'
	),

	[_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	  KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,							KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  KC_TAB,	  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,							KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      NAV,       SYM,   KC_ENT,     KC_SPC,   NUM,    KC_RALT
                                      //`--------------------------'  `--------------------------'
	),

	[_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	  _______, KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  KC_DEL,  KC_GRV,  KC_ASTR, KC_PLUS,  KC_EQL, _______,                      KC_PIPE, KC_SLSH, KC_LCBR, KC_RCBR, KC_BSLS, _______,
  //|--------+--------+--------+-------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  _______, BR_TILD, _______, BR_DQUO, BR_QUOT, _______,                      _______, _______, BR_LBRC, BR_RBRC, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
	),

	[_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	   KC_DEL,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  _______,  KC_F11,  KC_F12, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
	),

	[_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	  _______, _______,MA_WI_CUT,MA_WI_COPY,MA_WI_PSTE,_______,                  _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+-------+--------|
	   KC_DEL, _______, KC_HOME, KC_LEFT, KC_RIGHT,KC_PGUP,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  _______, _______, KC_END,  KC_DOWN,   KC_UP, KC_PGDN,                      _______, OSM(MOD_RCTL), OSM(MOD_RSFT), OSM(MOD_RALT), OSM(MOD_RGUI), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
	),

	[_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	  QK_BOOT, _______, _______, _______, _______, _______,                      RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, RGB_TOG, _______, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	   EE_CLR, _______, _______, _______, _______, _______,                      RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD, CK_TOGG, _______, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                      _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NUM, _ADJUST);
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
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
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
