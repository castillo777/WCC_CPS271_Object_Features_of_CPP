#include "Publication.h"
#include <iostream>

using namespace std;

Publication::Publication()
{
	title = "";
	price = 0.00;
}

Publication::~Publication() {};

void Publication::readData()
{	
	cout << "Enter title: ";	
	getline(cin, title);
	
	cout << "Enter price: $";
	cin >> price;
	
	cin.get();
}

void Publication::displayData() const
{
	cout << "Title: " << title
		 << endl;

	cout << "Price: $" << price
		 << endl;
}