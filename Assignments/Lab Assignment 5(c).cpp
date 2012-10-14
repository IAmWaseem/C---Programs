#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int x,y;
	char op;
	cout << "Enter the Expression : " << endl;
	cin >> x >> op >> y;
	cout << endl;
	if(op=='+') {
		cout << x << " + " << y << " = " << x+y << endl;
	}
	else if(op=='-') {
		cout << x << " - " << y << " = " << x-y << endl;
	}
	else if(op=='*') {
		cout << x << " * " << y << " = " << x*y << endl;
	}
	else if(op=='/') {
		cout << x << " / " << y << " = " << x/y << endl;
	}
	else {
		cout << endl << "Invalid Expression Entered";
	}
	getch();
	return 0;
}