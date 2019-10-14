#pragma once
#include "Publication.h"
#include "Sales.h"

class Book : public Publication, public Sales
{
public:
	Book();	
	void readData();
	void displaySales() const;
	void displayData() const;
private:
	int pages;
};