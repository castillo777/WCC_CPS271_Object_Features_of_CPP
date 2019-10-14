#include "Report.h" 

int Report::rowCounter = 0; //intialisation

Report::Report() {

	names = new string[MAX];

}

Report::Report(const Report& obj) {

	if (*this != obj)

	{

		delete[] names;

		for (int r = 0; r < rowCounter; ++r)

			names[r] = obj.names[r];

	}

}

string Report::getName() const {

	return (*names);

}

istream& operator >> (istream& is, Report& obj) {

	is >> obj[obj.rowCounter];

	Report::rowCounter++;

	return(is);

}
