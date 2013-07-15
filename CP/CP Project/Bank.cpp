#include "Bank.h"

Bank::Bank() {

}

Bank& Bank::SetFirstName(std::string fName) {
	First_Name = fName;
	return *this;
}

Bank& Bank::SetMiddleName(std::string mName) {
	Middle_Name = mName;
	return *this;
}

Bank& Bank::SetLastName(std::string lName) {
	Last_Name = lName;
	return *this;
}

Bank& Bank::SetCNICNumber(std::string cnic) {
	CNIC_Number = cnic;
	return *this;
}

Bank& Bank::SetAddress(std::string add) {
	Address = add;
	return *this;
}

Bank& Bank::SetTelephoneNumber(std::string telephone) {
	Telephone_Number = telephone;
	return *this;
}

Bank& Bank::SetDateOfBirth(Date dob) {
	DateOfBirth = dob;
	return *this;
}

std::string Bank::GetFirstName() const {
	return First_Name;
}

std::string Bank::GetMiddleName() const {
	return Middle_Name;
}

std::string Bank::GetLastName() const {
	return Last_Name;
}

std::string Bank::GetCNICNumber() const {
	return CNIC_Number;
}

std::string Bank::GetAddress() const {
	return Address;
}

std::string Bank::GetTelephoneNumber() const {
	return Telephone_Number;
}

Date& Bank::GetDateOfBirth() {
	return DateOfBirth;
}