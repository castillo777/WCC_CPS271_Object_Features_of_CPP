#ifndef STOCKTYPE_H_
#define STOCKTYPE_H_
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class StockType
{
	friend istream& operator >> (istream& in, StockType& cStock);
	friend ostream& operator << (ostream& out, const StockType& cStock);	
public:
	void setStock(string sSymbol, double oPrice, double cPrice,
		double tHigh, double tLow, int nShares, double pClosePrice);
	//[] Print stock information
	void printStock();
	// []Show different prices
	void showDifferentPrices();
	//[]Calculate and price the percent gain/loss
	void calculateGainLoss();
	//[]Show number of shares
	void showNumberOfShares();;
	//**The natual order of the stock list is by the stock symbol. Overload the relational operators to compare two stock objects by their symbols.
	bool operator> (StockType &cStock)
	{
		return (this->stockSymbol.compare(cStock.stockSymbol) > 0);
	}
	bool operator>= (StockType &cStock)
	{
		return (this->stockSymbol.compare(cStock.stockSymbol) >= 0);
	}
	bool operator< (StockType &cStock)
	{
		return (this->stockSymbol.compare(cStock.stockSymbol) < 0);
	}
	bool operator<= (StockType &cStock)
	{
		return (this->stockSymbol.compare(cStock.stockSymbol) <= 0);
	}
	bool operator==(StockType &cStock)
	{
		return (this->stockSymbol.compare(cStock.stockSymbol) == 0);
	}
private:
	string stockSymbol = "";
	double openingPrice = 0.00;
	double closingPrice = 0.00;
	double todayHigh = 0.00;
	double todayLow = 0.00;
	int numberOfShares = 0;
	double previousClosePrice = 0.00;
	double percentGainLoss = 0.00;

};

#endif