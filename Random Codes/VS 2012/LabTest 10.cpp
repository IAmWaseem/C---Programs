#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int arr1[6] = {1,9,2,8,6,5}, arr2[6] = {5,10,7,6,3,5};
	int temp;
	cout << "arr1\tarr2" << endl;
	for(int i=0;i<6;i++) {
		cout << arr1[i] << "\t" << arr2[i] << endl;
	}
	for(int i=0;i<6;i++) {
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	cout << "Values of Array after swapping" << endl;
	cout << "arr1\tarr2" << endl;
	for(int i=0;i<6;i++) {
		cout << arr1[i] << "\t" << arr2[i] << endl;
	}
	getch();
	return 0;
}