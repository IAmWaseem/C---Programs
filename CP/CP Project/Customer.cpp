#include "Customer.h"
#include <string>
#include <fstream>
#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "MasterCard.h"
#include "VisaCard.h"
#include "LocalCard.h"

Customer::Customer() {

}

void Customer::SetAccountType(Account* Type) {
	AccountType = Type;
}

void Customer::SetCardType(CreditCard* Type) {
	CardType = Type;
}

Account* Customer::GetAccountType() const {
	return AccountType;
}

CreditCard* Customer::GetCardType() const {
	return CardType;
}

std::istream& operator>>(std::istream& in, Customer& TempCustomer) {
	int Choice;
	std::cout << "Enter First Name : ";
	fflush(stdin);
	std::getline(in, TempCustomer.First_Name);
	std::cout << "Enter Middle Name : ";
	fflush(stdin);
	std::getline(in, TempCustomer.Middle_Name);
	std::cout << "Enter Last Name : ";
	fflush(stdin);
	std::getline(in, TempCustomer.Last_Name);
	std::cout << "Enter CNIC Number : ";
	fflush(stdin);
	std::getline(in, TempCustomer.CNIC_Number);
	std::cout << "Enter Address : ";
	fflush(stdin);
	std::getline(in, TempCustomer.Address);
	std::cout << "Enter Telephone Number : ";
	fflush(stdin);
	std::getline(in, TempCustomer.Telephone_Number);
	std::cout << "Enter Date Of Birth : ";
	std::cin >> TempCustomer.DateOfBirth;
	do {
		std::cout << "Enter Account Type : " << std::endl << std::endl
				  << "[1] Checking Account" << std::endl
				  << "[2] Savings Account" << std::endl << std::endl
				  << "Enter Choice[1-2]: ";
		in        >> Choice;
		switch(Choice) {
			case 1:
				TempCustomer.AccountType = new CheckingAccount();
				TempCustomer.AccountType -> SetAccountType("Checking Account");
				break;
			case 2:
				TempCustomer.AccountType = new SavingsAccount();
				TempCustomer.AccountType -> SetAccountType("Savings Account");
				break;
			default:
				std::cout << "Invalid Choice" << std::endl;
				break;
		}
	} while(Choice < 1 && Choice > 2);
	do {
		std::cout << "Enter Credit Card Type : " << std::endl << std::endl
				  << "[1] Master Card" << std::endl
				  << "[2] Visa Card" << std::endl
				  << "[3] Local Card" << std::endl << std::endl
				  << "Enter Choice[1-3]: ";
		in		  >> Choice;
		switch(Choice) {
			case 1:
				TempCustomer.CardType = new MasterCard();
				TempCustomer.CardType -> SetCardType("MasterCard");
				break;
			case 2:
				TempCustomer.CardType = new VisaCard();
				TempCustomer.CardType -> SetCardType("VisaCard");
				break;
			case 3:
				TempCustomer.CardType = new LocalCard();
				TempCustomer.CardType -> SetCardType("LocalCard");
				break;
			default:
				std::cout << "Invalid Choice" << std::endl;
				break;
		}
	} while(Choice < 1 && Choice > 3);
	std::cout << "Enter Initial Amount in the Account : ";
	double Balance;
	in >> Balance;
	TempCustomer.AccountType -> SetBalance(Balance);
	TempCustomer.AccountType -> GetAccountCreationDate().CurrentDate();
	TempCustomer.CardType -> GenerateCreditCardNumber();
	return in;
}

