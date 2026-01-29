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

int main() {
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
    // assign it to stdudentInfo
    while (getline(studentFile, studentInfo)) {
        istringstream iss(studentInfo);
        iss >> student.num >> student.name >> student.kor >> student.eng >>
            student.math;

        student.tot = student.kor + student.eng + student.math;
        student.avg = static_cast<float>(student.tot) / 3;

        students.push_back(student);
        studentInfo = "";
    }
    studentFile.close();

    for (Student student : students) {
        cout << student.name << " - average score: " << student.avg << endl;
    }

    return 0;
}
