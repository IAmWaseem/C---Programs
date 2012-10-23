#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	float range,transformation;
	int check;
	cout << "Enter Floating Point Value : ";
	cin >> range;
	if(range>=2.2&&range<=5.7) {
		check=1;
	}
	else if(range>=0.2&&range<=1.9) {
		check=2;
	}
	else if(range>=7.43&&range<=10.3) {
		check=3;
	}
	else if(range>=11.0&&range<=13.0) {
		check=4;
	}
	else {
		check=0;
	}
	switch(check) {
		case 1: {
			transformation=pow(range,2)-3*range-4;
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		case 2: {
			transformation=pow(range,2)-4*range+5;
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		case 3: {
			transformation=pow((range+4),2);
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		case 4: {
			transformation=pow(range,2);
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		default: {
			cout << "Wrong Value Entered" << endl;
		}
	}
	getch();
	return 0;
}