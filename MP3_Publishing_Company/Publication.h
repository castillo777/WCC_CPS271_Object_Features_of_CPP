#pragma once
#include <string>

class Publication
{
public:
	Publication();
	virtual ~Publication();
	virtual void displaySales() const = 0;
	virtual void readData();
	virtual void displayData() const;
private:
	std::string title;
	double price;
};