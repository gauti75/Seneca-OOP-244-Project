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

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include <iostream>
#include <fstream>
#include "Error.h"
#include "POS.h"
#include "PosIO.h"


namespace sdds {

	class Item :public PosIO {
	private:
		char SKU[MAX_SKU_LEN + 1];
		char* name;//dynamically for the item name
		double price;
		bool tax;
		int Quantity;
	protected:
		int diaplayType;// can be either pos_list or pos_form
		Error err;
		Item();//no argument constructor which sets to empty state

		Item(const Item& copyItem);//copy constructor
		Item& operator=(const Item& assignItem);
		


	public:
		const char* get_sku();
		~Item();//destructor
		void set_quantity(int new_quantity);
		void setEmpty();
		void setName(const char* temp_name);
		bool operator==(const char* newsku);
		bool operator>(const Item& compare);
		void operator+=(int added_quantity);
		int operator-=(int other_quantity);
		operator bool()const;
		virtual char itemType() const = 0;
		Item& displayType(int mode);
		//double cost()const;
		int quantity()const;
		Item& clear();
		double cost()const;
		char* return_name()const;

		// Virtual methods

		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::ofstream& save(std::ofstream& ofstr)const;
		virtual std::istream& read(std::istream& istr);
		virtual std::ifstream& load(std::ifstream& ifstr);

		// billPrint
		std::ostream& bprint(std::ostream& ostr)const;


	};

	double& operator+=(double& left, const Item& item);



}
#endif