#pragma once
class Date
{
public:
	Date();							//default constructor (no parameters)
	Date(int, int, int);			//constructor w/month day year parameters - check validity

	void setDate(int, int, int);	//set month day year values - call validDate()

	int getMonth();					//return current month value
	int getDay();					//return current day value
	int getYear();					//return current 4-digit year value

	void displayDate();				// display current date value in mm/dd/yyyy format

private:
	bool validMonth();				//check for valid month range (1 - 12)
	bool validDay();				//check for valid day range (max value: 31, 30, 28 or 29)
	bool validYear();				//check for valid year (>0) - convert 1- & 2-digit year to yyyy
	bool validDate();				//check for month day year - return true if all 3 valid else setDefaultDate()

	void setDefaultDate();			//set month day year values to default date (1/01/1970)

	int month;						//current month value
	int day;						//current day value
	int year;						//current year value

};
