#pragma once
#include <vector>
#include <memory>
#include "person.hpp"
using std::vector, std::shared_ptr;

class Student;

class Teacher : public Person {
    
    vector<shared_ptr<Student>> theClass;
    static vector<shared_ptr<Teacher>> teachers;

    public:
    
    Teacher(string name1, string name2, int old, string user, string pass);
    static shared_ptr<Teacher> createTeacher();
    int getSizeOfClass();
    void addStudent(shared_ptr<Student> studentToAdd);
    void accessGradeBook();
    void printAssignmentReport(int assignmentNumber);
    void printStudentReport(int studentNumber);
    void createNewAssignment();
    void dashboard();
    void changeSettings();
    void printInformation();
    static shared_ptr<Teacher> findTeacher(std::string username);
    static shared_ptr<Teacher> findAvailableTeacher(std::string studentUser);
    static void addDefaultTeacher();
    

};

