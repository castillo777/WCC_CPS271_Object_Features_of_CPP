/*
Class: CPS 271
Author: Sergio M. Castillo
StudentID: @00620298
Assigment No: MP4 - Election
Purpose: This program gathers data from a file
containing election results from a city and prints 
out the results of the election.
*/
#include "Votes.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	votes generalElection;

	ifstream inFile;

	inFile.open("mp4election.txt");

	if (!inFile)
	{
		cout << "File could not be opened.";

		return 1;
	}

	while (!inFile.eof())
	{
		inFile >> generalElection;		
	}

	cout << generalElection;

	inFile.close();

	system("pause");

	return 0;
}
