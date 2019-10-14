#include "Publication.h"
#include "Sales.h"
#include "Tape.h"
#include <iostream>

using namespace std;

Tape::Tape()
{
	playingTimeInMinutes = 0.00;
}

void Tape::displaySales() const
{
	cout << "###DISPLAYING SALES FOR TAPE###" << endl;
}

void Tape::readData()
{
	cout << "Enter the information of your tape down below."
		 << endl;

	Publication::readData();

	cout << "Enter playing time (in minutes): ";
	cin >> playingTimeInMinutes;

	Sales::readData();

	cin.get();

	cout << endl;
}

void Tape::displayData() const
{
	cout << "***TAPE INFORMATION***\n";
	Publication::displayData();

	cout << "Minutes: " << playingTimeInMinutes
		 << endl << endl;

	Tape::displaySales();
	
	Sales::displayData();

	cout << endl << endl;
}
