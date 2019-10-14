#ifndef PERCENTAGE_H_
#define PERCENTAGE_H_
#include "Report.h"
#include "Votes.h"

class Percentage : public Report, public Votes
{
public:
	
private:
	double percentageOfVotes;
};

#endif