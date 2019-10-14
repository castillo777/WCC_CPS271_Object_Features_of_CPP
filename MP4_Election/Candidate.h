#ifndef CANDIDATE_H_
#define CANDIDATE_H_
#include "Report.h"
#include <iostream>
#include <string>
#include <vector>

class Candidate : public Report
{
	friend std::istream& operator>>(std::istream& isObject, Candidate& classObject);
	friend std::ostream& operator<<(std::ostream& osObject, const Candidate& classObject);	

public:
	virtual void printResults() const;
private:
	std::vector<std::string> name = { "" };
	std::vector
	totalVotesReceived = 0;
};

#endif