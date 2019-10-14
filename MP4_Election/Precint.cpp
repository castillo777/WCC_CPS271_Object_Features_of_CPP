#include "Report.h"
#include "Precint.h"
#include <iostream>
#include <iomanip>

using namespace std;

istream& operator >> (istream& isObject, Precint& classObject)
{
	for (int i = 0; i < TOTAL_CANDIDATES; i++)
	{
		for (int j = 0; j < TOTAL_PRECINTS; j++)
			isObject >> classObject.votesPerPrecint[i][j];
	}
		
	return isObject;
}

ostream& operator << (ostream& osObject, const Precint& classObject)
{
	for (int i = 0; i < TOTAL_CANDIDATES; i++)
	{
		for (int j = 0; j < TOTAL_PRECINTS; j++)
			osObject << classObject.votesPerPrecint[i][j] ;
	}

	return osObject;
}