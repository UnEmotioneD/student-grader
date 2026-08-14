#pragma once

#include <string>

using std::string;

// Box drawing characters (https://symbl.cc/en/unicode-table/#box-drawing)
const string BOX_H = "\u2500";  // ─  horizontal
const string BOX_V = "\u2502";  // │  vertical
const string BOX_TL = "\u250C"; // ┌  top-left
const string BOX_TR = "\u2510"; // ┐  top-right
const string BOX_BL = "\u2514"; // └  bottom-left
const string BOX_BR = "\u2518"; // ┘  bottom-right
const string BOX_LT = "\u251C"; // ├  left tee
const string BOX_RT = "\u2524"; // ┤  right tee
const string BOX_TT = "\u252C"; // ┬  top tee
const string BOX_BT = "\u2534"; // ┴  bottom tee
const string BOX_CR = "\u253C"; // ┼  cross
