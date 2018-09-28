// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.h
// Date: 2018/03/26
// Author: Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description:
// This file contains declarations.
///////////////////////////////////////////////////

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double rate;
	
	public:
			// constructor initializes balance and interest rate
		SavingsAccount(double, double);

			// perform month end transactions
		void monthEnd();

			// display inserts the account information into an ostream			
		void display(std::ostream&) const;
	};
}
#endif
