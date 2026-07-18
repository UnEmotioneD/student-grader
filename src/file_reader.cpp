#include <vector>

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "config.h"
#include "file_reader.h"
#include "student.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ifstream;
using std::istringstream;
using std::runtime_error;

void read_students_info(std::vector<Student> &students) {
    ifstream ifs;

    try {
        ifs.open(students_file);
        if (!ifs.is_open()) {
            throw runtime_error("Failed to open: " + students_file);
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

        cout << "Successfully read: " << students_file << "\n" << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
}
