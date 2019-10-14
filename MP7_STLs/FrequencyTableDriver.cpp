#include "FrequencyCountTable.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	FrequencyCountTable ff;

	string fileNme;

	cout << "Enter the filename: ";

	cin >> fileNme;

	ff.readFromFile(fileNme);

	ff.printFreq();

	system("pause");
	return 0;
}