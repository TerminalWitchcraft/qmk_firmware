// Copyright 2025 Andrew Kannan (awkannan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define _BASE 0
#define _SYS 1
#define _NUM 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,                     KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_GRV,  KC_W,    KC_L,    KC_Y,    KC_P,  KC_B,                     KC_Z,    KC_F,   KC_O,    KC_U,    KC_DQT,  KC_BSPC,
  KC_LALT,  KC_C,    KC_R,    KC_S,    KC_T,  KC_G,                     KC_M,    KC_N,   KC_E,    KC_I,    KC_A,    KC_RCTL,
  KC_LCTL, KC_Q,    KC_J,    KC_V,    KC_D,  KC_K,   MS_BTN2, MS_BTN1, KC_X,    KC_H,   KC_COMM, KC_DOT,  KC_QUES, KC_RALT,
           EC_NORM, QK_REPEAT_KEY, MT(MOD_LGUI, KC_ESC),  LT(2, KC_SPC), KC_TAB,         OSM(MOD_LSFT), LT(1, KC_BSPC), MT(MOD_RGUI, KC_ENT), QK_ALT_REPEAT_KEY, EC_SWAP
),


[_SYS] = LAYOUT(
  KC_F11,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F12,
  QK_BOOT, KC_TRNS,  KC_HOME,  KC_UP,  KC_END,  KC_TRNS,                    KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_INS,  KC_DEL,
  KC_TRNS, KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_TRNS,                    KC_PGDN,  OSM(MOD_RSFT),  OSM(MOD_RGUI),  OSM(MOD_RALT), OSM(MOD_RCTL), KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_PGUP,  KC_TRNS,  KC_PGDN,  KC_TRNS, KC_MUTE,  KC_MPLY, KC_CAPS,  KC_PGUP,  KC_MPRV,  KC_MNXT,  KC_PSCR, KC_TRNS,
           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),
// _NUM (ported from boardsource/unicorne termw): right-hand numpad,
// one-shot CTL/ALT/GUI on the left home-row mod fingers.
[_NUM] = LAYOUT(
  KC_F11,  KC_F1,   KC_F2,         KC_F3,         KC_F4,         KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                   KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_TRNS, KC_TRNS,
  KC_TRNS, OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), KC_TRNS,                   KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

// Combos are defined in combos.def and expanded by the include of
// "g/keymap_combo.h" at the top of this file (it generates the enum, the
// key arrays, and the key_combos[] table).

// The encoder middle-click combo presses two separate knobs, so give it a wide
// window; the symbol combos keep the tight default COMBO_TERM.
#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    if (index == ENC_MIDDLE_CLICK) {
        return 200;
    }
    return COMBO_TERM;
}
#endif

// Key overrides (ported from boardsource/unicorne termw). Several triggers are
// keycodes the ported combos emit (KC_AT, KC_PEQL, KC_PMNS, KC_KP_SLASH, ...),
// so holding Shift while firing a combo yields the alternate symbol.
const key_override_t delete_key_override         = ko_make_basic(MOD_MASK_ALT,   LT(2, KC_BSPC), KC_DEL);   // Alt + Backspace = Del (link backspace is LT(2, KC_BSPC))
const key_override_t quote_override              = ko_make_basic(MOD_MASK_SHIFT, KC_DQT,         KC_QUOT);  // Shift + " = '
const key_override_t dot_colon_override          = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,         KC_COLN);  // Shift + . = :
const key_override_t comma_semicolon_override    = ko_make_basic(MOD_MASK_SHIFT, KC_COMM,        KC_SCLN);  // Shift + , = ;
const key_override_t question_exclamation_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES,      KC_EXLM);  // Shift + ? = !
const key_override_t equal_exclamation_override  = ko_make_basic(MOD_MASK_SHIFT, KC_PEQL,        KC_EXLM);  // Shift + = = !
const key_override_t minus_plus_override         = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS,        KC_PPLS);  // Shift + - = +
const key_override_t fslash_asterisk_override    = ko_make_basic(MOD_MASK_SHIFT, KC_KP_SLASH,    KC_ASTR);  // Shift + / = *
const key_override_t under_super_override        = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS,        KC_CIRC);  // Shift + _ = ^
const key_override_t lt_sqopen_override          = ko_make_basic(MOD_MASK_SHIFT, KC_LT,          KC_LBRC);  // Shift + < = [
const key_override_t gt_sqclose_override         = ko_make_basic(MOD_MASK_SHIFT, KC_GT,          KC_RBRC);  // Shift + > = ]
const key_override_t at_percent_override         = ko_make_basic(MOD_MASK_SHIFT, KC_AT,          KC_PERC);  // Shift + @ = %
const key_override_t and_or_override             = ko_make_basic(MOD_MASK_SHIFT, KC_AMPR,        KC_PIPE);  // Shift + & = |
const key_override_t hash_dollar_override        = ko_make_basic(MOD_MASK_SHIFT, KC_HASH,        KC_DLR);   // Shift + # = $

