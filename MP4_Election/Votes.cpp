
#include "Votes.h"
#include <exception>

votes::votes() 
{
	the_votes = new int*[MAX];
	total = new int[MAX] {};
	totalPrecinct = new int[MAX] {};

	for (int i = 0; i < MAX; ++i)
		the_votes[i] = new int[MAX] {};

	totalVotes = 0;
}

votes::votes(const votes& obj) : Report(obj)
{
	if (*this != obj)
	{

		delete[] the_votes;
		for (int r = 0; r < rowCounter; ++r)
		{
			for (int c = 0; c < columnCount; ++c)
				the_votes[r][c] = obj.the_votes[r][c];
		}
	}
}

void votes::getPrecint()
{
	for (int columns = 0; columns < columnCount; ++columns)
	{
		for (int row = 0; row < rowCounter; ++row)
		{
			totalPrecinct[columns] += the_votes[row][columns];
		}
	}
}

string votes::displayTableForm(const votes& obj) const {

	stringstream ss;

	ss << setw(23) << left << "Candidates Name " << setw(12) << left << "Votes"

		<< left << "Candidates Totals " << endl;

	for (int i = 0; i < rowCounter - 1; ++i)
	{
		ss << left << setw(15) << obj[i] << " ";

		for (int c = 0; c < columnCount; ++c)
		{
			ss << right << setw(5) << the_votes[i][c];
		}

		ss << right << setw(7) << total[i] << endl;
	}

	ss << left << setw(16) << "Total Precinct ";

	for (int ivar = 0; ivar < columnCount; ++ivar) 
	{
		ss << right << setw(5) << totalPrecinct[ivar];
	}

	ss << endl << "Total Votes Casted " << left << totalVotes << endl << endl;

	return (ss.str());

}

string votes::displayPrecinct(const votes& obj) const {

	stringstream ss;

	ss << setw(20) << left << "Candidates Name " << setw(13) << left

		<< "Precinct Percentage" << endl;

	for (int i = 0; i < rowCounter - 1; ++i) {

		ss << left << setw(15) << obj[i] << " " << fixed << showpoint

			<< setprecision(1);

		for (int column = 0; column < columnCount; ++column) {

			ss << right << setw(8)

				<< ((double)the_votes[i][column] / totalPrecinct[column])

				* 100;

		}

		ss << endl;

	}

	ss << left << setw(20) << "Total Precinct ";

	for (int ivar = 0; ivar < columnCount; ++ivar) {

		ss << left << setw(8) << totalPrecinct[ivar];

	}

	ss << endl << endl;

	return (ss.str());

}

string votes::displayWinner(const votes& obj) const {

	stringstream ss;

	ss << setw(20) << left << "Candidates Name " << setw(13) << left << left

		<< setw(25) << "Candidates Totals " << right

		<< "Candidates Percentage" << endl;

	for (int i = 0; i < rowCounter - 1; ++i) {

		ss << left << setw(15) << obj[i] << " " << right << setw(15) << total[i]

			<< fixed << showpoint << setprecision(1) << setw(18)

			<< ((double)total[i] / totalVotes) * 100 << endl;

	}

	ss << endl << setw(18) << left << "Total Votes Casted " << right << setw(5)

		<< totalVotes << endl << endl;

	return (ss.str());

}

void votes::selectSort() {

	int temp;

	int largest = 0;

	int row = 0;

	for (int i = 0; i < rowCounter; ++i) {

		row = i;

		for (int x = 0; x < 3; x++) {

			largest = x;

			for (int j = 1 + x; j < 3; ++j) {

				if (the_votes[row][largest] < the_votes[i][j]) {

					largest = j;

					row = i;

				}

			}

			temp = the_votes[row][largest];

			the_votes[i][largest] = the_votes[i][x];

			the_votes[row][x] = temp;

		}

	}

}

void votes::swap(votes& obj, int r, int r3) {

	int* temp = new int[4];

	string name = obj[r];

	int* t = new int;

	for (int i = 0; i < 4; ++i)

		temp[i] = this->the_votes[r][i];

	for (int i = 0; i < 4; ++i)

		this->the_votes[r][i] = this->the_votes[r3][i];

	obj[r] = obj[r3];

	for (int i = 0; i < 4; ++i)

		this->the_votes[r3][i] = temp[i];

	obj[r3] = name;

	*t = total[r];

	this->total[r] = this->total[r3];

	this->total[r3] = *t;

	delete t;

	delete[] temp;

}

template<class T>

void votes::sort(T& obj) {

	selectSort();

	int largest = 0, j = 0, row = 0;

	for (int i = 0; i < 7 - 1; ++i) {

		largest = i;

		for (int x = i + 1; x < 7; x++) {

			for (j = 0; j < 3; ++j) {

				if (obj.the_votes[largest][row] < obj.the_votes[x][j]) {

					largest = x;

					row = j;

				}

			}

		}

		votes::swap(obj, i, largest);

	}

}

string votes::what() const throw () {

	return ("Bad input source: check file\n");

}

istream& operator >> (istream& is, votes& obj) throw () {

	try {

		for (int r = 0; r < obj.MAX && is; r++) {

			is >> obj[r];

			for (int i = 0; i < obj.columnCount; ++i) {

				is >> obj.the_votes[r][i];

				obj.total[r] += obj.the_votes[r][i];

				obj.totalVotes += obj.the_votes[r][i];

				if (!is.good() && !is.eof())

					throw votes();

			}

			obj.rowCounter++;

		}

		obj.getPrecint();

		obj.output = obj.displayTableForm(obj);

		obj.output += obj.displayPrecinct(obj);

		obj.sort(obj);

		obj.output += obj.displayWinner(obj);

	}
	catch (votes& e) {

		cout << e.what();

		is.clear();

	}

	return (is);

}

ostream& operator<<(ostream& os, const votes& obj) {

	os << obj.output;

	return (os);

}