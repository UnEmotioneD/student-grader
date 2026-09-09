#include <iostream>
#include <vector>

#include "../include/print_info.h"
#include "../include/student.h"

using std::cout;
using std::endl;
using std::vector;

// TODO: Print into table format using border line characters
void print_students_info(vector<Student> &students) {
    cout << "number | name | korean | english | math | total | average | grade "
            "| rank"
         << endl;

    for (Student &student : students) {
        cout << student.num << ' ' << student.name << ' ' << student.kor << ' '
             << student.eng << ' ' << student.math << ' ' << student.tot
             << ' ' << student.avg << ' ' << student.grade << ' '
             << student.rank << endl;
    }
}
