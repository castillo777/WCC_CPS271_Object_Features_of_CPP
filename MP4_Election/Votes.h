#ifndef VOTES_H_
#define VOTES_H_
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Report.h"

using namespace std;

class votes : public Report {
	friend ostream& operator<<(ostream&, const votes&);
	friend istream& operator >> (istream&, votes&) throw ();

public:
	static const int columnCount = 3;
	bool operator==(const votes& obj)
	{
		return (this == &obj);
	}

	bool operator!=(const votes& obj)
	{
		return (this != &obj);
	}

	bool operator>(const votes& obj)
	{
		return (this > &obj);
	}

	virtual string what() const throw();

	votes();	

	votes(const votes&);

	template<class T>

	void sort(T&);

	void getPrecint();

	string displayTableForm(const votes&)const;

	string displayPrecinct(const votes&) const;

	string displayWinner(const votes&)const;

	~votes()
	{
		delete[] the_votes;
		delete[] total;
		delete[] totalPrecinct;
	}

private:
	void selectSort();
	void swap(votes&, int, int);
	int **the_votes;
	int* total;
	int* totalPrecinct;
	int totalVotes;
	string output;
};

#endif
