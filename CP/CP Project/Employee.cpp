#include "Employee.h"
#include <string>
#include <conio.h>
#include <fstream>
#include "Date.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "MasterCard.h"
#include "VisaCard.h"
#include "LocalCard.h"

Employee::Employee() {
	
}

bool Employee::ValidateLogin(const std::vector<Employee>& EmployeeList, std::string TempUserName, std::string TempPassword) const {
	for(unsigned int i = 0; i < EmployeeList.size(); i++) {
		if(strcmp(EmployeeList[i].UserName.c_str(), TempUserName.c_str()) == 0 && strcmp(EmployeeList[i].Password.c_str(), TempPassword.c_str()) == 0) {
			return true;
		}
	}
	return false;
}

void Employee::CreateAccount(std::vector<Customer>& CustomerList) {
	Customer TempCustomer;
	std::cin >> TempCustomer;
	CustomerList.push_back(TempCustomer);
	std::cout << CustomerList.back();
	std::cout << "Account Created Successfully" << std::endl;
}

void Employee::DeleteAccount(std::vector<Customer>& CustomerList) {
	int Check = 0;
	int AccountNumber;
	std::cout << "Enter Account Number of Account you want to Delete : ";
	std::cin >> AccountNumber;
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(CustomerList[i].GetAccountType() -> GetAccountNumber() == AccountNumber) {
			std::cout << CustomerList[i];
			std::cout << "Are You Sure You Want to Delete?";
			char ch = _getche();
			if(ch == 'y' || ch == 'Y') {
				delete CustomerList[i].GetAccountType();
				delete CustomerList[i].GetCardType();
				CustomerList.erase(CustomerList.begin() + i);
				std::cout << "Account Deleted Successfully" << std::endl;
			}
			else {
				std::cout << "Account Not Deleted" << std::endl;
			}
			Check = 1;
			break;
		}
	}
	if(!Check) {
		std::cout << "Account Not Found with Account Number " << AccountNumber << std::endl;
	}
}

