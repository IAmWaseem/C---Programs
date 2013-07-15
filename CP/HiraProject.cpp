#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
	int Number, check = 1;
	cout << "Enter Number : ";
	cin >> Number;
	for(int i=2;i<Number;i++) {
		if(Number%i==0) {
			cout << "Number is not Prime" << endl;
			check = 0;
			break;
		}
	}
	if(check) {
		cout << "Number is Prime" << endl;
	}
	int a = 5 * Number * Number + 4;
	int b = 5 * Number * Number - 4;
	float temp1 = sqrt(a);
	float temp2 = sqrt(b);
	int temp1_1 = temp1;
	int temp2_2 = temp2;
	if(temp1==temp1_1 || temp2==temp2_2) {
		cout << "Number is a Fibonacci Number" << endl;
	}
	else {
		cout << "Number is not a Fibonacci Number" << endl;
	}
	int sum = 0;
	while(Number!=0) {
		sum = sum + Number % 10;
		Number = Number / 10;
	}
	cout << "Sum of Digits = " << sum << endl;
	getch();
	return 0;
}