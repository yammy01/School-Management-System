#include <string>

struct Grade {

    //cut the assignmentName if it's too long
    std::string name;
    int assignmentNumber;
    int points; //out of 100
    bool dailyGrade;
    std::string status;
    std::string date;

};