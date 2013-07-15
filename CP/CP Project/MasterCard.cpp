#include "MasterCard.h"

double MasterCard::Withdraw(double balance, double amount) {
	if(balance - amount < -50000) {
		std::cout << "Not Enough Balance in your Acount" << std::endl;
		return balance;
	}
	balance -= amount;
	balance -= amount * 0.18;
	std::cout << "Amount Withdrawn Successfully" << std::endl;
	return balance;
}
