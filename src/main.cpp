// Copyright (c) 2025 UnEmotioneD

#include <vector>

#include "grade.h"
#include "print_info.h"
#include "rank.h"
#include "reader.h"
#include "sort.h"
#include "student.h"
#include "terminal.h"

// import standard library to current namespace for unqualified(without prefix) use
using std::vector;

vector<Student> students;

int main() {
    clear_term();

    if (!read_students(students)) {
        return 0;
    }
    grade_students(students);
    bubble_sort(students);
    assign_ranks(students);

    print_students_info(students);

    return 0;
}
