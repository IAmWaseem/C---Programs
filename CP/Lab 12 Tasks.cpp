#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void MinMax(int[][5], int);

int main() {
	int a[5][5];
	srand(time(0));
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			a[i][j] = rand();
		}
	}
	MinMax(a,5);
	getch();
	return 0;
}

void MinMax(int a[][5], int size) {
	int min = a[0][0];
	int max = a[0][0];
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			cout << a[i][j] << endl;
		}
	}
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			if(min>a[i][j]) {
				min = a[i][j];
			}
			if(max<a[i][j]) {
				max = a[i][j];
			}
		}
	}
	cout << "Max Value : " << max << endl << endl;
	cout << "Min Value : " << min << endl << endl;

}