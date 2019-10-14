#pragma once
#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount(double initialBalance);
	void credit(double creditAmount);
	void debit(double debitAmount);
private:
	const double TRANSACTION_FEE = 0.02;
};