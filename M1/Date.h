// Final Project Milestone 1
//
// Version 1.0
// Date.h
// Date: 14/03/2018
// Author: Woohyuk Kim
// Email: wkim33@myseneca.ca
// Description:
//	This file contains declarations used in this program.
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

// header safe guard 
#ifndef AMA_DATE_H
#define AMA_DATE_H

// declare namespace
namespace AMA {
	
	// define error states
	#define NO_ERROR 0
	#define CIN_FAILED 1
	#define YEAR_ERROR 2
	#define MON_ERROR 3
	#define DAY_ERROR 4

	const int min_year = 2000;
	const int max_year = 2030;
	const int min_month = 1;
	const int max_month = 12;

  class Date {
	// declare private members
	  int err;
	  int year;
	  int month;
	  int day;
	  int mdays(int, int)const;
	  void errCode(int);
	  int comp_value;
 
  public:
	// declare member functions
	  Date();
	  Date(int, int, int);
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  int errCode() const;
	  bool bad() const;

	  std::istream& read(std::istream&);
	  std::ostream& write(std::ostream&) const;
  };

  // declare helper functions
  std::ostream& operator<<(std::ostream&, const Date&);
  std::istream& operator>>(std::istream&, Date&);

}
#endif
