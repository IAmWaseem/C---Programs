#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount : public Account {
	public:
		double Interest();
		void GovernmentTax(double amount);
	private:

};

#endif
