#pragma once
#pragma once
#include "student.h"

//create NetworkStudent subclass of Student
class NetworkStudent : public Student {
public:
	Degree degreeProg = NETWORKING;
	Degree getDegreeProgram() override;
	NetworkStudent();
	NetworkStudent(string, string, string, string, int, int*, Degree);
	void print();
};