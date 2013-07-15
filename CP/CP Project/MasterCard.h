#ifndef MASTERCARD_H
#define MASTERCARD_H
#include "creditcard.h"

class MasterCard : public CreditCard {
	public:
		double Withdraw(double balance, double amount);
	private:

};

#endif