std::ostream& operator<<(std::ostream& out, const Customer& TempCustomer) {
	out << "First Name : " << TempCustomer.First_Name << std::endl
			  << "Middle Name : " << TempCustomer.Middle_Name << std::endl
			  << "Last Name : " << TempCustomer.Last_Name << std::endl
			  << "CNIC Number : " << TempCustomer.CNIC_Number << std::endl
			  << "Address : " << TempCustomer.Address << std::endl
			  << "Telephone Number : " << TempCustomer.Telephone_Number << std::endl
			  << "Date of Birth : " << TempCustomer.DateOfBirth << std::endl
			  << "Account Type : " << TempCustomer.AccountType -> GetAccountType() << std::endl
			  << "Account Number : " << TempCustomer.AccountType -> GetAccountNumber() << std::endl
			  << "Account Balance : " << TempCustomer.AccountType -> GetBalance() << std::endl
			  << "Credit Card Type : " << TempCustomer.CardType -> GetCardType() << std::endl
			  << "Credit Card Number : " << TempCustomer.CardType -> GetCreditCardNumber() << std::endl
			  << std::endl;
	return out;
}

void Customer::MiniStatement(const std::vector<Transaction>& TransactionList, const::std::vector<Customer>& CustomerList) {
	std::string CNIC;
	int Check1 = 0, Check2 = 0;
	int Count = 0;
	int AccNumber;
	std::cout << "Enter Account Number : ";
	std::cin >> AccNumber;
	std::cout << "Enter CNIC Number : ";
	fflush(stdin);
	std::getline(std::cin, CNIC);
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(strcmp(CustomerList[i].GetCNICNumber().c_str(), CNIC.c_str()) == 0 && CustomerList[i].GetAccountType() -> GetAccountNumber() == AccNumber) {
			std::cout << "Mini Statement" << std::endl << std::endl;
			for(unsigned int i = 0; i < TransactionList.size(); i++) {
				if(TransactionList[i].AccountID == AccNumber) {
					std::cout << TransactionList[i] << std::endl;
					Check2 = 1;
				}
			}
			Count++;
			if(Count == 10) {
				break;
			}
			Check1 = 1;
		}
	}
	if(!Check1) {
		std::cout << "No Account Found with Account Number " << AccNumber << std::endl;
	}
	else if(!Check2) {
		std::cout << "No Transactions Found" << std::endl;
	}
}

void Customer::WithdrawViaCreditCard(std::vector<Transaction>& TransactionList, std::vector<Customer>& CustomerList) {
	std::string CardNumber;
	std::cout << "Enter Credit Card Number : ";
	fflush(stdin);
	std::getline(std::cin, CardNumber);
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(strcmp(CustomerList[i].GetCardType() -> GetCreditCardNumber().c_str(), CardNumber.c_str()) == 0) {
			std::cout << "Current Balance : " << CustomerList[i].GetAccountType() -> GetBalance() << std::endl;
			std::cout << "Enter Amount to Withdraw : ";
			double TempAmount;
			std::cin >> TempAmount;
			CustomerList[i].GetAccountType() -> ServiceCharges(TempAmount);
			CustomerList[i].GetAccountType() -> GovernmentTax(TempAmount);
			CustomerList[i].GetAccountType() -> SetBalance(CustomerList[i].GetCardType() -> Withdraw(CustomerList[i].GetAccountType() -> GetBalance(), TempAmount));
			Transaction Temp;
			Temp.AccountID = CustomerList[i].GetAccountType() -> GetAccountNumber();
			Temp.Amount = TempAmount;
			Date TempDate;
			TempDate.CurrentDate();
			Temp.WithdrawDate = TempDate;
			TransactionList.push_back(Temp);
		}
	}
}

