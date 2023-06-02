#include <iostream>
#include <iomanip>
#include <vector>
#include "gradesheet.hpp"
#include <string>

GradeSheet::GradeSheet() : grades() {};

void GradeSheet::openGradeReportStudent() {
    std::cout << std::setw(25) << std::left << "ASSIGNMENT NAME" << std::setw (3) << "" << std::setw (8) << std::left << "GRADE" << std::endl;
    std::cout << "\n";
    if (grades.empty()) {
        std::cout << "Looks like you don't have any grades here!\n";
        std::cout << "Your average is a 100\n";
        return;
    }
    for (auto grade : grades) {
        std::cout << grade.assignmentNumber << ") " << std::setw(25) << std::left << grade.name << std::setw (3) << "" << std::setw (8) << std::left << grade.points << std::endl;
    }
    std::cout << "AVERAGE: " << calculateAverage() << "\n" << std::endl;

    while (true) {
        std::cout << "What would you like to do next?\n";
        std::cout << "1) Look at a Specific Assignment\n";
        std::cout << "2) Back\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Fetching assignment...\n\n";
            openAssignmentReport(choice);
        } else if (choice == 2) {
            break;
        } else {
            std::cout << "That wasn't an option.\n";
        }
        }
    }

void GradeSheet::openAssignmentReport(int number) {
    bool assignmentFound = false;
    for (auto grade : grades) {
        if (grade.assignmentNumber == number) {
            assignmentFound = true;
            std::cout << "ASSIGNMENT NAME: " << grade.name << "\n";
            std::cout << "ASSIGNMENT DATE: " << grade.date << "\n";
            std::cout << grade.points << " out of 100\n";
            //may be an error here bc there might need to be parenthesis
            grade.dailyGrade ? std::cout << "Daily Grade\n" : std::cout << "Major Grade\n";
            if (grade.status != "") {
                std::cout << "STATUS: " << grade.status << "\n";
            }
        }
    }
    if (!assignmentFound) {
        std::cout <<  "We could not find your assignment! Sorry." << std::endl;
    }
}

int GradeSheet::calculateAverage() {

    if (grades.empty()) {
        return 0;
    }

    int totalPointsDaily = 0;
    int totalPointsMajor = 0;
    int totalNumDaily = 0;
    int totalNumMajor = 0;
    for (auto grade : grades) {
        if (grade.dailyGrade) {
            totalNumDaily++;
            totalPointsDaily += grade.points;
        } else {
            totalNumMajor++;
            totalPointsMajor += grade.points;
        }
    }

    if (totalNumDaily == 0) {
        return totalPointsMajor / totalNumMajor;
    } else if (totalNumMajor == 0) {
        return totalPointsDaily / totalNumDaily;
    } else {
        
    double dailyAvg = totalPointsDaily / totalNumDaily;
    double majorAvg = totalPointsMajor / totalNumMajor;

    return (dailyAvg + majorAvg) / 2;
    }

}

int GradeSheet::getNewAssignmentNumber() {
    return grades.size() + 2;
}

void GradeSheet::addAssignment(std::string assignmentName, int num, int actualGrade, bool isDailyGrade, std::string time) {
    Grade g = {assignmentName, num, actualGrade, isDailyGrade, time};
    grades.push_back(g);
    std::cout << g.name << std::endl;
    std::cout << grades[0].name << std::endl;
}

std::vector<Grade> GradeSheet::getGrades() {
    return grades;
}