// Final Project Milestone 2 - ErrorState Class
// ErrorState.cpp
// Date	2018-03-21
// Author Woohyuk Kim
//
// Description
// This file contains function definitions to be used in this 
// program.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////

// include necessary headers
#include <cstring>
#include "ErrorState.h"

using namespace std;

namespace AMA {

	// this function sets data 
	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			mes = nullptr;

		} else {
			message(errorMessage);
		}
		
	}

	// this function deallocates dynamically allocated memory
	ErrorState::~ErrorState() {
		delete [] mes;
	}
	
	// this function clears any message stored by the current object
	void ErrorState::clear() {
		delete [] mes;
		mes = nullptr;
	}
	
	// this function checks if the current object is in a safe empty state
	bool ErrorState::isClear() const {
		return (mes == nullptr ? true : false);
	}
	
	// this function stores a copy of the string
	void ErrorState::message(const char *str) {
		clear();
		mes = new char[strlen(str) + 1];
		strncpy(mes, str, strlen(str));
		mes[strlen(str) + 1] = '\0';
	}
	
	// this function returns the address of the message stored in the current object
	const char* ErrorState::message() const {
		return mes;
	}

	// this function sends an ErrorState message if one exists
	std::ostream& operator<<(std::ostream& os, const ErrorState& s) {
		if (!(s.isClear())) {
			os << s.ErrorState::message();
		}
		
		return os;
	}
}
