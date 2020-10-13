#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent() {}

NetworkStudent::NetworkStudent(string ID, string first, string Last, string emailAddress, int setAge, int* numDays, Degree studentDegree) : Student(ID, first, Last, emailAddress, setAge, numDays) {

	degreeProg = studentDegree;
}

Degree NetworkStudent::getDegreeProgram() {

	return degreeProg;
}

void NetworkStudent::print() {

	cout << getStudentID();
	cout << "\tfirst Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Age: " << getAge();
	cout << "\t" << "daysInCourse: {"; cout << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}";
	cout << "\t Degree Program: NETWORK";
	cout << endl;
}