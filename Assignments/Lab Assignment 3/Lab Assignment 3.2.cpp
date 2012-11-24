#include <iostream>
#include <conio.h>

using namespace std;

float SumAndAverage(int, int, int, int, int);

int main() {
	int num1, num2, num3, num4, num5;
	cout << "Enter 1st Number : ";
	cin >> num1;
	cout << "Enter 2nd Number : ";
	cin >> num2;
	cout << "Enter 3rd Number : ";
	cin >> num3;
	cout << "Enter 4th Number : ";
	cin >> num4;
	cout << "Enter 5th Number : ";
	cin >> num5;
	int Sum = static_cast<int>(SumAndAverage(num1,num2,num3,num4,num5));
	float Average = SumAndAverage(num1,num2,num3,num4,num5);
	cout << "Sum of Numbers : " << Sum << endl << endl;
	cout << "Average of Numbers : " << Average << endl;
	getch();
	return 0;
}

float SumAndAverage(int num1, int num2, int num3, int num4, int num5) {
	int Sum = num1 + num2 + num3 + num4 + num5;
	static int check = 0;
	if(!check) {
		check = 1;
		return Sum;
	}
	else {
		return static_cast<float>(Sum)/5;
	}
}