void Employee::UpdateAccount(std::vector<Customer>& CustomerList) {
	int Check = 0;
	int tChoice;
	int AccountNumber;
	int Choice;
	double TempBalance;
	std::string Temp;
	std::cout << "Enter Account Number of Account you want to Update Information : ";
	std::cin >> AccountNumber;
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(CustomerList[i].GetAccountType() -> GetAccountNumber() == AccountNumber) {
			std::cout << CustomerList[i];
			do {
				std::cout << "What do you Want to Update?" << std::endl << std::endl
					<< "[1] First Name" << std::endl
					<< "[2] Middle Name" << std::endl
					<< "[3] Last Name" << std::endl
					<< "[4] CNIC Number" << std::endl
					<< "[5] Address" << std::endl
					<< "[6] Telephone Number" << std::endl
					<< "[7] Date of Birth" << std::endl
					<< "[8] Account Type" << std::endl
					<< "[9] Account Balance" << std::endl
					<< "[10] Credit Card Type" << std::endl
					<< "[11] Stop Updating" << std::endl << std::endl
					<< "Enter Choice[1-11]: ";
				std::cin  >> Choice;
				switch(Choice) {
					case 1:
						std::cout << "First Name[Old]: " << CustomerList[i].GetFirstName() << std::endl;
						std::cout << "Enter First Name[New]: ";
						fflush(stdin);
						std::getline(std::cin, Temp);
						CustomerList[i].SetFirstName(Temp);
						std::cout << "First Name Changed Successfully" << std::endl;
						break;
					case 2:
						std::cout << "Middle Name[Old]: " << CustomerList[i].GetMiddleName() << std::endl;
						std::cout << "Enter Middle Name[New]: ";
						fflush(stdin);
						std::getline(std::cin, Temp);
						CustomerList[i].SetMiddleName(Temp);
						std::cout << "Middle Name Changed Successfully" << std::endl;
						break;
					case 3:
						std::cout << "Last Name[Old]: " << CustomerList[i].GetLastName() << std::endl;
						std::cout << "Enter Last Name[New]: ";
						fflush(stdin);
						std::getline(std::cin, Temp);
						CustomerList[i].SetLastName(Temp);
						std::cout << "Last Name Changed Successfully" << std::endl;
						break;
					case 4:
						char Temp1[16];
						std::cout << "CNIC Number[Old]: " << CustomerList[i].GetCNICNumber() << std::endl;
						std::cout << "Enter CNIC Number[New]: ";
						fflush(stdin);
						std::cin.getline(Temp1, 16);
						CustomerList[i].SetCNICNumber(Temp1);
						std::cout << "CNIC Number Changed Successfully" << std::endl;
						break;
					case 5:
						std::cout << "Address[Old]: " << CustomerList[i].GetAddress() << std::endl;
						std::cout << "Enter Address[New]: ";
						fflush(stdin);
						std::getline(std::cin, Temp);
						CustomerList[i].SetAddress(Temp);
						std::cout << "Address Changed Successfully" << std::endl;
						break;
					case 6:
						std::cout << "Telephone Number[Old]: " << CustomerList[i].GetTelephoneNumber() << std::endl;
						std::cout << "Enter Telephone Number[New]: ";
						fflush(stdin);
						std::getline(std::cin, Temp);
						CustomerList[i].SetTelephoneNumber(Temp);
						std::cout << "Telephone Number Changed Successfully" << std::endl;
						break;
					case 7:
						std::cout << "Date of Birth[Old]: " << CustomerList[i].GetDateOfBirth() << std::endl;
						std::cout << "Enter Date of Birth[New]: ";
						//Date Temp2;
						//std::cin >> Temp2;
						//CustomerList[i].SetDateOfBirth(Temp2);
						std::cout << "Date of Birth Changed Successfully" << std::endl;
						break;
					case 8:
						std::cout << "Account Type[Old]: " << CustomerList[i].GetAccountType() -> GetAccountType() << std::endl;
						std::cout << "Enter Account Type[New]: " << std::endl << std::endl;
						std::cout << "[1] Checking Account" << std::endl
							<< "[2] Savings Account" << std::endl << std::endl
							<< "Enter Choice[1-2]: ";
						std::cin  >> tChoice;
						if((CustomerList[i].GetAccountType() -> GetAccountType() == "Checking Account" && tChoice == 1) || (CustomerList[i].GetAccountType() -> GetAccountType() == "Savings Account" && tChoice == 2)) {
							// Do Nothing
						}
						else {
							switch(tChoice) {
							case 1:
								delete CustomerList[i].GetAccountType();
								CustomerList[i].SetAccountType(new CheckingAccount());
								CustomerList[i].GetAccountType() -> SetAccountType("Checking Account");
								std::cout << "Enter Initial Balance : ";
								std::cin >> TempBalance;
								CustomerList[i].GetAccountType() -> SetBalance(TempBalance);
								std::cout << "Account Type Changed Successfully" << std::endl;
								break;
							case 2:
								delete CustomerList[i].GetAccountType();
								CustomerList[i].SetAccountType(new SavingsAccount());
								CustomerList[i].GetAccountType() -> SetAccountType("Savings Account");
								std::cout << "Enter Initial Balance : ";
								std::cin >> TempBalance;
								CustomerList[i].GetAccountType() -> SetBalance(TempBalance);
								std::cout << "Account Type Changed Successfully" << std::endl;
								break;
							default:
								std::cout << "Invalid Choice" << std::endl;
								break;
							}
						}
						break;
					case 9:
						std::cout << "Account Balance[Old]: " << CustomerList[i].GetAccountType() -> GetBalance()<< std::endl;
						std::cout << "Enter Account Balance[New]: ";
						CustomerList[i].GetAccountType() -> SetBalance(TempBalance);
						std::cout << "Account Balance Changed Successfully" << std::endl;
						break;
					case 10:
						std::cout << "Credit Card Type[Old]: " << CustomerList[i].GetCardType() -> GetCardType() << std::endl;
						std::cout << "Enter Credit Card Type[New]: " << std::endl << std::endl;
						std::cout << "[1] Master Card" << std::endl
							<< "[2] Visa Card" << std::endl
							<< "[3] Local Card" << std::endl << std::endl
							<< "Enter Choice[1-3]: ";
						std::cin  >> tChoice;
						if((CustomerList[i].GetCardType() -> GetCardType() == "MasterCard" && tChoice == 1) || (CustomerList[i].GetCardType() -> GetCardType() == "VisaCard" && tChoice == 2) || (CustomerList[i].GetCardType() -> GetCardType() == "LocalCard" && tChoice == 3)) {
							// Do Nothing
						}
						else {
							switch(tChoice) {
							case 1:
								delete CustomerList[i].GetCardType();
								CustomerList[i].SetCardType(new MasterCard());
								CustomerList[i].GetCardType() -> SetCardType("MasterCard");
								std::cout << "Credit Card Type Changed Successfully" << std::endl;
								break;
							case 2:
								delete CustomerList[i].GetCardType();
								CustomerList[i].SetCardType(new VisaCard());
								CustomerList[i].GetCardType() -> SetCardType("VisaCard");
								std::cout << "Credit Card Type Changed Successfully" << std::endl;
								break;
							case 3:
								delete CustomerList[i].GetCardType();
								CustomerList[i].SetCardType(new LocalCard());
								CustomerList[i].GetCardType() -> SetCardType("LocalCard");
								std::cout << "Credit Card Type Changed Successfully" << std::endl;
								break;
							default:
								std::cout << "Invalid Choice" << std::endl;
								break;
							}
						}
						break;
					case 11:
						std::cout << "Finished Updating" << std::endl;
						break;
					default:
						std::cout << "Invalid Choice" << std::endl;
						break;
				}
				system("pause");
			} while(Choice != 11);
			Check = 1;
		}
	}
	if(!Check) {
		std::cout << "Account Not Found with Account Number " << AccountNumber << std::endl;
	}
}

