#include <iostream>
#include "roster.h"
using namespace std;

//The course title, programming language used, WGU student ID, and student name are all correctly printed at the top.
int main()
{
    cout << "C867 - Scripting and Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 006868740" << endl;
    cout << "Name: Brandon Robinson\n" << endl;
    
    //Personal information in the last item of the “studentData Table” is complete.
    const string studentData[] =
        {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
            "A5,Brandon,Robinson,brob538@wgu.edu,31,30,90,10,SOFTWARE"
        };
        
    const int studentDataTable = 5;
    Roster roster;
        
    //All pseudo code is correctly converted to complete the rest of the main() function and is in order. All can be seen below.
    //Displays all students
    for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
    cout << "Displaying all students:" << std::endl;
    roster.printAll();
    cout << std::endl;
    
    //Displays all invalid emails
    cout << "Displaying invalid email addess:" << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
    
    //Displays the average days in course per student
    for (int i = 0; i < studentDataTable; i++)
    {
    roster.printAverageDays(roster.classRosterArray[i]->getStudID());
    }
    cout << std::endl;
    
    //Displays all students in the software program
    cout << "Showing students in degree program: SOFTWARE" << std::endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;
    
    //Outputs for the removed student ID A3
    cout << "Removing A3:\n" << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;

    cout << "Removing A3 again\n" << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl << std::endl;
}
