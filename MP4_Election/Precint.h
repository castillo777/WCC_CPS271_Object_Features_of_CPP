#ifndef PRECINT_H_
#define PRECINT_H_
#include "Report.h"
#include <iostream>
#include <vector>

class Precint : public Report
{
	friend std::istream& operator >> (std::istream& isObject, Precint& classObject);
	friend std::ostream& operator << (std::ostream& osObject, const Precint& classObject);
public:
	//virtual void printResults();
private:
	std::vector<std::vector<int>> votesPerPrecint;
	std::Vector<int> candidatesTotalVotes
};

#endif