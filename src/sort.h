#pragma once

// Declare interface
//  to allow function call from main.cpp
//  and implemented by sort.cpp

#include <vector>

#include "student.h"

using std::vector;

void bubble_sort(vector<Student> &students);
