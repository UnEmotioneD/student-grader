#include <vector>

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "config.h"
#include "reader.h"
#include "student.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ifstream;
using std::istringstream;
using std::runtime_error;
using std::vector;

bool read_students(vector<Student> &students) {
    ifstream ifs;
    bool is_read = false;

    try {
        ifs.open(STUDENTS_FILE);
        if (!ifs.is_open()) {
            throw runtime_error("Failed to open: " + STUDENTS_FILE);
        }

        Student student;
        string student_info;

        // each line from file to studentInfo
        while (getline(ifs, student_info)) {
            // parse line into student fields using string stream
            istringstream iss(student_info);
            iss >> student.num >> student.name >> student.kor >> student.eng >>
                student.math;

            // adds student object to students list
            students.push_back(student);
            student_info = "";
        }
        ifs.close();

        if (students.empty()) {
            cerr << "Error: " << STUDENTS_FILE << " is empty." << endl;
        } else {
            is_read = true;
            cout << "Successfully read: " << STUDENTS_FILE << "\n" << endl;
        }
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return is_read;
}
