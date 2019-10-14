#include "Account.h"
#include "CheckingAccount.h"
#include <iostream>

using namespace std;

CheckingAccount::CheckingAccount(double initialBalance) : Account(initialBalance) {}

void CheckingAccount::credit(double creditAmount)
{
	Account::credit(creditAmount);
	
	accountBalance -= (creditAmount * TRANSACTION_FEE);
}

void CheckingAccount::debit(double debitAmount)
{
	Account::debit(debitAmount);

	if (debitAmount < accountBalance)
	{
		accountBalance -= (debitAmount * TRANSACTION_FEE);
	}
}