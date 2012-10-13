#include <iostream>

using namespace std;

int main() {
	float x,y,z;
	cout << "Enter 1st value in Float : ";
	cin >> x;
	cout << "Enter 2nd value in Float : ";
	cin >> y;
	cout << "Enter 3rd value in Float : ";
	cin >> z;
	cout << endl << "Distributive Law of Multiplication" << endl;
	cout << "L.H.S = " << x*(y+z) << endl;
	cout << "R.H.S = " << x*y+x*z << endl;
	cout << "-------" << endl;
	cout << "Associative Law of Addition" << endl;
	cout << "L.H.S = " << (x+y)+z << endl;
	cout << "R.H.S = " << x+(y+z) << endl;
	system("pause");
	return 0;
}