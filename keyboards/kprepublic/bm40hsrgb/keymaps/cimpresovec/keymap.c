/* Copyright 2020 tominabox1
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

enum layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

// alpha hold modifiers
#define KC_CTL_A  MT(MOD_LCTL, KC_A)     // Tap for A, hold for Control
#define KC_CTL_O  MT(MOD_RCTL, KC_O)     // Tap for colon, hold for Control
#define KC_SFT_Z  MT(MOD_LSFT, KC_Z)     // Tap for Z, hold for Shift
#define KC_SFT_SL MT(MOD_RSFT, KC_SLSH)  // Tap for slash, hold for Shift

// thumb modifiers/toggles
#define KC_GUI_ESC MT(MOD_LGUI, KC_ESC)  // Tap for Esc, hold for GUI (Meta, Command, Win)
#define KC_ALT_ENT MT(MOD_LALT, KC_ENT)  // Tap for Enter, hold for Alt (Option)
#define KC_SPE_SPC LT(_LOWER, KC_SPC)  // Tap for Space, hold for Special layer
#define KC_NUM_SPC LT(_RAISE, KC_SPC)  // Tap for Space, hold for Numbers layer
#define KC_SFT_TAB MT(MOD_RSFT, KC_TAB)  // Tap for Tab, hold for Right Shift

const uint16_t PROGMEM backspace_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM esc_1[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM esc_2[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM tab[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM enter[] = {KC_C, KC_D, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
    COMBO(backspace_combo, KC_BSPC),
    COMBO(esc_1, KC_ESC),
    COMBO(esc_2, KC_ESC),
    COMBO(tab, KC_TAB),
    COMBO(enter, KC_ENT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_mit(
        KC_Q,     KC_W,   KC_F,   KC_P,   KC_B, _______, _______, KC_J,   KC_L,   KC_U,     KC_Y,   KC_SCLN,
        KC_CTL_A, KC_R,   KC_S,   KC_T,   KC_G,  _______, _______,    KC_M,   KC_N,   KC_E,     KC_I,   KC_CTL_O,
        KC_SFT_Z, KC_X,   KC_C,   KC_D,   KC_V,  _______, _______,     KC_K,   KC_H,   KC_COMMA, KC_DOT, KC_SFT_SL,
        _______, _______, KC_GUI_ESC, KC_ALT_ENT, KC_SPE_SPC,  _______,  KC_NUM_SPC, KC_LSFT, KC_SFT_TAB, _______,_______ ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,_______,         KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
        KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2, _______,_______,         KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
        KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1, _______,_______,         KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
        _______,_______, CMB_TOG, KC_SCLN, KC_EQL, _______,         KC_EQL, KC_SCLN, KC_DEL, _______,_______
        ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_1,  KC_2,  KC_3,  KC_4,  KC_5, _______,_______,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   _______,_______,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  _______,_______,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
        _______,_______, KC_F11, KC_F12, KC_TRNS,  _______,       KC_TRNS,  KC_MPLY,  MO(_ADJUST), _______,_______
        ),
    /* Adjust (Lower + Raise)
     *                      v------------------------RGB CONTROL--------------------v
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        _______, _______, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RESET, _______, _______, _______, _______, _______, _______, _______, _______)

};