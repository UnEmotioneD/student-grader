#pragma once

#include <string>

// Box drawing characters (https://symbl.cc/en/unicode-table/#box-drawing)
const std::string BOX_H = "\u2500";  // ─  horizontal
const std::string BOX_V = "\u2502";  // │  vertical
const std::string BOX_TL = "\u250C"; // ┌  top-left
const std::string BOX_TR = "\u2510"; // ┐  top-right
const std::string BOX_BL = "\u2514"; // └  bottom-left
const std::string BOX_BR = "\u2518"; // ┘  bottom-right
const std::string BOX_LT = "\u251C"; // ├  left tee
const std::string BOX_RT = "\u2524"; // ┤  right tee
const std::string BOX_TT = "\u252C"; // ┬  top tee
const std::string BOX_BT = "\u2534"; // ┴  bottom tee
const std::string BOX_CR = "\u253C"; // ┼  cross
