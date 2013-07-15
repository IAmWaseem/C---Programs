#include "SavingsAccount.h"

double SavingsAccount::Interest() {
	return 0.01 * Balance;
}

void SavingsAccount::GovernmentTax(double amount) {
	if(amount < Balance) {
		if(Withdrawn >= 50000) {
			Balance -= Balance * 0.025;
		}
	}
	Balance = Balance - Interest() * 0.005;
}