#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int tcd,charges,check=0;
	cout << "Please Enter Total Call Duration in Minutes: ";
	cin >> tcd;
	if(tcd>0 && tcd<=2) {
		charges=12;
		check=1;
	}
	else if(tcd>2 && tcd<=5) {
		charges=10;
		check=1;
	}
	else if(tcd>5 && tcd<=10) {
		charges=5;
		check=1;
	}
	else if(tcd>10) {
		charges=3;
		check=1;
	}
	else {
		cout << "Wrong Value Entered";
	}
	if(check==1) {
		cout << "Total Call Duration is: " << tcd << endl;
		cout << "Tocal Call Charges are: " << tcd*charges << "Pkr." << endl;
	}
	getch();
	return  0;
}