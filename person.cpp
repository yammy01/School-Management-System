#include <iostream>
#include "person.hpp"
using std::string, std::cin, std::cout, std::endl;


Person::Person(string name1, string name2, int old, string user, string pass) {
    firstName = name1;
    lastName = name2;
    age = old;
    username = user;
    password = pass;
}

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

string Person::getFullName() {
    return firstName + " " + lastName;
}

int Person::getAge() {
    return age;
}

void Person::changeUser() {
    cout << "What would you like your new username to be?" << endl;
    string newUser;
    cin >> newUser;
    username = newUser;
    cout << "Changed! Your username is now " << username << ".\n\n";
}

string Person::getUser() {
    return username;
}

void Person::changePassword() {
    cout << "What's your current password?" << endl;
    string attemptPass;
    cin >> attemptPass;
    if (attemptPass == getPassword()) {
        bool matching = false;
        while (!matching) {
            cout << "What do you want your new password to be?" << endl;
            string newPass1;
            cin >> newPass1;
            cout << "Please reenter your new password for verification." << endl;
            string newPass2;
            cin >> newPass2;
            if (newPass1 == newPass2) {
                cout << "Your password matches!" << endl;
                password = newPass1;
                cout << "Password successfully changed." << endl;
                cout << "\n";
                break;
            } else {
                cout << "Sorry, your passwords didn't match." << endl;
                cout << "You need to go through this process again." << endl;
                cout << "\n";
            }
        }
    } else {
        cout << "Sorry, that's the incorrect password." << endl;
    }
}

string Person::getPassword() {
    return password;
}
