#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char grade;
	cout << "Enter Grade : ";
	cin >> grade;
	if(grade=='a' || grade=='A') {
		cout << "Marks = 10";
	}
	else if(grade=='b' || grade=='B') {
		cout << "Marks = 8";
	}
	else if(grade=='c' || grade=='C') {
		cout << "Marks = 6";
	}
	else if(grade=='d' || grade=='D') {
		cout << "Marks = 5";
	}
	else if(grade=='f' || grade=='F') {
		cout << "Marks = 0";
	}
	else {
		cout << "Wrong Grade Entered";
	}
	getch();
	return 0;
}