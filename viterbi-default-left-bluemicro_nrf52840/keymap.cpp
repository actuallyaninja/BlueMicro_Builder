/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"



#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
        KC_ESC,   KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,  KC_5,
        KC_MINUS, KC_EQUAL,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,
        KC_GRAVE, KC_BSLASH, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,
        KC_0,     KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,
        KC_LCTRL, KC_LGUI,   KC_LBRC, KC_RBRC, KC_LALT, KC_0,  KC_SPACE 
    ));

void setupKeymap() {

   // no layers for SINGLE keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}
#endif


#if KEYBOARD_SIDE == LEFT

/* Qwerty
 * ,------------------------------------------------.
 * | Esc  |  Tab |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+-------------|
 * |  -   |   =  |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------+-------------|
 * |  `   |   \  |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------+------|------|
 * | L(2) | Shift|   Z  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  [   |  ]   | Alt  | L(1) |Space |
 * `------------------------------------------------'
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
        KC_ESC,   KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_MINUS, KC_EQUAL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, 
        KC_GRAVE, KC_BSLASH, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        LAYER_2,  KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_LCTL,  KC_LGUI,   KC_LBRC, KC_RBRC, KC_LALT, LAYER_1, KC_SPC
    ));

 
void setupKeymap() {

/* Layer 1 (Raise)
//   ,------------------------------------------------.   
  // |  ~   |      |  F1  |  F2  |  F3  |  F4  |  F5  |
  // |------+------+------+------+------+------+------|
  // |      |      | MB2  | M-UP | MB1  | MW-UP|      |
  // |------+------+------+------+------+------+------|
  // |      |      | M-LT | M-DN | M-RT | MW-DN|      |
  // |------+------+------+------+------+------+------|
  // |      | CAPS | MACL0| MACL1| MACL2|      |      |
  // |------+------+------+------+------+------+------|
  // |      |      |      |      |      |      |      |
  // `------------------------------------------------'
  //
 */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_TILD,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  \
  _______,  _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, _______,  \
  _______,  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,  \
  _______,  KC_CAPS, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,  \
  _______,  _______, _______, _______, _______, _______, _______  \
);

/* Layer 2 (lower)
 // ,------------------------------------------------.
 // |      |      |      |      |      |      |      |
 // |------+------+------+------+------+------+------|
 // |      |      |      |      |      |      |      |
 // |------+------+------+------+------+------+------|
 // |      |      |      |      |      |      |      |
 // |------+------+------+------+------+------+------|
 // |      |      |      |      |      |      |      |
 // |------+------+------+------+------+------+------|
 // |  BT  |      |      |      |      |      |      |
 // `------------------------------------------------'
 //
 */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  _______,  _______, _______, _______, _______, _______, _______,  \
  _______,  _______, _______, _______, _______, _______, _______,  \
  _______,  _______, _______, _______, _______, _______, _______,  \
  _______,  _______, _______, _______, _______, _______, _______,  \
  LAYER_3,  _______, _______, _______, _______, _______, _______  \
);

    /* Layer 3
 * ,------------------------------------------------.
 * |      |      | BT_1 | BT_2 | BT_3 |      |      | 
 * |------+------+------+------+------+-------------|
 * |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |
 * `------------------------------------------------'
 */
    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  _______,   _______, BLEPROFILE_1, BLEPROFILE_2, BLEPROFILE_3, _______, _______,  \
  _______,   _______, _______,      _______,      _______,      _______, _______,  \
  _______,   _______, _______,      _______,      _______,      _______, _______,  \
  _______,   _______, _______,      _______,      _______,      _______, _______,  \
  _______,   _______, _______,      _______,      _______,      _______, _______  \
);

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS, layer3[row][col]);
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}

#endif  // left



#if KEYBOARD_SIDE == RIGHT

