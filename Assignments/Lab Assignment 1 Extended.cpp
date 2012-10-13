#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
	float a,b,c,x1,x2,im;
	cout << "Enter a : ";
	cin >> a;
	cout << "Enter b : ";
	cin >> b;
	cout << "Enter c : ";
	cin >> c;
	if((pow(b,2)-4*a*c)==0) {
		cout << "Real and 1 Root" << endl << endl;
		cout << "X = " << -b/(2*a) << endl;
	}
	else if((pow(b,2)-4*a*c)>0) {
		x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
		x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
		cout << "Real and 2 Roots" << endl << endl;
		cout << "X = " << x1 << endl << "X = " << x2 << endl;
	}
	else if((pow(b,2)-4*a*c)<0) {
		cout << "Imaginary and 2 Roots" << endl << endl;
		im = sqrt(-(pow(b,2)-4*a*c))/(2*a);
		cout << "X = " << -b/(2*a) << " + " << im << "i" << endl;
		cout << "X = " << -b/(2*a) << " - " << im << "i" << endl;
	}
	_getch();
	return 0;
}