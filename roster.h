#pragma once
#pragma once
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "student.h"

//given data
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Timothy,Eady,teady1@wgu.edu,35,21,14,22,SOFTWARE"
};

//create Roster class
class Roster {
private:

	//create array of pointers
	Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr };

public:

	Roster();
	~Roster();

	int index = 0;
	void Add(string ID, string first, string last, string emailAddress, int setAge, int numDays0, int numDays1, int numDays2, Degree);
	void Remove(string studentID);
	void printAll();
	void printAverage(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);

	Student** getClassRosterArray();
};