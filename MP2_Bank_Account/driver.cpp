// header files
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	CheckingAccount customerCheckingAccount(500.00);
	SavingsAccount customerSavingsAccount(1000.00, 0.01);

	cout << fixed << showpoint << setprecision(2);

	customerCheckingAccount.debit(230.00);
	cout << "The balance of your checking account is: $" 
		 << customerCheckingAccount.getBalance() << endl;

	customerSavingsAccount.debit(100.85);
	cout << "The balance of your savings account is: $"
		 << customerSavingsAccount.getBalance() << endl;

	customerCheckingAccount.credit(400.25);
	cout << "The balance of your checking account is: $"
		 << customerCheckingAccount.getBalance() << endl;

	customerCheckingAccount.credit(250.00);
	cout << "The balance of your checking account is: $"
		 << customerCheckingAccount.getBalance() << endl;

	customerSavingsAccount.credit(500.00);
	cout << "The balance of your savings account is: $"
		 << customerSavingsAccount.getBalance() << endl;

	customerCheckingAccount.debit(2000.00);
	cout << "The balance of your checking account is: $"
		 << customerCheckingAccount.getBalance() << endl;

	customerSavingsAccount.debit(1000.00);
	cout << "The balance of your savings account is: $"
		 << customerSavingsAccount.getBalance() << endl;

	customerSavingsAccount.debit(1500.00);
	cout << "The balance of your savings account is: $"
		 << customerSavingsAccount.getBalance() << endl;

	customerSavingsAccount.credit(-500.00);
	cout << "The balance of your savings account is: $"
		 << customerSavingsAccount.getBalance() << endl;
		
	system("pause");
	return 0;
}