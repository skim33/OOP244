// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Date: 2018/03/26
// Author: Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description:
// This file contains declarations.
///////////////////////////////////////////////////

// header safeguard
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

// include necessary header
#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount {
		double bal;

	protected:
		double balance() const;

	public:
		// constructor initializes account balance, defaults to 0.0 
		Account(double);

		// credit adds +ve amount to the balance 
		bool credit(double);

		// debit subtracts a +ve amount from the balance
		bool debit(double);
	};


}
#endif
