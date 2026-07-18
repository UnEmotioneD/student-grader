// Copyright (c) 2025 UnEmotioneD

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

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

class Student {
  public:
    int num;
    string name;
    int kor;
    int eng;
    int math;
    int tot;
    float avg;
    char grade;
    int rank;
};

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

        cout << "Successfully read: " << student_scores << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    // use reference to modify original values
    for (Student &student : students) {
        student.tot = student.kor + student.eng + student.math;
        student.avg = static_cast<float>(student.tot) / 3;

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

        cout << student.name << " - total: " << student.tot
             << " | average: " << student.avg << " | grade: " << student.grade
             << endl;
    }

    // sorting
    int n = students.size();
    bool swapped = false;
    for (int j = 0; j < n - 1; j++) {
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

    cout << "\n==============================" << endl;
    cout << "Sorted" << endl;
    cout << "==============================\n" << endl;

    // use reference to get the original values
    for (Student &student : students) {
        cout << student.name << " - average: " << student.avg
             << " | grade: " << student.grade << endl;
    }

    return 0;
}
