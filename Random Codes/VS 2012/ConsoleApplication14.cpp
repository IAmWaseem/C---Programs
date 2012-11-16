#include <iostream>

using namespace std;

int Sum(int x, int y);

int main() {
	int a,b,sum;
	cout << "Enter 1st Number : ";
	cin >> a;
	cout << "Enter 2nd Number : ";
	cin >> b;
	sum = Sum(a,b);
	cout << "Sum : " << sum;
	return 0;
}

int Sum(int x, int y) {
	return x+y;
}