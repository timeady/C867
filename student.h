#pragma once
#include <string>
#include "degree.h"

using namespace std;

//create baseclass of Student
class Student {
protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[3];

public:
	//accessors
	string getStudentID(); 
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();

	//mutators
	void setStudentID(string studentID);	
	void setFirstName(string firstName);	
	void setLastName(string lastName);	
	void setEmail(string email);	
	void setAge(int age);	
	void setDaysToComplete(int course1, int course2, int course3);
	void setDegree(string degree);

	//constructors
	Student();
	Student(string ID, string first, string last, string emailAdd, int Age, int* numDays);

	//virtual functions
	virtual void print();
	Degree virtual getDegreeProgram();
	
	//destructor
	~Student(); 
};