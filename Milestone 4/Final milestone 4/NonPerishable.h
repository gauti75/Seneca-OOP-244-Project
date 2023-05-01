
#ifndef SDDS_NONPERISHABLE_H_
#define SDDS_NONPERISHABLE_H_
#include <iostream>
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

#include <fstream>
#include "Item.h"


namespace sdds {

	class NonPerishable :public Item {

		virtual char itemType()const;
		virtual std::ostream& write(std::ostream& ostr)const;

	};



}



#endif