#pragma once
#include <vector>
#include <memory>
#include "grade.cpp"
using std::vector;


class GradeSheet {

    vector<Grade> grades;

    public:
    GradeSheet();
    void openGradeReportStudent();
    int calculateAverage();
    void openAssignmentReport(int number);
    int getNewAssignmentNumber();
    void addAssignment(std::string assignmentName, int num, int actualGrade, bool isDailyGrade, std::string time);
    std::vector<Grade> getGrades();

};