void Employee::SearchAccount(const std::vector<Customer>& CustomerList) {
	int Choice;
	do {
		int Check = 0;
		int AccountNumber;
		std::string CNIC;
		std::cout << "[1] Search Account Using Account Number" << std::endl
				  << "[2] Search Account Using CNIC Number" << std::endl
				  << "[3] Back to Menu" << std::endl << std::endl
				  << "Enter Choice[1-3]: ";
		std::cin  >> Choice;
		switch(Choice) {
			case 1:
				std::cout << "Enter Account Number : ";
				std::cin >> AccountNumber;
				break;
			case 2:
				std::cout << "Enter CNIC Number : ";
				std::getline(std::cin, CNIC);
				break;
			case 3:
				break;
			default:
				break;
		}
		if(Choice == 1 || Choice == 2) {
			for(unsigned int i = 0; i < CustomerList.size(); i++) {
				if(Choice == 2) {
					if(CustomerList[i].GetCNICNumber() == CNIC) {
						std::cout << CustomerList[i];
						Check = 1;
						break;
					}
				}
				else if(Choice == 1) {
					if(CustomerList[i].GetAccountType() -> GetAccountNumber() == AccountNumber) {
						std::cout << CustomerList[i];
						Check = 1;
						break;
					}
				}
			}
		}
		if(!Check && (Choice == 1 || Choice == 2)) {
			std::cout << "Account Not Found with Account Number " << AccountNumber << std::endl;
		}
	} while(Choice != 3);
}

