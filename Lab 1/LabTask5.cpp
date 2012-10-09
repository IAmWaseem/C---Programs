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
}