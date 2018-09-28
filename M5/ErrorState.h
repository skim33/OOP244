// Final Project - Milestone 3 - MyProduct and Test Modules
// Version 3.3
// Date: March 23, 2018
// ErrorState.h
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description
// This file contains declarations to be used in Product.h.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////

// safe header guard
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

namespace AMA {

	// create ErrorState class
	class ErrorState {
		char* err_message;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState&) = delete;
		ErrorState& operator=(const ErrorState&) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream&, const ErrorState&);
}
#endif
