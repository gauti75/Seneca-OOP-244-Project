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

#ifndef SDDS_POS_H_
#define SDDS_POS_H_
#include <iostream>


namespace sdds {

	const int MAX_NAME_LEN = 40;

	const int  POS_LIST = 1;
	const int  POS_FORM = 2;

#define ERROR_POS_SKU = "SKU too long";
#define ERROR_POS_NAME : "Item name too long";
#define ERROR_POS_PRICE : "Invalid price value";
#define ERROR_POS_TAX : "Invalid tax status";;
#define ERROR_POS_QTY : "Invalid quantity value";
#define ERROR_POS_STOCK : "Item out of stock";
#define ERROR_POS_EMPTY : "Invalid Empty Item";

	const double TAX = 0.13;
	const int MAX_SKU_LEN = 7;

	const int MIN_YEAR = 2000;
	const int MAX_YEAR = 2030;

	const int MAX_STOCK_NUMBER = 99;
	const int MAX_NO_ITEMS = 2000;

}

#endif