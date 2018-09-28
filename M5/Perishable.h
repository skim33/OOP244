// Final Project Milestone 5
//
// Version 1.0
// Perishable.h
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

// safe header guards
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

// include necessary headers
#include<iostream>
#include<fstream>
#include "Product.h"
#include "Date.h"

namespace AMA {

	// Perishable class
	class Perishable : public Product {
		Date date;

	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}

#endif