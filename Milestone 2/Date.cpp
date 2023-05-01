/*
*****************************************************************************
				  Milestone 2

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 16 March 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include "Date.h"
#include "Utils.h"
#include "POS.h"

using namespace std;

namespace sdds {

	void Date::set_Empty() {
		year = 0;
		month = 0;
		day = 0;
		hours = 0;
		minutes = 0;
		

	}

	void Date::valid_Data() {
		if (year<MIN_YEAR || year>MAX_YEAR) {
			err.set_error("Invalid Year");
		}
		else if (month < 1 || month>12) {
			err.set_error("Invalid Month");
		}
		else if (day<1 || day>daysOfMonth(year, month)) {
			err.set_error("Invalid Day");
		}
		else if (hours < 0 || hours>23) {
			err.set_error("Invalid Hour");
		}
		else if (minutes < 0 || minutes>59) {
			err.set_error("Invlid Minute");
		}
	}

	Date::Date() {
		getSystemDate(year, month, day, hours, minutes, date_only);
	}


	Date::Date(int c_year, int c_month, int c_day) {
		year = c_year;
		month = c_month;
		day = c_day;
		date_only = true;
		valid_Data();
	}
	Date::Date(int c_year, int c_month, int c_day, int c_hour) {
		year = c_year;
		month = c_month;
		day = c_day;
		hours = c_hour;
		minutes = 0;
		//date_only = true;
		valid_Data();
	}
	Date::Date(int c_year, int c_month, int c_day, int c_hour, int c_minute) {
		year = c_year;
		month = c_month;
		day = c_day;
		hours = c_hour;
		minutes = c_minute;
		date_only = false;
		valid_Data();
	}
	void Date::set_error(const char* error)
	{
		if (error != nullptr) {
			err.set_error(error);
		}
		else {
			err = nullptr;
		}

	}

	Date& Date::dateOnly(bool c_dateOnly) {
		date_only = c_dateOnly;
		if (c_dateOnly == true) {
			hours = 0;
			minutes = 0;
		}
		return *this;
	}

	Date::operator bool()const {
		return !error();
	}
	const Error& Date::error() const {
		return err;
	}
	bool Date::get_bool() {
		return date_only;
	}

	std::ostream& Date::display(std::ostream& ostr = cout)const {
		if (!error()) {
			if (date_only == true) {
				ostr << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day;
			}
			else if (date_only == false) {
				ostr << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << ", " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes;
			}
		}
		else if (error()) {
			if (date_only == true) {
				ostr << error() << "(" << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << ")";
			}
			else if (date_only == false) {
				ostr << error() << "(" << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << ", " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ")";
			}
		}
	
		
		
		return ostr;
	}


	ostream& operator<<(std::ostream& ostr, const Date& Date) {
		return Date.display(ostr);

	}

	istream& operator>>(istream& istr, Date& Date) {
		Error error;
		
		//error.set_error("nullptr");

		Date.set_Empty();
		bool validity = true;

		int c_year=0;
		int c_month=0;
		int c_day=0;
		int c_hours=0;
		int c_minutes=0;
		
		if (Date.get_bool() == true) {
			istr >> c_year;
			if (istr.fail()) {
			
				validity = false;
				return istr;
			}
			
			
			istr.ignore();

			istr >> c_month;
			
			if (istr.fail()) {
				
				Date.set_error("Cannot read month entry");
				validity = false;
				return istr;
			}
			istr.ignore();

			istr >> c_day;
			if (istr.fail()) {
				Date.set_error("Cannot read day entry");
				validity = false;
				return istr;
			}
			c_hours = 0;
			c_minutes = 0;
		}
		

		else if (Date.get_bool()==false) {
			
			istr >> c_year;
			if (istr.fail()) {

				
				Date.set_error("Cannot read year entry");
				validity = false;
				return istr;
			}
			
	       
			istr.ignore();

			istr >> c_month;
			if (istr.fail()) {
				Date.set_Empty();
				Date.set_year(c_year);
				Date.set_error("Cannot read month entry");
				validity = false;
				return istr;
			}
			
			istr.ignore();

			istr >> c_day;
			
			if (istr.fail()) {
				//Date.set_Empty();
				Date.set_year(c_year);
				Date.set_month(c_month);
				Date.set_error("Cannot read day entry");
				validity = false;
				return istr;
			}

			istr.ignore();
			istr >> c_hours;
			if (istr.fail()) {
				//Date.set_Empty();
				Date.set_year(c_year);
				Date.set_month(c_month);
				Date.set_day(c_day);
				//Date.set_day(c_day);
				Date.set_error("Cannot read hour entry");
				validity = false;
				return istr;
			}
			istr.ignore();

			istr >> c_minutes;
			if (istr.fail()) {
				Date.set_year(c_year);
				Date.set_month(c_month);
				Date.set_day(c_day);
				Date.set_hours(c_hours);
				Date.set_error("Cannot read minute entry");
				validity = false;
				return istr;
			}
		}

		if (validity == true && Date.get_bool() == true) {
			Date.set_year(c_year);
			Date.set_month(c_month);
			Date.set_day(c_day);
			Date.valid_Data();

		}
		else if (validity == true && Date.get_bool() == false) {
			Date.set_year(c_year);
			Date.set_month(c_month);
			Date.set_day(c_day);
			Date.set_hours(c_hours);
			Date.set_minutes(c_minutes);
			Date.valid_Data();

		}
		return istr;
		
		
	}


	bool Date::operator==(const Date& other) const {
		if (date_only == true) {
			return year == other.year && month == other.month && day == other.day;
		}
		else if(date_only==false) {
			return year == other.year && month == other.month && day == other.day && hours == other.hours && minutes == other.minutes;
		}
		else {
			return 0;
		}
		
	}
	bool Date::operator!=(const Date& other) const {
		return !(*this == other);
	}
	bool Date::operator<(const Date& other) const {
		if (year < other.year) {
			return true;
		}
		else if (year > other.year) {
			return false;
		}
		else if (month < other.month) {
			return true;
		}
		else if (month > other.month) {
			return false;
		}
		else {
			return day < other.day;
		}
	}
	bool Date::operator>(const Date& other) const {
		return other < *this;
	}
	bool Date::operator<=(const Date& other) const {
		return !(other < *this);
	}
	bool Date::operator>=(const Date& other) const {
		return !(*this < other);
	}

	void Date::set_year(int temp_year) {
		year = temp_year;
	}
	void Date::set_month(int temp_month) {
		month = temp_month;
	}
	void Date::set_day(int temp_day) {
		day = temp_day;
	}
	void Date::set_hours(int temp_hour) {
		hours = temp_hour;
	}
	void Date::set_minutes(int temp_minutes) {
		minutes = temp_minutes;
	}
	

}
