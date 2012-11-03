#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int start,end,sumEVEN=0,sumODD=0;
	cout << "Enter Starting Value : ";
	cin >> start;
	cout << "Enter Ending Value : ";
	cin >> end;
	for(;start<=end;start++) {
		if(start%2==0) {
			sumEVEN += start;
		}
		else {
			sumODD += start;
		}
	}
	cout << endl << "Sum of EVEN Values : " << sumEVEN << endl;
	cout << "Sum of ODD Values : " << sumODD << endl;
	getch();
	return 0;
}