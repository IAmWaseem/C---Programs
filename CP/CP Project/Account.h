#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Date.h"

class Account {
	public:
		virtual double Interest() = 0;
		virtual void GovernmentTax(double amount);
		Account();
		void Withdraw(double amount);
		int GetAccountNumber() const;
		void ServiceCharges(double amount);
		void SetBalance(double amount);
		double GetWithdrawn();
		void SetWithdrawn(double amount);
		void SetAccountNumber(int number);
		Date&  GetAccountCreationDate();
		Date& GetWithdrawnLastTime();
		void SetAccountType(std::string acctype);
		std::string GetAccountType() const;
		static int GetTotalAccounts();
		static void SetTotalAccounts(int total);
		double GetBalance();
	protected:
		std::string AccountType;
		int AccountNumber;
		static int TotalAccounts;
		double Balance;
		Date AccountCreationDate;
		double Withdrawn;
		Date WithdrawnLastTime;
};

#endif