void Customer::WithdrawViaCheckBook(std::vector<Transaction>& TransactionList, std::vector<Customer>& CustomerList) {
	int Check = 0;
	std::string CNIC;
	int AccNumber;
	std::cout << "Enter Account Number : ";
	std::cin >> AccNumber;
	std::cout << "Enter CNIC Number : ";
	fflush(stdin);
	std::getline(std::cin, CNIC);
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(strcmp(CustomerList[i].GetCNICNumber().c_str(), CNIC.c_str()) == 0 && CustomerList[i].GetAccountType() -> GetAccountNumber() == AccNumber) {
			std::cout << "Current Balance : " << CustomerList[i].GetAccountType() -> GetBalance() << std::endl;
			std::cout << "Enter Amount to Withdraw : ";
			double TempAmount;
			std::cin >> TempAmount;
			CustomerList[i].GetAccountType() -> GovernmentTax(TempAmount);
			CustomerList[i].GetAccountType() -> Withdraw(TempAmount);
			Transaction Temp;
			Temp.AccountID = CustomerList[i].GetAccountType() -> GetAccountNumber();
			Temp.Amount = TempAmount;
			Date TempDate;
			TempDate.CurrentDate();
			Temp.WithdrawDate = TempDate;
			TransactionList.push_back(Temp);
			Check = 1;
		}
	}
	if(!Check) {
		std::cout << "Account Not Found with Account Number " << AccNumber << std::endl;
	}
}

void Customer::BalanceEnquiry(const std::vector<Customer>& CustomerList) {
	int Check = 0;
	std::string CNIC;
	int AccNumber;
	std::cout << "Enter Account Number : ";
	std::cin >> AccNumber;
	std::cout << "Enter CNIC Number : ";
	fflush(stdin);
	std::getline(std::cin, CNIC);
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(strcmp(CustomerList[i].GetCNICNumber().c_str(), CNIC.c_str()) == 0 && CustomerList[i].GetAccountType() -> GetAccountNumber() == AccNumber) {
			std::cout << "Balance in the Account : " << CustomerList[i].GetAccountType() -> GetBalance() << std::endl;
			Check = 1;
		}
	}
	if(!Check) {
		std::cout << "Account Not Found with Account Number " << AccNumber << std::endl;
	}
}

void Customer::TransactionHistory(const std::vector<Transaction>& TransactionList, const std::vector<Customer>& CustomerList) {
	std::string CNIC;
	int Check1 = 0, Check2 = 0;
	int AccNumber;
	std::cout << "Enter Account Number : ";
	std::cin >> AccNumber;
	std::cout << "Enter CNIC Number : ";
	fflush(stdin);
	std::getline(std::cin, CNIC);
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(strcmp(CustomerList[i].GetCNICNumber().c_str(), CNIC.c_str()) == 0 && CustomerList[i].GetAccountType() -> GetAccountNumber() == AccNumber) {
			std::cout << "Mini Statement" << std::endl << std::endl;
			for(unsigned int i = 0; i < TransactionList.size(); i++) {
				if(TransactionList[i].AccountID == AccNumber) {
					std::cout << TransactionList[i] << std::endl;
					Check2 = 1;
				}
			}
			Check1 = 1;
		}
	}
	if(!Check1) {
		std::cout << "No Account Found with Account Number " << AccNumber << std::endl;
	}
	else if(!Check2) {
		std::cout << "No Transactions Found" << std::endl;
	}
}

