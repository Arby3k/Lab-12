#include "Stdafx.h"
#include "CCourse.h"
#include "CStudent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <regex>


using namespace std;


void CCourse::printMenu() {
	std::cout << "**************************************** \n"
		 << "ELEX4618 Grade System, by STUDENT NUMBER \n"
		 << "**************************************** \n\n"
		 << "(A)dd student \n"
		 << "(E)dit student \n"
		 << "(P)rint grades \n"
		 << "(D)elete student \n"
		 << "(L)ist all students \n\n"
		 << "(S)ave to file\n"
		 << "L(O)ad from file\n\n"
		 << "(Q)uit \n"
		 << "\nCommand:";
}

void CCourse::addStudent() {
	CStudent student;
	string testNum;
	string grade;
	regex studentNum("([A]0[0-1][0-9]{6})$");
	
	int invalid_studentNum = 0;
	bool validEntry;
	
	cout << "Adding a student" << endl;
	
	cout << "Student number: ";
	do {
		cin >> testNum; 
		if (regex_match(testNum, studentNum)) {
			student.m_number = testNum;
			invalid_studentNum = 0;
		}
		else {
			cout << "Not Valid Student number\nAcceptable Student#  A00123456  or A01234567\nPlease enter valid student number:";
			invalid_studentNum = 1;
		}
	} while (invalid_studentNum == 1);

	cout << "Lab Grade: ";

	do {

		cin >> grade;
		validEntry = errorCheck(grade);
	
		if (validEntry == true) {
			student.m_lab = stof(grade);
	
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	cout << "Quiz Grade: ";

	do {

		cin >> grade;
		validEntry = errorCheck(grade);

		if (validEntry == true) {
			student.m_quiz = stof(grade);
	
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);
	
	cout << "Midterm grade: ";

	do {

		cin >> grade;
		validEntry = errorCheck(grade);
	
		if (validEntry == true) {
			student.m_midTerm = stof(grade);
		
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);
	
	cout << "Final Exam Grade: ";

	do {

		cin >> grade;
		validEntry = errorCheck(grade);
	
		if (validEntry == true) {
			student.m_final = stof(grade);
	
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	student.m_grade = (((student.m_lab) * 40) + ((student.m_quiz) * 10) + ((student.m_midTerm) * 20) + ((student.m_final) * 30)) / 100;

	this->students.push_back(student);
}

void CCourse::editStudent() {
	int entry = 0;
	string test;
	string grade;
	int invalid_studentNum = 0;
	bool validEntry;
	regex studentNum("([A]0[0-1][0-9]{6})$");


	cout << "Editing a student" << endl;
	cout << "Which student: ";
	cin >> entry;
	
	cout << "New Student Number: ";
	do {
		cin >> test;
		if (regex_match(test, studentNum)) {
			this->students[entry - 1].m_number = test;
			invalid_studentNum = 0;
		}
		else {
			cout << "Not Valid Student number\nAcceptable Student#  A00123456  or A01234567\nPlease enter valid student number:";
			invalid_studentNum = 1;
		}
	} while (invalid_studentNum == 1);

	cout << "New Lab Grade: ";
	
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		
		if (validEntry == true) {
			this->students[entry - 1].m_lab = stof(grade);
		
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	cout << "New Quiz Grade: ";
	
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
	
		if (validEntry == true) {
			this->students[entry - 1].m_quiz = stof(grade);
		
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);
	
	cout << "New Midterm grade: ";
	
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
	
		if (validEntry == true) {
			this->students[entry - 1].m_midTerm = stof(grade);
	
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	cout << "New Final Grade: ";
	
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
	
		if (validEntry == true) {
			this->students[entry - 1].m_final = stof(grade);
	
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	this->students[entry - 1].m_grade = (((this->students[entry - 1].m_lab) * 40) + ((this->students[entry - 1].m_quiz) * 10) + ((this->students[entry - 1].m_midTerm) * 20) + ((this->students[entry - 1].m_final) * 30)) / 100;
}

void CCourse::printStudent() {
	int entry = 0;
	cout << "Printing" << endl;
	cout << "Which student: ";
	cin >> entry;
	this->students[entry - 1].print();
}

void CCourse::deleteStudent() {
	int entry = 0;
	int flag = 0;
	do {
		cout << "Deleting" << endl;
		cout << "Which student: ";
		cin >> entry;
		if ((entry - 1) >= students.size()) {
			cout << "This student doesnt exist please enter another number\n";
		}
		else {
			this->students.erase(this->students.begin() + entry - 1);
			flag = 1;
		}
	} while (!flag);
}

void CCourse::listStudents() {
	cout << "The class has: " << this->students.size() << " student(s)\n";
	cout << setw(3) << "" << setw(15) << "Student#:" << setw(10) << "Lab:" << setw(10) << "Quiz:" << setw(12) << "MidTerm:" << setw(15) << "Final Exam:" << setw(15) << "Final Grade:" << std::endl;
	for (int i = 0; i < this->students.size(); i++) {
		cout << setw(3) << i + 1;
		this->students[i].print();
	}

}

bool CCourse::errorCheck(string grade) {


	float testGrade;
	regex alpha("(^[0-9\.]{1,5})*$");

	if (regex_match(grade, alpha)) {
		testGrade = stof(grade);
		if (testGrade <= 100 && testGrade >= 0) {

			return true;
		}
		else {
			return false;

		}
	}
	else
		return false;
	}

void CCourse::saveFile() {
	string fileName;
	string fileType = ".txt";
	cout << "\nName Save file\n";
	cin >> fileName;
	fileName.append(fileType);

	ofstream saved(fileName);
	if (!saved) {
		cout << "Error saving file for output" << endl;
		return ;
	}
	for (int i = 0; i < students.size(); i++) {
		saved << students[i].m_number  << "," 
			  << students[i].m_lab     << "," 
			  << students[i].m_quiz    << "," 
			  << students[i].m_midTerm << "," 
			  << students[i].m_final   << "," 
			  << students[i].m_grade   << endl;
	}
	cout << "File Saved\n\n";
	saved.close();
	return ;
}

void CCourse::loadFile() {
	CStudent student;
	string loadedGrade;

	string fileName;
	string fileType = ".txt";
	cout << "\nName Save file\n";
	cin >> fileName;
	fileName.append(fileType);


	this->students.clear();

	ifstream saved(fileName);
	if (!saved) {
		cout << "Error saving file for output" << endl;
		return;
	}
	else {
		while (getline(saved, student.m_number, ',')) {
			getline(saved, loadedGrade, ',');
			student.m_lab = stof(loadedGrade);

			getline(saved, loadedGrade, ',');
			student.m_quiz = stof(loadedGrade);

			getline(saved, loadedGrade, ',');
			student.m_midTerm = stof(loadedGrade);

			getline(saved, loadedGrade, ',');
			student.m_final = stof(loadedGrade);

			getline(saved, loadedGrade);
			student.m_grade = stof(loadedGrade);
			this->students.push_back(student);
		}
		cout << "File Loaded\n\n";
		saved.close();
	}
	return;
	
}

