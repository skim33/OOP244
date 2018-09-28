/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 1/29/2018
// Author Woohyuk Kim
// E-mail: wkim33@myseneca.ca
// Description
// It contains structure and function declaration used in 
// Kingdom.cpp and w2_in_lab.cpp
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace
namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom &kingdom);

	void display(const Kingdom *kingdom, int num);

}
#endif
