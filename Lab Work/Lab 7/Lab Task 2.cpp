#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char ch;
	cout << "Enter any Character : ";
	cin >> ch;
	cout << "The ASCII code for Character " << ch << " : " << static_cast<int>(ch) << endl;
	getch();
	return 0;
}