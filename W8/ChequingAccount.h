// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Version: 2.0
// Date: 2018/03/30
// Author: Woohyuk Kim
// Description:
// This file contains declarations for ChequingAccount class. 
///////////////////////////////////////////////////

// header safe guard
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

// include necessary header
#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
		double trans_fee;
		double month_fee;

		public:
			// constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);

			// credit adds +ve amount to the balance
			bool credit(double);

			// debit subtracts a +ve amount from the balance
			bool debit(double);

			// month end
			void monthEnd();

			// display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif
