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
	for(int i=0;i<6;i++) {
		cout << "IntegerArray[" << i << "] = " << IntegerArray[i] << endl;
	}
	for(int i=0;i<5;i++) {
		cout << "DoubleArray[" << i << "] = " << DoubleArray[i] << endl;
	}
	for(int i=0;i<4;i++) {
		cout << "CharacterArray[" << i << "] = " << CharacterArray[i] << endl;
	}
	getch();
	return 0;
}