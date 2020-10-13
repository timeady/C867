#pragma once
#include "student.h"

//create SoftwareStudent subclass of Student
class SoftwareStudent : public Student {
public:
	Degree degreeProg = SOFTWARE;
	Degree getDegreeProgram() override;
	void print();
	SoftwareStudent();
	SoftwareStudent(string, string, string, string, int, int*, Degree);
};