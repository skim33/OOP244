// Final Project - Milestone 3 - MyProduct and Test Modules
// Version 3.3
// Date: March 23, 2018
// Product.cpp
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description
// This file contains definitions to used in this program.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

// include necessaey headers
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Product.h"

using namespace std;

namespace AMA {

	// set name after validation
	void Product::name(const char* name) {
		if (name != nullptr) {
			delete[] prodName;
			prodName = nullptr;
			prodName = new char[strlen(name) + 1];
			strncpy(prodName, name, strlen(name) + 1);
			prodName[strlen(name)] = '\0';
		
		} else {
			delete[] prodName;
		}
	}

	// returns name
	const char* Product::name() const {
		return prodName;
	}

	// returns prodSku
	const char* Product::sku() const {
		return prodSku;
	}

	// returns prodUnit
	const char* Product::unit() const {
		return prodUnit;
	}

	// returns prodTax
	bool Product::taxed() const {
		return prodTax;
	}

	// returns prodPrice
	double Product::price() const {
		return prodPrice;
	}

	// returns price or price including tax
	double Product::cost() const {
		if (taxed()){
			return price() * (1 + tax_rate);
		
		} else {
			return price();
		}
	}

	// set message after validation
	void Product::message(const char* errorMessage) {
		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			err.clear();
		
		} else {
			err.message(errorMessage);
		}
	}

	// returns true if err is nullptr otherwise false
	bool Product::isClear() const {
		if (err.isClear()) {
			return true;
		}
		return false;
	}

	// set data to safe empty state. if type is given, set it to current object
	Product::Product(char optional) {
		type = optional;
		prodSku[0] = '\0';
		prodUnit[0] = '\0';
		prodName = nullptr;
		qty = 0;
		neededQty = 0;
		prodPrice = 0;
		prodTax = true;
		err.clear();
	}

	// set data to the current object
	Product::Product(const char* _prodSku, const char* _prodName, const char* _prodUnit, int _qty, bool _prodTax, double _prodPrice, int _neededQty) {
		type = 'N';
		strncpy(prodSku, _prodSku, max_sku_length);
		prodSku[max_sku_length - 1] = '\0';
		prodName = nullptr;
		name(_prodName);
		strncpy(prodUnit, _prodUnit, max_unit_length);
		prodUnit[max_unit_length - 1] = '\0';
		qty = _qty;
		prodTax = _prodTax;
		prodPrice = _prodPrice;
		neededQty = _neededQty;
	}

	// copies the object referenced to the current object
	Product::Product(const Product& src) {
		prodName = nullptr;
		*this = src;
	}

	// replaces the current object with a copy of the object referenced
	Product& Product::operator=(const Product& src) {
		if (this != &src) {
			strncpy(prodSku, src.sku(), max_sku_length);
			prodSku[max_sku_length] = '\0';
			strncpy(prodUnit, src.unit(), max_unit_length);
			prodUnit[max_unit_length] = '\0';
			qty = src.quantity();
			neededQty = src.qtyNeeded();
			prodPrice = src.price();
			prodTax = src.taxed();
			if (src.err.message() != nullptr && src.err.message()[0] != '\0') {
				err.message(src.err.message());
			
			}else {
				err.clear();
			}
			
			prodName = nullptr;
			if (src.name() != nullptr) {
				name(src.name());
			}
		}
		return *this;
	}

	// deallocates memory that has been synamically allocated
	Product::~Product() {
		delete [] prodName;
	}

	// returns a reference to the fstream object
	fstream& Product::store(fstream& file, bool newLine) const {
		file << type << ',';
		file << sku() << ',';
		file << name() << ',';
		file << unit() << ',';
		file << taxed() << ',';
		file << price() << ',';
		file << quantity() << ',';
		file << qtyNeeded();
		
		if (newLine) {
			file << '\n';
		}

		return file;
	}

	// returns a reference to fstream object
	fstream& Product::load(fstream& file) {
		char _prodSku[max_sku_length + 1];
		char _prodName[max_name_length + 1];
		double _prodPrice;
		bool _prodTax;
		int _qty;
		char _prodUnit[max_unit_length + 1];
		int _neededQty;
	
        if (file.is_open()) {
			file.getline(_prodSku, max_sku_length, ',');
			file.getline(_prodName, max_name_length, ',');
			file.getline(_prodUnit, max_unit_length, ',');
			file >> _prodTax;
			file.ignore();
			file >> _prodPrice;
			file.ignore();
			file >> _qty;
			file.ignore();
			file >> _neededQty;


			*this = Product(_prodSku, _prodName, _prodUnit, _qty, _prodTax, _prodPrice, _neededQty);

             // file opened;
		} else {
        	cout << "file is not opened. " << endl;
        }

		return file;
	}

	// returns a reference to the ostream object after validation
	ostream& Product::write(ostream& os, bool linear) const {
		
		if (err.isClear()) {

			if (linear) {
				os << std::setw(7) << std::setfill(' ') << std::left << sku() << "|";
				os << std::setw(20) << std::left << name() << "|";
				os << std::setw(7) << std::fixed << std::right << std::setprecision(2) << cost() << "|";
				os << std::setw(4) << std::right << quantity() << "|";
				os << std::setw(10) << std::left << unit() << "|";
				os << std::setw(4) << std::right << qtyNeeded() << "|";

			} else {
				
				os << " Sku: " << sku() << endl;
				os << " Name (no spaces): " << name() << endl;
				os << " Price: " << fixed << price() << endl;
				os << " Price after tax: ";
				if (taxed()) {
					os << fixed << cost() << endl;
				} else {
					os << "N/A" << endl;
				}
				os << " Quantity on Hand: " << quantity();
				os << " " << unit() << endl;
				os << " Quantity needed: " << qtyNeeded();
				

			}

		} else {
			os << err.message();
		}

		return os;
	}

	// returns a reference to the istream object after validation
	istream& Product::read(istream& is) {
		char _prodSku[max_sku_length + 1];
		char _prodName[max_name_length + 1];
		char _prodUnit[max_unit_length + 1];
		char check_tax;
		bool check;
		double _prodPrice;
		int _qty;
		int _neededQty;

		err.clear();
		cout << " Sku: ";
		is.getline(_prodSku, max_sku_length + 1, '\n');
		if (is.fail()) { return is; }

		cout << " Name (no spaces): ";
		is.getline(_prodName, max_name_length + 1, '\n');
		if (is.fail()) { return is; }

		cout << " Unit: ";
		is.getline(_prodUnit, max_unit_length + 1, '\n');
		if (is.fail()) { return is; }

		if (err.isClear()) {
			cout << " Taxed? (y/n): ";
			is >> check_tax;

			if (check_tax == 'Y' || check_tax == 'y') {
				check = true;
			} else if (check_tax == 'N' || check_tax == 'n') {
				check = false;
			} else {
				is.setstate(ios::failbit);
				err.message("Only (Y)es or (N)o are acceptable");
				return is;
			}
		}

		if (err.isClear()) {
			cout << " Price: ";
			is >> _prodPrice;
			if (is.fail()) {
				err.message("Invalid Price Entry");
				return is;
			}
		}

		if (err.isClear()) {
			cout << " Quantity on hand: ";
			is >> _qty;

			if (is.fail()) {
				err.message("Invalid Quantity Entry");
				return is;
			}
		}

		if (err.isClear()) {
			cout << " Quantity needed: ";
			is >> _neededQty;
			is.ignore();

			if (is.fail()) {
				err.message("Invalid Quantity Needed Entry");
				return is;
			}
		}

		*this = Product(_prodSku, _prodName, _prodUnit, _qty, check, _prodPrice, _neededQty);

		return is;
	}

	// returns true if the string is identical to the sku of the current object
	bool Product::operator==(const char* string_sku) const {
		if (strcmp(prodSku, string_sku) == 0) {
			return true;
		}
		return false;
	}
	
	// returns the total cost of all items of the product on hand to the number received
	double Product::total_cost() const {
		return quantity() * cost();
	}

	// resets the number of units that are on hand to the number received
	void Product::quantity(int unit) {
		qty = unit;
	}

	// returns true if the object is in a safe empty state
	bool Product::isEmpty() const {
		if (type == 'N' && prodSku[0] == '\0' && prodUnit[0] == '\0' && prodName == nullptr && qty == 0 && neededQty == 0 && prodPrice == 0 && prodTax && isClear()) {
			return true;
		}

		return false;
	}

	// returns the number of units of the product that are needed
	int Product::qtyNeeded() const {
		return neededQty;
	}

	// returns the number of units of the product that are on hand
	int Product::quantity() const {
		return qty;
	}

	// returns true if the skuf the current object is greater than the string the string stored at the received address
	bool Product::operator>(const char* sku_tmp) const {
		if (strlen(sku()) > strlen(sku_tmp)) {
			return true;
		}
		else if (strlen(sku()) < strlen(sku_tmp)) {
			return false;
		}
		else {
			int sku_length = strlen(sku());
			for (int i = 0; i < sku_length; i++) {
				if (prodSku[i] > sku_tmp[i]) {
					return true;
				}
			}
			return false;
		}
	}

	// returns true if the name of the current object is greater than the name referenced Product object
	bool Product::operator>(const iProduct& product) const {
		if (strcmp(name(), product.name()) > 0) {
			return true;
		}
		return false;
	}

	// returns the updated number of units on hand
	int Product::operator+=(int unit_tmp) {
		if (unit_tmp > 0) {
			qty += unit_tmp;
		}
		return quantity();
	}

	// returns a reference to the ostream object
	ostream& operator<<(ostream& os, const iProduct& product) {
		product.write(os, true);
		return os;
	}

	// returns a reference to the istream object
	istream& operator>>(istream& is, iProduct& product) {
		product.read(is);
		return is;
	}

	// returns a double after addition
	double operator+=(double& totalCost, const iProduct& product) {
		totalCost += product.total_cost();
		return totalCost;
	}
}
