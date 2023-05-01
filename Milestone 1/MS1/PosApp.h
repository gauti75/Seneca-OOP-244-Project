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


#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include <iostream>

namespace sdds {

    class PosApp {
        char m_filename[256];

       
        PosApp(const PosApp&);
        PosApp& operator=(const PosApp&);

        void addItem(std::ostream& ostr);
       
        void removeItem(std::ostream& ostr);

        void stockItem(std::ostream& ostr);

        void listItems(std:: ostream& ostr);

        void POS(std:: ostream& ostr);

        void loadItems(std::ostream& ostr);

        void saveRecs(std::ostream& ostr);

       int menu();

       

    public:

        PosApp(const char* filename);

        void run();

        
    };

}

#endif 



