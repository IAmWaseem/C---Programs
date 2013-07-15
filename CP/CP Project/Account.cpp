#include "Account.h"

int Account::TotalAccounts = 0;

Account::Account() {
	Balance = 0.0;
	AccountNumber = TotalAccounts + 1;
	TotalAccounts++;
	Withdrawn = 0.0;
	WithdrawnLastTime.CurrentDate();
}

void Account::Withdraw(double amount) {
	if(Balance < amount) {
		std::cout << "Not Enough Balance in Account" << std::endl;
		return;
	}
	Balance -= amount;
	ServiceCharges(amount);
}

void Account::GovernmentTax(double amount) {
	if(amount < Balance) {
		if(Withdrawn >= 50000) {
			Balance -= Balance * 0.025;
		}
	}
}

void Account::ServiceCharges(double amount) {
	if(amount < Balance) {
		if(amount > 5000) {
			Balance -= Balance * 0.002;
		}
	}
}

int Account::GetAccountNumber() const {
	return AccountNumber;
}

void Account::SetBalance(double amount) {
	Balance = amount;
}

Date& Account::GetAccountCreationDate() {
	return AccountCreationDate;
}

void Account::SetAccountType(std::string acctype) {
	AccountType = acctype;
}

std::string Account::GetAccountType() const {
	return AccountType;
}

double Account::GetBalance() {
	return Balance;
}

double Account::GetWithdrawn() {
	return Withdrawn;
}

Date& Account::GetWithdrawnLastTime() {
	return WithdrawnLastTime;
}

int Account::GetTotalAccounts() {
	return TotalAccounts;
}

void Account::SetAccountNumber(int number) {
	AccountNumber = number;
}

void Account::SetWithdrawn(double amount) {
	Withdrawn = amount;
}

void Account::SetTotalAccounts(int total) {
	TotalAccounts = total;
}