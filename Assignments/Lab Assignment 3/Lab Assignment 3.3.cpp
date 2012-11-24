#include <iostream>
#include <conio.h>

using namespace std;

int sum(int);

int main() {
	int num;
	cout << "Enter a 5-Digit Number : ";
	cin >> num;
	int Sum;
	Sum = sum(num);
	cout << "Sum of Digits : " << Sum;
	getch();
	return 0;
}

int sum(int n) {
	int sum = 0;
	while(n!=0) {
		sum = sum + n % 10;
		n = n / 10;
	}
	return sum;
}