#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H
#include "Date.h"
#include <vector>

struct Transaction {
	int AccountID;
	Date WithdrawDate;
	double Amount;
};

std::ostream& operator<<(std::ostream& out, const Transaction& obj);
void ReadTransactions(std::vector<Transaction>& TransactionList);
void WriteTransactions(const std::vector<Transaction>& TransactionList);

#endif