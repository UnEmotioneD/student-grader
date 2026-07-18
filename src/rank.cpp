#include <vector>

#include "student.h"

void assign_ranks(std::vector<Student> &students) {
    int n = students.size();

    // Competition ranking:
    // same score = same rank
    // next rank skips tied positions
    students[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if (students[i - 1].tot == students[i].tot) {
            students[i].rank = students[i - 1].rank;
        } else {
            students[i].rank = i + 1;
        }
    }
}
