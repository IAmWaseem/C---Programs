#include "LocalCard.h"

LocalCard::LocalCard() {
	ChargeLimit = 10000;
	InterestRate = 25.0;
	LastWithdrawAmount = 0;
}

double LocalCard::Withdraw(double balance, double amount) {
	if(balance - amount < -ChargeLimit) {
		std::cout << "Not Enough Balance in your Account" << std::endl;
		return balance;
	}
	if(amount > 3 * LastWithdrawAmount) {
		InterestRate = 20.0;
		ChargeLimit = 15000;
	}
	LastWithdrawAmount = amount;
	balance -= amount;
	balance -= amount * InterestRate;
	std::cout << "Amount Withdrawn Successfully" << std::endl;
	return balance;
}

double LocalCard::GetChargeLimit() {
	return ChargeLimit;
}

double LocalCard::GetInterestRate() {
	return InterestRate;
}

double LocalCard::GetLastWithdrawAmount() {
	return LastWithdrawAmount;
}

void LocalCard::SetChargeLimit(double num) {
	ChargeLimit = num;
}

void LocalCard::SetInterestRate(double num) {
	InterestRate = num;
}

void LocalCard::SetLastWithdrawAmount(double num) {
	LastWithdrawAmount = num;
}