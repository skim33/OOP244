#include <cstring>
#include <iostream>
#include <fstream>
#include "Product.h"

using namespace std;

namespace AMA {

	void Product::name(const char* _prodName) {
		if (_prodName == nullptr) {
			prodName = nullptr;

		} else {
			prodName = nullptr;
			prodName = new char[max_name_length + 1];
			strncpy(prodName, _prodName, max_name_length);
			prodName[max_name_length] = '\0';
		}
	}

	const char* Product::name() const {
		return prodName;
	}

	const char* Product::sku() const {
		return prodSku;
	}

	const char* Product::unit() const {
		return prodUnit;
	}

	bool Product::taxed() const {
		return tax_state;
	}

	double Product::price() const {
		return prodPrice;
	}

	double Product::cost() const {
		return prodPrice * (1 + tax);
	}

	void Product::message(const char* _err) {
		err.message(_err);
	}

	bool Product::isClear() const {
		return err.isClear();
	}
	
	Product::Product(char c) {
		productType = c;
		prodSku[0] = '\0';
		prodUnit[0] = '\0';
		prodName[0] = '\0';
		currentQty = 0;
		neededQty = 0;
		prodPrice = 0.0;
		tax_state = true;

	}

	Product::Product(const char* _prodSku, const char* _prodName, const char* _prodUnit, int _currentQty, bool _tax_state, double _prodPrice, int _neededQty) {
		if (_prodUnit != nullptr && _prodUnit[0] != '\0') {
			strncpy(prodUnit, _prodUnit, max_unit_length + 1);
			prodUnit[max_unit_length] = '\0';
		}
		else {
			strncpy(prodSku, _prodSku, max_sku_length + 1);
			prodSku[max_sku_length] = '\0';
			strncpy(prodName, _prodName, max_name_length + 1);
			prodName[max_name_length] = '\0';
			prodUnit[0] = '\0';
			currentQty = _currentQty;
			tax_state = _tax_state;
			prodPrice = _prodPrice;
			neededQty = _neededQty;
		}
	}

	Product::Product(const Product& src) {
		strncpy(prodSku, src.prodSku, max_sku_length + 1);
		prodSku[max_sku_length] = '\0';
		strncpy(prodName, src.prodName, max_name_length + 1);
		prodName[max_name_length] = '\0';
		strncpy(prodUnit, src.prodUnit, max_unit_length + 1);
		prodUnit[max_unit_length] = '\0';
		currentQty = src.currentQty;
		tax_state = src.tax_state;
		prodPrice = src.prodPrice;
		neededQty = src.neededQty;
	}

	Product& Product::operator=(const Product& src) {
		if (this != &src) {
	
			strncpy(prodSku, src.prodSku, max_sku_length + 1);
			prodSku[max_sku_length] = '\0';
		
			strncpy(prodName, src.prodName, max_name_length + 1);
			prodName[max_name_length] = '\0';
	
			strncpy(prodUnit, src.prodUnit, max_unit_length + 1);
			prodUnit[max_unit_length] = '\0';
			currentQty = src.currentQty;
			tax_state = src.tax_state;
			prodPrice = src.prodPrice;
			neededQty = src.neededQty;
		}
		return *this;
	}

