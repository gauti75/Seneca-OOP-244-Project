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


#include "Item.h"



using namespace std;


namespace sdds {

	void Item::setEmpty() {
		delete[] name;
		SKU[0] = 0;
		name = nullptr;
		price = 0.0;
		tax = false;
		Quantity = 0;
		diaplayType = 0;
		err.clear();
	}

	void Item::setName(const char* temp_name) {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
		if (temp_name != nullptr && strlen(temp_name) > 0) {
			name = new char[(strlen(temp_name)) + 1];
			strcpy(name, temp_name);
		}
		else {
			name = nullptr;
		}

	}

	Item::Item() {
		SKU[0] = 0;
		name = nullptr;
		price = 0.0;
		tax = false;
		Quantity = 0;
		diaplayType = 0;
		err.clear();
	}

	Item::Item(const Item& copyItem) {
		*this = copyItem;
	}
	/*
	Item& Item::operator=(const Item& other) {
		if(name!=)
		if (this != &other) {
			setEmpty();
			strncpy(SKU, other.SKU, MAX_SKU_LEN);
			setName(other.name);
			price = other.price;
			tax = other.tax;
			Quantity = other.Quantity;
			diaplayType = other.diaplayType;
		}
		return *this;
	}
	*/


	Item& Item::operator=(const Item& assignItem) {

		if (this != &assignItem) {
			setEmpty();
			//dynamically allocate item name
			err = assignItem.err;
			if (assignItem) {
				name = new char[(strlen(assignItem.name)) + 1];
				strcpy(name, assignItem.name);

				// copying static members
				strcpy(SKU, assignItem.SKU);
				price = assignItem.price;
				tax = assignItem.tax;
				Quantity = assignItem.Quantity;
				diaplayType = assignItem.diaplayType;

			}



		}


		return *this;
	}


	bool Item::operator==(const char* newsku) {
		return strcmp(SKU, newsku) == 0;
	}

	bool Item::operator>(const Item& compare) {
		//name = new char[strlen(compare.name) + 1];
		//strcpy(name, compare.name);

		//return strcmp(name, compare.name) > 0;
		return true;
	}

	int Item::operator+=(int added_quantity) {


		if ((Quantity + added_quantity) > MAX_STOCK_NUMBER) {
			Quantity = MAX_STOCK_NUMBER;
			//err.set_error("Invalid quantity value");
		}
		else {
			Quantity = Quantity + added_quantity;
		}
		return Quantity;
	}

	int Item::operator-=(int other_quantity) {
		if ((Quantity - other_quantity) > Quantity) {
			Quantity = 0;
			err.set_error("Item out of stock");
		}
		else {
			Quantity = Quantity - other_quantity;
		}
		return Quantity;
	}

	Item::operator bool()const {
		return !err;
	}



	double& operator+=(double& left, const Item& item) {
		left += item.cost() * item.quantity();
		return left;
	}

	Item& Item::displayType(int mode) {
		if (mode == POS_FORM || mode == POS_LIST) {
			diaplayType = mode;
		}
		return *this;
	}

	double Item::cost()const {
		double final_cost = price;
		if (tax) {
			final_cost = final_cost + (final_cost * 0.13);

		}
		return final_cost;
	}

	int Item::quantity()const {
		return Quantity;
	}

	Item& Item::clear() {
		err.clear();
		return *this;
	}

	std::ostream& Item::write(std::ostream& ostr)const {

		if (err) {
			ostr << err;
		}
		else {
			if (diaplayType == POS_LIST) {
				string t_name = name;
				ostr << SKU << "   |";
				ostr << setw(20) << left << t_name.substr(0, 20) << "| ";
				ostr << setw(6) << right << fixed << setprecision(2) << price << "|";
				if (tax == true) {
					ostr << " X |" <<setw(4)<< right << quantity() << "|" << setw(9) << fixed << setprecision(2) << cost() * quantity() << "|";
				}
				else if (tax == false) {
					ostr << "   |  " << right << quantity() << "|" << setw(9) << fixed << setprecision(2) << cost() * quantity() << "|";
				}

			}
			else if (diaplayType == POS_FORM) {
				ostr << "=============v" << endl;
				ostr <<left<<setw(13)<< "Name: "  << name << endl;
				ostr <<left<<setw(13)<< "Sku: "<< SKU << endl;
				ostr <<left<<setw(13)<<"Price:"  <<price << endl;
				if (tax) {
					ostr << left << setw(13)<< "Price + tax: " << cost() << endl;
				}
				else {
					ostr << left << setw(13)<< "Price + tax: " << "N/A" << endl;
				}
				ostr << left << setw(13)<< "Stock Qty: "  << Quantity << endl;



			}
		}

		ostr.unsetf(ios::right);
		return ostr;
	}

	std::ofstream& Item::save(std::ofstream& ofstr)const {

		
		ofstr << itemType();
		ofstr << "," << SKU << ",";
		ofstr << name << ",";
		ofstr << fixed << setprecision(2) << price << ",";
		ofstr << tax << ",";
		ofstr << Quantity;
		
		if (ofstr.fail()) {
			cerr << err << endl;
		}

		
		return ofstr;
	}


