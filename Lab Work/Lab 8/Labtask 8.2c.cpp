#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main() {
	float range,transformation;
	int check;
	char ch=' ';
	cout << "Enter Floating Point Value : ";
	cin >> range;
	transformation = ((range<=5.7&&range>=2.2)?pow(range,2)-3*range-4:(range<=1.9&&range>=0.2)?pow(range,2)-4*range+5:(range<=10.3&&range>=7.43)?pow((range+4),2):(range<=13.0&&range>=11.0)?pow(range,2):-500);
	cout << (((range<=5.7&&range>=2.2)||(range<=1.9&&range>=0.2)||(range<=10.3&&range>=7.43)||(range<=13.0&&range>=11.0))?"Result of Transformation Value : ":"Invalid Value Entered");
	cout << ((transformation!=-500)?transformation:ch);
	getch();
	return 0;
}