#include "Sales.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Sales::Sales()
{
	for (unsigned int i = 0; i < lastQuarterSales.max_size(); i++)
		lastQuarterSales[i] = 0.00;
}

Sales::~Sales() {}

void Sales::readData()
{
	string month[THREE_MONTHS] = {"first", "second", "third"};

	for (unsigned int i = 0; i < lastQuarterSales.max_size(); i++)
	{
		cout << "Enter total sales of this item for the "
			 << month[i] << " month in the last quarter: $";
		
		cin >> lastQuarterSales[i];
	}
}

void Sales::displayData() const
{
	string month[THREE_MONTHS] = {"1st Month", "2nd Month", "3rd Month"};
	
	cout << "Total sales for last quarter:"
		 << endl;
		
	for (unsigned int i = 0; i < lastQuarterSales.max_size(); i++)
	{
		cout << left << setw(16) << month[i];
	}

	cout << endl;

	for (unsigned int i = 0; i < lastQuarterSales.max_size(); i++)
	{
		cout << fixed << showpoint << setprecision(2);

		cout << left << "$" << setw(15) << lastQuarterSales[i];
	}
}