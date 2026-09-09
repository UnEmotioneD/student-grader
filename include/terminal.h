// compile only once even if header file is included from multiple files
#pragma once

#include <iostream>

using std::cout;
using std::flush;

// inline: keep the linker from throwing `multiple definition` error
//  when more then 2 .cpp files includes header file
inline void clear_term() {
    // cross platform on modern OSs
    cout << "\x1B[2J\x1B[H" << flush;
    // \x1B[2J   : erase entire screen
    // \x1B[H    : move cursor to top-left
    // std:flush : force output buffer to write immediately
}
