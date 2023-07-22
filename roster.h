#include "student.h"
#ifndef roster_h
#define roster_h

class Roster
{
public:
    int index = -1;
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable]; //The array of pointers created to hold the data provided in the “studentData Table” is complete and is correct.
    void parse(string tableRow);
    void add(string sStudID, string sFirstName, string sLastName, string sEmailAdd, int sAge, int day1, int day2, int day3, DegreeProgram dp); //The student object for each student in the classRosterArray is correctly populated
    void printAll();
    void printByDegreeProgram(DegreeProgram dp);
    void printInvalidEmails(); 
    void printAverageDays(string studID);
    bool removeStudentByID(string studID);
    ~Roster();
};


#endif