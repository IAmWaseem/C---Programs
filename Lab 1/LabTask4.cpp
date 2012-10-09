#include <iostream>

using namespace std;

int main() {
	int n;
	float temp,res;
	cout << "What do you want to do?" << endl;
	cout << "[1] Convert Fahrenheit to Celsius" << endl;
	cout << "[2] Convert Celsius to Fahrenheit" << endl;
	cout << "[3] Exit" << endl;
	cout << "Enter Choice[1-3]: ";
	cin >> n;
	switch(n) {
		case 1: {
			cout << "Enter Temperature in Fahrenheit : ";
			cin >> temp;
			res = (temp-32)*5/9;
			cout << "The Temperature in Celsius is " << res << endl;
			break;
		}
		case 2: {
			cout << "Enter Temperature in Celsius : ";
			cin >> temp;
			res = temp*9/5+32;
			cout << "The Temperature in Fahrenheit is " << res << endl;
			break;
		}
		case 3: {
			cout << "Exiting" << endl;
			break;
		}
		default: {
			cout << "Invalid Choice" << endl;
		}
	}
	system("pause");
	return 0;
}