	istream& Item::read(istream& is) {

		bool isValid = false;
		char taxed = { '\0' };
		char temp_name[MAX_NAME_LEN];
		err.clear();


		cout << "Sku" << endl;
		do {
			cout << "> ";
			is.getline(SKU, MAX_SKU_LEN);

			if (is.fail()) {

				is.clear();
				is.ignore(1000, '\n');
				err.set_error("SKU too long");
				cout << err << endl;
				//isValid = false;
			}
			else if (strlen(SKU) > MAX_SKU_LEN) {

				err.set_error("SKU too long");
				cout << err << endl;

			}
			else {
				isValid = true;
			}

		} while (!isValid || is.fail());

		isValid = false;
		err.clear();
		cout << "Name" << endl;
		do {
			cout << "> ";
			is.getline(temp_name, MAX_NAME_LEN);
			if (name != nullptr) {
				delete[] name;
				name = nullptr;
			}
			name = new char[strlen(temp_name) + 1];
			strcpy(name, temp_name);

			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
				err.set_error("Item name too long");
				cout << err << endl;

			}
			else if (strlen(name) > MAX_NAME_LEN) {
				err.set_error("Item name too long");
				//cout << "Item name too long";
				cout << err << endl;
			}
			else {
				isValid = true;
			}

		} while (!isValid || is.fail());


		isValid = false;
		err.clear();
		cout << "Price" << endl;
		do {
			cout << "> ";
			is >> price;


			if (is.fail()) {
				//cout << "Invalid price value";

				is.clear();
				is.ignore(1000, '\n');
				err.set_error("Invalid price value");
				cout << err << endl;
			}
			else if (price < 0) {
				//cout << "Invalid price value";
				err.set_error("Invalid price value");
				cout << err << endl;
			}
			else {
				isValid = true;
			}
		} while (!isValid || is.fail());


		isValid = false;
		err.clear();
		cout << "Taxed?" << endl;
		cout << "(Y)es/(N)o: ";
		do {

			is >> taxed;

			if (taxed != 'y' && taxed != 'Y' && taxed != 'n' && taxed != 'N') {
				cout << "Only 'y' and 'n' are acceptable: ";
				is >> taxed;
				is.clear();
				is.ignore(1000, '\n');
				err.set_error("Invalid tax status");

			}
			else if (taxed == 'y' || taxed == 'Y') {
				tax = true;
				isValid = true;

			}
			else if (taxed == 'n' || taxed == 'N') {
				tax = false;
				isValid = true;
			}
		} while (!isValid || is.fail());

		isValid = false;
		err.clear();
		cout << "Quantity" << endl;
		do {
			cout << "> ";
			is >> Quantity;

			if (is.fail()) {

				//cout << "Invalid quantity value";
				is.clear();
				is.ignore(1000, '\n');
				err.set_error("Invalid quantity value");
				cout << err << endl;
			}
			else if (Quantity < 1 || Quantity > 99) {
				//cout << "Invalid quantity value";
				err.set_error("Invalid quantity value");
				cout << err << endl;
			}
			else {
				isValid = true;
			}
		} while (!isValid || is.fail());
		err.clear();
		return is;
	}


	std::ifstream& Item::load(std::ifstream& ifstr) {




		// Clearing the error
		err.clear();
		//setEmpty();

		//char user_sku[MAX_SKU_LEN];
		//char user_name[MAX_NAME_LEN];
		string user_sku = "";
		string user_name = "";
		double user_price = 0;
		bool user_tax = false;
		int user_quantity = 0;
		//int user_diaplayType;
		//char user_taxvalue;

		//ifstr >> user_sku >>comma>> user_name >> comma >> user_price >> comma >> user_price >>comma >> user_taxvalue >> comma >> user_quantity;
		//ifstr.getline(user_sku, MAX_SKU_LEN, ',');
		//ifstr.getline(user_name, MAX_NAME_LEN, ',');
		getline(ifstr, user_sku, ',');
		getline(ifstr, user_name, ',');
		ifstr >> user_price;
		ifstr.ignore();
		ifstr >> user_tax;
		ifstr.ignore();
		ifstr >> user_quantity;

		//bool valid = true;

		if (ifstr.fail()) {

			return ifstr;
		}
		if (user_sku.size() > MAX_SKU_LEN) {

			err.set_error("SKU too long");

			return ifstr;

		}


		if (user_name.size() > MAX_NAME_LEN) {
			err.set_error("Item name too long");
			//cout << err;
			return ifstr;

		}

		if (user_price < 0) {
			err.set_error("Invalid price value");
			//cout << err;
			return ifstr;

		}

		// ifstr.clear();

		if (user_quantity < 1 || user_quantity > 100) {
			err.set_error("Invalid quantity value");
			//cout << err;
			return ifstr;

		}

		//setEmpty();
		strcpy(SKU, user_sku.c_str());
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
		if (strlen(user_name.c_str()) > 0) {
			name = new char[(strlen(user_name.c_str())) + 1];
			strcpy(name, user_name.c_str());
		}

		price = user_price;

		tax = user_tax;
		Quantity = user_quantity;

		return ifstr;

	}


	std::ostream& Item::bprint(std::ostream& ostr) {
		string t_name = name;

		ostr << "| ";
		ostr << setw(20) << left << t_name.substr(0, 20) << "| ";
		ostr << fixed << setprecision(2) << setw(9) << right << cost() << " |";
		if (tax) {
			ostr << "  T  |" << endl;
		}
		else {
			ostr << "     |" << endl;
		}
		return ostr;
	}



	Item::~Item() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
	}




}