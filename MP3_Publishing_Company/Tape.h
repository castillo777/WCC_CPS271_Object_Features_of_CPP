#pragma once
#include "Publication.h"
#include "Sales.h"

class Tape : public Publication, public Sales
{
public:
	Tape();	
	void readData();
	void displaySales() const;
	void displayData() const;
private:
	double playingTimeInMinutes;
};