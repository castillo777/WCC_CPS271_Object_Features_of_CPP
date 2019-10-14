#pragma once
#include <array>

const int THREE_MONTHS = 3;

class Sales
{
public:
	Sales();
	virtual ~Sales();
	virtual void readData();
	virtual void displayData() const;
private:
	std::array<double, THREE_MONTHS> lastQuarterSales;
};