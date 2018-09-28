// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2018/03/30
// Author: Woohyuk Kim
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

// include necessary headers
#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double in_acc_bal, double _trans_fee, double _month_fee) : Account(in_acc_bal) {
		if (_trans_fee > 0) {
			trans_fee = _trans_fee;

		} else {
			trans_fee = 0.0;
		}

		if (_month_fee > 0) {
			month_fee = _month_fee;
		} else {
			month_fee = 0.0;
		}
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double amount) {
		if (amount > 0) {
			Account::credit(amount - trans_fee);
			return true;
		}
		return false;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double amount) {
		if (amount > 0) {
			Account::debit(amount + trans_fee);
			return true;
		}
		return false;
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		ChequingAccount::debit(month_fee);
	}

	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os.precision(2);
		os.setf(ios::fixed);
		os << "Balance: $" << balance() << endl;
		os << "Per Transaction Fee: " << trans_fee << endl;
		os << "Monthly Fee: " << month_fee << endl;
		os.precision(6);
	}
}
