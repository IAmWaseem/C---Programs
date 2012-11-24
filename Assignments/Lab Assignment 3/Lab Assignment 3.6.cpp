#include <iostream>
#include <conio.h>

using namespace std;

int MyPower(int, int);
long int Factorial(int);

int main() {
	int n, b, e;
	cout << "Enter Number : ";
	cin >> n;
	cout << "Factorial is : " << Factorial(n) << endl;
	cout << "Enter Base : ";
	cin >> b;
	cout << "Enter Exponent : ";
	cin >> e;
	cout << "Result of MyPower Function : " << MyPower(b,e);
	getch();
	return 0;
}

int MyPower(int b, int e) {
	int Result = 1;
	for(int i=0;i<e;i++) {
		Result = Result * b;
	}
	return Result;
}

long Factorial(int n) {
	long int fact = 1;
	for(int i=1;i<=n;i++) {
		fact = fact * i;
	}
	return fact;
}