#pragma once
#ifndef BANK_H
#define BANK_H
#include "Date.h"

class Bank {
	public:
		//virtual void Read(std::vector<Customer>& TempVector) = 0;
		//virtual void Write(std::vector<Customer>& TempVector) = 0;
		Bank& SetFirstName(std::string fName);
		Bank& SetMiddleName(std::string mName);
		Bank& SetLastName(std::string lName);
		Bank& SetCNICNumber(std::string cnic);
		Bank& SetAddress(std::string add);
		Bank& SetTelephoneNumber(std::string telephone);
		Bank& SetDateOfBirth(Date dob);
		std::string GetFirstName() const;
		std::string GetMiddleName() const;
		std::string GetLastName() const;
		std::string GetCNICNumber() const;
		std::string GetAddress() const;
		std::string GetTelephoneNumber() const;
		Date& GetDateOfBirth();
		Bank();
	protected:
		//static std::vector<Customer> CustomerList;
		//static std::vector<Employee> EmployeeList;
		std::string First_Name;
		std::string Middle_Name;
		std::string Last_Name;
		std::string CNIC_Number;
		std::string Address;
		std::string Telephone_Number;
		Date DateOfBirth;
};

#endif
