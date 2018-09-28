// Final Project - Milestone 4
// Version 3.3
// Date: April 10, 2018
// iProduct.h
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description
// This file contains declarations.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

// safe header guard
#ifndef AMA_iProduct_H
#define AMA_iProduct_H

// include necessary headers
#include <iostream>
#include <fstream>

namespace AMA {
	
	// create iProduct class
	class iProduct {

	public:
		// pure virtual functions
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iProduct&) const = 0;
	};
	
	// helper functions
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
	iProduct* CreateProduct();
	iProduct* CreatePerishable();	
}

#endif
