#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int IntegerArray[10];
	float FloatArray[15];
	double DoubleArray[20];
	char CharacterArray[25];
	cout << "Memory Size of Integer Type Array of 10 Indexes : " << sizeof(IntegerArray) << endl;
	cout << "Memory Size of Float Type Array of 15 Indexes : " << sizeof(FloatArray) << endl;
	cout << "Memory Size of Double Type Array of 20 Indexes : " << sizeof(DoubleArray) << endl;
	cout << "Memory Size of Character Type Array of 25 Indexes : "<< sizeof(CharacterArray) << endl;
	getch();
	return 0;
}