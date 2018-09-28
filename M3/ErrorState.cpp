// Final Project - Milestone 3 - MyProduct and Test Modules
// Version 3.3
// Date: March 23, 2018
// ErrorState.cpp
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description
// This file contains definitions to used in this program.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

// include necessaey headers
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "ErrorState.h"

using namespace std;
namespace AMA {
	
	// copy errorMessage after validation
	//
	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			err_message = nullptr;
		}
		else if (errorMessage[0] != '\0') {
			message(errorMessage);
		}	
	}

	// deallocate dynamic memory 
	//
	ErrorState::~ErrorState() {
		delete[] err_message;
	}

	// deallocate dynamic memory for err_message
	//
	void ErrorState::clear() {
		delete[] err_message;
		err_message = nullptr;
	}

	// return true if the current object is in safe empty state
	//
	bool ErrorState::isClear() const {
		if (err_message == nullptr) {
			return true;
		}
		return false;
	}

	// copy str string 
	//
	void ErrorState::message(const char* str) {
		delete[] err_message;
		err_message = new char[strlen(str) + 1];
		strncpy(err_message, str, strlen(str));

	}

	// return the address of err_message
	//
	const char* ErrorState::message() const {
		return err_message;
	}

	// send ErrorState message after validation
	//
	ostream& operator<<(ostream& os, const ErrorState& em) {
		if (!em.isClear()) {
			os << em.message();
		}
		return os;
	}
}
