
#include <iostream>
#include <conio.h>

using namespace std;

int Pascal(int, int);

int main() {
	int Number;
	cout << "Enter Number : ";
	cin >> Number;
	cout << "Binomial Coefficients : ";
	for(int i = 0; i <= Number; i++) {
		cout << Pascal(Number + 1,i + 1) << " ";
	}
	getch();
	return 0;
}

int Pascal(int Row, int Column) {
	int Result = 0;
	if(Column == 1 || Row == Column) {
		Result = 1;
	}
	else {
		Result = Pascal(Row - 1, Column - 1) + Pascal(Row - 1, Column);
	}
	return Result;
}
