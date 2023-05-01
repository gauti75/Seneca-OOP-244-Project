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
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
#include "Error.h"

namespace sdds {
	class Date {
	private:
		int year;
		int month;
		int day;
		int hours;
		int minutes;
		bool date_only;
		Error err;
	public:
		Date& operator=(Date& rhs_date);
		void set_year(int temp_year);
		void set_month(int temp_month);
		void set_day(int temp_day);
		void set_hours(int temp_hour);
		void set_minutes(int temp_minutes);
		void set_error(const char* error);
		bool get_bool();
		void valid_Data();
		void set_Empty();
		Date();//Default Constructor
		Date(int c_year, int c_month, int c_day);//Date only mode
		Date(int c_year, int c_month, int c_day, int c_hour);//Date only mode
		Date(int c_year, int c_month, int c_day, int c_hour, int c_minute);//Date With Time mode
		Date& dateOnly(bool c_dateOnly);
		operator bool()const;
		const Error& error() const;
		std::ostream& display(std::ostream& ostr)const;

		// operator overloading

		bool operator==(const Date& other) const;
		bool operator!=(const Date& other) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator>=(const Date& other) const;

	};
	std::ostream& operator<<(std::ostream& ostr, const Date& Date);//ostream insertion
	std::istream& operator>>(std::istream& istr, Date& Date);

}

#endif