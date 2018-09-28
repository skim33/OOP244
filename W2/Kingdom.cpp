/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 1/29/2018
// Author Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description
// It contains the definition of functions 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

// TODO: the sict namespace
namespace sict {

	// TODO:definition for display(...)
	// print the object to the screen
	void display(const Kingdom &kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}

	//print the object to the screen
	void display(const Kingdom *kingdom, int num) {
		int total = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		
		for (int i = 0; i < num; i++) {
			total = total + kingdom[i].m_population;
			cout << i + 1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}

}
