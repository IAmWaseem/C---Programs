#include <iostream>
#include <conio.h>

using namespace std;

void Circulate(int &, int &, int &);

int main() {
	int x, y, z;
	cout << "Enter x : ";
	cin >> x;
	cout << "Enter y : ";
	cin >> y;
	cout << "Enter z : ";
	cin >> z;
	cout << endl << "Values Before Circulation" << endl << endl;
	cout << "x = " << x << endl << "y = " << y << endl << "z = " << z << endl;
	Circulate(x,y,z);
	cout << endl << "Values After Circulation" << endl << endl;
	cout << "x = " << x << endl << "y = " << y << endl << "z = " << z << endl;
	getch();

	return 0;
}

void Circulate(int &a, int &b, int &c) {
	int temp1, temp2;
	temp1 = c;
	c = b;
	temp2 = a;
	a = temp1;
	b = temp2;
	return;
}