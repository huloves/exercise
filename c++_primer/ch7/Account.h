#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include <string>

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static const int period = 30;
	double daily_tbl[period];
};

double Account::interestRate = initRate();
constexpr int Account::period;

void Account::rate(double newRate) {
	interestRate = newRate;
}

#endif
