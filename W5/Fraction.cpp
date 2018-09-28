// Workshop 5: operator overloading
// File: Fraction.cpp
// Date: 2018/2/19
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description:
// This file contains function definitions.
/////////////////////////////////////////////

// include necessary header files
#include <iostream>
#include "Fraction.h"

using namespace std;

// continue the namespace
namespace sict {

	// implement the default constructor
	// This constructor sets an object to a safe empty state
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}

	// implement the two-argument constructor
	// This constructor sets data after validation
	Fraction::Fraction(int temp_numerator, int temp_denominator) {
		if (temp_numerator >= 0 && temp_denominator > 0) {

			numerator = temp_numerator;
			denominator = temp_denominator;
			reduce();

		} else {
			*this = Fraction();
		}
	}

	// implement the max query
	// This function returns greater value
	int Fraction::max() const {
		return (numerator > denominator) ? numerator : denominator;
	}

    // implement the min query
	// This function returns lesser value
	int Fraction::min() const {
		return (numerator < denominator) ? numerator : denominator;
	}

	// gcd returns the greatest common divisor of num and denom
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // implement the reduce modifier
	// This function devide instances by gcd()
	void Fraction::reduce() {
		int g_c_d = gcd();
		numerator /= g_c_d;
		denominator /= g_c_d;
	}

    // implement the display query
	// This function displays object
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		} else {
			if (denominator == 1) {
				cout << numerator;
			} else {
				cout << numerator << "/" << denominator;
			}
		}
	}

    // implement the isEmpty query
	// This function checks if an objects is in a safe empty state
	bool Fraction::isEmpty() const {
		return (numerator == 0 && denominator == 0) ? true : false;
	}

    // implement the + operator
	// This function returns a copy of the result of the addition operation in reduced form
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction temp;
		if (isEmpty() == false && rhs.isEmpty() == false){
			temp.numerator = (denominator * rhs.numerator) + (numerator * rhs.denominator);
			temp.denominator = denominator * rhs.denominator;
		}

		return temp;
	}

	// implement the * operator
	// This function returns a copy of the results of the multiplication operation in reduced form
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction temp;
		if (isEmpty() == false && rhs.isEmpty() == false){
			temp.numerator = rhs.numerator * numerator;
			temp.denominator = rhs.denominator * denominator;
		}

		return temp;
	}

	// implement the == operator
	// This function checks if the both operands are non-empty fractions of equal value
	bool Fraction::operator==(const Fraction& rhs) const {
		if (isEmpty() == false && rhs.isEmpty() == false) {
			return ((numerator * rhs.denominator) == (denominator * rhs.numerator)) ? true : false; 
		}

		return false;
	}

	// implement the != operator
	// This function checks if the both operands are non-empty fractions of unequal value
	bool Fraction::operator!=(const Fraction& rhs) const {
		if (isEmpty() == false && rhs.isEmpty() == false) {
			return ((numerator * rhs.denominator) != (denominator * rhs.numerator)) ? true : false; 
		}

		return false;
	}

	// implement the += operator
	// This function returns a reference to the current object storing the result of the addition operation in reduced form
	Fraction Fraction::operator+=(const Fraction& rhs) {
		if (isEmpty() == false && rhs.isEmpty() == false) {
			*this = *this + rhs;
			reduce();
			return *this;
		}

		return *this;
	}

}
