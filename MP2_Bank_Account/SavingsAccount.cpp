#include "Account.h"
#include "SavingsAccount.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount(double initialBalance, double interest) : Account(initialBalance)
{
	if (interest < 0)
	{
		interestRate = 0.00;
		cout << "Invalid value entry. The account interest is 0%"
			 << endl;
	}
	else
		interestRate = interest;
}

double SavingsAccount::calculateInterest()
{
	return (accountBalance * interestRate);
}

void SavingsAccount::credit(double creditAmount)
{	
	Account::credit(creditAmount);

	accountBalance += calculateInterest();	
}

void SavingsAccount::debit(double debitAmount)
{
	Account::debit(debitAmount);
}

