// Workshop 5: operator overloading
// File: Fraction.h
// Date: 2018/2/19
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description:
// This file contains declarations.
/////////////////////////////////////////////

// header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// Declare namespace
namespace sict {

	// define the Fraction class
	class Fraction {
		// declare instance variables
		int numerator;
		int denominator;

		// declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;

		// declare the operators
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);
	};
}

#endif
