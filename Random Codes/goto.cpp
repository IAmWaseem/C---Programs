#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int a,b,n;
	MENU:
	system("cls");
	cout << "[1] Add" << endl;
	cout << "[2] Subtract" << endl;
	cout << "[3] Multiplication" << endl;
	cout << "[4] Division" << endl;
	cout << "[5] Exit" << endl;
	cout << "Enter Choice[1-5]: ";
	cin >> n;
	if(n>=1 && n<5) {
		cout << "Enter 1st Value : ";
		cin >> a;
		cout << "Enter 2nd Value : ";
		cin >> b;
	}
	if(n==1) {
		cout << "The SUM of " << a << " and " << b << " is " << a+b << endl;
		getch();
		goto MENU;
	}
	else if(n==2) {
		cout << "The SUBTRACTION of " << a << " and " << b << " is " << a-b << endl;
		getch();
		goto MENU;
	}
	else if(n==3) {
		cout << "The PRODUCT of " << a << " and " << b << " is " << a*b << endl;
		getch();
		goto MENU;
	}
	else if(n==4) {
		if(b==0) {
			cout << "Error : Division By Zero Not Possible";
		}
		else {
			cout << "The DIVISION of " << a << " and " << b << " is " << a/b << endl;
		}
		getch();
		goto MENU;
	}
	else if(n==5) {
		cout << "Exiting" << endl;
	}
	else {
		cout << "Invalid Choice" << endl;
		cout << "Enter Again";
		getch();
		goto MENU;
	}
	getch();
	return 0;
}