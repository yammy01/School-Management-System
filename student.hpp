#pragma once
#include <vector>
#include <string>
#include <memory>
#include "person.hpp"
using std::string, std::vector, std::shared_ptr;

class Teacher;
class GradeSheet;

class Student : public Person {

    shared_ptr<GradeSheet> grades;
    shared_ptr<Teacher> studentsTeacher;
    int fees;
    static vector<shared_ptr<Student>> students;
    int classNumber;

    public:
    
    Student(string name1, string name2, int old, string user, string pass, shared_ptr<GradeSheet> grade);
    static shared_ptr<Student> createStudent();
    static void createDefaultStudent();
    static shared_ptr<Student> findStudent(string username);
    void findTeacher();
    void dashboard();
    shared_ptr<GradeSheet> getStudentsGradebook();
    shared_ptr<Teacher> getTeacher();
    int getClassNumber();
    void changeSettings();
    void printInformation();

};
