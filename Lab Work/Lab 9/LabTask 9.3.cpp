#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n,i=1,fact=1;
	AGAIN:
	cout << "Enter Number : ";
	cin >> n;
	if(n<0) {
		cout << "Wrong Value Entered" << endl;
		goto AGAIN;
	}
	else if(n>=1) {
		while(i<=n) {
			fact *= i;
			i++;
		}
		cout << "Factorial of " << n << " is : " << fact << endl;
	}
	else {
		cout << "Factorial of 0 is : 1" << endl;
	}
	getch();
	return 0;
}