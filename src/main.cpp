// Copyright (c) 2025 UnEmotioneD

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::list;
using std::string;

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

void clearTerm() {
    // cross platform on modern OSs
    cout << "\x1B[2J\x1B[H" << std::flush;
    // \x1B[2J   : erase entire screen
    // \x1B[H    : move cursor to top-left
    // std:flush : force output buffer to write immediately
}

int main() {
    clearTerm();

    // Read file
    ifstream studentFile;
    studentFile.open("./student_scores.txt");

    // Create student class
    Student student;
    list<Student> students;

    // Assign contents of file to string variable
    string studentInfo = "";

    // read from studentFile
    // for each line
    // assign it to studentInfo
    while (getline(studentFile, studentInfo)) {
        istringstream iss(studentInfo);
        iss >> student.num >> student.name >> student.kor >> student.eng >>
            student.math;

        // adds student object to students list
        students.push_back(student);
        studentInfo = "";
    }
    studentFile.close();

    for (Student student : students) {
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

    return 0;
}
