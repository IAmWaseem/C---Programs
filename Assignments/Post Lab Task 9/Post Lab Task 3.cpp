#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n;
	cout << "Enter the Length of Pyramid : ";
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			cout << " ";
		}
		for(int j=0;j<=i*2;j++) {
			cout << "*";
		}
		cout << endl;
	}
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<=i;j++) {
			cout << " ";
		}
		for(int j=(n-1)*2;j>(i*2)+1;j--) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}