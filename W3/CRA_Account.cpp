/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 2.1
// 2018/02/05
// Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description
// This file contains function definitions.
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
//
///////////////////////////////////////////////////////////
**********************************************************/

//including necessary headers
#include "CRA_Account.h"
#include<iostream>
#include<cstring>

using namespace std;

namespace sict {
	//This function stores data after validation.
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		int sin_temp = sin;
		int sinArray[9];
		int array1[4];
		int sum_array1 = 0;
		int total = 0;
		int check_num = 0;
		
		//put the sin number in an array
		for (int i = 0; i < 9; i++) {
			sinArray[i] = sin_temp % 10;
			sin_temp = sin_temp / 10;
		}

		array1[0] = sinArray[1] * 2;
		array1[1] = sinArray[3] * 2;
		array1[2] = sinArray[5] * 2;
		array1[3] = sinArray[7] * 2;

		for (int j = 0; j < 4; j++) {
			if (array1[j] < 10) {
				sum_array1 += array1[j];

			} else {
				sum_array1 += (array1[j] % 10) + 1;
			}
		}

		total = sum_array1 + sinArray[2] + sinArray[4] + sinArray[6] + sinArray[8];

		check_num = ((total / 10) + 1) * 10;

		//if validation fails
		if (*familyName == '\0' || *givenName == '\0' || (check_num - total) != sinArray[0]) {
			first_sin = 0;
			*family_name = '\0';
			*given_name = '\0';
		
		//if validation succeeds 
		} else {
			strncpy(family_name, familyName, max_name_length);
			strncpy(given_name, givenName, max_name_length);
			first_sin = sin;
			years = 0;
		}
	}

	//This function checks if the sin is valid
	bool CRA_Account::isEmpty() const {
		if (first_sin < min_sin || first_sin > max_sin || first_sin == 0) {
			return true;
		} else {
			return false;
		}
	}

	//This function display data
	void CRA_Account::display() const {
		if (CRA_Account::isEmpty() == false) {
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << given_name << endl;
			cout << "CRA Account: " << first_sin << endl;

			if (*tax_years != '\0' && *balance_owed != '\0') {
				for (int i = 0; i < years; i++) {
					if (balance_owed[i] > 2) {
						cout << "Year (" << tax_years[i] << ") balance owing: ";
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << balance_owed[i] << endl;;

					} else if (balance_owed[i] < -2) {
						cout << "Year (" << tax_years[i] << ") refund due: ";
						cout.setf(ios::fixed); 
						cout.precision(2);
						cout << (balance_owed[i] * (-1)) << endl;

					} else {
						cout << "Year (" << tax_years[i] << ") No balance owing or refund due!" << endl;
					}
				}
			}

		} else {
			cout << "Account object is empty!" << endl;
		}
	}

	//This function set data after validation
	void CRA_Account::set(int year, double balance) {
		if (CRA_Account::isEmpty() == false) {
			tax_years[years] = year;
			balance_owed[years] = balance;
			years = years + 1;
		}
	}
}
