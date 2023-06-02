#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "student.hpp"
#include "teacher.hpp"
#include "gradesheet.hpp"
using std::string, std::cout, std::vector, std::shared_ptr, std::cin, std::endl;

vector<shared_ptr<Student>> Student::students;

Student::Student(string name1, string name2, int old, string user, string pass, shared_ptr<GradeSheet> grade) : Person(name1, name2, old, user, pass), grades(grade) {}

shared_ptr<Student> Student::createStudent() {
    cout << "What is your first name?" << endl;
    string firstName;
    cin >> firstName;
    cout << "What is your last name?" << endl;
    string lastName;
    cin >> lastName;
    cout << "What is your age?" << endl;
    int age;
    cin >> age;
    cout << "What do you want your username to be?" << endl;
    string username;
    cin >> username;
    cout << "What will your password be?" << endl;
    string password;
    cin >> password;
    
    auto studentsGrades = std::make_shared<GradeSheet>();
    auto student = std::make_shared<Student>(firstName, lastName, age, username, password, studentsGrades);
    students.push_back(student);
    return student;
}

void Student::createDefaultStudent() {
    auto studentGradesheet = std::make_shared<GradeSheet>();
    auto defaultStudent = std::make_shared<Student>("Jacob", "Yan2", 16, "jacobb", "yann", studentGradesheet);
    students.push_back(defaultStudent);
    defaultStudent -> findTeacher();
}

shared_ptr<Student> Student::findStudent(string username) {
    for (auto student : students) {
        if (student -> getUser() == username) {
            return student;
        }
    }
    return nullptr;
}

shared_ptr<GradeSheet> Student::getStudentsGradebook() {
    return grades;
}

void Student::findTeacher() {
    cout << "Finding teacher...\n";
    studentsTeacher = Teacher::findAvailableTeacher(username);
    classNumber = (studentsTeacher -> getSizeOfClass());
    
    cout << "Your teacher's name is " << studentsTeacher -> getFirstName() << "!\n";
}

shared_ptr<Teacher> Student::getTeacher() {
    return studentsTeacher;
}

int Student::getClassNumber() {
    return classNumber;
}

void Student::dashboard() {
    bool stayIn = true;
    while(stayIn) {
        cout << "\nWelcome " << firstName << "!\n";
        cout << "What would you like to do today?\n";
        cout << "1) Check Grades\n";
        cout << "2) Edit Profile/Settings\n";
        cout << "3) Logout\n";
        int choice;
        cin >> choice;
        switch(choice) {
        case 1:
        {
            cout << "Retrieving grades...\n\n";
            grades -> openGradeReportStudent();
            break;
        }
        case 2:
            changeSettings();
            break;
        case 3:
        {
            cout << "Logging out...\n";
            stayIn = false;
            break;
        }
        }
    }
}

void Student::changeSettings() {
    printInformation();
    std::cout << "What would you like to do?\n";
    if (studentsTeacher == nullptr) {
        cout << "1) Change Username\n";
        cout << "2) Change Password\n"; 
        cout << "3) Find a teacher" << endl;
    
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            changeUser();
            break;
        case 2:
            changePassword();
            break;
        case 3: {
            findTeacher();
            cout << "Your teacher is " << studentsTeacher -> getFullName() << endl;
        }
        default:
            cout << "That wasn't an option.\n";
            break;
        }
    } else {
        cout << "1) Change Username\n";
        cout << "2) Change Password\n";
        int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            changeUser();
            break;
        case 2:
            changePassword();
            break;
        default:
            cout << "That wasn't an option.\n";
            break;
        }
    }

}

void Student::printInformation() {
    cout << "First name: " << firstName << "\n";
    cout << "Last name: " << lastName << "\n";
    cout << "Username: " << username << "\n";
    cout << "Age: " << age << "\n";
    if (studentsTeacher != nullptr) {
        cout << "Teacher's name: " << studentsTeacher -> getFullName() << endl;
    }
}

