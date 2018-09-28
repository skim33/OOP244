// Final Project Milestone 1
//
// Version 1.0
// Date.cpp
// Date: 14/03/2018
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description:
//	This file contains function definitions used in this program.
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason

// include necessary headers
#include<iostream>
#include "Date.h"

using namespace std;

namespace AMA {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	// this function sets the error state variable
	void Date::errCode(int errCode) {
		err = errCode;
	}

	// this function sets the current object to a safe empty state
	Date::Date() {
		err = 0;
		year = 0;
		month = 0;
		day = 0;
		comp_value = 0;
	}

	// this function stores the values received in the current object after validation
	Date::Date(int _year, int _month, int _day) {
		bool yCheck = true;
		bool mCheck = true;
		bool dCheck = true;

		if (_year < min_year || _year > max_year) {
			yCheck = false;
			*this = Date();
			err = YEAR_ERROR;
		}

		if (_month < min_month || _month > max_month) {
			mCheck = false;
			*this = Date();
			err = MON_ERROR;
		}

		if (_day <= 0 || _day > mdays(_month, _year)) {
			dCheck = false;
			*this = Date();
			err = DAY_ERROR;
		}

		if (yCheck && mCheck && dCheck) {
			year = _year;
			month = _month;
			day = _day;
			err = NO_ERROR;
			comp_value = (_year * 372) +(_month * 13) + _day;
		}

	}

	// this function checks if the Date stored in the current object is equal to the data in rhs
	bool Date::operator==(const Date& rhs) const {
		return ((!(this->bad())) && (!rhs.bad()) && (this->comp_value == rhs.comp_value) ? true : false);
	}

	// this function checks if the Date stored in the current object is not equal to the data in rhs
	bool Date::operator!=(const Date& rhs) const {
		return ((!(this->bad())) && (!rhs.bad()) && (this->comp_value != rhs.comp_value) ? true : false);
	}

	// this function checks if the Date stored in the current object is before the data in rhs
	bool Date::operator<(const Date& rhs) const {
		return ((!(this->bad())) && (!rhs.bad()) && (this->comp_value < rhs.comp_value) ? true : false);
	}

	// this function checks if the Date stored in the current object is after the data in rhs
	bool Date::operator>(const Date& rhs) const {
		return ((!(this->bad())) && (!rhs.bad()) && (this->comp_value > rhs.comp_value) ? true : false);
	}

	// this function checks if the Date stored in the current object is equal to or before the data in rhs
	bool Date::operator<=(const Date& rhs) const {
		return ((!(this->bad())) && (!rhs.bad()) && (this->comp_value <= rhs.comp_value) ? true : false);
	}

	// this function checks if the Date stored in the current object is equal to or after the data in rhs
	bool Date::operator>=(const Date& rhs) const {
		return ((!(this->bad())) && (!rhs.bad()) && (this->comp_value >= rhs.comp_value) ? true : false);
	}

	// this function returns the error state as an error code value
	int Date::errCode() const {
		return err;
	}

	// this function checks if the error state is NO_ERROR
	bool Date::bad() const {
		return (((this->year == 0) && (this->month == 0) && (this->day == 0)) || (err != 0) ? true : false);
	}

	// this function reads the date from the console
	std::istream& Date::read(std::istream& istr) {
		char connector;

		istr >> year >> connector >> month >> connector >> day;

		if (istr.fail()){
			errCode(CIN_FAILED);

		} else if (year < min_year || year > max_year) {
			*this = Date();
			errCode(YEAR_ERROR);

		} else if (month < min_month || month > max_month) {
			*this = Date();
			errCode(MON_ERROR);

		} else if (day <= 0 || day > mdays(month, year)){
			*this = Date();
			errCode(DAY_ERROR);
		}

		return istr;

	}

	// this function writes date to an std::ostream object
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << year << "/";

		ostr.fill('0');
		ostr.width(2);
		ostr << month << "/"; 
		ostr.width(2);
		ostr << day;

		return ostr;

	}

	// this operator works with an std::ostream object to print a date
	std::ostream& operator<<(std::ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

	// this operator works with an std::istream object to read a date
	std::istream& operator>>(std::istream& istr, Date& date) {
		return date.read(istr);
	}
}
