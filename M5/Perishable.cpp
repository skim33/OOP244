// Final Project Milestone 5
//
// Version 1.0
// Perishable.cpp
// Date: 16/04/2018
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description:
//	This file contains declarations used in this program.
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

// include necessary header
#include "Perishable.h"

namespace AMA {

	// sets the current object to a safe empty state
	Perishable::Perishable() : Product('P') {
		date = Date();
	}

	// returns a reference to the modified fstream object
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, false);
		file << ',' << expiry();

		if (newLine) {
			file << '\n';
		}

		return file;
	}

	// returns a reference to fstream object
	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);
		file.ignore();
		date.read(file);
		return file;
	}

	// returns a reference to the modified ostream object
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear) {
				os << expiry();

			} else {
				os << std::endl << " Expiry date: " << expiry();
			}
		}

		return os;
	}

	// returns a reference to the modified istream object
	std::istream& Perishable::read(std::istream& is) {
		Date _date;

		Product::read(is);

		if (!is.fail()) {

			if (isClear()) {
				std::cout << " Expiry date (YYYY/MM/DD): ";
				
				_date.Date::read(is);

				if (_date.Date::errCode() == CIN_FAILED) {
					Product::message("Invalid Date Entry");
					is.setstate(std::ios::failbit);

				} else if (_date.Date::errCode() == YEAR_ERROR) {
					Product::message("Invalid Year in Date Entry");
					is.setstate(std::ios::failbit);

				} else if (_date.Date::errCode() == MON_ERROR) {
					Product::message("Invalid Month in Date Entry");
					is.setstate(std::ios::failbit);

				} else if (_date.Date::errCode() == DAY_ERROR) {
					Product::message("Invalid Day in Date Entry");
					is.setstate(std::ios::failbit);

				} else {
					date = _date;
				}

			}
		}

		return is;
	}

	// copy assigns the temporary Date object to the instance Date object
	const Date& Perishable::expiry() const {
		return date;
	}
}