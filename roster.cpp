#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include "roster.h"
#include<iomanip>

using namespace std;

Roster::Roster() {}

int main() {

	//Print course and personal information
	cout << "C867 - Scripting and Programming - Applications" << endl;
	cout << "This program was written in C++" << endl;
	cout << "Student ID #: 001141627" << endl;
	cout << "Name: Timothy Eady" << endl;

	//create roster
	Roster classRoster;
	//create degree
	Degree degreeObject = SOFTWARE;

	int i = 0;

	//create student objects for each student and assign Degree
	for (i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++)
	{

		string input = studentData[i];
		istringstream ss(input);
		string token;
		string hold[9];

		int x = 0;
		while (getline(ss, token, ','))
		{
			hold[x] = token;
			x += 1;
		}
		if (hold[8] == "SECURITY")
		{
			degreeObject = Degree::SECURITY;
		}
		else if (hold[8] == "SOFTWARE")
		{
			degreeObject = Degree::SOFTWARE;
		}
		else if (hold[8] == "NETWORK")
		{
			degreeObject = Degree::NETWORKING;
		}
		classRoster.Add(hold[0], hold[1], hold[2], hold[3], stoi(hold[4]), stoi(hold[5]),
			stoi(hold[6]), stoi(hold[7]), degreeObject);
	}

	classRoster.printAll();
	
	for (i = 0; i < 5; i++) 
	{
		classRoster.printAverage(classRoster.getClassRosterArray()[i]->getStudentID());
	}
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster.Remove("A3");
	classRoster.Remove("A3");
	system("pause");
}
//update classRosterArray
void Roster::Add(string ID, string first, string last, string emailAddress, int setAge, int numDays0, int numDays1, int numDays2, Degree degreeProg)
{
	int averageDays[3] = { numDays0, numDays1, numDays2 };

	if (degreeProg == NETWORKING) {
		classRosterArray[index] = new NetworkStudent(ID, first, last, emailAddress, setAge, averageDays, degreeProg);
	}
	else if (degreeProg == SECURITY) {
		classRosterArray[index] = new SecurityStudent(ID, first, last, emailAddress, setAge, averageDays, degreeProg);
	}
	else if (degreeProg == SOFTWARE) {
		classRosterArray[index] = new SoftwareStudent(ID, first, last, emailAddress, setAge, averageDays, degreeProg);
	}
	index = index + 1;

}

void Roster::Remove(string studentID) 
{
	bool remove = false;
	int i = 0;

	for (i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) 
	{
		if (classRosterArray[i] != nullptr && (*classRosterArray[i]).getStudentID() == studentID) 
		{
			classRosterArray[i] = nullptr;
			remove = true;
			break;
		}
	}

	if (remove == false) 
	{
		cout << "The student ID " << studentID << " was not found." << endl;
	}
}

void Roster::printAll() 
{
	cout << endl;
	cout << endl;
	int i;
	for (i = 0; i < 5; i++) {
		(*classRosterArray[i]).print();
	}
	cout << endl;
}

//print average 
void Roster::printAverage(string studentID)
{
	float averageDays = 0;
	int maximumValue = 3;

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			int* daysInCourse = classRosterArray[i]->getDaysToComplete();
			for (int x = 0; x < maximumValue; x++) {
				averageDays += daysInCourse[x];
			}

			cout << "Student ID " << classRosterArray[i]->getStudentID() << " has an average of " << (averageDays / maximumValue) << " days to complete 3 courses." << endl;
			break;
		}
	}
}

//print invalid emails
void Roster::printInvalidEmails() 
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i)
	{
		string invalidEmails = classRosterArray[i]->getEmail();
		int none = -1;

		if ((invalidEmails.find("@") == none) || (invalidEmails.find(".") == none) || !(invalidEmails.find(" ") == none)) 
		{
			cout << invalidEmails << " is an invalid email" << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(Degree SOFTWARE) 
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == SOFTWARE) 
		{
			classRosterArray[i]->print();
		}
	}
}


Student** Roster::getClassRosterArray()
{
	return classRosterArray;
}

//class destructor
Roster::~Roster()
{

	for (int i = 0; i < 5; i++) 
	{
		if (classRosterArray[i] != nullptr) 
		{
			delete classRosterArray[i];
		}
	}
}