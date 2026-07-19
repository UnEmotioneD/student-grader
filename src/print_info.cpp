#include <iostream>
#include <vector>

#include "print_info.h"
#include "student.h"

using std::cout;
using std::endl;
using std::vector;

// TODO: Print into table format using border line characters
void print_students_info(vector<Student> &students) {
    cout << "number | name | korean | english | math | total | average | grade "
            "| rank"
         << endl;

    for (Student &student : students) {
        cout << student.num << ' ' << student.name << "\t" << student.kor
             << "\t" << student.eng << "\t" << student.math << "\t"
             << student.tot << "\t" << student.avg << "\t" << student.grade
             << "\t" << student.rank << endl;
    }
}
