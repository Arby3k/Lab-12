#pragma once
#include "stdafx.h"
#include "CStudent.h"
#include <vector>
#include <fstream>

class CCourse {
	
public:

	
	void printMenu();
	void addStudent();
	void editStudent();
	void printStudent();
	void deleteStudent();
	void listStudents();
	void saveFile();
	void loadFile();

	bool errorCheck(std::string grade);

private: 
	std::vector<CStudent> students;
};