/* Qwerty
 * ,------------------------------------------------.
 * |   6  |   7  |   8  |   9  |   0  |  Del | Bksp |
 * |------+------+------+------+------+-------------|
 * |   Y  |   U  |   I  |   O  |   P  | PgUp | PgDn |
 * |------+------+------+------+------+-------------|
 * |   H  |   J  |   K  |   L  |   ;  |  '   | Enter|
 * |------+------+------+------+------+------|------|
 * |   N  |   M  |   ,  |   .  |   /  |  Up  | Shift|
 * |------+------+------+------+------+------+------|
 * | Space| Home | End  | Ctrl | Left | Down |Right |
 * `------------------------------------------------'
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
        KC_6,    KC_7,    KC_8,     KC_9,     KC_0,      KC_DEL,    KC_BSPACE,
        KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,      KC_PGUP,   KC_PGDN,
        KC_H,    KC_J,    KC_K,     KC_L,     KC_SCOLON, KC_QUOTE,  KC_ENTER, 
        KC_N,    KC_M,    KC_COMMA, KC_DOT,   KC_SLSH,   KC_UP,     KC_RSHIFT,
        KC_SPC,  KC_HOME, KC_END,   KC_RCTRL, KC_LEFT,   KC_DOWN,   KC_RIGHT
    ));

 

void setupKeymap() {

/* Layer 1
 * ,------------------------------------------------.
 * |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |
 * |-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |
 * |------|------+------+------+------+------+------|
 * |      |      |      |      |      | PGUP |      |
 * |------+------+------+------+------+------+------|
 * |      |      |      |      |      | PGDN |      |
 * `------------------------------------------------'
 */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,  \
  _______,  _______, _______, _______, _______,  _______,   _______,  \
  _______,  _______, _______, _______, _______,  _______,   _______,  \
  _______,  _______, _______, _______, _______,  KC_PGUP,   _______,  \
  _______,  _______, _______, _______, _______,  KC_PGDN,   _______  \
);

/* Layer 2
 *  ,------------------------------------------------.
 *  |      |   7  |   8  |   9  |      |      |      |
 *  |-------------+------+------+------+------+------|
 *  |      |   4  |   5  |   6  |      |      |      |
 *  |------|------+------+------+------+------+------|
 *  |      |   1  |   2  |   3  |      |      |      |
 *  |------|------+------+------+------+------+------|
 *  |      |      |      |      |      | PGUP |      |
 *  |------+------+------+------+------+------+------|
 *  |   0  |      |      |      |      | PGDN |      |
 *  `------------------------------------------------'
 */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  _______,  KC_7,    KC_8,    KC_9,    _______,  _______,   _______,  \
  _______,  KC_4,    KC_5,    KC_6,    _______,  _______,   _______,  \
  _______,  KC_1,    KC_2,    KC_3,    _______,  _______,   _______,  \
  _______,  _______, _______, _______, _______,  KC_PGUP,   _______,  \
  KC_0,     _______, _______, _______, _______,  KC_PGDN,   _______  \
);

    /* Layer 3
*  ,------------------------------------------------.
*  |      |      |      |      |      |      |      |
*  |-------------+------+------+------+------+------|
*  |      |      |      |      |      |      |      |
*  |------|------+------+------+------+------+------|
*  |      |      |      |      |      |      |      |
*  |------+------+------+------+------+------+------|
*  |      |      |      |      |      |      |      |
*  |------+------+------+------+------+------+------|
*  |      |      |      |      |      |      |      |
*  `------------------------------------------------'
* 
*/
    uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  _______,  _______, _______, _______, _______,  _______,   _______,  \
  _______,  _______, _______, _______, _______,  _______,   _______,  \
  _______,  _______, _______, _______, _______,  _______,   _______,  \
  _______,  _______, _______, _______, _______,  _______,   _______,  \
  _______,  _______, _______, _______, _______,  _______,   _______  \
);

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS, layer3[row][col]);
        }
    }

}


#endif




