#include <iostream>
#include <utility>
#include <vector>

#include "sort.h"
#include "student.h"

using std::cout;
using std::endl;
using std::swap;
using std::vector;

void bubble_sort(vector<Student> &students) {
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

                swap(students[k], students[k + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }

    cout << "Sorted high to low" << "\n" << endl;
}
