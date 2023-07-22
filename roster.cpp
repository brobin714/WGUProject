#include <string>
#include "roster.h"
using namespace std;

//The data is parsed correctly.
void Roster::parse(string studentdata)
{
    //Parses student ID
    int i = studentdata.find(',');
    string sStudID = studentdata.substr(0, i);
    
    //Parses first name
    int j = i + 1;
    i = studentdata.find(',', j);
    string sFirstName = studentdata.substr(j, i - j);
    
    //Parses last name
    j = i + 1;
    i = studentdata.find(',', j);
    string sLastName = studentdata.substr(j, i - j);
    
    //Parses email address
    j = i + 1;
    i = studentdata.find(",", j);
    string sEmailAdd = studentdata.substr(j, i - j);
    
    //Parses age
    j = i + 1;
    i = studentdata.find(",", j);
    int sAge = stoi(studentdata.substr(j, i - j));
    
    //Parses the first number of days
    j = i + 1;
    i = studentdata.find(",", j);
    int day1 = stod(studentdata.substr(j, i - j));
    
    //Parses the second number of days
    j = i + 1;
    i = studentdata.find(",", j);
    int day2 = stod(studentdata.substr(j, i - j));
    
    //Parses the third number of days
    j = i + 1;
    i = studentdata.find(",", j);
    int day3 = stod(studentdata.substr(j, i - j));
    
    //Parses the degree program
    j = i + 1;
    i = studentdata.find(",", j);
    DegreeProgram dp  = SECURITY;
    if (studentdata.at(j) == 'S' && studentdata.at(j + 1) == 'E') dp = SECURITY;
    else if (studentdata.at(j) == 'S' && studentdata.at(j + 1) == 'O') dp = SOFTWARE;
    else if (studentdata.at(j) == 'N') dp = NETWORK;
    
    //Each student object is correctly added to the classRosterArray.
    add(sStudID, sFirstName, sLastName, sEmailAdd, sAge, day1, day2, day3, dp);
}

//The public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,DegreeProgram degreeprogram) function is correctly defined to set the instance variables from part D1 and update the roster.
void Roster::add(string studID, string firstName, string lastName, string emailAdd, int age, int day1, int day2, int day3, DegreeProgram dp)
{
    int daysComp[3] = {day1, day2, day3};
    classRosterArray[++index] = new Student(studID, firstName, lastName, emailAdd, age, daysComp, dp);
}

//The public void remove(string studentID) that removes students from the roster by student ID is correctly defined.
bool Roster::removeStudentByID(string studID)
{
    bool success = false;
    for (int i=0; i <= Roster::index; i++)
    {
        if (classRosterArray[i]->getStudID() == studID)
        {
            success = true;
            if (i < studentDataTable - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
                classRosterArray[studentDataTable - 1] = temp;
            }
            Roster::index--;
        }
    }
    if (success)
    {
        this->printAll();
    }
    else cout << "The student with ID: " << studID << " was not found." << std::endl << std::endl;;
    return 0;
}

//The public void printAll() prints a complete tab-separated list of student data. The printAll() correctly loops through all of the students in the student list and correctly calls the print() function for each student.
void Roster::printAll()
{
    
    for (int i = 0; i <= Roster::index; i++) Roster::classRosterArray[i]->print();
}

//A public void printAverageDaysInCourse(string studentID) correctly prints a student’s average number of days in the 3 courses by student ID. The student is correctly identified by the student-ID parameter.
void Roster::printAverageDays(string studID)
{
    for (int i = 0; i <= Roster::index; i++)
    {
        if (classRosterArray[i]->getStudID()==studID)
        {
            cout << "student ID: " << studID << ", average days in course is: ";
            cout << (classRosterArray[i]->getDays()[0]+
                     classRosterArray[i]->getDays()[1]+
                     classRosterArray[i]->getDays()[2])/3 << std::endl;
        }
    }
}

//A public void printInvalidEmails() correctly verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::index; i++)
    {
        string emailAdd = (classRosterArray[i]->getEmailAdd());
        if ((emailAdd.find("@") == string::npos) || (emailAdd.find(" ") != string::npos) || (emailAdd.find(".") == string::npos))
        {
            any = true;
            cout << emailAdd << " - is invalid" << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

//A public void printByDegreeProgram (DegreeProgram degreeProgram) correctly prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram dp)
{
    
    for (int i = 0; i <= Roster::index; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
    }
    
}

//The Roster memory is released by implementing the destructor.
Roster::~Roster()
{
    
    for (int i=0; i < studentDataTable; i++)
    {
        
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}