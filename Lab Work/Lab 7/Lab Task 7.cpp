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
	if(tcd>2 && tcd<=5) {
		charges=10;
	}
	if(tcd>5 && tcd<=8) {
		charges=7;
	}
	if(tcd>8 && tcd<=10) {
		charges=5;
	}
	if(tcd>10) {
		charges=3;
	}
	if(tcd<=0) {
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