#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	/*
	cout << "*******************" << endl;
	cout << " *****************" << endl;
	cout << "  ***************" << endl;
	cout << "   *************" << endl;
	cout << "    ***********" << endl;
	cout << "     *********" << endl;
	cout << "      *******" << endl;
	cout << "       *****" << endl;
	cout << "        ***" << endl;
	cout << "         *" << endl;
	*/
	int n;
	cout << "Enter Height of Diamond : ";
	cin >> n;
	for(int i=0;i<n-1;i++) {
		for(int j=i;j<n-1;j++) {
			cout << " ";
		}
		for(int k=0;k<=i*2;k++) {
			cout << "*";
		}
		cout << endl;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<i;j++) {
			cout << " ";
		}
		for(int k=i*2;k<(n*2)-1;k++) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}

cout << (a<b?"TRUE":"FALSE");