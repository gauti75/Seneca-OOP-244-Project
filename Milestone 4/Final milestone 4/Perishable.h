/*
*****************************************************************************
				  Milestone 4

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 04 April 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

*****************************************************************************
*/

#ifndef SDDS_PERISHABLE_H_
#define SDDS_PERISHABLE_H_
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Date.h"

namespace sdds {

	class Perishable :public Item {

		Date expiry_date;
		virtual char itemType()const;

		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::ofstream& save(std::ofstream& ofstr)const;
		virtual std::istream& read(std::istream& istr);
		virtual std::ifstream& load(std::ifstream& ifstr);
	};




}



#endif