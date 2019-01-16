#pragma once
#include "stdafx.h"
#include "CStudent.h"
#include <vector>

class CCourse {
	
public:
	void printMenu();
	void addStudent();
	void editStudent();
	void printStudent();
	void deleteStudent();
	void listStudents();
	std::vector<CStudent> students;
	
	bool errorCheck(std::string grade);
};