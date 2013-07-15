#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int Number;
	int Key;
	int NumberBinary[32];
	cout << "Enter Number : ";
	cin >> Number;
	cout << "Enter Key : ";
	cin >> Key;
	for(int i=31,j=0;i>=0;i--,j++) {
		NumberBinary[j] = (Number >> i) % 2;
	}
	NumberBinary[Key] = 1;
	Number = 0;
	for(int i=0,j=31;i<32;i++,j--) {
		Number = Number + NumberBinary[i] * pow(2,j);
	}
	Number = Number >> Key;
	for(int i=31,j=0;i>=0;i--,j++) {
		NumberBinary[j] = (Number >> i) % 2;
	}
	if(Number%2==0) {
		for(int i=0;i<32;i++) {
			if(NumberBinary[i]) {
				NumberBinary[i] = 0;
			}
			else {
				NumberBinary[i] = 1;
			}
		}
	}
	else {
		for(int i=1;i<32;i+=2) {
			if(NumberBinary[i]) {
				NumberBinary[i] = 0;
			}
			else {
				NumberBinary[i] = 1;
			}
		}
	}
	Number = 0;
	for(int i=0,j=31;i<32;i++,j--) {
		Number = Number + NumberBinary[i] * pow(2,j);
	}
	cout << endl << "Encrypted Text : " << Number;
	getch();
	return 0;
}