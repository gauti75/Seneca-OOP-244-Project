/*
*****************************************************************************
                  Milestone 1

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 07 March 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include "PosApp.h"

using namespace std;

namespace sdds {


    void PosApp::addItem(ostream& ostr = cout) {
        ostr << ">>>> Adding Item to the store................................................" << endl;
        ostr << "Running addItem()\n";
    }

    void PosApp::removeItem(ostream& ostr = cout) {
        ostr << ">>>> Remove Item............................................................." << endl;
        ostr << "Running removeItem()\n";
    }

    void PosApp::stockItem(ostream& ostr = cout) {
        ostr << ">>>> Select an item to stock................................................." << endl;
        ostr << "Running stockItem()\n";
    }

    void PosApp::listItems(ostream& ostr = cout) {
        ostr << ">>>> Listing Items..........................................................." << endl;
        ostr << "Running listItems()\n";
    }

    void PosApp::POS(ostream& ostr = cout) {
        ostr << ">>>> Starting Point of Sale.................................................." << endl;
        ostr << "Running POS()\n";
    }

    void PosApp::loadItems(ostream& ostr = cout) {
        ostr << ">>>> Loading Items..........................................................." << endl;
        ostr << "Loading data from datafile.csv" << endl;

    }

    void PosApp::saveRecs(ostream& ostr = cout) {
        ostr << ">>>> Saving Data............................................................." << endl;
        ostr <<"Saving data in "<< m_filename << endl;
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
            << "5- Point of Sale\n"
            << "0- exit program\n"
            << "> ";
        cin >> user_input;

        return user_input;

    }



    void PosApp::run() {
        int temp = 0;
        bool done = false;
        loadItems();

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

              
            

  

