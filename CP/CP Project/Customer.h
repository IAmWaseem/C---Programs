#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "CreditCard.h"
#include "Account.h"
#include "Bank.h"
#include <vector>
#include "TransactionHistory.h"

class Customer : public Bank {
	friend class Employee;
	friend std::istream& operator>>(std::istream& in, Customer& TempCustomer);
	friend std::ostream& operator<<(std::ostream& out, const Customer& TempCustomer);
	public:
		void Read(std::vector<Customer>& TempVector);
		void Write(std::vector<Customer>& TempVector);
		void MiniStatement(const std::vector<Transaction>& TransactionList, const std::vector<Customer>& CustomerList);
		void WithdrawViaCreditCard(std::vector<Transaction>& TransactionList, std::vector<Customer>& CustomerList);
		void WithdrawViaCheckBook(std::vector<Transaction>& TransactionList, std::vector<Customer>& CustomerList);
		void BalanceEnquiry(const std::vector<Customer>& CustomerList);
		void TransactionHistory(const std::vector<Transaction>& TransactionList, const std::vector<Customer>& CustomerList);
		void SetAccountType(Account* Type);
		void SetCardType(CreditCard* Type);
		Account* GetAccountType() const;
		CreditCard* GetCardType() const;
		Customer();
	private:
		Account* AccountType;
		CreditCard* CardType;
};

#endif
