#include <iostream>
#include "login.hpp"
#include "person.hpp"
#include "student.hpp"
#include "teacher.hpp"
#include "gradesheet.hpp"
using std::endl, std::cout, std::cin;



void Login::login() {
    Teacher::addDefaultTeacher();
    Student::createDefaultStudent();
    while (true) {
        cout << "Welcome to your new school login system!\n";
        cout << "Are you logging in or do you need to create an account?\n";
        cout << "1) Log in\n";
        cout << "2) Create an account\n";
        int choice;
        cin >> choice;
        // add a try and catch thing here
        if (choice == 1) {
            cout << "Are you a student or a teacher?\n";
            cout << "1) Student\n";
            cout << "2) Teacher" << endl;
            int studentOrTeacher;
            cin >> studentOrTeacher;
            if (studentOrTeacher == 1) {
                cout << "What is your username?" << endl;
                string username;
                cin >> username;
                if (Student::findStudent(username) == nullptr) {
                    cout << "Account was not found\n";
                } else {
                    auto studentAccount = Student::findStudent(username);
                    cout << "Account has been found!\n";
                    cout << "What is your password?" << endl;
                    bool passwordPass = false;
                    int attemptsLeft = 3;
                    while (!passwordPass && attemptsLeft != 0){
                    string passwordAttempt;
                    cin >> passwordAttempt;
                    if (passwordAttempt == studentAccount -> getPassword()) {
                        cout << "Correct password!\n";
                        passwordPass = true;
                        studentAccount -> dashboard();
                    } else {
                        attemptsLeft--;
                        cout << "Password was incorrect. You get " << attemptsLeft << " attempts left." << endl;
                    }
                    //if there are too many failed password attempts, they have to resign in with their username
                    }
                }
            } else if (studentOrTeacher == 2) {
                cout << "What is your username?\n";
                string username;
                cin >> username;
                if (Teacher::findTeacher(username) == nullptr) {
                    std::cout << "Sorry this account was not found.\n";
                } else {
                    auto teacherAccount = Teacher::findTeacher(username);
                    cout << "Account has been found!\n";
                    cout << "What is your password?\n";
                    bool passwordPass = false;
                    int attemptsLeft = 3;
                    while (!passwordPass && attemptsLeft != 0) {
                        string passwordAttempt;
                        cin >> passwordAttempt;
                        if (passwordAttempt == teacherAccount -> getPassword()) {
                            cout << "Correct Password!\n";
                            passwordPass = true;
                            teacherAccount -> dashboard();
                        } else {
                            attemptsLeft--;
                            cout << "Password was incorrect. You have " << attemptsLeft << " attempts left.\n";
                        }
                    }
                }
        } else {

        }

        } else if (choice == 2) {
            cout << "Are you a student or a teacher?\n";
                cout << "1) Student\n";
                cout << "2) Teacher" << endl;
                int studentOrTeacher;
                cin >> studentOrTeacher;
                if (studentOrTeacher == 1) {
                    auto currentAccount = Student::createStudent();
                    //currentAccount -> getTeacher() -> addStudent(currentAccount);
                    currentAccount -> dashboard();
                } else if (studentOrTeacher == 2) {
                    auto currentAccount = Teacher::createTeacher();
                    currentAccount -> dashboard();
                } else {
                    cout << "You didn't choose student or teacher.\n";
                }
            }
        }
    }