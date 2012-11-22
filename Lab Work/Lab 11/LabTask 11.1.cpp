#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	double arr[10][10] = {0};
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j];
			cout << endl;
		}
	}
	getch();
	return 0;
}