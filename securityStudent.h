#pragma once
#include "student.h"

//create SecuritySTudent subclass of Student
class SecurityStudent : public Student {
public:
	//override
	Degree getDegreeProgram() override;
	Degree degreeProg = SECURITY;
	void print();
	SecurityStudent();
	SecurityStudent(string, string, string, string, int, int*, Degree);
};