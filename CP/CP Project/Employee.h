#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Customer.h"
#include <vector>
#include "Bank.h"


class Employee : public Bank {
	public:
		Employee();
		void Read(std::vector<Employee>& EmployeeData);
		void Write(std::vector<Employee>& EmployeeData);
		bool ValidateLogin(const std::vector<Employee>& EmployeeList, std::string TempUserName, std::string TempPassword) const;
		void CreateAccount(std::vector<Customer>& CustomerList);
		void DeleteAccount(std::vector<Customer>& CustomerList);
		void UpdateAccount(std::vector<Customer>& CustomerList);
		void SearchAccount(const std::vector<Customer>& CustomerList);
		void DisplayAccount(const std::vector<Customer>& CustomerList);
		void MakeTransaction(std::vector<Customer>& CustomerList);
		std::string GetUserName() const;
		std::string GetPassword() const;
		void SetUserName(std::string username);
		void SetPassword(std::string password);
		void CreateEmployee(std::vector <Employee>& EmployeeList);
	private:
		std::string UserName;
		std::string Password;
};

#endif
