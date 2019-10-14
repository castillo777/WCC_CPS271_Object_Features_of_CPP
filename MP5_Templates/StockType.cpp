#include "StockType.h"
#include <iomanip>
#include <iostream>

istream& operator >> (istream& in, StockType& cStock)
{
	// Since operator<< is a friend of the Stock class, we can access Stock's members directly.
	in >> cStock.stockSymbol;
	in >> cStock.openingPrice;
	in >> cStock.closingPrice;
	in >> cStock.todayHigh;
	in >> cStock.todayLow;
	in >> cStock.previousClosePrice;
	in >> cStock.numberOfShares;
	return in;
}

ostream& operator<< (ostream& out, const StockType& cStock)
{
	// Since operator<< is a friend of the Stock class, we can access Stock's members directly.
	out << setw(8) << left << cStock.stockSymbol << right << fixed << setprecision(2) << setw(8) <<
		cStock.openingPrice << fixed << setprecision(2) << setw(8) <<
		cStock.closingPrice << fixed << setprecision(2) << setw(8) <<
		cStock.todayHigh << fixed << setprecision(2) << setw(8) <<
		cStock.todayLow << fixed << setprecision(2) << setw(8) <<
		cStock.previousClosePrice << fixed << setprecision(2) << setw(8) <<
		cStock.percentGainLoss << fixed << setprecision(2) << setw(12) <<
		cStock.numberOfShares << endl;
	return out;
}

void StockType::setStock(string sSymbol, double oPrice, double cPrice,
	double tHigh, double tLow, int nShares, double pClosePrice)
{
	stockSymbol = sSymbol;
	openingPrice = oPrice;
	closingPrice = cPrice;
	todayHigh = tHigh;
	todayLow = tLow;
	numberOfShares = nShares;
	previousClosePrice = pClosePrice;
}
//[] Print stock information
void StockType::printStock()
{
	cout << "Stock name is " << stockSymbol << endl;
}
// []Show different prices
void StockType::showDifferentPrices()
{
	cout << "today's opening price was " << openingPrice << ", the closing was " << closingPrice << ", today's high was " <<
		todayHigh << ", today's low was " << todayLow << " Previous closing price is " << previousClosePrice << endl;
}
//[]Calculate and price the percent gain/loss
void StockType::calculateGainLoss()
{
	percentGainLoss = (closingPrice - previousClosePrice) / previousClosePrice * 100;
}
//[]Show number of shares
void StockType::showNumberOfShares()
{
	cout << "Number of share is " << numberOfShares << endl;
}

