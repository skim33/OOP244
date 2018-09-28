// OOP244 Workshop 7: Derived Classes
// Hero.cpp
// Date 2018/03/19
// Author Woohyuk Kim
// Description
//       This file contains function definitions.
/////////////////////////////////////////////////////

// include necessary headers
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;

namespace sict {
	
	// this function sets data to a safe empty state
	SuperHero::SuperHero() : Hero() {
		bonus = 0;
		defendS = 0;
	}
	
	// this function sets data after validation
	SuperHero::SuperHero(const char* _name, int _health, int _attack, int _bonus, int _defendS) : Hero(_name, _health, _attack) {
		if (_bonus > 0 && _defendS > 0) {
			bonus = _bonus;
			defendS = _defendS;

		} else {
			*this = SuperHero();
		}
	}
	
	// this function returns the attack strength of the current object
	int SuperHero::attackStrength() const {
		if (bonus == 0 && defendS == 0) {
			return 0;
		}

		return Hero::attackStrength() + bonus;
	}
	
	// this function returns defendstrength of the current object
	int SuperHero::defend() const {
		if (bonus == 0 && defendS == 0) {
			return 0;
		}

		return defendS;
	}
	
	// this function returns a non-friend that returns as unmodifiable reference to the winner
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int i = 0;
		bool first_temp1 = true;
		bool second_temp2 = true;
		SuperHero temp1 = first;
		SuperHero temp2 = second;
		int damage1 = second.attackStrength() - first.defend();
		int damage2 = first.attackStrength() - second.defend();

		for (i = 0; i < max_rounds; i++) {
			temp1 -= damage1;
			temp2 -= damage2;

			if (!(temp1.isAlive())) {
				first_temp1 = false;
				break;

			} else if (!(temp2.isAlive())) {
				second_temp2 = false;
				break;
			}
		}

		if (first_temp1 && second_temp2) {
			cout << "Super Fight! " << first << " vs " << second << " : " << "Winner is " << first << " in " << i + 1 << " rounds." << endl;

		} else {
			cout << "Super Fight! " << first << " vs " << second << " : " << "Winner is " << (first_temp1 ? first : second) << " in " << i + 1 << " rounds." << endl;
		}

		return (first_temp1 ? first : second);
	}
}
