#include "stdafx.h"
#include "Date.h"
#include <iostream>

using namespace std;


Date::Date()					//default constructor (no parameters) set default date (1/01/1970)
{
	setDefaultDate();
}


Date::Date(int m, int d, int y)		//constructor with month day year parameters
{
	setDate(m, d, y);				//set date to constuctor parameters - if invalid setDefaultDate()
}

void Date::setDate(int mm, int dd, int yyyy) //set month day year values - call validDate() returns true if all 3 values valid
{
	month = mm;
	day = dd;
	year = yyyy;
	
	if (!validDate())				//validDate() calls validYear() validMonth() & valideDay()
		setDefaultDate();			//set date to constructor parameters - if invalid setDefaultDate()
}

int Date::getMonth()					//simply return integer value of month
{
	return month;
}

int Date::getDay()						//simply return integer value of day
{
	return day;
}

int Date::getYear()						//simply return integer value of year
{
	return year;
}

void Date::displayDate()			//dispay current date value using cout in mm/dd/yyyy format call setDefaultDate() if result is not fully-valid date
{
	cout << endl << month << '/' << day << '/' << year << endl;
}

		//private member funtions	validMonth() validDay() validYear() called only by validDate()
bool Date::validMonth()				//valid month must fall in range 1 - 12
{
	bool valid = false;

	if (month >= 1 && month <= 12)
			valid = true;
	else
			valid;

	return valid;
}

bool Date::validDay()				//valid day range (1-30 for Apr, June, Sept, Nov)(1-28 for Feb - except during leap year 1-29)(1-31 for all other months) 
{									//leap years are evenly divisible by 4 (use modulo arithmetic - year % 4) & % 100 NOT unless % 400  
	bool valid = false;
	
	if (day > 31)
		valid;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		valid;
	else if (month == 2 && day == 29 && year % 4 == 0 && year % 100 != 0 || month == 2 && day == 29 && year % 400 == 0)
		valid = true;
	else if (month == 2 && day > 28)
		valid;
	else
		valid = true;

	return valid;
	

}

bool Date::validYear()				// valid year must be >= 0 - adjust if 1- or 2-digit year; if < 100... 0-30 + 2000, 31-99 + 1900
{
	bool valid = false;

	if (year != abs(year))
		return valid;
	else if (year <= 30)
			year = year + 2000;
		{
			if (year >= 31 && year <= 99)
				year = year + 1900;
		}
		valid = true;
	
	return valid;
}

bool Date::validDate()				// call validYear() validMonth() validDay()-true if all valid-false if any is false
{
	return validYear() && validMonth() && validDay();
}

void Date::setDefaultDate()				//set month day year values to default date (1/01/1970)
{
	month = 1;
	day = 1;
	year = 1970;
}

