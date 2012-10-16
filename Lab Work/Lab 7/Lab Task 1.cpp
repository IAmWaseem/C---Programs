#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int a=1;
	char b='A';
	float c=2.3;
	double d=2.4;
	cout << "The Size of Integer variable a : " << sizeof(a) << endl;
	cout << "The Size of Character variable b : " << sizeof(b) << endl;
	cout << "The Size of Floating variable c : " << sizeof(c) << endl;
	cout << "The Size of Double variable d : " << sizeof(d) << endl;
	getch();
	return 0;
}