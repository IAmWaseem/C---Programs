#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	double salary, al_hrent,al_med,al_conv;
	cout << "Enter Salary of the Employee : ";
	cin >> salary;
	al_hrent = (20*salary)/100;
	al_med = (10*salary)/100;
	al_conv = (10*salary)/100;
	cout << "House Rent Allowance : " << al_hrent << endl;
	cout << "Medical Allowance : " << al_med << endl;
	cout << "Conveyence Allowance : " << al_conv << endl;
	_getch();
	return 0;
}