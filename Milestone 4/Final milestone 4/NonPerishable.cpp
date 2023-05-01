/*
*****************************************************************************
				  Milestone 4

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 03 April 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<string.h>
#include <iomanip>
#include<string>

#include "NonPerishable.h"
//#include "Item.h"



using namespace std;


namespace sdds {

	char NonPerishable::itemType()const {
		return 'N';
	}

	std::ostream& NonPerishable::write(std::ostream& ostr)const {
		
		if (!*this) {
			
		}
		else if (*this) {
			Item::write(ostr);
			if (diaplayType == POS_LIST) {

				ostr << "     N / A   |";
			}
			else if (diaplayType == POS_FORM) {
				
				ostr << "=============^" << endl;

			}
		}
		
		return ostr;

	}



}