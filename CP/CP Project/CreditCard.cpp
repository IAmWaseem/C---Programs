#include "CreditCard.h"
#include <iostream>
#include "Extra.cpp"

void CreditCard::GenerateCreditCardNumber() {
	for(int i = 0; i < 15; i++) {
		CreditCardNumber += IntToChar(rand() % 10);	
	}
}

void CreditCard::SetCardType(std::string cardtype) {
	CardType = cardtype;
}

std::string CreditCard::GetCardType() const {
	return CardType;
}

std::string CreditCard::GetCreditCardNumber() {
	return CreditCardNumber;
}

double CreditCard::GetChargeLimit() {
	return 0;
}

double CreditCard::GetInterestRate() {
	return 0;
}

double CreditCard::GetLastWithdrawAmount() {
	return 0;
}

double CreditCard::GetFrequentUsagePoints() {
	return 0;
}

void CreditCard::SetCreditCardNumber(std::string number) {
	CreditCardNumber = number;
}

void CreditCard::SetChargeLimit(double num) {
	
}

void CreditCard::SetFrequentUsagePoints(double num) {
	
}

void CreditCard::SetInterestRate(double num) {

}

void CreditCard::SetLastWithdrawAmount(double num) {

}