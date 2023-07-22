#ifndef student_h
#define student_h
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

//The class Student is correctly created
class Student
{
public:
    //Sets the array to a constant size of 3 for the total of days to complete a course; ie the 30, 35, 40 under John Smith.
    const static int daysToCompleteArray = 3;

//Correct inclusion of given variables
private:
    string studID;
    string firstName;
    string lastName;
    string emailAdd;
    int age;
    int days[daysToCompleteArray];
    DegreeProgram degreeProgram;
    
public:
    Student(); //constructor with no args
    Student(string studID, string firstName, string lastName, string emailAdd, int age, int days[], DegreeProgram degreeProgram); //constructor with all args
    ~Student(); //destructor
    
    //The accessor function in the Student class for each instance variable from part D1 is functional and is complete. All listed below.
    //The mutator function in the Student class for each instance variable from part D1 is functional or is complete. All listed below. 
    
    //getter and setter for student ID
    string getStudID();
    void setID(string studID);
    
    //getter and setter for first name
    string getFirstName();
    void setFirstName(string FirstName);
    
    //getter and setter for last name
    string getLastName();
    void setLastName(string LastName);
    
    //getter and setter for email address
    string getEmailAdd();
    void setEmailAdd(string emailAdd);
    
    //getter and setter for age
    int getAge();
    void setAge(int age);
    
    //getter and setter for days
    int* getDays();
    void setDays(int days[]);
    
    //getter and setters for degree program
    DegreeProgram getDegreeProgram();
    void setDegreeProgram(DegreeProgram dp);
    
    void print();
};

#endif