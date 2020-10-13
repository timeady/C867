#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// default constructor
Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	email = "";
	age = 0;
	daysToComplete[0] = 0;
	daysToComplete[1] = 0;
	daysToComplete[2] = 0;
}

//full constructor 
Student::Student(string ID, string first, string last, string emailAdd, int Age, int* numDays) {

	studentID = ID;
	firstName = first;
	lastName = last;
	email = emailAdd;
	age = Age;
	daysToComplete[0] = numDays[0];
	daysToComplete[1] = numDays[1];
	daysToComplete[2] = numDays[2];
}


//accessors
string Student::getStudentID()
{
	return studentID;
}
string Student::getFirstName()
{
	return firstName;
}
string Student::getLastName()
{
	return lastName;
}
string Student::getEmail()
{
	return email;
}
int Student::getAge()
{
	return age;
}
int* Student::getDaysToComplete()
{
	return daysToComplete;
}
Degree Student::getDegreeProgram() {
	return Degree::SOFTWARE;
}

//mutators
void Student::setStudentID(string ID)
{
	this->studentID = ID;
}
void Student::setFirstName(string First)
{
	this->firstName = First;
}
void Student::setLastName(string last)
{
	this->lastName = last;
}
void Student::setEmail(string emailAddress)
{
	this->email = emailAddress;
}
void Student::setAge(int setAge)
{
	this->age = setAge;
}

void Student::setDaysToComplete(int numDays0, int numDays1, int numDays2)
{
	this->daysToComplete[0] = numDays0;
	this->daysToComplete[1] = numDays1;
	this->daysToComplete[2] = numDays2;
}

void Student::setDegree(string degree)
{
	degree = degree;
}

void Student::print() {

}

//Destructor
Student::~Student() {}