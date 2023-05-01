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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include "Error.h"

using namespace std;

namespace sdds {


	Error::operator bool()const {
		if (error_message != nullptr) {

			return true;
		}
		else {


			return false;
		}
	}
	Error::Error() {
		error_message = nullptr;
	}

	void Error::set_error(const char* error) {
		if (error_message != nullptr) {
			delete[] error_message;
			error_message = nullptr;
		}
		if (error != nullptr) {

			error_message = new char[strlen(error) + 1];
			strcpy(error_message, error);
		}

	}
	Error::Error(const char* error) {
		if (error != nullptr) {
			error_message = new char[strlen(error) + 1];
			strcpy(error_message, error);
		}
		else {
			error_message = nullptr;
		}
	}

	Error::Error(const Error& copyError) {
		//error_message = nullptr;
		if (copyError.error_message != nullptr) {

			error_message = new char[strlen(copyError.error_message) + 1];
			strcpy(error_message, copyError.error_message);
		}
		else {
			error_message = nullptr;
		}
	}


	Error& Error::operator=(const Error& assignError) {
		if (error_message != nullptr) {
			delete[] error_message;
			error_message = nullptr;
			if (this != &assignError) {

				error_message = new char[strlen(assignError.error_message) + 1];
				strcpy(error_message, assignError.error_message);
			}
		}

		else {
			error_message = nullptr;
		}
		return *this;

	}

	Error& Error::clear() {
		if (error_message != nullptr) {
			delete[] error_message;
			error_message = nullptr;
		}
		return *this;
	}



	Error::~Error() {
		if (error_message != nullptr) {
			delete[] error_message;
			error_message = nullptr;
		}
	}

	std::ostream& Error::display(std::ostream& ostr = cout)const {
		if (error_message != nullptr) {
			ostr << error_message;
		}
		return ostr;
	}

	ostream& operator<<(std::ostream& ostr, const Error& Err) {
		return Err.display(ostr);

	}

}