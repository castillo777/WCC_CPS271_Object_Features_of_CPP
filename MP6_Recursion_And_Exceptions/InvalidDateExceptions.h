#ifndef INVALIDDATEEXCEPTIONS_H_
#define INVALIDDATEEXCEPTIONS_H_
#include <string>

class InvalidHour
{
public:
	InvalidHour();
	InvalidHour(std::string msg);
	std::string what();
private:
	std::string message;
};

class InvalidMinute
{
public:
	InvalidMinute();
	InvalidMinute(std::string msg);
	std::string what();
private:
	std::string message;
};

class InvalidSecond
{
public:
	InvalidSecond();
	InvalidSecond(std::string msg);
	std::string what();
private:
	std::string message;
};

class InvalidTimePeriod
{
public:
	InvalidTimePeriod();
	InvalidTimePeriod(std::string msg);
	std::string what();
private:
	std::string message;
};

class InvalidDay
{
public:
	InvalidDay();
	InvalidDay(std::string msg);
	std::string what();
private:
	std::string message;
};

class InvalidMonth
{
public:
	InvalidMonth();
	InvalidMonth(std::string msg);
	std::string what();
private:
	std::string message;
};
#endif;