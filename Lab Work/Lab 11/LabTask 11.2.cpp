#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int data[5][5];
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			cout << "Enter Value to Store in Row : " << i+1 << " Column : " << j+1 << " : ";
			cin >> data[i][j];
		}
	}
	cout << endl << endl << "Values Stored in the Array" << endl << endl;
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
	getch();
	return 0;
}