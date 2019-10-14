#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(double initialBalance, double interest);
	double calculateInterest();
	void credit(double creditAmount);
	void debit(double debitAmount);
private:
	double interestRate;
};