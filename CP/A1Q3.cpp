
#include <iostream>
#include <conio.h>

using namespace std;

void LinearSearch(int*, int);

int main() {
	int Data[10];
	char Choice;
	int Number;
	for(int i = 0; i < 10; i++) {
		cout << "Enter Number : ";
		cin >> Data[i];
	}
	while(1) {
		cout << "Do You Want to Search an Element in the Array?[Y - Yes or N - No] : ";
		cin >> Choice;
		if(Choice == 'N' || Choice == 'n') {
			break;
		}
		else if(Choice == 'Y' || Choice == 'y') {
			cout << "Enter Number to Search : ";
			cin >> Number;
			LinearSearch(Data,Number);
		}
		else {
			cout << "Invalid Choice, Enter Again" << endl << endl;
		}

	}
	getch();
	return 0;
}

void LinearSearch(int* pData, int Number) {
	static int Location = 0;
	static int isFound = 1;
	if(*pData == Number) {
		if(Location == 0) {						// Check for 1st Index
			cout << "Number Found";
		}
		return;
	}
	else if(Location == 10) {
		isFound = 0;
		return;
	}
	Location++;
	LinearSearch(pData + 1, Number);			// Pass Address of Next Value in the Array to the Function
	Location--;
	if(isFound && Location == 0) {
		cout << "Number Found" << endl;
	}
	else if(!isFound && Location == 0) {
		cout << "Number Not Found" << endl;
	}
	return;
}
