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

#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include <iostream>


namespace sdds {
	class Error {
	private:
		char* error_message = nullptr;


	public:

		void set_error(const char* error);
		Error();
		Error(const char* error);
		Error(const Error& copyError);//Copy Constructor
		Error& operator=(const Error& assignError);//Assignment operator
		// void setError(const char* error);//assigning the error message
		operator bool()const;//bool operator overloading
		Error& clear();
		std::ostream& display(std::ostream& ostr)const;
		~Error();//Destructor
		//friend std::ostream& operator<<(std::ostream& ostr, const Error& Err);//ostream insertion
	};
	std::ostream& operator<<(std::ostream& ostr, const Error& Err);//ostream insertion

}

#endif