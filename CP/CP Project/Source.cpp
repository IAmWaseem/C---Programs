#include <iostream>
#include <string>
#include <vector>
#include "Bank.h"
#include "Customer.h"
#include "Employee.h"

void MainMenu();
void BankCustomer(std::vector<Customer>& CustomerList, std::vector<Transaction>& TransactionList, Customer TempCustomer);
void BankEmployee(std::vector<Customer>& CustomerList, const std::vector<Employee>& EmployeeList, Employee TempEmployee);

int main() {
	MainMenu();
	return 0;
}

void MainMenu() {
	std::vector<Customer> CustomerList;
	std::vector<Employee> EmployeeList;
	std::vector<Transaction> TransactionList;
	Employee TempEmployee;
	Customer TempCustomer;
	TempEmployee.Read(EmployeeList);
	TempCustomer.Read(CustomerList);
	//TempEmployee.CreateEmployee(EmployeeList);
	ReadTransactions(TransactionList);
	int Choice;
	do {
		system("cls");
		std::cout << "FAST Banking System" << std::endl << std::endl
				  << "Login As" << std::endl << std::endl
				  << "[1] Bank Employee" << std::endl
				  << "[2] Bank Customer" << std::endl
				  << "[3] Exit the Application" << std::endl
				  << "Enter Choice[1-3]: ";
		std::cin  >> Choice;
		switch(Choice) {
			case 1:
				BankEmployee(CustomerList, EmployeeList, TempEmployee);
				break;
			case 2:
				BankCustomer(CustomerList, TransactionList, TempCustomer);
				break;
			case 3:
				break;
			default:
				std::cout << "Invalid Choice" << std::endl;
				break;
		}
	} while(Choice != 3);
	if(!CustomerList.empty()) {
		TempCustomer.Write(CustomerList);
	}
	if(!EmployeeList.empty()) {
		TempEmployee.Write(EmployeeList);
	}
	//WriteTransactions(TransactionList);
}

void BankCustomer(std::vector<Customer>& CustomerList, std::vector<Transaction>& TransactionList, Customer TempCustomer) {
	int Choice;
	do {
		system("cls");
		std::cout << "Welcome Customer" << std::endl << std::endl
				  << "[1] Mini Statement" << std::endl
				  << "[2] Withdraw Money via Credit Card" << std::endl
				  << "[3] Withdraw Money via Check Book" << std::endl
				  << "[4] Balance Inquiry" << std::endl
				  << "[5] Transaction History" << std::endl
				  << "[6] Back to Main Menu" << std::endl << std::endl
				  << "Enter Choice[1-6]: ";
		std::cin  >> Choice;
		switch(Choice) {
			case 1:
				TempCustomer.MiniStatement(TransactionList, CustomerList);
				break;
			case 2:
				TempCustomer.WithdrawViaCreditCard(TransactionList, CustomerList);
				break;
			case 3:
				TempCustomer.WithdrawViaCheckBook(TransactionList, CustomerList);
				break;
			case 4:
				TempCustomer.BalanceEnquiry(CustomerList);
				break;
			case 5:
				TempCustomer.TransactionHistory(TransactionList, CustomerList);
				break;
			case 6:
				break;
			default:
				std::cout << "Invalid Choice" << std::endl;
				break;
		}
		system("pause");
	} while(Choice != 6);
}

void BankEmployee(std::vector<Customer>& CustomerList, const std::vector<Employee>& EmployeeList, Employee TempEmployee) {
	std::string TempUserName, TempPassword;
	std::cout << "Employee Login" << std::endl;
	std::cout << "Enter Username : ";
	fflush(stdin);
	std::getline(std::cin, TempUserName);
	std::cout << "Enter Password : ";
	fflush(stdin);
	std::getline(std::cin, TempPassword);
	if((TempEmployee.ValidateLogin(EmployeeList, TempUserName, TempPassword))) {
		std::cout << "Invalid Login Username or Password" << std::endl;
		system("pause");
		system("cls");
		BankEmployee(CustomerList, EmployeeList, TempEmployee);
	}
	else {
		int Choice;
		std::cout << "Logged in Successfully." << std::endl;
		system("pause");
		do {
			system("cls");
			std::cout << "Welcome " << TempEmployee.GetFirstName() << std::endl << std::endl
					  << "[1] Create an Account" << std::endl
					  << "[2] Delete an Account" << std::endl
					  << "[3] Update an Account's Information" << std::endl
					  << "[4] Find Account Holders Information" << std::endl
					  << "[5] Display All Accounts of Particular Account Type" << std::endl
					  << "[6] Deposit or Withdraw amount to / from a particular Account" << std::endl
					  << "[7] Log Out" << std::endl << std::endl
					  << "Enter Choice[1-7]: ";
			std::cin  >> Choice;
			switch(Choice) {
				case 1:
					TempEmployee.CreateAccount(CustomerList);
					break;
				case 2:
					TempEmployee.DeleteAccount(CustomerList);
					break;
				case 3:
					TempEmployee.UpdateAccount(CustomerList);
					break;
				case 4:
					TempEmployee.SearchAccount(CustomerList);
					break;
				case 5:
					TempEmployee.DisplayAccount(CustomerList);
					break;
				case 6:
					TempEmployee.MakeTransaction(CustomerList);
					break;
				case 7:
					std::cout << "Successfully Logged Out" << std::endl;
					break;
				default:
					std::cout << "Invalid Choice" << std::endl;
					break;
			}
			system("pause");
		} while(Choice != 7);
	}
}
