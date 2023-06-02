#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
using std::string, std::shared_ptr;
#include "teacher.hpp"
#include "student.hpp"
#include "gradesheet.hpp"
//REMEMBER TO PUT A DEFAULT TEACHER
using std::cout, std::endl, std::cin;
vector<shared_ptr<Teacher>> Teacher::teachers;

Teacher::Teacher(string name1, string name2, int old, string user, string pass) : Person(name1, name2, old, user, pass) {}

shared_ptr<Teacher> Teacher::createTeacher() {
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
    auto teacherMade = std::make_shared<Teacher>(firstName, lastName, age, username, password);
    teachers.push_back(teacherMade);
    return teacherMade;
}

int Teacher::getSizeOfClass() {
    return (theClass.size());
}

void Teacher::addStudent(shared_ptr<Student> studentToAdd) {
    theClass.push_back(studentToAdd);

}

void Teacher::accessGradeBook() {
    std::cout << "I am now printing your gradebook of students.\n\n";
    cout << "#  " <<  std::setw(25) << std::left << "NAME" << std::setw(7) << std::left << "AVERAGE" << endl;
    cout << "\n";
    for (auto student : theClass) {
        cout << std::setw(3) << std::left << student -> getClassNumber() << std::setw(25) << std::left << student -> getFullName() << std::setw(7) << (student -> getStudentsGradebook() -> calculateAverage()) << endl;
    }
    cout << "\n";
    bool continueLoop = true;
    while(continueLoop) {
    std::cout << "What would you like to do next?\n";
    std::cout << "1) Look at a specific student\n";
    std::cout << "2) Look at assignments\n";
    std::cout << "3) Create a new assignment\n";
    std::cout << "4) Go back\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            std::cout << "What is the number of the student whom you wish to look at?\n";
            int studentNum;
            std::cin >> studentNum;
            printStudentReport(studentNum);
        }
        case 2: {
            std::cout << "Sorry I haven't added this feature!\n\n";
            break;
        }
        case 3: {
            createNewAssignment();
        }
        case 4:
        {
        std::cout << "Going back\n";
        continueLoop = false;
        }
        break;
        
        default:
        std::cout << "That doesn't exist.\n";
        break;
    }
    
    }
}

void Teacher::printAssignmentReport(int assignmentNumber) {
    //the ex gradebook is from the first student in the class, unless there is none
    auto exampleGradebook = theClass[0] -> getStudentsGradebook();
    
}

shared_ptr<Teacher> Teacher::findTeacher(string username) {
    for (auto teacher : teachers) {
        if (teacher -> getUser() == username) {
            return teacher;
        }
    }
    return nullptr;
}

void Teacher::addDefaultTeacher() {
    auto defaultTeacher = std::make_shared<Teacher>("Jacob", "Yan", 30, "jacobyan", "haha");
    teachers.push_back(defaultTeacher);

}

void Teacher::printStudentReport(int studentNumber) {
    auto currentGradeBook = theClass[studentNumber - 1] -> getStudentsGradebook();
    currentGradeBook -> openGradeReportStudent();
    
}

void Teacher::createNewAssignment() {
    std::cout << "What is your assignment's name?\n";
    std::string assignmentName;
    std::cin >> assignmentName;
    std::cout << "What is the date of creation?\n";
    std::string date;
    std::cin >> date;
    std::cout << "Is this a daily grade? Y/N\n";
    bool dailyGrade;
    char response;
    std::cin >> response;
    if (response == 'Y') {
        dailyGrade = true;
    } else if (response == 'N') {
        dailyGrade = false;
    } else {
        std::cout << "That was not an option.\n";
    }
    auto firstGradeBook = theClass[0] -> getStudentsGradebook();
    int newAssignmentNumber = firstGradeBook -> getNewAssignmentNumber();

    for (auto student : theClass) {
        std::cout << "What is " << student -> getFirstName() << "'s grade?\n";
        int studentGrade;
        std::cin >> studentGrade;
        student -> getStudentsGradebook() -> addAssignment(assignmentName, newAssignmentNumber, studentGrade, dailyGrade, date);
    }

    std::cout << "Grade Addition Complete!\n";

}

shared_ptr<Teacher> Teacher::findAvailableTeacher(string studentUser) {
    
    auto teacherWithLeast = teachers[0];
    for (int i = 0; i < teachers.size(); i++) {
        if (teachers[i] -> theClass.size() < teacherWithLeast -> theClass.size()) {
            teacherWithLeast = teachers[i];
        }
    }
    teacherWithLeast -> addStudent(Student::findStudent(studentUser));

    return teacherWithLeast;
}

void Teacher::printInformation() {
    cout << "First name: " << firstName << "\n";
    cout << "Last name: " << lastName << "\n";
    cout << "Username: " << username << "\n";
    cout << "Age: " << age << "\n";
    cout << "Class size: " << theClass.size() << "\n";
}

void Teacher::dashboard() {
    bool stayLoggedin = true;
    while(stayLoggedin) {
    cout << "\nWhat would you like to do?\n";
    cout << "1) Edit profile/Settings\n"; 
    cout << "2) Access Gradebook\n";
    cout << "3) Logout\n\n";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            changeSettings();
            break;
        case 2: {
            if (theClass.size() == 0) {
                cout << "Sorry you don't have any students.\n\n";
                break;
            } else {
            accessGradeBook();
            }
            break;
        }
        case 3:
            stayLoggedin = false;
            break;
        default:
            cout << "That wasn't an option.\n\n";
            break;
    }
    }
}

void Teacher::changeSettings() {
    printInformation();
    std::cout << "What would you like to do?\n";
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
            cout << "That wasn't an option.\n\n";
            break;
        }
}
