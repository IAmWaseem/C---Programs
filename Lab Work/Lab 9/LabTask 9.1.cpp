#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	float n;
	cout << "Enter any Value : ";
	cin >> n;
	while(n>0) {
		cout << n << endl;
		n-=0.5;
	}
	getch();
	return 0;
}