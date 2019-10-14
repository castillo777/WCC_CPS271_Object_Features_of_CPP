#include "Candidate.h"
#include "Precint.h"
#include "Report.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Report **ptrRprt;
	Candidate name;
	Precint votes;
	
	ifstream inFile;

	inFile.open("mp4election.txt");

	if (!inFile)
	{
		cout << "Unable to open file. Please, make sure the"
			 << " correct file is loaded on the program and"
			 << " try again.";

		return 1;
	}

	while (inFile >> name >> votes)
	{
		cout << name << votes;
	}

	inFile.close;

	system("pause");
	return 0;
}