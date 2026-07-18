#include <iostream>
#include <utility>
#include <vector>

#include "bubble_sort.h"
#include "student.h"

void bubble_sort_students(std::vector<Student> &students) {
    int n = students.size();
    bool swapped = false;

    for (int j = 0; j < n - 1; j++) {
        swapped = false;

        for (int k = 0; k < n - j - 1; k++) {
            // high to low
            if (students[k].tot < students[k + 1].tot) {
                // Student tmp = students[k];
                // students[k] = students[k + 1];
                // students[k + 1] = tmp;

                std::swap(students[k], students[k + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }

    std::cout << "Sorted high to low" << "\n" << std::endl;
}
