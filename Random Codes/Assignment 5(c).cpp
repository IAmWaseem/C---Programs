/*

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



#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int tcd,charges,check=1;
	cout << "Please Enter Total Call Duration in Minutes: ";
	cin >> tcd;
	if(tcd>0 && tcd<=2) {
		charges=12;
	}
	else if(tcd>2 && tcd<=5) {
		charges=10;
	}
	else if(tcd>5 && tcd<=8) {
		charges=7;
	}
	else if(tcd>8 && tcd<=10) {
		charges=5;
	}
	else if(tcd>10) {
		charges=3;
	}
	else {
		cout << "Wrong Value Entered";
		check=0;
	}
	if(check==1) {
		cout << "Total Call Duration is: " << tcd << endl;
		cout << "Tocal Call Charges are: " << tcd*charges << "Pkr." << endl;
	}
	getch();
	return  0;
}
*/

#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
int main ()
{
float y,x,b,a;
float m;
cout<< "Enter value of y= ";
cin>>y;

cout<< "Enter value of x= ";
cin>>x;

cout<< "Enter value of b= ";
cin>>b;

m=(y-b)/x;
cout<<"m =" <<m;
getch();
return 0;
}   