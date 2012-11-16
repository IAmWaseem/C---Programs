/*
#include <iostream>

using namespace std;

int main() {
	int x,y;
	cout << "Enter 1st Value in Integer : ";
	cin >> x;
	cout << "Enter 2nd Value in Integer : ";
	cin >> y;
	cout << endl << "Addition : " << x+y << endl << "Subtraction : " << x-y << endl << "Multiplication : " << x*y << endl;
	system("pause");
	return 0;

}
*/

/*
#include <iostream>

using namespace std;

int main() {
	float x,y,z;
	cout << "Enter 1st value in Float : ";
	cin >> x;
	cout << "Enter 2nd value in Float : ";
	cin >> y;
	cout << "Enter 3rd value in Float : ";
	cin >> z;
	cout << endl << "Distributive Law of Multiplication" << endl;
	cout << "L.H.S = " << x*(y+z) << endl;
	cout << "R.H.S = " << x*y+x*z << endl;
	cout << "-------" << endl;
	cout << "Associative Law of Addition" << endl;
	cout << "L.H.S = " << (x+y)+z << endl;
	cout << "R.H.S = " << x+(y+z) << endl;
	system("pause");
	return 0;
}
*/


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

/*
#include <iostream>
#define PI 3.14

using namespace std;

int main() {
	float r,h,vol,area;
	cout << "Enter Radius of Cylinder : ";
	cin >> r;
	cout << "Enter Height of Cylinder : ";
	cin >> h;
	vol = PI*r*r*h;
	area = 2*PI*r*h + 2*PI*r*r;
	cout << "Volume of Cylinder : " << vol << endl;
	cout << "Surface Area of Cylinder : " << area << endl;
	system("pause");
	return 0;
}*/