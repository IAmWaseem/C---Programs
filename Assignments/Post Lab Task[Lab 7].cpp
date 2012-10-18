#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	long double total_cost,down_payment,payable_amount,new_payable_amount,monthly_installment;
	int installment_months,check=1;
	float interest_rate;
	cout << "What is te Total Cost of Car: ";
	cin >> total_cost;
	cout << endl << "What is the Down Payment: ";
	cin >> down_payment;
	cout << endl << "For how much months you want to Lease a Car: ";
	cin >> installment_months;
	payable_amount = total_cost - down_payment ;
	if(installment_months<=12) {
		interest_rate = payable_amount * 0.10;
	}
	else if(installment_months>12 && installment_months<=24) {
		interest_rate = payable_amount * 0.15;
	}
	else if(installment_months>24 && installment_months<=36) {
		interest_rate = payable_amount * 0.20;
	}
	else if(installment_months>36 && installment_months<=48) {
		interest_rate = payable_amount * 0.25;
	}
	else if(installment_months>48 && installment_months<=60) {
		interest_rate = payable_amount * 0.30;
	}
	else {
		check=0;
		cout << "Error : Invalid Number of Months Entered";
	}
	if(check==1) {
		new_payable_amount = payable_amount + interest_rate;
		monthly_installment = new_payable_amount/installment_months;
		cout << "Per Month Installment is: " << monthly_installment << endl;
	}
	getch();
	return 0;
}