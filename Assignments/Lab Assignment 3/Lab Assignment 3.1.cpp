#include <iostream>
#include <conio.h>

using namespace std;

float Product(int, float);

int main() {
	int num1;
	float num2;
	int Result;
	cout << "Enter Integer Number : ";
	cin >> num1;
	cout << "Enter Floating Number : ";
	cin >> num2;
	Result = Product(num1,num2);
	cout << endl << "The Product of " << num1 << " and " << num2 << " is " << Result << endl;

	getch();
	return 0;
}

float Product(int x, float y) {
	return x*y;
}