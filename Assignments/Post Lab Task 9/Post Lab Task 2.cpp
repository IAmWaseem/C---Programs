#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	for(int i=0;i<4;i++) {
		for(int j=i+1;j<4;j++) {
			cout << " ";
		}
		for(int j=0;j<=i*2;j++) {
			cout << "*";
		}
		cout << endl;
	}
	for(int i=0;i<3;i++) {
		for(int j=0;j<=i;j++) {
			cout << " ";
		}
		for(int j=6;j>(i*2)+1;j--) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}