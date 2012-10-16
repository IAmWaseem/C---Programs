#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	float marks;
	cout << "Enter Marks of Student : ";
	cin >> marks;
	if(marks==10) {
		cout << "Grade is 'A'" << endl;
	}
	else if(marks<10 && marks>=8) {
		cout << "Grade is 'B'";
	}
	else if(marks<8 && marks>=6) {
		cout << "Grade is 'C'";
	}
	else if(marks<6 && marks>=5) {
		cout << "Grade is 'D'";
	}
	else if(marks<5 && marks>=0) {
		cout << "Grade is 'F'";
	}
	else {
		cout << "Invalid Marks Entered";
	}
	getch();
	return 0;
}