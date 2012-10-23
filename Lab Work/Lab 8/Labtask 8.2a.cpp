#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
	float range,transformation;
	int check=1;
	cout << "Enter Floating Point Value : ";
	cin >> range;
	if(range>=2.2&&range<=5.7) {
		transformation=pow(range,2)-3*range-4;
	}
	else if(range>=0.2&&range<=1.9) {
		transformation=pow(range,2)-4*range+5;
	}
	else if(range>=7.43&&range<=10.3) {
		transformation=pow((range+4),2);
	}
	else if(range>=11.0&&range<=13.0) {
		transformation=pow(range,2);
	}
	else {
		cout << "Wrong Value Entered" << endl;
		check=0;
	}
	if(check) {
		cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
	}
	getch();
	return 0;
}