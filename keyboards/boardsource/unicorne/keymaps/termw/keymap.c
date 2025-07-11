#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 40 //Switch to fast animation when over words per minute
#ifdef OLED_ENABLE
#include "lib/oled.h"
#include "demon.c"
#endif

#define _BASE 0
#define _NAV 1
#define _SYS 2
#define MAGIC_REPEAT LSFT_T(KC_0)

// Custom keycodes
enum custom_keycodes {
    M_UPDIR = SAFE_RANGE,
    VI_WQA,
    VI_ZQ,
    VI_W
};

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(_______, KC_W, KC_L,        KC_Y,        KC_P,        KC_B,        KC_Z, KC_F,        KC_O,        KC_U,        KC_QUOT, MO(_SYS),
                                 QK_LLCK, KC_C, CTL_T(KC_R), LALT_T(KC_S), GUI_T(KC_T), KC_G,        KC_M, GUI_T(KC_N), LALT_T(KC_E), CTL_T(KC_I), KC_A,    QK_LLCK,
                                 KC_TAB,  KC_Q, KC_J,        KC_V,        KC_D,        KC_K,        KC_X, KC_H,        KC_COMM,     KC_DOT,      KC_QUES, KC_SCLN,
                                                     LT(_NAV, KC_ESC), KC_SPC,  MAGIC_REPEAT,  OSM(MOD_RSFT),  KC_BSPC, LT(_NAV, KC_ENT)),

    [_NAV] = LAYOUT_split_3x6_3(_______, G(KC_X), C(KC_D), C(KC_U), G(KC_C), _______,     VI_WQA,  KC_P7, KC_P8, KC_P9, _______, _______,
                                _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,      KC_P0,   KC_P4, KC_P5, KC_P6, _______, _______,
                                _______, G(KC_A), KC_PGDN, KC_PGUP, G(KC_V),  VI_W,       VI_ZQ,   KC_P1, KC_P2, KC_P3, _______, _______,
                                                           _______, _______,  _______,     _______, _______, _______),

    [_SYS] = LAYOUT_split_3x6_3(QK_BOOT, _______, _______, _______, _______, _______,       RM_VALU, RM_HUEU, RM_SATU, RM_NEXT, RM_TOGG, QK_BOOT,
                                _______,  _______, _______, _______, _______, _______,      RM_VALD, RM_HUED, RM_SATD, RM_PREV, CK_TOGG, _______,
                                _______, _______,  _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                                                           _______, _______, _______,       _______, _______, _______)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );


// Shift + esc = `
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, LT(_NAV, KC_ESC), KC_GRV);
// GUI + esc = ~
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, LT(_NAV, KC_ESC), S(KC_GRV));
// Shift + . = :
const key_override_t dot_colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
// Shift + , = ;
const key_override_t comma_semicolon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
// Shift + ? = !
const key_override_t question_exclamation_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
// Shift + = = !
const key_override_t equal_exclamation_override = ko_make_basic(MOD_MASK_SHIFT, KC_PEQL, KC_EXLM);
// Shift + - = +
const key_override_t minus_plus_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_PPLS);
// Shift + / = *
const key_override_t fslash_asterisk_override = ko_make_basic(MOD_MASK_SHIFT, KC_KP_SLASH, KC_ASTR);
// Shift + _ = ^
const key_override_t under_super_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_CIRC);
// Shift + < = [
const key_override_t lt_sqopen_override = ko_make_basic(MOD_MASK_SHIFT, KC_LT, KC_LBRC);
// Shift + > = ]
const key_override_t gt_sqclose_override = ko_make_basic(MOD_MASK_SHIFT, KC_GT, KC_RBRC);

// Shift + @ = %]
const key_override_t at_percent_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_PERC);
// Shift + & = |]
const key_override_t and_or_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_PIPE);
// Shift + # = $]
const key_override_t hash_dollar_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_DLR);

const key_override_t *key_overrides[] = {
	&tilde_esc_override,
	&grave_esc_override,
    &dot_colon_override,
    &comma_semicolon_override,
    &question_exclamation_override,
    &equal_exclamation_override,
    &minus_plus_override,
    &fslash_asterisk_override,
    &under_super_override,
    &lt_sqopen_override,
    &gt_sqclose_override,
    &at_percent_override,
    &and_or_override,
    &hash_dollar_override
};

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    return true;
}
#endif

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case KC_A ... KC_Z:
            if ((*remembered_mods & ~MOD_MASK_SHIFT) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            break;
        case KC_ESC:
        case LT(_NAV, KC_ESC):
        case MAGIC_REPEAT:
            return false;
    }
    return true;  // Other keys can be repeated.
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_ASTR: return KC_HASH;
        case KC_DOT: return M_UPDIR;
        case KC_TAB:
            {
                bool shifted = (mods & MOD_MASK_SHIFT);
                if (shifted) {        // If the last key was Shift + Tab,
                    return KC_TAB;    // ... the reverse is Tab.
                } else {              // Otherwise, the last key was Tab,
                    return S(KC_TAB); // ... and the reverse is Shift + Tab.
                }
            }
    }
    return KC_TRNS;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAGIC_REPEAT:
            if (record->tap.count) {
                uint8_t mod_state = get_mods();
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    alt_repeat_key_invoke(&record->event);
                    set_mods(mod_state);
                } else {
                    repeat_key_invoke(&record->event);
                }
                return false;
            }
            return true;
        case M_UPDIR:
            if (record->event.pressed) {
                SEND_STRING("./");
            }
            return false;
        case VI_W:
            if (record->event.pressed) {
                SEND_STRING(":w\n"); return true;
            }
            return false;
        case VI_WQA:
            if (record->event.pressed) {
                SEND_STRING(":wqa\n"); return true;
            }
            return false;
        case VI_ZQ:
            if (record->event.pressed) {
                SEND_STRING("ZQ"); return true;
            }
            return false;
    }
    return true; // Return true to allow QMK to process the key as normal (though in this case, we've replaced its behavior)
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_anim();
  } else {
    render_layer_state();
  }
  return false;
}
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_CORAL);
                }
            }
        }
    }
    return false;
}
