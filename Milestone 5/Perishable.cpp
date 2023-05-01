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
#include<string.h>
#include <iomanip>
#include<string>

#include "Date.h"
//#include "Item.h"
#include "Perishable.h"



using namespace std;


namespace sdds {

	char Perishable::itemType()const {
		return 'P';
	}

	std::istream& Perishable::read(std::istream& istr) {
		Item::read(istr);
		if (*this && istr.good()) {
			Date local_date; 
			local_date.dateOnly(true);
			cout << "Expiry date (YYYY/MM/DD)" << endl;
			cout << "> ";
			istr >> local_date;
			if (local_date) {
				expiry_date = local_date;
			}
			else if (!local_date) {
				//Item::err.set_error(expiry_date.error());
				Item::err = expiry_date.error();
			}
		}
		else {
			istr.setstate(std::ios::failbit);
		}
		return istr;
	}


	std::ostream& Perishable::write(std::ostream& ostr)const {
		Item::write(ostr);
		if (!*this) {
			return ostr;

		}
		else if (*this) {
			if (diaplayType == POS_LIST) {
				ostr << "  " << expiry_date << " " << "|";
			}
			else if (diaplayType == POS_FORM) {
				ostr << "Expiry date: " << expiry_date << endl;
				ostr << "=============^" << endl;
			}
		}
		return ostr;
	}

	std::ifstream& Perishable::load(std::ifstream& ifstr) {
		Item::load(ifstr);

		
		if (*this && ifstr.good()) {
			Date user_date;
			user_date.dateOnly(true);
			ifstr.ignore();
			ifstr >> user_date;
			if (user_date) {
				expiry_date = user_date;
				//expiry_date.set_year(user_date.year);
			}
			else if (!user_date) {
				Item::err = expiry_date.error();
			}
		}
		else {
			ifstr.setstate(std::ios::failbit);
		}
		return ifstr;
	}

	std::ofstream& Perishable::save(std::ofstream& ofstr)const {
		Item::save(ofstr);
		if (*this) {
			ofstr << "," << expiry_date;
			ofstr << endl;

		}
		else {
			
			return ofstr;
		}

		return ofstr;
	}



}