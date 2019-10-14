#include "Publication.h"
#include "Sales.h"
#include "Book.h"
#include <iostream>

using namespace std;

Book::Book()
{
	pages = 0;
}

void Book::displaySales() const
{
	cout << "###DISPLAYING SALES FOR BOOK###" << endl;
}

void Book::readData()
{
	cout << "Enter the information of your book down below."
		 << endl;

	Publication::readData();

	cout << "Enter page count: ";
	cin >> pages;

	Sales::readData();

	cin.get();

	cout << endl;
}

void Book::displayData() const
{
	cout << "***BOOK INFORMATION***\n";
	Publication::displayData();

	cout << "Pages: " << pages
		 << endl << endl;
	
	Book::displaySales();

	Sales::displayData();
	
	cout << endl << endl;
}