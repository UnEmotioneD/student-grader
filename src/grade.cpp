#include <iostream>
#include <math.h>
#include <vector>

#include "grade.h"
#include "student.h"

using std::cout;
using std::endl;
using std::round;

void grade_students(std::vector<Student> &students) {
    // use reference to modify original values
    for (Student &student : students) {
        student.tot = student.kor + student.eng + student.math;
        student.avg =
            round((static_cast<float>(student.tot) / 3.0f) * 100.0f) / 100.0f;

        // assign grades by avg score
        if (student.avg >= 90.0) {
            student.grade = 'A';
        } else if (student.avg >= 80.0) {
            student.grade = 'B';
        } else if (student.avg >= 70.0) {
            student.grade = 'C';
        } else if (student.avg >= 60.0) {
            student.grade = 'D';
        } else {
            student.grade = 'F';
        }
    }

    cout << "Grades assigned" << "\n" << endl;
}
