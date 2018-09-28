// OOP244 Workshop 7: Derived Classes
// Hero.h
// Date 2018/03/19
// Author Woohyuk Kim
// Description
//       This file contains declarations.
/////////////////////////////////////////////////////

// declare header safe guard
#ifndef SICT_HERO_H
#define SICT_HERO_H

// include necessary header
#include <iostream>

namespace sict {

	const int max_rounds = 100;
	const int max_name = 40;

	// declare hero class
	class Hero {
		char name[max_name];
		int health;
		int attack;

	public:
		Hero();
		Hero(const char*, int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};

	// declare helper operator
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif