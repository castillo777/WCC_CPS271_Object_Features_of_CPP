#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

void palindromeTester(string& originalString)
{
	string noPunctString = "";
	string finalString = "";
	
	transform(originalString.begin(), originalString.end(), originalString.begin(), ::tolower);
	
	remove_copy_if(originalString.begin(), originalString.end(), back_inserter(noPunctString), ptr_fun<int, int>(&::ispunct));
	
	remove_copy_if(noPunctString.begin(), noPunctString.end(), back_inserter(finalString), ptr_fun<int, int>(&::isspace));
	
	string nonReversedString = finalString;

	reverse(finalString.begin(), finalString.end());

	if (nonReversedString == finalString)
		cout << "String is Palindrome!" << endl << endl;
	else
		cout << "String is not Palindrome!" << endl << endl;
}

int main()
{
	string sentence =  "";

	cout << "Please, enter a sentence of your choice: ";
	getline(cin, sentence);
	cout << endl;

	palindromeTester(sentence);

	system("pause");
	return 0;
}