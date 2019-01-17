#include "Stdafx.h"
#include "CStudent.h"
using namespace std;

void CStudent::print() {

	cout << setw(15) << fixed << setprecision(2) << m_number << setw(10) << m_lab << setw(10) << m_quiz << setw(12) << m_midTerm << setw(15) << m_final << setw(15) <<  m_grade << std::endl;

}
