#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	for(int i=0;i<6;i++) {
		cout << "Enter Value of Integer Type Array at Location " << i << " : ";
		cin >> IntegerArray[i];
	}
	for(int i=0;i<5;i++) {
		cout << "Enter Value of Double Type Array at Location " << i << " : ";
		cin >> DoubleArray[i];
	}
	for(int i=0;i<4;i++) {
		cout << "Enter Value of Character Type Array at Location " << i << " : ";
		cin >> CharacterArray[i];
	}
	getch();
	return 0;
}