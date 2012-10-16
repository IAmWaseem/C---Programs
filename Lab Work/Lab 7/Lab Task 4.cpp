#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int age1,age2;
	cout << "Enter Age of 1st Person : ";
	cin >> age1;
	cout << "Enter Age of 2nd Person : ";
	cin >> age2;
	cout << "Greater Age : " << ((age1>age2)?age1:age2);
	getch();
	return 0;
}