	Product::~Product() {
		delete [] prodSku;
		delete [] prodName;
		delete [] prodUnit;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file << productType << ',';
		file << sku() << ',';
		file << unit() << ',';
		file << name() << ',';
		file << quantity() << ',';
		file << qtyNeeded() << ',';
		file << price() << ',';
		file << taxed() << ',';

		if (newLine) {
			file << '\n';
		}
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		Product *temp = nullptr;
		temp = new Product();

		file.getline(temp->prodSku, max_sku_length, ',');
		file.getline(temp->prodUnit, max_unit_length, ',');
		file.getline(temp->prodName, max_name_length, ',');
		file >> temp->currentQty;
		file.ignore(1);
		file >> temp->neededQty;
		file.ignore(1);
		file >> temp->prodPrice;
		file.ignore(1);
		file >> temp->tax_state;

		*this = *temp;

		delete temp;

		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (linear) {
			os.width(max_sku_length);
			os.setf(ios::left);
			os << sku() << '|';
			os.width(20);
			os << name() << '|';
			os.unsetf(ios::left);
			os.width(7);
			os.setf(ios::right);
			os.setf(ios::fixed);
			os.precision(2);
			os << prodPrice << '|';
			os.width(4);
			os << currentQty << '|';
			os.unsetf(ios::right);
			os.width(10);
			os.setf(ios::left);
			os << prodUnit << '|';
			os.unsetf(ios::left);
			os.width(4);
			os.setf(ios::right);
			os << neededQty << '|';
			os.unsetf(ios::right);

		} else {
			os << "Sku: " << sku() << std::endl;
			os << "Name (no spaces): " << name() << std::endl;
			os << "Price: " << price() << std::endl;
			os << "Price after tax: ";
			if (cost() != price()) {
				os << cost() << std::endl;
			} else {
				os << "N/A" << std::endl;
			}
			os << "Quantity On Hand: " << quantity() << std::endl;
			os << "Quantity Needed: " << qtyNeeded() << std::endl;
		}
		return os;
	}

	std::istream& Product::read(std::istream& is) {
		Product *temp = nullptr;
		temp = new Product();
		char taxed;
		bool keep = true;

		while (keep) {
		
			std::cout << "Sku: ";
			cin.getline(temp->prodSku, max_sku_length);
			std::cout << "Name (no spaces): ";
			cin.getline(temp->prodName, max_name_length);
			std::cout << "Unit: ";
			is >> temp->prodUnit;
			is.clear();
			std::cout << "Taxed? (y/n): ";
			is >> taxed;
			if (taxed == 'Y' || taxed == 'y') {
				temp->tax_state = true;
			} else if (taxed == 'N' || taxed == 'n') {
				temp->tax_state = false;
			} else {
				temp->err.message("Only (Y)es or (N)o are acceptable");
				is.setstate(ios::failbit);
				keep = false;
			}
			std::cout << "Price: ";
			is >> temp->prodPrice;
			if (is.fail()) {
				temp->err.message("Invalid Price Entry");
				is.setstate(ios::failbit);
				keep = false;
			}
			is.clear();
			std::cout << "Quantity On Hand: ";
			is >> temp->currentQty;
			if (is.fail()) {
				temp->err.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				keep = false;
			}
			is.clear();
			std::cout << "Quantity Needed: ";
			is >> temp->neededQty;
			if (is.fail()) {
				temp->err.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				keep = false;
			}
			is.clear();

			break;

		}

		if (!cin.fail()) {
			temp->err.clear();
		}

		*this = *temp;

		delete temp;

		return is;
	}

	bool Product::operator==(const char* src) const {
		return ((prodSku == src) ? true : false);
	}

	double Product::total_cost() const {
		return prodPrice * currentQty * (1 + tax);
	}

	void Product::quantity(int _currentQty) {
		currentQty = _currentQty;
	}

	bool Product::isEmpty() const {
		if (prodSku[0] == '\0' && prodName == nullptr && prodUnit[0] == '\0' && tax_state == false && prodPrice == 0 && currentQty == 0 && neededQty == 0) {
			return true;
		}
		return false;
	}

	int Product::qtyNeeded() const {
		return neededQty;
	}

	int Product::quantity() const {
		return currentQty;
	}

	bool Product::operator>(const char* src) const {
		std::string str1(prodSku);
		std::string str2(src);
		return (str1.compare(str2) > 0) ? true : false;
	}

	bool Product::operator>(const Product& temp) const {
		std::string str1(prodName);
		std::string str2(temp.prodName);
		return (str1.compare(str2) > 0) ? true : false;
	}

	int Product::operator+=(int unit) {
		if (unit > 0) {
			currentQty += unit;
		}
		return currentQty;
	}
	
	std::ostream& operator<<(std::ostream& os, const Product& temp) {
		temp.write(os, true);
		return os;
	}

	std::istream& operator>>(std::istream& is, Product& temp) {
		temp.read(is);
		return is;
	}

	double operator+=(double& add, const Product& temp) {
		add = temp.total_cost();
		return add;
	}
}
