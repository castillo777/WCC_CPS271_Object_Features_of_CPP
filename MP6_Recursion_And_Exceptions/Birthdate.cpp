#include "InvalidDateExceptions.h"
#include "Birthdate.h"
#include <iostream>
#include <string>

using namespace std;

Birthdate::Birthdate() // Default constructor
{
	hour = 0, minute = 0; second = 0, timeNotationChoice = 0;
	month = 0, day = 0, year = 0, 
	timePeriod = "", monthInLetters = "", abbreviation = "";
	thereAreExceptions = false;	
}

void Birthdate::readBirthDate()
{
	cout << "Enter '1' for 12-hour notation and '2' for 24-hour notation of your date of birth: ";
	cin >> timeNotationChoice;
	cin.get();

	while (timeNotationChoice < 1 || timeNotationChoice > 2)
	{
		cout << "Invalid entry. Please choose between '1' and '2': ";
		cin >> timeNotationChoice;
		cin.get();
	}

	if (timeNotationChoice == 1)
	{
		cout << "Please enter your date of birth in numeric form."
			<< "\nEx: (8-27-1980 10:56:59 pm): ";
		cin >> month;
		cin.get();
		Birthdate::checkMonth();

		cin >> day;
		cin.get();
		Birthdate::checkDay();

		cin >> year;
		cin.get();

		cin >> hour;
		cin.get();
		Birthdate::checkHour();

		cin >> minute;
		cin.get();
		Birthdate::checkMinute();

		cin >> second;
		cin.get();
		Birthdate::checkSecond();

		cin >> timePeriod;
		cin.get();
		Birthdate::checkTimePeriod();
	} // end if
	else
	{
		cout << "Please enter your date of birth in numeric form."
			<< "\nEx: (8-27-1980 22:56:59): ";
		cin >> month;
		cin.get();
		Birthdate::checkMonth();

		cin >> day;
		cin.get();
		Birthdate::checkDay();

		cin >> year;
		cin.get();

		cin >> hour;
		cin.get();
		Birthdate::checkHour24HrNotation();

		cin >> minute;
		cin.get();
		Birthdate::checkMinute();

		cin >> second;
		cin.get();
		Birthdate::checkSecond();
	} // end else

	if (thereAreExceptions)
	{
		system("pause");
		exit(1);
	}		

} // End function BirthDate

void Birthdate::checkMonth()
{
	try
	{
		if (month < 01 || month > 12)
			throw InvalidMonth();
	}
	catch (InvalidMonth invMnthObj)
	{
		cout << invMnthObj.what() << month
			 << endl << endl;
		
		thereAreExceptions = true;
	}
}

void Birthdate::checkDay()
{
	try
	{
		if (day < 01 || day > 31)
			throw InvalidDay();
	}
	catch (InvalidDay invDayObj)
	{
		cout << invDayObj.what() << day
			<< endl << endl;

		thereAreExceptions = true;
	}
}

void Birthdate::checkHour()
{
	try
	{
		if (hour < 01 || hour > 12)
			throw InvalidHour();
	}
	catch (InvalidHour invHrObj)
	{
		cout << invHrObj.what() << hour
			<< endl << endl;

		thereAreExceptions = true;
	}
}

void Birthdate::checkHour24HrNotation()
{
	try
	{
		if (hour < 00 || hour > 23)
			throw InvalidHour();
	}
	catch (InvalidHour invHrObj)
	{
		cout << invHrObj.what() << hour
			<< endl << endl;

		thereAreExceptions = true;
	}
}

void Birthdate::checkMinute()
{
	try
	{
		if (minute < 00 || minute > 59)
			throw InvalidMinute();
	}
	catch (InvalidMinute invMinObj)
	{
		cout << invMinObj.what() << minute
			<< endl << endl;

		thereAreExceptions = true;
	}
}

void Birthdate::checkSecond()
{
	try
	{
		if (second < 00 || second > 59)
			throw InvalidSecond();
	}
	catch (InvalidSecond invSecObj)
	{
		cout << invSecObj.what() << second
			<< endl << endl;
		
		thereAreExceptions = true;
	}
}

void Birthdate::checkTimePeriod()
{
	try
	{
		if (hour < 01 || hour > 12)
			throw InvalidTimePeriod();
	}
	catch (InvalidTimePeriod invTimePObj)
	{
		cout << invTimePObj.what() << timePeriod
			<< endl << endl;

		thereAreExceptions = true;
	}
}

void Birthdate::changeBirthDateFormat()
{
	switch (timeNotationChoice) // Time notation conversion switch
	{
	case 1:	
		if (timePeriod == "am" && hour == 12)
			hour = 00;
		
		if ( (timePeriod == "pm") && (hour >= 01) && (hour <= 12) )
			hour += 12;
		break;
	case 2:
		if (hour >= 1 && hour <= 12)
			timePeriod = "am";
		else if (hour >= 12 && hour <= 23)
		{ 
			hour = 12 % hour;
			timePeriod = "pm";
		}
		else
		{
			hour = 01;
			timePeriod = "am";
		}	
		break;
	} // end time notation conversion switch
		
	switch (month) // switch converts month into letter format
	{
	case 1:
		monthInLetters = "January";
		break;
	case 2:
		monthInLetters = "February";
		break;
	case 3:
		monthInLetters = "March";
		break;
	case 4:
		monthInLetters = "April";
		break;
	case 5:
		monthInLetters = "May";
		break;
	case 6:
		monthInLetters = "June";
		break;
	case 7:
		monthInLetters = "July";
		break;
	case 8:
		monthInLetters = "August";
		break;
	case 9:
		monthInLetters = "September";
		break;
	case 10:
		monthInLetters = "October";
		break;
	case 11:
		monthInLetters = "November";
		break;
	case 12:
		monthInLetters = "December";
		break;
	} //End month conversion switch

	switch (day) //switch creates abbreviation for days
	{ 
		case 1:
			abbreviation = "st";
			break;
		case 2:
			abbreviation = "nd";
			break;
		case 3:
			abbreviation = "rd";
			break;
		default:
			abbreviation = "th";
	} //End abbreviation switch
} //End function changeBirthDateFormat

void Birthdate::displayBirthDate() const
{
	switch (timeNotationChoice)
	{
	case 1:	//Displays date on 12-hour notation
		cout << "\nYou were born on " << monthInLetters << " " << day << abbreviation << ", "
			 << year << " at " << hour << ":" << minute << ":" << second << endl << endl;
		break;
	case 2: //Displays date on 14-hour notation
		cout << "\nYou were born on " << monthInLetters << " " << day << abbreviation << ", "
			 << year << " at " << hour << ":" << minute << ":" << second << " " << timePeriod
		     << endl << endl;
		break;
	}
}