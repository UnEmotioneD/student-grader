#pragma once

// Declare interface
//  to allow function call from main.cpp
//  and implemented by sort.cpp

#include <vector>

#include "student.h"

void bubble_sort(std::vector<Student> &students);
