#include <iostream>
#include <string>
#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent() {}

SoftwareStudent::SoftwareStudent(string ID, string first, string last, string emailAddress, int setAge, int* numDays, Degree studentDegree) : Student(ID, first, last, emailAddress, setAge, numDays) {

	degreeProg = studentDegree;
}

Degree SoftwareStudent::getDegreeProgram()
{
	return degreeProg;
}

void SoftwareStudent::print() {

	cout << getStudentID();
	cout << "\tFirst Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Age: " << getAge();
	cout << "\t" << "daysInCourse: {"; cout << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}";
	cout << "\t Degree Program: SOFTWARE";
	cout << endl;
}