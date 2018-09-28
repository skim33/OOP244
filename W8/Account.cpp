// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Date: 2018/03/26
// Author: Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description:
// This file contains function definitions.
///////////////////////////////////////////////////

// include necessary header
#include "Account.h"

namespace sict{
	// this function returns the current balance of the account
	double Account::balance() const {
		return bal;
	}

	// this function sets data after validation
	Account::Account(double temp_bal) {
		if (temp_bal > 0) {
			bal = temp_bal;
		} else {
			bal = 0;
		}
	}
	
	// this function credits an amount from the account balance
	bool Account::credit(double temp_bal) {
		if (temp_bal > 0) {
			bal += temp_bal;
			return true;

		} else {
			return false;
		}
	}

	// this function debits an amount from the account balance
	bool Account::debit(double temp_bal) {
		if (temp_bal > 0) {
			bal -= temp_bal;
			return true;

		} else {
			return false;
		}
	}
}