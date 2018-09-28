// Workshop 6 - Class with a Resource
// Contact.h
// Woohyuk Kim
// Student #:121968176
// Email: wkim33@myseneca.ca
// 2018/03/14

// header file guard
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

// declare namespace
namespace sict {
	
	const int max_size = 19;
	
	// define the Contact class
	class Contact {
		
		// declare instance variables 
		char name[max_size];
		long long* num;
		int num_of_p;
	
	public:

		// declare private member functions
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool isValid(const long long);

		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+=(const long long);
	
	};
}

#endif
