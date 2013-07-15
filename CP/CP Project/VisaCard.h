#ifndef VISACARD_H
#define VISACARD_H
#include "CreditCard.h"

class VisaCard : public CreditCard {
	public:
		double Withdraw(double balance, double amount);
		double GetFrequentUsagePoints();
		void SetFrequentUsagePoints(double num);
		VisaCard();
	private:
		double FrequentUsagePoints;
};

#endif
