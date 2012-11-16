#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int x,y,sum;
	cout << "Enter 1st Number : ";
	cin >> x;
	cout << "Enter 2nd Number : ";
	cin >> y;
	sum = x + y;
	cout << "The SUM of " << x << " and " << y << " is " << sum << "." << endl;
	_getch();
	return 0;
}