void Employee::DisplayAccount(const std::vector<Customer>& CustomerList) {
	int Choice;
	int Check = 0;
	std::cout << "What Accounts you want to Display?" << std::endl << std::endl;
	std::cout << "[1] Savings Accounts" << std::endl
			  << "[2] Checking Accounts" << std::endl
			  << "[3] Accounts that use Master Cards" << std::endl
			  << "[4] Accounts that use Visa Cards" << std::endl
			  << "[5] Accounts that use Local Cards" << std::endl
			  << "[6] Back to Menu" << std::endl << std::endl
			  << "Enter Choice[1-6]:";
	std::cin  >> Choice;
	if(Choice > 0 && Choice < 6) {
		for(unsigned int i = 0; i < CustomerList.size(); i++) {
			if(Choice == 1) {
				if(strcmp(CustomerList[i].GetAccountType() -> GetAccountType().c_str(), "Savings Account") == 0) {
					std::cout << CustomerList[i] << std::endl;
					Check = 1;
				}
			}
			else if(Choice == 2) {
				if(strcmp(CustomerList[i].GetAccountType() -> GetAccountType().c_str(), "Checking Account") == 0) {
					std::cout << CustomerList[i] << std::endl;
					Check = 1;
				}
			}
			else if(Choice == 3) {
				if(strcmp(CustomerList[i].GetCardType() -> GetCardType().c_str(), "MasterCard") == 0) {
					std::cout << CustomerList[i] << std::endl;
					Check = 1;
				}
			}
			else if(Choice == 4) {
				if(strcmp(CustomerList[i].GetCardType() -> GetCardType().c_str(), "VisaCard") == 0) {
					std::cout << CustomerList[i] << std::endl;
					Check = 1;
				}
			}
			else if(Choice == 5) {
				if(strcmp(CustomerList[i].GetCardType() -> GetCardType().c_str(), "LocalCard") == 0) {
					std::cout << CustomerList[i] << std::endl;
					Check = 1;
				}
			}
		}
		if(!Check) {
			std::cout << "No Account Not Found" << std::endl;
		}
	}
	else {
		std::cout << "Invalid Choice Entered" << std::endl;
	}
}

void Employee::MakeTransaction(std::vector<Customer>& CustomerList) {
	int AccountNumber;
	int Choice;
	double TempMoney;
	std::cout << "Enter Account Number : ";
	std::cin >> AccountNumber;
	for(unsigned int i = 0; i < CustomerList.size(); i++) {
		if(CustomerList[i].GetAccountType() -> GetAccountNumber() == AccountNumber) {
			do {
				std::cout << "Current Balance : " << CustomerList[i].GetAccountType() -> GetBalance() << std::endl;
				std::cout << "What do you want to do?" << std::endl << std::endl
						  << "[1] Deposit Money" << std::endl
						  << "[2] Withdraw Money" << std::endl
						  << "[3] Back to Menu" << std::endl << std::endl
						  << "Enter Choice[1-3]: ";
				std::cin  >> Choice;
				switch(Choice) {
					case 1:
						std::cout << "Enter Amount to Deposit : ";
						std::cin >> TempMoney;
						CustomerList[i].GetAccountType() -> SetBalance(CustomerList[i].GetAccountType() -> GetBalance() + TempMoney);
						std::cout << TempMoney << " deposited to that Account." << std::endl << "New Balance : " << CustomerList[i].GetAccountType() -> GetBalance() << std::endl;
						break;
					case 2:
						std::cout << "Enter Amount to Withdraw : ";
						std::cin >> TempMoney;
						if(CustomerList[i].GetAccountType() -> GetBalance() < TempMoney) {
							std::cout << "Not Enough Money in the Account" << std::endl;
						}
						else {
							CustomerList[i].GetAccountType() -> Withdraw(TempMoney);
							CustomerList[i].GetAccountType() -> GovernmentTax(TempMoney);
							std::cout << "Successfully Withdrawn Money from Account" << std::endl;
						}
						break;
					case 3:
						break;
					default:
						std::cout << "Invalid Choice" << std::endl;
						break;
				}
				system("pause");
			} while(Choice != 3);
		}
	}
}

std::string Employee::GetUserName() const {
	return UserName;
}

std::string Employee::GetPassword() const {
	return Password;
}

void Employee::CreateEmployee(std::vector<Employee>& EmployeeList) {
	std::cout << "Enter First Name : ";
	fflush(stdin);
	getline(std::cin, this -> First_Name);
	std::cout <<"Enter Middle Name : ";
	fflush(stdin);
	getline(std::cin, this -> Middle_Name);
	std::cout << "Enter Last Name : ";
	fflush(stdin);
	getline(std::cin, this -> Last_Name);
	std::cout << "Enter Address : ";
	fflush(stdin);
	getline(std::cin, this -> Address);
	std::cout << "Enter Telephone Number : ";
	fflush(stdin);
	getline(std::cin, this -> Telephone_Number);
	std::cout << "Enter CNIC Number : ";
	fflush(stdin);
	getline(std::cin, this -> CNIC_Number);
	std::cout << "Enter Date of Birth : ";
	std::cin >> DateOfBirth;
	std::cout << "Enter UserName : ";
	fflush(stdin);
	getline(std::cin, this -> UserName);
	std::cout << "Enter Password : ";
	fflush(stdin);
	getline(std::cin, this -> Password);
	std::cout << "Employee Created Successfully" << std::endl << std::endl;
	std::cout << "UserName : " << this -> UserName << std::endl;
	std::cout << "Password : " << this -> Password << std::endl;
	EmployeeList.push_back(*this);
}

