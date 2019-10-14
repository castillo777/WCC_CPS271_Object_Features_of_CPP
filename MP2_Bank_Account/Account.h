#pragma once

class Account
{
public:
	Account(double initialBalance);
	void virtual credit(double creditAmount);
	void virtual debit(double debitAmount);
	double getBalance() const;
protected:
	double accountBalance;
};