#include "Report.h"
#include "Candidate.h"
#include <iostream>
#include <string>

using namespace std;

std::istream& operator>>(std::istream& isObject, Candidate& classObject)
{
	for (int i = 0; i < TOTAL_CANDIDATES; i++)
	{
		isObject >> classObject.name[i];

	}
		return isObject;
	
}

/*ostream& operator<<(ostream& osObject, const Candidate& classObject)
{
	for (int i = 0; i < TOTAL_CANDIDATES; i++)
		osObject << classObject.name[i] << endl;
	return osObject;
} */

void Candidate::printResults() const
{
	Candidate candidateList;

	cout << candidateList;
}