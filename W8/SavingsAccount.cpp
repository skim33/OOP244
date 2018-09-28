// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Date: 2018/03/26
// Author: Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description:
// This file contains function definitions.
///////////////////////////////////////////////////

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
	// this function sets data after validation
	SavingsAccount::SavingsAccount(double in_bal, double in_rate) : Account(in_bal){
		if (in_rate > 0) {
			rate = in_rate;

		} else {
			rate = 0.0;
		}
	}

	// this function calculates the interest earned on the current balance
	void SavingsAccount::monthEnd() {
		Account::credit(balance() * rate);
	}
	
	// this function displays data
	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << endl;
		os << "Balance: $";
		os.setf(ios::fixed);
		os.precision(2);
		os << balance() << endl;
		os << "Interest Rate (%): ";
		os << rate * 100 << endl;
		os.unsetf(ios::fixed);
		os.precision(6);

	}
}