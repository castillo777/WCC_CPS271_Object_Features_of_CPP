#ifndef REPORT_H_
#define REPORT_H_
#include <iostream>
#include <string>

using namespace std;

class Report
{
public:
	static int rowCounter;
	static const int MAX = 10;
	virtual bool operator==(const Report& obj) { return (this == &obj); }
	virtual bool operator!=(const Report& obj) { return (this != &obj); }
	virtual bool operator>(const Report& obj) { return (this > &obj); }
	virtual string& operator[](int n) { return (names[n]); }
	virtual const string& operator[](int n) const { return (names[n]); }
	virtual string what() const throw() = 0;
	string getName() const;
	virtual ~Report() { delete[] names; }
	Report();
	Report(const Report&);
private:
	string* names;
};

#endif
