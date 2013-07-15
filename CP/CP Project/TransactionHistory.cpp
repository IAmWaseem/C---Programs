#include "TransactionHistory.h"
#include <fstream>

std::ostream& operator<<(std::ostream& out, const Transaction& obj) {
	out << "Amount Withdrawn : " << obj.Amount << std::endl
		<< "Date : " << obj.WithdrawDate << std::endl;
	return out;
}

void ReadTransactions(std::vector<Transaction>& TransactionList) {
	std::ifstream inFile;
	inFile.open("Transactions.dat", std::ios::in | std::ios::binary);
	if(!inFile) {
		TransactionList.clear();
		return;
	}
	int VectorSize;
	inFile.read((char*)&VectorSize, sizeof(int));
	TransactionList.resize(VectorSize);
	inFile.read((char*)&TransactionList, sizeof(Transaction) * VectorSize);
	inFile.close();
}

void WriteTransactions(const std::vector<Transaction>& TransactionList) {
	std::ofstream outFile;
	outFile.open("Transactions.dat", std::ios::out | std::ios::binary);
	if(!outFile) {
		std::cout << "Failed to Open File for Writing" << std::endl;
		return;
	}
	if(!TransactionList.empty()) {
		unsigned int VectorSize = TransactionList.size();
		outFile.write((char*)&VectorSize, sizeof(unsigned int));
		outFile.write((char*)&TransactionList, sizeof(Transaction) * VectorSize);
		outFile.flush();
	}
	else {
		// Save Nothing
	}
	outFile.close();
}