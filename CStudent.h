#pragma once 

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

class CStudent {

	public:
		std::string m_number;
		float m_lab;
		float m_quiz;
		float m_midTerm;
		float m_final;
		float m_grade;

		void print();


};


