#ifndef BIRTHDATE_H_
#define BIRTHDATE_H_
#include <iostream>
#include <string>

class Birthdate
{
public:
	Birthdate();
	void readBirthDate();
	void changeBirthDateFormat();
	void displayBirthDate() const;
protected:
	void checkMonth();
	void checkDay();
	void checkHour();
	void checkHour24HrNotation();
	void checkMinute();
	void checkSecond();
	void checkTimePeriod();
private:
	int hour, minute, second, timeNotationChoice;
	int month, day, year;
	std::string timePeriod;
	std::string monthInLetters;
	std::string abbreviation;
	bool thereAreExceptions;
};
#endif;