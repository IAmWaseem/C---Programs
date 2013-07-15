#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <iostream>

class CreditCard {
	public:
		virtual double Withdraw(double balance, double amount) = 0;
		virtual double GetChargeLimit();
		virtual void SetChargeLimit(double num);
		virtual double GetInterestRate();
		virtual void SetInterestRate(double num);
		virtual double GetLastWithdrawAmount();
		virtual void SetLastWithdrawAmount(double num);
		virtual double GetFrequentUsagePoints();
		virtual void SetFrequentUsagePoints(double num);
		void GenerateCreditCardNumber();
		void SetCreditCardNumber(std::string number);
		void SetCardType(std::string cardtype);
		std::string GetCardType() const;
		std::string GetCreditCardNumber();
	private:
		std::string CreditCardNumber;
		std::string CardType;
};

#endif
