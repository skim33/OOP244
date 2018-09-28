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

using namespace std;

namespace sict{

	// this function sets date to a safe empty state
	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		attack = 0;
	}

	// this function sets data after validation
	Hero::Hero(const char* _name, int _health, int _attack) {

		if (_name != nullptr && _name[0] != '\0' && _health > 0 && _attack > 0) {
			strncpy(name, _name, max_name);
			name[max_name + 1] = '\0';

			health = _health;
			attack = _attack;
		
		} else {
			*this = Hero();
		}

	}

	// this function deducts the attck strenght received from the current object's health 
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			health -= attack;
		}

		if (health <= 0) {
			health = 0;
		}
	}

	// this function checks if the current object is healthy
	bool Hero::isAlive() const {
		return ((health > 0) ? true : false);
	}

	// this function returns attack strength of the current object after validation
	int Hero::attackStrength() const {
		if (name[0] == '\0' && health == 0 && attack == 0) {
			return 0;
		}

		return attack;
	}

	// this function inserts the name of hero into stream os and returns a reference to that stream
	ostream& operator<<(ostream& os, const Hero& hero) {
		if (hero.name[0] == '\0' && hero.health == 0 && hero.attack == 0) {
			cout << "No hero" << endl;
		
		} else {
			os << hero.name;
		}

		return os;
	}

	// this function returns an unmodifiable reference to the winner of the battle between the heros
	const Hero& operator*(const Hero& first, const Hero& second) {
		int i = 0;
		bool first_temp1 = true;
		bool second_temp2 = true;
		Hero temp1 = first;
		Hero temp2 = second;

		for (i = 0; i < max_rounds; i++) {
			temp1 -= temp2.attackStrength();
			temp2 -= temp1.attackStrength();

			if (!(temp1.isAlive())) {
				first_temp1 = false;
				break;

			}
			else if (!(temp2.isAlive())) {
				second_temp2 = false;
				break;
			}
		}

		if (first_temp1 && second_temp2) {
			cout << "Ancient Battle! " << first << " vs " << second << " : " << "Winner is " << first << " in " << i + 1 << " rounds." << endl;

		} else {
			cout << "Ancient Battle! " << first << " vs " << second << " : " << "Winner is " << (first_temp1 ? first : second) << " in " << i + 1 << " rounds." << endl;
		}

		return (first_temp1 ? first : second);
	}
}