const key_override_t *key_overrides[] = {
    &delete_key_override,
    &quote_override,
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

/* ============================ Keyboard pet: Luna ============================
 * Adapted from HellSingCoder's Sofle "luna" (GPL-2.0). Sprites are 32x22 (3
 * pages). The Sofle renders them with a single oled_write_raw_P into a 32-wide
 * canvas; the Link master is 64 wide at OLED_ROTATION_0, so a 96-byte linear
 * write would wrap. We instead blit the sprite as three 32-byte page-rows at
 * column 0. Luna reacts to WPM (sit/walk/run), barks on Caps Lock or Caps Word,
 * sneaks while Ctrl is held, and jumps while Space is held. On-screen position/orientation may need an on-device tweak.
 * ========================================================================== */
#ifdef OLED_ENABLE

#    define LUNA_MIN_WALK_SPEED 10
#    define LUNA_MIN_RUN_SPEED  40
#    define LUNA_FRAME_DURATION 200  // ms per frame
#    define LUNA_ANIM_SIZE      96   // bytes per frame (32x22 -> 32 cols x 3 pages)
#    define LUNA_JUMP           2    // pages the sprite hops up on Space

static uint32_t luna_anim_timer  = 0;
static uint8_t  luna_frame       = 0;
static int      luna_wpm         = 0;
static led_t    luna_led_state;
static bool     luna_sneaking    = false;
static bool     luna_jumping     = false;
static bool     luna_showed_jump = true;

// clang-format off
static const char PROGMEM luna_sit[2][LUNA_ANIM_SIZE] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};
static const char PROGMEM luna_walk[2][LUNA_ANIM_SIZE] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};
static const char PROGMEM luna_run[2][LUNA_ANIM_SIZE] = {
    {0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};
static const char PROGMEM luna_bark[2][LUNA_ANIM_SIZE] = {
    {0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};
static const char PROGMEM luna_sneak[2][LUNA_ANIM_SIZE] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}
};
// clang-format on

// Expand a byte's 8 bits to 16 bits, doubling each bit (for 2x vertical scale).
// Bit i of the input maps to bits 2i and 2i+1 of the output, preserving the
// OLED page bit order (LSB = topmost pixel).
static uint16_t luna_expand_byte(uint8_t x) {
    uint16_t r = 0;
    for (uint8_t i = 0; i < 8; i++) {
        if (x & (1u << i)) {
            r |= (uint16_t)0x3 << (2 * i);
        }
    }
    return r;
}