void Employee::Read(std::vector<Employee>& EmployeeData) {
	std::ifstream inFile;
	inFile.open("EmployeeData.dat", std::ios::in | std::ios::binary);
	if(!inFile) {

	}
	else {
		int VectorSize;
		inFile.read((char*)&VectorSize, sizeof(VectorSize));
		EmployeeData.resize(VectorSize);
		for(int i = 0; i < VectorSize; i++) {
			int TotalSize, Temp;
			std::string Temp2;
			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetFirstName(Temp2);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetMiddleName(Temp2);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetLastName(Temp2);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetCNICNumber(Temp2);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetAddress(Temp2);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetTelephoneNumber(Temp2);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			inFile.read((char*)&Temp, TotalSize);
			EmployeeData[i].GetDateOfBirth().SetDay(Temp);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			inFile.read((char*)&Temp, TotalSize);
			EmployeeData[i].GetDateOfBirth().SetMonth(Temp);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			inFile.read((char*)&Temp, TotalSize);
			EmployeeData[i].GetDateOfBirth().SetYear(Temp);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetUserName(Temp2);

			inFile.read((char*)&TotalSize, sizeof(TotalSize));
			Temp2.resize(TotalSize);
			inFile.read((char*)Temp2.c_str(), TotalSize);
			Temp2[TotalSize] = NULL;
			EmployeeData[i].SetPassword(Temp2);
		}
	}
}

void Employee::Write(std::vector<Employee>& EmployeeData) {
	std::ofstream outFile;
	outFile.open("EmployeeData.dat", std::ios::out | std::ios::binary);
	if(!outFile) {
		std::cout << "Cannot Open EmployeeData.dat for Writing" << std::endl;
		return;
	}
	int VectorSize = EmployeeData.size();
	outFile.write((char*)&VectorSize, sizeof(VectorSize));
	for(int i = 0; i < VectorSize; i++) {
		int Temp, TotalSize;
		TotalSize = EmployeeData[i].GetFirstName().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetFirstName().c_str(), TotalSize);

		TotalSize = EmployeeData[i].GetMiddleName().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetMiddleName().c_str(), TotalSize);

		TotalSize = EmployeeData[i].GetLastName().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetLastName().c_str(), TotalSize);

		TotalSize = EmployeeData[i].GetCNICNumber().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetCNICNumber().c_str(), TotalSize);

		TotalSize = EmployeeData[i].GetAddress().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetAddress().c_str(), TotalSize);

		TotalSize = EmployeeData[i].GetTelephoneNumber().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetTelephoneNumber().c_str(), TotalSize);

		TotalSize = sizeof(EmployeeData[i].GetDateOfBirth().GetDay());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = EmployeeData[i].DateOfBirth.GetDay();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(EmployeeData[i].GetDateOfBirth().GetMonth());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = EmployeeData[i].DateOfBirth.GetMonth();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = sizeof(EmployeeData[i].GetDateOfBirth().GetYear());
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		Temp = EmployeeData[i].DateOfBirth.GetYear();
		outFile.write((char*)&Temp, TotalSize);

		TotalSize = EmployeeData[i].GetUserName().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetUserName().c_str(), TotalSize);

		TotalSize = EmployeeData[i].GetPassword().length();
		outFile.write((char*)&TotalSize, sizeof(TotalSize));
		outFile.write((char*)EmployeeData[i].GetPassword().c_str(), TotalSize);
	}
}

void Employee::SetUserName(std::string username) {
	UserName = username;
}

void Employee::SetPassword(std::string password) {
	Password = password;
}