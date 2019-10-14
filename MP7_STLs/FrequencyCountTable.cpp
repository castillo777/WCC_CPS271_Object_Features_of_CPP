#include "FrequencyCountTable.h"
#include <iostream>
#include <ctype.h>
#include <fstream>

using namespace std;

FrequencyCountTable::FrequencyCountTable()

{
	words = {};
}

void FrequencyCountTable::readFromFile(string fileNme)
{
	ifstream fID;
	//exceptions
	fID.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		//open the file
		fID.open(fileNme);

		string tt;
		int fg = 0;
		//read string from file
		while (fID >> tt)
		{
			//set fg to 0
			fg = 0;

			//check tt is a string
			if (tt != "\n" && tt != "\t")
			{
				//check last character is punctuation
				if (ispunct(tt[tt.length() - 1]))
				{
					//remove the punctuation
					tt = tt.substr(0, tt.length() - 1);
				}
				//check tt exist in words
				for (int kk = 0; kk<words.size(); kk++)
				{
					//if it exists
					if (words[kk].first == tt)
					{
						//set fg to 1
						fg = 1;

						//increment tt count by 1
						words[kk].second++;
					}
				}
				//if tt doesnot exist in words
				if (fg == 0)
				{
					//add tt to words
					words.push_back(make_pair(tt, 1));
				}
			}
		}
		//close the file
		fID.close();
	}
	//catch the file exceptions
	catch (const ifstream::failure& e)
	{
		//print the exceptions
		std::cerr << "EXCEPTIONS OPENING/READING FILE!!!" << endl;
	}
}

//print words
void FrequencyCountTable::printFreq()
{
	cout << "--------------------------------------------------" << endl;
	//loop to print all words
	for (int kk = 0; kk<words.size(); kk++)
	{
		//print words with count
		cout << words[kk].first << " " << words[kk].second << endl;
	}
	cout << "--------------------------------------------------" << endl;
}