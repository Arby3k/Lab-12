#pragma once
#include "stdafx.h"
#include "CStudent.h"
#include <vector>

class CCourse {
	
public:
	std::vector<CStudent> students;
	
	void printMenu();
	void addStudent();
	void editStudent();
	void printStudent();
	void deleteStudent();
	void listStudents();
	void saveFile();
	void loadFile();

	bool errorCheck(std::string grade);
};