// Lab 1.cpp : Defines the entry point for the console application.
//
//ADDING COMMENTS MORE COMMENTS AND MORE
#include "stdafx.h"
#include "CStudent.h"
#include "CCourse.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;

//Functions
void printMenu();
void addStudent();
void editStudent();
void printStudent();


std::vector<CStudent> students;


int main()
{
	char inputSelect;

	do {
		printMenu();

		switch (inputSelect)
		{
		case 'A':
		case 'a': {
			addStudent();
			break;
		}
		case 'E':
		case 'e': {
			editStudent();
			break;
		}
		case 'P':
		case 'p': {
			printStudent();
			break;
		}
		case 'D':
		case 'd': {
			int entry = 0;
			std::cout << "Deleting" << endl;
			std::cout << "Which student: ";
			cin >> entry;
			students.erase(students.begin() + entry - 1);
			break;
		}

		case 'L':
		case 'l': {
			cout << "The class has: " << students.size() << " student(s)\n";
			std::cout << setw(3) << "" << setw(15) << "Student#:" << setw(10) << "Lab:" << setw(10) << "Quiz:" << setw(12) << "MidTerm:" << setw(15) << "Final Exam:" << setw(15) << "Final Grade:" << std::endl;
			for (int i = 0; i < students.size(); i++) {
				cout  << setw(3) << i+1;
				students[i].print();
			}
			break;
		}

		case 'Q':
		case 'q':
			std::cout << "Quiting" << endl;
			break;
		default:
			std::cout << "Command not found\nCommand: ";
			std::cin >> inputSelect;
			break;
		}
		cout << "Back to Main Menu?(y/n): ";
		cin >> inputSelect;

	} while (inputSelect == 'Y' || inputSelect == 'y');
		
	return 0;

}

void printMenu() {
	cout << "**************************************** \n"
		<< "ELEX4618 Grade System, by STUDENT NUMBER \n"
		<< "**************************************** \n\n"
		<< "(A)dd student \n"
		<< "(E)dit student \n"
		<< "(P)rint grades \n"
		<< "(D)elete student \n"
		<< "(L)ist all students \n"
		<< "(Q)uit \n"
		<< "\nCommand:";
	cin >> inputSelect;
}

void addStudent() {
	CStudent student;
	cout << "Adding a student" << endl;
	cout << "Student number: ";
	cin >> student.m_number;
	cout << "Lab Grade: ";
	cin >> student.m_lab;
	cout << "Quiz Grade: ";
	cin >> student.m_quiz;
	cout << "Midterm grade: ";
	cin >> student.m_midTerm;
	cout << "Final Exam Grade: ";
	cin >> student.m_final;
	student.m_grade = (((student.m_lab)*40) + ((student.m_quiz) * 10) + ((student.m_midTerm) * 20) + ((student.m_final) * 30))/100;

	students.push_back(student);
}

void editStudent() {
	int entry = 0;
	std::cout << "Editing a student" << endl;
	std::cout << "Which student: ";
	cin >> entry;
	cout << "New Student Number: ";
	cin >> students[entry - 1].m_number;
	cout << "New Lab Grade: ";
	cin >> students[entry - 1].m_lab;
	cout << "New Quiz Grade: ";
	cin >> students[entry - 1].m_quiz;
	cout << "New Midterm grade: ";
	cin >> students[entry - 1].m_midTerm;
	cout << "New Final Grade: ";
	cin >> students[entry - 1].m_final;
	students[entry - 1].m_grade = (((students[entry - 1].m_lab) * 40) + ((students[entry - 1].m_quiz) * 10) + ((students[entry - 1].m_midTerm) * 20) + ((students[entry - 1].m_final) * 30)) / 100;
}

void printStudent() {
	int entry = 0;
	std::cout << "Printing" << endl;
	std::cout << "Which student: ";
	cin >> entry;
	students[entry - 1].print();
}