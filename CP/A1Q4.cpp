

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

double CalculatePie(double);

int main() {
	int Number;
	cout << "Enter a Positive ODD Number : ";
	cin >> Number;
	cout << "Value of Pie = " << setprecision(15) << CalculatePie(Number);
	getch();
	return 0;
}

double CalculatePie(double Number) {
	static double Pie = 0;
	if(int(Number) == 0) {
		return 4 * Pie;
	}
	if(int(Number) % 2 == 0) {
		Pie = Pie - 1/(Number + Number - 1);
	}
	else {
		Pie = Pie + 1/(Number + Number - 1);
	}
	return CalculatePie(--Number);
}
