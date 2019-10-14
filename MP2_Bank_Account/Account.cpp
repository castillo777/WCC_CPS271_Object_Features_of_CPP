#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(double initialBalance)
{
	if (initialBalance < 0)
	{
		accountBalance = 0.00;
		cout << " Invalid value entry, account balance is $0.00."
			 << endl;
	}
	else
		accountBalance = initialBalance;
}

void Account::credit(double creditAmount)
{
	if (creditAmount < 0)
	{
		cout << "Credit amount is less than $0.00."
			 << endl;
	}
	else
		accountBalance += creditAmount;
}

void Account::debit(double debitAmount)
{
	if (debitAmount > accountBalance)
	{
		cout << "Debit amount exceeds account balance."
			 << endl;
	}
	else
		accountBalance -= debitAmount;
}

double Account::getBalance() const
{
	return accountBalance;
}