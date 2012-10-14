#include <iostream>
#include <conio.h>

using namespace std;

int main() { //Wajeeh :P
	float x,y,b,m;
	cout << "Enter value of x: ";
	cin >> x;
	cout << "Enter value of y: ";
	cin >> y;
	cout << "Enter value of b: ";
	cin >> b;
	m = (y-b)/x;
	cout << endl << "Slope of the line is " << m << endl;
	getch();
	return 0;
}