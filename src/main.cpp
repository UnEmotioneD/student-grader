// Copyright (c) 2025 UnEmotioneD

#include <vector>

#include "bubble_sort.h"
#include "file_reader.h"
#include "grading.h"
#include "print_info.h"
#include "rank.h"
#include "student.h"
#include "terminal.h"

std::vector<Student> students;

int main() {
    clear_term();

    read_students_info(students);
    grade_students(students);
    bubble_sort_students(students);
    // TODO: assign ranks

    print_students_info(students);

    return 0;
}
