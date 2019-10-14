#include "InvalidDateExceptions.h"
#include <string>

using namespace std;

InvalidHour::InvalidHour()
{
	message = "Inavlid hour: ";
}

InvalidHour::InvalidHour(string msg)
{
	message = msg;
}

string InvalidHour::what()
{
	return message;
}

InvalidMinute::InvalidMinute()
{
	message = "Inavlid minute: ";
}

InvalidMinute::InvalidMinute(string msg)
{
	message = msg;
}

string InvalidMinute::what()
{
	return message;
}

InvalidSecond::InvalidSecond()
{
	message = "Inavlid second: ";
}

InvalidSecond::InvalidSecond(string msg)
{
	message = msg;
}

string InvalidSecond::what()
{
	return message;
}

InvalidTimePeriod::InvalidTimePeriod()
{
	message = "Inavlid time period: ";
}

InvalidTimePeriod::InvalidTimePeriod(string msg)
{
	message = msg;
}

string InvalidTimePeriod::what()
{
	return message;
}

InvalidDay::InvalidDay()
{
	message = "Inavlid day: ";
}

InvalidDay::InvalidDay(string msg)
{
	message = msg;
}

string InvalidDay::what()
{
	return message;
}

InvalidMonth::InvalidMonth()
{
	message = "Inavlid month: ";
}

InvalidMonth::InvalidMonth(string msg)
{
	message = msg;
}

string InvalidMonth::what()
{
	return message;
}