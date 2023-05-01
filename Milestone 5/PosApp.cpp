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
#include "PosApp.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace sdds {

	Item* PosApp::search(const char* user_sku) {
		int i = 0;
		bool flag = true;
		while(i<nptr&&flag) {
			if (strcmp(iptr[i]->get_sku(),user_sku)==0) {
				flag = false;
				return iptr[i];
			}
			
			i++;
		}
		if (flag == true) {
			return nullptr;
		}
		return nullptr;
	}
	void PosApp::POS(ostream& ostr=cout) {
		ostr << ">>>> Starting Point of Sale.................................................." << endl;
		char sku[MAX_SKU_LEN + 1] = { '\0' };
		//double total = 0;
		bool done = false;
		Bill m_bill;
		while (!done) {
			cout << "Enter SKU or <ENTER> only to end sale..." << endl;
			cout << "> ";
			cin.getline(sku, MAX_SKU_LEN + 1);
			if (strlen(sku) == 0) {
				done = true;
			}
			else if (cin.fail()) {
				cout << "SKU too long" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				Item* item = search(sku);
				if (item!=nullptr) {
					if (item->quantity() > 0) {
						int q = item->quantity();
						q -= 1;
						item->set_quantity(q);

						//item->quantity(item->quantity() - 1);
						ostr<<item->displayType(POS_FORM);
						m_bill.add(item);
						//total += item->cost();
						
						cout << endl;
						cout << ">>>>> Added to bill" << endl;
						cout << ">>>>> Total: " <<setprecision(2)<<fixed<< m_bill.total() << endl;
						//m_bill.add(item);
					}
					else {
						cout << "Item out of stock" << endl;
					}
				}
				else if(item==nullptr) {
					cout << "!!!!! Item Not Found !!!!!" << endl;
				}
			}
		}
		m_bill.print(ostr);
	}

	

	void PosApp::sortbyItemName(Item** arr, int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (strcmp(arr[j]->return_name(), arr[j + 1]->return_name()) > 0) {
					// Swap the pointers to Item objects
					Item* temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	PosApp::~PosApp()
	{
		for (int i = 0; i < nptr; i++) {

			delete iptr[i];
		}
		nptr = 0;
	}

	
	void PosApp::loadRecs(ostream& ostr = cout) {
		char type;
		actionTitle("Loading Items");
		ifstream input(m_filename);
		if (!input.is_open()) {
			ofstream output(m_filename);
			output.close();
			return;

		}


		if (nptr != 0) {
			for (int i = 0; i < nptr; i++) {
				if (iptr[i] != nullptr) {
					delete iptr[i];
					iptr[i] = nullptr;
				}
			}
		}



		while (input.good() && nptr < MAX_NO_ITEMS) {
			input >> type;
			if (input)
			{
				if (type == 'P' || type == 'N') {
					Item* item = nullptr;
					if (type == 'P') {
						item = new Perishable();
					}
					else if (type == 'N') {
						item = new NonPerishable();
					}
					input.ignore();
					item->load(input);
					iptr[nptr] = item;
					nptr++;

				}
			}
		}
		input.close();



	}


	

	void PosApp::actionTitle(const char* title) {
		cout << ">>>> " << setw(72) << left << setfill('.') << title << endl;
		cout << setfill(' ');
	}

	void PosApp::addItem(ostream& ostr = cout) {
		//ostr << ">>>> Adding Item to the store................................................" << endl;
		//ostr << "Running addItem()\n";
		char type_item;
		bool flag = true;
		actionTitle("Adding Item to the store");
		if (nptr == MAX_NO_ITEMS) {
			ostr << "Inventory Full!" << endl;

		}
		else {
			Item* temp_item = nullptr;
			ostr << "Is the Item perishable? (Y)es/(N)o: ";
			cin >> type_item;
			cin.ignore();
			if (type_item == 'y' || type_item == 'Y') {
				temp_item = new Perishable();
			}
			else if (type_item == 'N' || type_item == 'n') {
				temp_item = new NonPerishable();
			}
			for (int i = 0; i < MAX_NO_ITEMS && flag == true; i++) {
				temp_item->read(cin);
				if (temp_item) {

					iptr[nptr] = temp_item;
					nptr++;
					//cout << "das" << nptr;
					flag = false;
					actionTitle("DONE!");
					//delete[] iptr[nptr];
				}
				else if (!temp_item) {
					cin.clear();
					cin.ignore(1000, '\n');
					ostr << temp_item;
					ostr << ", try again...\n";
					flag = true;
				}

			}

			//nptr++;

		}

	}

	void PosApp::stockItem(ostream& ostr = cout) {
		actionTitle("Select an item to stock");
		//selectItem(ostr);
		
		int row_remove;
		row_remove = selectItem(ostr);
		ostr << "Selected Item:\n";
		int index_remove = row_remove - 1;
		
		ostr << iptr[index_remove]->displayType(POS_FORM);
		//ostr << "Enter quantity to add: ";

		bool done = false;
		int value = 0;
		//bool flag = true;

		ostr << "Enter quantity to add: ";
		do {

			/*do {*/

			if (!done) {

				cin >> value;
			}

			if (cin) {
				if (value<1 || value>nptr) {

					cout << "[1<=value<=69], retry: Enter quantity to add: ";
				}
				else {
					done = true;


				}
			}
			else {
				cin.clear();
				//cin.ignore(10000, '\n');
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid Integer, try again: ";
			}
			/*}while()*/
			if (!done) {
				cin.ignore(10000, '\n');
			}




		} while (!done);
		//ostr << value;
		
		int q = iptr[index_remove]->quantity();
		q += value;
		iptr[index_remove]->set_quantity(q);
		
		
		//iptr[index_remove]->quantity() = (iptr[index_remove] += value);

		
		
		actionTitle("DONE!");

	}



	void PosApp::removeItem(ostream& ostr = cout) {
		actionTitle("Remove Item");
		//int n = sizeof(iptr) / sizeof(iptr[0]);
		int row_remove;
		row_remove = selectItem(ostr);
		int index_remove = row_remove - 1;
		cout << "Removing...." << endl;
		ostr<<iptr[index_remove]->displayType(POS_FORM);
		delete iptr[index_remove];
		for (int i = index_remove; i < nptr - 1; i++) {
			
			iptr[i] = iptr[i + 1];
			
		}
		nptr--;
		actionTitle("DONE!");

	}

	

	int PosApp::selectItem(ostream& ostr = cout) {
		//bool done = false;
		//int value = 0;

		actionTitle("Item Selection by row number");
		ostr << "Press <ENTER> to start....";
		cin.ignore();
		

		actionTitle("Listing Items");
		


		sortbyItemName(iptr, nptr);
		ostr << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		ostr << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

		for (int i = 0, j = 1; i < nptr; i++) {
			//ostr <<"   " << j++ << " |";
			ostr << right << setw(4) << j++ << " | ";
			ostr << iptr[i]->displayType(POS_LIST) << endl;

		}
		ostr << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		ostr.unsetf(ios::right);
		bool done = false;
		int value = 0;
		//bool flag = true;

			cout << "Enter the row number: ";
		do {
		
			/*do {*/

				if (!done) {

					cin >> value;
				}

				if (cin) {
					if (value<1 || value>nptr) {

						cout << "[1<=value<=" << nptr << "], retry: Enter the row number: ";
					}
					else {
						done = true;
						

					}
				}
				else {
					cin.clear();
					//cin.ignore(10000, '\n');
					//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid Integer, try again: ";
				}
			/*}while()*/
			if (!done) {
			cin.ignore(10000, '\n');
		}
			

			
			
		} while (!done);

		return value;
	}

	void PosApp::listItems(ostream& ostr = cout) {
		double totalAsset = 0.0;
		

		actionTitle("Listing Items");

		sortbyItemName(iptr, nptr);
		ostr << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
		ostr << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

		for (int i = 0, j = 1; i < nptr; i++) {
			//ostr <<"   " << j++ << " |";
			ostr << right << setw(4) << j++ << " | ";
			ostr << iptr[i]->displayType(POS_LIST) << endl;
			totalAsset += iptr[i]->cost() * iptr[i]->quantity();
		}

		ostr << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
		ostr << setw(49) << "Total Asset: $  | " << setw(13) << right << fixed << setprecision(2) << totalAsset << "|" << endl;

		ostr << "-----------------------------------------------^--------------^" << endl;
		ostr << endl;
		ostr.unsetf(ios::right);

	}

	



	void PosApp::saveRecs(ostream& ostr = cout) {
		//ostr << ">>>> Saving Data............................................................." << endl;
		actionTitle("Saving Data");
		ofstream output(m_filename);
		//nptr--;
		for (int i = 0; i < nptr; i++) {

			if (iptr[i]) {
				iptr[i]->save(output);
				//ostr << endl;
			}

		}
		ostr << "Goodbye!\n";
	}

	PosApp::PosApp(const char* filename) {
		strcpy(m_filename, filename);
	}




	int PosApp::menu() {

		int user_input;


		cout << "The Sene-Store\n"
			<< "1- List items\n"
			<< "2- Add item\n"
			<< "3- Remove item\n"
			<< "4- Stock item\n"
			<< "5- POS\n"
			<< "0- exit program\n"
			<< "> ";
		cin >> user_input;

		return user_input;

	}



	void PosApp::run() {
		int temp = 0;
		bool done = false;
		loadRecs();

		do {
			temp = menu();

			do {
				// cheking input is integer only and not a garbage value
				if (cin.get() != '\n') {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid Integer, try again: ";
					cin >> temp;
				}

				// checking input is in between the range 
				else if (temp < 0 || temp > 5) {
					cout << "[0<=value<=5], retry: > ";
					cin >> temp;

				}
				else {
					done = true;

				}
			} while (!done);



			switch (temp) {
			case 1:
				listItems();
				break;
			case 2:
				addItem();
				break;
			case 3:
				removeItem();
				break;
			case 4:
				stockItem();
				break;
			case 5:
				POS();
				break;
			case 0:
				saveRecs();
				break;
			}





		} while (temp != 0);

	}





}






