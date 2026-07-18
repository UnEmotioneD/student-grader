// Copyright (c) 2025 UnEmotioneD

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "bubble_sort.h"
#include "grading.h"
#include "print_info.h"
#include "student.h"
#include "terminal.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ifstream;
using std::istringstream;
using std::runtime_error;
using std::string;
using std::vector;

string student_scores = "./student_scores.txt";

int main() {
    clear_term();

    // Create student class
    Student student;
    vector<Student> students;

    // Read file
    ifstream student_file;

    try {
        student_file.open(student_scores);
        if (!student_file.is_open()) {
            throw runtime_error("Failed to open: " + student_scores);
        }

        string student_info = "";
        // each line from file to studentInfo
        while (getline(student_file, student_info)) {
            // parse line into student fields using string stream
            istringstream iss(student_info);
            iss >> student.num >> student.name >> student.kor >> student.eng >>
                student.math;

            // adds student object to students list
            students.push_back(student);
            student_info = "";
        }
        student_file.close();

        cout << "Successfully read: " << student_scores << "\n" << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    grade_students(students);
    bubble_sort_students(students);
    print_students_info(students);

    return 0;
}
