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


#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include <iostream>
#include "Item.h"
#include "POS.h"
#include <string>
#include "Perishable.h"
#include "NonPerishable.h"
#include "Bill.h"
namespace sdds {

    class PosApp {
        int sort_size = 0;
        char m_filename[128];
        Item* iptr[MAX_NO_ITEMS];
        int nptr=0;//how many item pointers are in the array
            
        void actionTitle(const char* title);
        PosApp(const PosApp&);
       // PosApp& operator=(const PosApp&);

        void addItem(std::ostream& ostr);

        void removeItem(std::ostream& ostr);

        void stockItem(std::ostream& ostr);

        void listItems(std::ostream& ostr);

        void POS(std::ostream& ostr);

        void loadRecs(std::ostream& ostr);

        void saveRecs(std::ostream& ostr);

        int menu();

        int selectItem(std::ostream& ostr);


    public:
        Item* search(const char* user_sku);

      
        PosApp(const char* filename);

        void run();

        void sortbyItemName(Item** arr, int size);


        ~PosApp();

    };

}

#endif 



