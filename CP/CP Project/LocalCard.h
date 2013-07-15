#ifndef LOCALCARD_H
#define LOCALCARD_H
#include "CreditCard.h"

class LocalCard : public CreditCard {
	public:
		LocalCard();
		double Withdraw(double balance, double amount);
		double GetInterestRate();
		void SetInterestRate(double num);
		double GetChargeLimit();
		void SetChargeLimit(double num);
		double GetLastWithdrawAmount();
		void SetLastWithdrawAmount(double num);
	private:
		double InterestRate;
		double ChargeLimit;
		double LastWithdrawAmount;
};

#endif
