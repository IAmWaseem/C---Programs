#include <iostream>
#include <conio.h>

using namespace std;

#define SIZE 10

void BinarySearch(int*, int*, int*, int);

int main() {
	int Data[SIZE];
	int Number, temp;
	char isSorted;
	for(int i = 0; i < SIZE; i++) {
		cout << "Enter Number : ";
		cin >> Data[i];
	}
	Sorting:
	cout << "The Data you Entered is Sorted or Not? [Y = Yes, N = No] : ";
	cin >> isSorted;
	if(isSorted == 'N' || isSorted == 'n') {
		for(int i = 0; i < SIZE; i++) {
			for(int j = 0; j < SIZE - i - 1; j++) {
				if(Data[j + 1] < Data[j]) {
					temp = Data[j];
					Data[j] = Data[j + 1];
					Data[j + 1] = temp;
				}
			}
		}
	}
	else if(isSorted == 'Y' || isSorted == 'y') {
		cout << "Skipping Sorting" << endl;
	}
	else {
		cout << "Invalid Choice, Enter Again";
		goto Sorting;
	}
	cout << "Enter Number to Search : ";
	cin >> Number;
	BinarySearch(Data,&Data[0],&Data[SIZE - 1], Number);
	getch();
	return 0;
}

void BinarySearch(int* Data, int* pStart, int* pEnd, int Number) {
	static int *pMiddle = &Data[int(SIZE / 2)];
	if(Number == *pMiddle) {
		cout << "Number Found";
		return;
	}
	else if(pStart > pEnd) {
		cout << "Number Not Found";
		return;
	}
	pMiddle = &Data[pEnd - pStart];
	if(Number < *pMiddle) {
		pEnd = pMiddle - 1;
	}
	else {
		pStart = pMiddle + 1;
	}
	BinarySearch(Data,pStart,pEnd,Number);
}