/*
*****************************************************************************
				  Milestone 5

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 11 April 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include "PosIO.h"


using namespace std;

namespace sdds {

	std::ostream& operator<<(std::ostream& ostr, const PosIO& pos_io) {
		return pos_io.write(ostr);

	}

	std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& pos_io) {
		return pos_io.save(ofstr);
	}

	std::istream& operator>>(std::istream& istr, PosIO& pos_io) {
		return pos_io.read(istr);
	}

	std::ifstream& operator>>(std::ifstream& ifstr, PosIO& pos_io) {
		return pos_io.load(ifstr);
	}


}