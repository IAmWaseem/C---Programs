#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n,a,b,c,d,e,f,g,h;
	cout << "Please enter a 5 digit nber: ";
	cin >> n;
	a=n%10;				
	b=n/10;				
	c=b%10;
	d=b/10;
	e=d%10;
	f=d/10;
	g=f%10;
	h=f/10;
	cout << "Displaying Separate Digits" << endl << endl;
	cout << h << endl;
	cout << g << endl;
	cout << e << endl;
	cout << c << endl;
	cout << a;
	getch();
	return 0;
}