void Customer::Read(std::vector<Customer>& TempVector) {
	std::ifstream inFile;
	inFile.open("Customer.dat", std::ios::out | std::ios::binary);
	if(!inFile) {
		TempVector.clear();
		return;
	}
	int VectorSize;
	inFile.read((char*)&VectorSize, sizeof(int));
	TempVector.resize(VectorSize);
	int TotalSize;
	for(unsigned int i = 0; i < TempVector.size(); i++) {
		int Temp;
		double Temp1;
		std::string Temp2;

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		Temp2[TotalSize] = NULL;
		TempVector[i].SetFirstName(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		Temp2[TotalSize] = NULL;
		TempVector[i].SetMiddleName(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		Temp2[TotalSize] = NULL;
		TempVector[i].SetLastName(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		Temp2[TotalSize] = NULL;
		TempVector[i].SetCNICNumber(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		Temp2[TotalSize] = NULL;
		TempVector[i].SetAddress(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		Temp2[TotalSize] = NULL;
		TempVector[i].SetTelephoneNumber(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].GetDateOfBirth().SetDay(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].GetDateOfBirth().SetMonth(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].GetDateOfBirth().SetYear(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		Temp2[TotalSize] = NULL;
		if(strcmp(Temp2.c_str(), "Checking Account") == 0) {
			TempVector[i].AccountType = new CheckingAccount();
		}
		else if(strcmp(Temp2.c_str(), "Savings Account") == 0) {
			TempVector[i].AccountType = new SavingsAccount();
		}
		TempVector[i].AccountType -> SetAccountType(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].AccountType -> SetAccountNumber(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp1, TotalSize);
		TempVector[i].AccountType -> SetBalance(Temp1);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].AccountType -> GetAccountCreationDate().SetDay(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].AccountType -> GetAccountCreationDate().SetMonth(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].AccountType -> GetAccountCreationDate().SetMonth(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp1, TotalSize);
		TempVector[i].AccountType -> SetWithdrawn(Temp1);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].AccountType -> GetWithdrawnLastTime().SetDay(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].AccountType -> GetWithdrawnLastTime().SetMonth(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		inFile.read((char*)&Temp, TotalSize);
		TempVector[i].AccountType -> GetWithdrawnLastTime().SetMonth(Temp);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		if(strcmp(Temp2.c_str(), "LocalCard") == 0) {
			TempVector[i].CardType = new LocalCard();
		}
		else if(strcmp(Temp2.c_str(), "MasterCard") == 0) {
			TempVector[i].CardType = new MasterCard();
		}
		else if(strcmp(Temp2.c_str(), "VisaCard") == 0) {
			TempVector[i].CardType = new VisaCard();
		}
		TempVector[i].CardType -> SetCardType(Temp2);

		inFile.read((char*)&TotalSize, sizeof(TotalSize));
		Temp2.resize(TotalSize);
		inFile.read((char*)Temp2.c_str(), TotalSize);
		TempVector[i].CardType -> SetCreditCardNumber(Temp2);

		if(strcmp(TempVector[i].CardType -> GetCardType().c_str(), "LocalCard") == 0) {
			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			inFile.read((char*)&Temp1, TotalSize);
			TempVector[i].CardType -> SetChargeLimit(Temp1);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			inFile.read((char*)&Temp1, TotalSize);
			TempVector[i].CardType -> SetInterestRate(Temp1);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			inFile.read((char*)&Temp1, TotalSize);
			TempVector[i].CardType -> SetLastWithdrawAmount(Temp1);
		}
		else if(strcmp(TempVector[i].CardType -> GetCardType().c_str(), "MasterCard") == 0) {
			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			inFile.read((char*)&Temp1, TotalSize);
			TempVector[i].CardType -> SetFrequentUsagePoints(Temp1);
		}
	}
	int TotalAccounts;
	inFile.read((char*)&TotalAccounts, sizeof(int));
	TempVector[0].AccountType -> SetTotalAccounts(TotalAccounts);
	//inFile.read((char*)&TotalSize, sizeof(int));
	//inFile.read((char*)&TempVector, TotalSize);
	inFile.close();
}

void Customer::Write(std::vector<Customer>& TempVector) {
	std::ofstream outFile;
	outFile.open("Customer.dat", std::ios::out | std::ios::binary);
	if(!outFile) {
		std::cout << "Cannot Open File Customer.dat" << std::endl;
		return;
	}
	int VectorSize = TempVector.size();
	outFile.write((char*)&VectorSize, sizeof(VectorSize));
	int TotalSize;
	for(unsigned int i = 0; i < TempVector.size(); i++) {
		int Temp;
		double Temp1;
		TotalSize = TempVector[i].GetFirstName().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].GetFirstName().c_str(), TotalSize);

		TotalSize = TempVector[i].GetMiddleName().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].GetMiddleName().c_str(), TotalSize);

		TotalSize = TempVector[i].GetLastName().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].GetLastName().c_str(), TotalSize);

		TotalSize = TempVector[i].GetCNICNumber().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].GetCNICNumber().c_str(), TotalSize);

		TotalSize = TempVector[i].GetAddress().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].GetAddress().c_str(), TotalSize);

		TotalSize = TempVector[i].GetTelephoneNumber().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].GetTelephoneNumber().c_str(), TotalSize);

		TotalSize = sizeof(TempVector[i].GetDateOfBirth().GetDay());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].DateOfBirth.GetDay();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].GetDateOfBirth().GetMonth());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].DateOfBirth.GetMonth();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].GetDateOfBirth().GetYear());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].DateOfBirth.GetYear();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = TempVector[i].AccountType -> GetAccountType().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].AccountType -> GetAccountType().c_str(), TotalSize);
		
		TotalSize = sizeof(TempVector[i].AccountType -> GetAccountNumber());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].AccountType -> GetAccountNumber();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetBalance());
		Temp1 = TempVector[i].AccountType -> GetBalance();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)&Temp1, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetAccountCreationDate().GetDay());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].AccountType -> GetAccountCreationDate().GetDay();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetAccountCreationDate().GetMonth());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].AccountType -> GetAccountCreationDate().GetMonth();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetAccountCreationDate().GetYear());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].AccountType -> GetAccountCreationDate().GetYear();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetWithdrawn());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp1 = TempVector[i].AccountType -> GetWithdrawn();
		outFile.write((char*)&Temp1, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetWithdrawnLastTime().GetDay());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].AccountType -> GetWithdrawnLastTime().GetDay();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetWithdrawnLastTime().GetMonth());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].AccountType -> GetWithdrawnLastTime().GetMonth();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(TempVector[i].AccountType -> GetWithdrawnLastTime().GetYear());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = TempVector[i].AccountType -> GetWithdrawnLastTime().GetYear();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = TempVector[i].CardType -> GetCardType().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].CardType -> GetCardType().c_str(), TotalSize);

		TotalSize = TempVector[i].CardType -> GetCreditCardNumber().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)TempVector[i].CardType -> GetCreditCardNumber().c_str(), TotalSize);

		if(strcmp(TempVector[i].CardType -> GetCardType().c_str(), "LocalCard") == 0) {
			TotalSize = sizeof(TempVector[i].CardType -> GetChargeLimit());
			outFile.write((char*)&TotalSize, sizeof(TotalSize));
			Temp1 = TempVector[i].CardType -> GetChargeLimit();
			outFile.write((char*)&Temp1, TotalSize);

			TotalSize = sizeof(TempVector[i].CardType -> GetInterestRate());
			outFile.write((char*)&TotalSize, sizeof(TotalSize));
			Temp1 = TempVector[i].CardType -> GetInterestRate();
			outFile.write((char*)&Temp1, TotalSize);

			TotalSize = sizeof(TempVector[i].CardType -> GetLastWithdrawAmount());
			outFile.write((char*)&TotalSize, sizeof(TotalSize));
			Temp1 = TempVector[i].CardType -> GetLastWithdrawAmount();
			outFile.write((char*)&Temp1, TotalSize);
		}
		else if(strcmp(TempVector[i].CardType -> GetCardType().c_str(), "MasterCard") == 0) {
			TotalSize = sizeof(TempVector[i].CardType -> GetFrequentUsagePoints());
			outFile.write((char*)&TotalSize, sizeof(TotalSize));
			Temp1 = TempVector[i].CardType -> GetFrequentUsagePoints();
			outFile.write((char*)&Temp1, TotalSize);
		}
	}
	int TotalAccounts = TempVector[0].GetAccountType() -> GetTotalAccounts();
	outFile.write((char*)&TotalAccounts, sizeof(int));
	outFile.flush();
	outFile.close();
}