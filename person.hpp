#pragma once
#include <vector>
#include <string>
using std::string, std::vector;

class Person {

    protected:
    string username;
    string password;
    string firstName;
    string lastName;
    int age;

    public:
    Person(string name1, string name2, int old, string user, string pass);
    
    string getFirstName();
    string getLastName();
    string getFullName();
    int getAge();
    void changeUser();
    string getUser();
    void changePassword();
    string getPassword();
};
