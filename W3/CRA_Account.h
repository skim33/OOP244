/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 2.1
// 2018/02/05
// Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description
// This file contains class declaration. 
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// 
///////////////////////////////////////////////////////////
**********************************************************/

//including a compilation safegurd 
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

//declare namespace
namespace sict {
	//predefine constants
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	//define class
	class CRA_Account {
		char family_name[max_name_length];
		char given_name[max_name_length];
		int first_sin;
		int tax_years[max_yrs];
		double balance_owed[max_yrs];
		int years;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};
}
#endif
