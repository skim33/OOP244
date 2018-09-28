// Final Project Milestone 2 - ErrorState Class
// ErrorState.h
// Date	2018-03-21
// Author Woohyuk Kim
//
// Description
// This file contains declarations to be used in this 
// program.
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////

// define header safe guards
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

// include necessary header
#include <iostream>

namespace AMA {
	
	// define ErrorState class
	class ErrorState {
		char *mes;

	public:
		explicit ErrorState(const char* err = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState&) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char *);
		const char* message() const;
	};

	// helper operator
	std::ostream& operator<<(std::ostream&, const ErrorState&);
}


#endif
