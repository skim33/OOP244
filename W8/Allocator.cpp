// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Date: 2018/03/26
// Author: Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description:
// This file contains function definitions.
///////////////////////////////////////////////////

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	const double rate = 0.05;
	const double trans_fee = 0.50;
	const double month_fee = 2.00;

	// Allocator function returns its address to the calling function
	iAccount* CreateAccount(const char* acc, double in_bal) {
		iAccount* a = nullptr;
		if (acc[0] == 'S') {
			a = new SavingsAccount(in_bal, rate);

		} else if (acc[0] == 'C') {
			a = new ChequingAccount(in_bal, trans_fee, month_fee);
		}

		return a;
	}








}
