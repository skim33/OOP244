// Final Project - Milestone 3 - MyProduct and Test Modules
// Version 3.3
// Date: March 23, 2018
// Product.h
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description
// This file contains declarations to be used in Product.cpp.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

// safe header guard
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

// include necessary headers
#include <iostream>
#include "ErrorState.h"

namespace AMA {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	// create Product class
	class Product : public ErrorState {
		char type;
		char prodSku[max_sku_length];
		char prodUnit[max_unit_length];
		char* prodName;
		int qty;
		int neededQty;
		double prodPrice;
		bool prodTax;
		ErrorState err;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Product();
		Product(char = 'N');
		Product(const char*, const char*, const char*, int = 0, bool = true, double = 0, int = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream&, bool = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}

#endif