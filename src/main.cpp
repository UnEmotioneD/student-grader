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
    int no;
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
    ifstream stdFile;
    stdFile.open("./student_scores.txt");

    // Create student class
    Student student;
    list<Student> students;

    // Assign contents of file to string variable
    string stdInfo = "";
    while (getline(stdFile, stdInfo)) {
        int kor = 0;
        int eng = 0;
        int math = 0;

        istringstream iss(stdInfo);
        iss >> student.no >> student.name >> kor >> eng >> math;

        student.kor = kor;
        student.eng = eng;
        student.math = math;
        student.tot = kor + eng + math;
        student.avg = static_cast<float>(student.tot) / 3;

        students.push_back(student);
    }
    stdFile.close();

    for (Student student : students) {
        cout << student.name << " - average score: " << student.avg << endl;
    }

    return 0;
}
