// OOP244 Workshop 9: Function Templates
// File: Data.h
// Date: 2018/04/02
// Author: Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description:
// This file contains declarations.
///////////////////////////////////////////////////

#include<iostream>

using namespace std;

namespace sict {
	// These numbers define 
	// the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	template <typename T>
	T max(const T* data, int n) {\
		T num = data[0];
		for (int i = 0; i < n; i++) {
			if (data[i] > num) {
				num = data[i];
			}
		}

		return static_cast<int>(num);
	}


	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n) {
			T num = data[0];
		for (int i = 0; i < n; i++) {
			if (data[i] < num) {
				num = data[i];
			}
		}

		return static_cast<int>(num);
	}

	// sum returns the sum of n items in data
	//
	template <typename T>
	T sum(const T* data, int n) {
		T num;
		for (int i = 0; i < n; i++) {
			if (data[i] < num) {
				num += data[i];
			}
		}

		return static_cast<int>(num);
	}
   
	// average returns the average of n items in data
	//
	template <typename T>
	double average(const T* data, int n) {
		double num;
		for (int i = 0; i < n; i++) {
			num += data[i];
		}

		num /= 5;

		return num;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(istream& input, T* data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore();
			input >> data[i];
		}

		if (input.fail()) {
			return false;
		}

		return true;
	}

	// display inserts n items of data into std::cout
	//
	template <typename T>
	void display(const char* name, const T* data, int n) {
		cout.setf(ios::right);
		cout.width(20);
		cout << name; 

		for (int i = 0; i < n; i++) {
			cout.width(COLUMN_WIDTH);
			cout << data[i];
		}

		cout << endl;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

