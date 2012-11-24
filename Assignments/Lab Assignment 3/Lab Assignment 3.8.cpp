#include <iostream>
#include <conio.h>

using namespace std;

void DecimalToBinary(int);

int main() {
	int num;
	cout << "Enter a Decimal Integer : ";
	cin >> num;
	DecimalToBinary(num);
	getch();
	return 0;
}

void DecimalToBinary(int n) {
	int test[100], count=0;
	while(n!=0) {
		test[count] = n%2;
		n = n / 2;
		count++;
	}
	cout << "Binary Equivalent : ";
	for(int i=count-1;i>=0;i--) {
		cout << test[i];
	}
	return;
}