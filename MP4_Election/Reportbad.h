#ifndef REPORT_H_
#define REPORT_H_

const int TOTAL_CANDIDATES = 10;
const int TOTAL_PRECINTS = 3;

class Report
{
public:
	virtual void printResults() const = 0;
private:
};

#endif