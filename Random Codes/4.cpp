#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int num=1,temp,a,b,c,d;
	cout << "Armstrong numbers between 1 & 500" << endl;
	while(num<=500) {
		a=num%10;
		d=num/10;
		b=d%10;
		c=d/10;
		temp=(a*a*a)+(b*b*b)+(c*c*c);
		if (temp==num) {
			cout << "Armstrong Number : " << temp << endl;
		}
		num++;
	}
	getch();
	return 0;
}