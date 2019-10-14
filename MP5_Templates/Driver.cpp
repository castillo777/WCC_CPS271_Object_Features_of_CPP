
#include "StockType.h"
#include "StockListType.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
	StockListType<StockType> stockArray(MAX);
	StockType localStock;

	ifstream infile("StockData.txt");
	
	int count = 0;
	if (!infile)
	{
		cout << "Unable to open file. Exiting from program ";
		return 1;
	}
	while (!infile.eof())
	{
		infile >> localStock;
		localStock.calculateGainLoss();
		stockArray.insertAt(localStock, count++);
	}	
	
	stockArray.sort();
	
	cout << "*************Financial Report*****************" << endl;
	cout << "Stock                   Today             Previous  Precent " << endl;
	cout << "Symbol     Open    Close   High     Low    Close     Gain      Volume" << endl;
	cout << "------     -----   -----   -----   -----  --------  -------    ------" << endl;
	stockArray.print();

	infile.close();

	system("pause");
	return 0;
}