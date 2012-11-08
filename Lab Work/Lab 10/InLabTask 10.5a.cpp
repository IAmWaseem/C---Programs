#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[6];
	double DoubleArray[5];
	char CharacterArray[4];
	int i=0;
	while(i<6) {
		cout << "Enter Value of Integer Type Array at Location " << i << " : ";
		cin >> IntegerArray[i];
		i++;
	}
	i=0;
	while(i<5) {
		cout << "Enter Value of Double Type Array at Location " << i << " : ";
		cin >> DoubleArray[i];
		i++;
	}
	i=0;
	while(i<4) {
		cout << "Enter Value of Character Type Array at Location " << i << " : ";
		cin >> CharacterArray[i];
		i++;
	}
	getch();
	return 0;
}