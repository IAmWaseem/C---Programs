#include "VisaCard.h"

VisaCard::VisaCard() {
	FrequentUsagePoints = 0;
}

double VisaCard::Withdraw(double balance, double amount) {
	FrequentUsagePoints += amount;
	if(balance - amount < -100000) {
		std::cout << "Not Enough Balance in your Acount" << std::endl;
		return balance;
	}
	balance -= amount;
	balance -= amount * 0.10;
	std::cout << "Amount Withdrawn Successfully" << std::endl;
	return balance;
}

double VisaCard::GetFrequentUsagePoints() {
	return FrequentUsagePoints;
}

void VisaCard::SetFrequentUsagePoints(double num) {
	FrequentUsagePoints = num;
}