// Render the current Luna frame scaled 2x: the 32x24 (3-page) sprite becomes
// 64x48 (6-page), filling the full master width. Both axes are exact integer
// doublings (32->64 wide, 24->48 tall = 6 pages), so it stays page-aligned.
static void render_luna(uint8_t base_page) {
    if (timer_elapsed32(luna_anim_timer) <= LUNA_FRAME_DURATION) {
        return;
    }
    luna_anim_timer = timer_read32();
    luna_frame      = (luna_frame + 1) % 2;

    const char *f;
    if (luna_led_state.caps_lock || is_caps_word_on()) {
        f = luna_bark[luna_frame];
    } else if (luna_sneaking) {
        f = luna_sneak[luna_frame];
    } else if (luna_wpm <= LUNA_MIN_WALK_SPEED) {
        f = luna_sit[luna_frame];
    } else if (luna_wpm <= LUNA_MIN_RUN_SPEED) {
        f = luna_walk[luna_frame];
    } else {
        f = luna_run[luna_frame];
    }

    // Build the 6 scaled page-rows (64 bytes each). For each source column we
    // double it into two dest columns; for each source page byte we expand its
    // 8 bits into 16 (two dest page bytes).
    uint8_t dest[6][64];
    for (uint8_t c = 0; c < 32; c++) {
        uint8_t dcol[6];
        for (uint8_t p = 0; p < 3; p++) {
            uint16_t e     = luna_expand_byte(pgm_read_byte(f + p * 32 + c));
            dcol[2 * p]     = e & 0xFF;
            dcol[2 * p + 1] = (e >> 8) & 0xFF;
        }
        for (uint8_t p = 0; p < 6; p++) {
            dest[p][2 * c]     = dcol[p];
            dest[p][2 * c + 1] = dcol[p];
        }
    }
    // Jump: hop the sprite up by LUNA_JUMP pages while Space is held (and at
    // least once per tap, via luna_showed_jump). Clear the pages the sprite
    // vacates so no ghost is left behind.
    uint8_t dp = base_page;
    if (luna_jumping || !luna_showed_jump) {
        dp               = base_page - LUNA_JUMP;
        luna_showed_jump = true;
    }
    uint8_t blank[64] = {0};
    for (uint8_t p = base_page - LUNA_JUMP; p <= base_page + 5; p++) {
        if (p < dp || p > dp + 5) {
            oled_set_cursor(0, p);
            oled_write_raw((const char *)blank, 64);
        }
    }
    for (uint8_t p = 0; p < 6; p++) {
        oled_set_cursor(0, dp + p);
        oled_write_raw((const char *)dest[p], 64);
    }
}

// Write a string horizontally centered on the given page line, padded with
// spaces to the full line width so any previous (longer) text is cleared.
static void oled_write_centered(uint8_t line, const char *str, bool invert) {
    char    buf[17];
    uint8_t max = oled_max_chars();
    if (max > 16) {
        max = 16;
    }
    uint8_t len = strlen(str);
    if (len > max) {
        len = max;
    }
    // Round the left pad up so odd remainders bias right, compensating for the
    // few unused pixels on the right edge (width isn't an exact multiple of the
    // font width). Keeps 3-char strings like "WPM"/the WPM number centered.
    uint8_t pad = (max - len + 1) / 2;
    uint8_t i   = 0;
    for (; i < pad; i++) {
        buf[i] = ' ';
    }
    for (uint8_t j = 0; j < len; j++) {
        buf[i++] = str[j];
    }
    for (; i < max; i++) {
        buf[i] = ' ';
    }
    buf[i] = '\0';
    oled_set_cursor(0, line);
    oled_write(buf, invert);
}

// Master half: WPM counter, Caps indicator, and Luna. Text is centered.
static void render_master(void) {
    uint8_t n = (uint8_t)luna_wpm;
    char    wpm_str[4];
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;

    oled_write_centered(1, "WPM", false);
    oled_write_centered(2, wpm_str, false);
    oled_write_centered(4, (luna_led_state.caps_lock || is_caps_word_on()) ? "CAPS" : "", false);

    render_luna(9);
}

// Matrix-style digital rain for the lower part of the slave OLED. Driven by WPM
// (synced across the split), so it speeds up as you type. Fixed columns, each a
// lit head with a short trailing streak; the tail pixel is erased every step so
// nothing accumulates.
#define RAIN_COLS   8
#define RAIN_TOP    16   // page 2: below the top margin (page 0) and name (page 1)
#define RAIN_BOTTOM 119  // page 14: leave the bottom page (15) as margin
#define RAIN_TRAIL  6

static uint8_t  rain_head[RAIN_COLS];
static bool     rain_ready = false;
static uint16_t rain_frame = 0;
static uint32_t rain_timer = 0;

