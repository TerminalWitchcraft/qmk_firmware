// Copyright 2025 Andrew Kannan (awkannan)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Symbol combos (ported from the corne) are tuned tight so they don't misfire
// while typing. The encoder middle-click combo needs a wide window since it
// presses two separate knobs, so it gets a longer term via get_combo_term().
#define COMBO_TERM 40
#define COMBO_TERM_PER_COMBO
#define COMBO_STRICT_TIMER

// Always resolve combo keys from the base layer (the Canary letters live there),
// so the letter combos work regardless of the active layer.
#define COMBO_ONLY_FROM_LAYER 0

// --- Ported from boardsource/unicorne termw config.h ---

// Tap-hold tuning. Affects the LT() thumb keys and OSM() on this keymap.
#define TAPPING_TERM 350
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 140
#define FLOW_TAP_TERM 150

// Mouse key tuning. Affects the encoder scroll/click behavior.
#define MK_COMBINED
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_INTERVAL 18

// Caps Word. Toggled by double-tapping Shift (here the OSM Shift thumb key,
// same as the corne).
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 3000  // 3 seconds.
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Sleep the OLED after this many ms with no input (burn-in protection); it wakes
// on the next keypress. The continuous Luna/rain animation is gated on this in
// oled_task_user.
#define OLED_TIMEOUT 60000

#define ONESHOT_TIMEOUT 2000
