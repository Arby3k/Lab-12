#include "Stdafx.h"
#include "CCourse.h"
#include "CStudent.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <regex>

using namespace std;
regex studentNum("([Aa]0[0-1][0-9]{6})$");

void CCourse::printMenu() {
	cout << "**************************************** \n"
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
	int invalid_studentNum = 0;
	bool validEntry;
	
	cout << "Adding a student" << endl;
	
	cout << "Student number: ";
	do {
		cin >> testNum; //student.m_number;
		if (regex_match(testNum, studentNum)) {
			student.m_number = testNum;
			invalid_studentNum = 0;
		}
		else {
			cout << "Not Valid Student number\nPlease enter valid student number:";
			invalid_studentNum = 1;
		}
	} while (invalid_studentNum == 1);

	cout << "Lab Grade: ";
	//cin >> student.m_lab;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			student.m_lab = stof(grade);
			//grade = 0;
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	cout << "Quiz Grade: ";
	//cin >> student.m_quiz;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			student.m_quiz = stof(grade);
			//grade = 0;
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);
	
	cout << "Midterm grade: ";
	//cin >> student.m_midTerm;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			student.m_midTerm = stof(grade);
			//grade = 0;
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);
	
	cout << "Final Exam Grade: ";
	//cin >> student.m_final;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			student.m_final = stof(grade);
			//grade = 0;
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


	cout << "Editing a student" << endl;
	cout << "Which student: ";
	cin >> entry;
	
	cout << "New Student Number: ";
	do {
		cin >> test; //student.m_number;
		if (regex_match(test, studentNum)) {
			this->students[entry - 1].m_number = test;
			invalid_studentNum = 0;
		}
		else {
			cout << "Not Valid Student number\nPlease enter valid student number:";
			invalid_studentNum = 1;
		}
	} while (invalid_studentNum == 1);

	cout << "New Lab Grade: ";
	//cin >> this->students[entry - 1].m_lab;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			this->students[entry - 1].m_lab = stof(grade);
			//grade = 0;
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	cout << "New Quiz Grade: ";
	//cin >> this->students[entry - 1].m_quiz;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			this->students[entry - 1].m_quiz = stof(grade);
			//grade = 0;
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);
	
	cout << "New Midterm grade: ";
	//cin >> this->students[entry - 1].m_midTerm;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			this->students[entry - 1].m_midTerm = stof(grade);
			//grade = 0;
		}
		else {
			cout << "Not Valid Grade\nPlease enter valid Grade:";
			validEntry = false;
		}
	} while (validEntry == false);

	cout << "New Final Grade: ";
	//cin >> this->students[entry - 1].m_final;
	do {

		cin >> grade;
		validEntry = errorCheck(grade);
		//errorCheck(x);
		if (validEntry == true) {
			this->students[entry - 1].m_final = stof(grade);
			//grade = 0;
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
	std::cout << "Printing" << endl;
	std::cout << "Which student: ";
	cin >> entry;
	this->students[entry - 1].print();
}

void CCourse::deleteStudent() {
	int entry = 0;
	std::cout << "Deleting" << endl;
	std::cout << "Which student: ";
	cin >> entry;
	this->students.erase(this->students.begin() + entry - 1);
}

void CCourse::listStudents() {
	cout << "The class has: " << this->students.size() << " student(s)\n";
	std::cout << setw(3) << "" << setw(15) << "Student#:" << setw(10) << "Lab:" << setw(10) << "Quiz:" << setw(12) << "MidTerm:" << setw(15) << "Final Exam:" << setw(15) << "Final Grade:" << std::endl;
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
	return;
}

void CCourse::loadFile() {
	return;
}