static void render_rain(void) {
    static const uint8_t period[RAIN_COLS] = {1, 2, 1, 3, 2, 3, 1, 2};  // per-column speed divisor

    if (!rain_ready) {
        for (uint8_t i = 0; i < RAIN_COLS; i++) {
            rain_head[i] = RAIN_TOP + (uint8_t)((i * 13) % (RAIN_BOTTOM - RAIN_TOP));
        }
        rain_ready = true;
    }

    uint8_t  wpm      = get_current_wpm();
    uint16_t interval = (wpm > LUNA_MIN_RUN_SPEED) ? 25 : (wpm > LUNA_MIN_WALK_SPEED ? 45 : 80);
    if (timer_elapsed32(rain_timer) <= interval) {
        return;
    }
    rain_timer = timer_read32();
    rain_frame++;

    for (uint8_t i = 0; i < RAIN_COLS; i++) {
        if (rain_frame % period[i] != 0) {
            continue;  // this column doesn't advance this frame
        }
        uint8_t x    = 3 + i * 8;
        int16_t tail = (int16_t)rain_head[i] - RAIN_TRAIL;
        if (tail >= RAIN_TOP && tail <= RAIN_BOTTOM) {
            oled_write_pixel(x, (uint8_t)tail, false);
        }
        int16_t nh = (int16_t)rain_head[i] + 1;
        if (nh - RAIN_TRAIL > RAIN_BOTTOM) {
            for (uint8_t y = RAIN_TOP; y <= RAIN_BOTTOM; y++) {
                oled_write_pixel(x, y, false);  // clear column on wrap
            }
            nh = RAIN_TOP + (i * 5) % 10;
        }
        rain_head[i] = (uint8_t)nh;
        if (rain_head[i] >= RAIN_TOP && rain_head[i] <= RAIN_BOTTOM) {
            oled_write_pixel(x, rain_head[i], true);
        }
    }
}

// Secondary half: active layer name (BASE / NUM / SYS) plus digital rain.
static void render_slave(void) {
    const char *name;
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            name = "Base";
            break;
        case _NUM:
            name = "Num";
            break;
        case _SYS:
            name = "Sys";
            break;
        default:
            name = "???";
            break;
    }
    oled_write_centered(1, name, false);
    render_rain();
}

// Force both halves to portrait (OLED_ROTATION_0) so the slave's layer readout
// matches the master's Luna orientation. link.c chains here for the rotation.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
#if OLED_TIMEOUT > 0
    // Only the MASTER decides sleep/wake. The on/off state is mirrored to the
    // slave via split.transport.sync.oled, so if the slave also toggled the
    // panel from its own activity timers it would fight the sync and flicker
    // (notably when Caps Lock is toggled from the host keyboard, which wakes the
    // master but not the slave's timers). Both halves skip drawing while off.
    if (is_keyboard_master()) {
        if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
            oled_off();
        } else {
            oled_on();
        }
    }
    if (!is_oled_on()) {
        return false;
    }
#endif

    if (is_keyboard_master()) {
        luna_wpm       = get_current_wpm();
        luna_led_state = host_keyboard_led_state();
        render_master();
    } else {
        render_slave();
    }
    return false;  // we fully own the OLED; skip link.c's default rendering
}
#endif  // OLED_ENABLE

// Luna sneaks while Ctrl is held and jumps while Space is held.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            luna_sneaking = record->event.pressed;
            break;
        case LT(1, KC_SPC):
            if (record->event.pressed) {
                luna_jumping     = true;
                luna_showed_jump = false;
            } else {
                luna_jumping = false;
            }
            break;
    }
#endif
    return true;
}

#ifdef ENCODER_ENABLE
// Encoder rotation is layer-dependent:
//   Base layer (0): thumb rollers scroll.
//     left  (index 0) -> vertical   scroll (CW = down,  CCW = up)
//     right (index 1) -> horizontal scroll (CW = right, CCW = left)
//   Sys layer (2): media/system control.
//     left  (index 0) -> volume     (CW = up, CCW = down)
//     right (index 1) -> brightness (CW = up, CCW = down)
// Any other layer returns true to fall through to the keyboard-level
// defaults in link.c (left = volume, right = PgUp/PgDn).
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            if (index == 0) {
                tap_code(clockwise ? MS_WHLD : MS_WHLU);
            } else if (index == 1) {
                tap_code(clockwise ? MS_WHLR : MS_WHLL);
            }
            return false;
        case 2:
            if (index == 0) {
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
            } else if (index == 1) {
                tap_code(clockwise ? KC_BRIU : KC_BRID);
            }
            return false;
        default:
            return true;
    }
}
#endif
