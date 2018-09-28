// Workshop 6 - Class with a Resource
// Contact.cpp
// Woohyuk Kim
// Student #:121968176
// Email: wkim33@myseneca.ca
// 2018/03/14

// include necessary headers
#include<cstring>
#include<iostream>
#include<string>
#include "Contact.h"

using namespace std;

namespace sict {
	
	// this function sets the current object to a safe empty state
	Contact::Contact() {
		name[0] = '\0';
		num = nullptr;
		num_of_p = 0;
	}

	// this function sets data after validation
	Contact::Contact(const char* _name, const long long* _num, int _num_of_p) {
		if (_name != nullptr && _name[0] != '\0') {
			if(!isEmpty()) {

				strncpy(name, _name, max_size);
				name[max_size + 1] = '\0';

				num_of_p = _num_of_p;

				num = new long long[num_of_p];

				for (int i = 0; i < num_of_p; i++) {
					if (isValid(_num[i])) {
						num[i] = _num[i];
					}
				}
						
			} else {
				*this = Contact();
			}

		} else {
			*this = Contact();
		}
	}

	// this function deallocates memory
	Contact:: ~Contact() {
		delete [] num;
		num = nullptr;
	}

	// this function checks if the current object is in a safe empty state
	bool Contact::isEmpty() const {
		return ((name[0] == '\0' && num == nullptr && num_of_p == 0) ? true : false);
	}

	// this function adds a phone number after validation to the num array
	Contact& Contact::operator+=(const long long pNum) {
		bool check = true;
		long long* temp = new long long[num_of_p + 1];
		
		if (!(isValid(pNum))) {
			check = false;
		}

		if(check) {
			num_of_p++;

			for (int i = 0; i < num_of_p; i++) {
				temp[i] = num[i];
			}

			delete [] num;

			num = new long long[num_of_p];

			for (int i = 0; i < num_of_p; i++) {
				num[i] = temp[i];
			}

			num[num_of_p - 1] = pNum;

		}
		delete [] temp;

		return *this;
	}
	
	// this function validates a phone num
	bool Contact::isValid(const long long num) {
		int size = to_string(num).size();

		if (size == 11) {
			if (to_string(num)[0] != '0' && to_string(num)[1] != '0' && to_string(num)[4] != '0') {
				return true;
			}
		} else if (size == 12) {
			if (to_string(num)[0] != '0' && to_string(num)[1] != '0' && to_string(num)[2] != '0' && to_string(num)[5] != '0') {
				return true;
			}
		}

		return false;

	}	

	// this function prints the data stored by the object
	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;

		} else {
			cout << name << endl;

			for (int i = 0; i < num_of_p; i++) {
				if (num[i] == 0) { continue; }

				else {
					int first = num[i] / 10000000000;
					int second = (num[i] / 10000000) - (first * 1000);
					int third = (num[i] / 10000) - (first * 1000000) - (second * 1000);
					int forth = (num[i] % 10000);				

					cout << "(+" << first << ") " << second << " " << third << "-" << forth << endl;
				}
			}
		}

	}

	// this function makes a copy of an existing instance
	Contact::Contact(const Contact& src) {
		num = nullptr;
		*this = src;
	}

	// this function copies the content of an object into the current object
	Contact& Contact::operator=(const Contact& src) {
		if (this != &src) {
			strncpy(name, src.name, max_size);
			name[max_size + 1] = '\0';

			num_of_p = src.num_of_p;

			num = new long long[num_of_p];

			for (int i = 0; i < num_of_p; i++) {
				num[i] = src.num[i];
			}
		
		} 

		return *this;
		
	}

}
