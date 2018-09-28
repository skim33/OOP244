// Workshop 4 - Constructors
// Passenger.h
// Woohyuk Kim
// Email: wkim33@myseneca.ca
// 2/16/2017
// This file contains function declarations.

// Adding header file guard
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// Declare namespace
namespace sict {
	const int max_size = 32;

	// Define the Passenger class
	class Passenger {
		char p_name[max_size + 1];
		char p_destination[max_size + 1];
		int p_year;
		int p_month;
		int p_day;

	public:
		Passenger();
		Passenger(const char *name, const char *destination );
		bool isEmpty() const;
		void display() const;
		Passenger(const char *name, const char *destination, int year, int month, int day);
		const char *name() const;
		bool canTravelWith(const Passenger& passenger) const;
	};

}
#endif


