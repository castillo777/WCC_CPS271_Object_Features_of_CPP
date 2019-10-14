#include "Birthdate.h"

using namespace std;

int main()
{
	Birthdate myBirthdateProgram;

   char tryAgain = 'y';
   do
   { 
	myBirthdateProgram.readBirthDate();
	myBirthdateProgram.changeBirthDateFormat();
	myBirthdateProgram.displayBirthDate();

	cout << "Would you like to try again? (y/n): ";
	cin >> tryAgain;
	cout << endl << endl;

   } while (tryAgain == 'Y' || tryAgain == 'y');
	
   system("pause");
	return 0;
}