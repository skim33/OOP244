// OOP244 Workshop 7: Derived Classes
// SuperHero.h
// Date 2018/03/19
// Author Woohyuk Kim
// Description
//       This file contains declarations.
/////////////////////////////////////////////////////

// declare header safe guard
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

// include necessary header
#include <iostream>

namespace sict {

	// declare superhero class
	class SuperHero : public Hero {
		char name[max_name];
		int health;
		int attack;
		int bonus;
		int defendS;

	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};

	// declare helper operator
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif
