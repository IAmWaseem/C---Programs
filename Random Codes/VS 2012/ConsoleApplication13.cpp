/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	const int size = 10;
	int Data[size];
	int max = size-1,min = 0;
	int key;
	for(int i=0;i<size;i++) {
		cout << "Enter Number : ";
		cin >> Data[i];
	}
	for(int i=0;i<size;i++) {
		for(int j=0;j<size-i-1;j++) {
			int temp;
			if(Data[j]>Data[j+1]) {
				temp = Data[j];
				Data[j] = Data[j+1];
				Data[j+1] = temp;
			}
		}
	}
	cout << "Enter Number to Search : ";
	cin >> key;
	while(min<=max) {
		int mid = (max+min)/2;
		if(Data[mid] == key) {
			cout << "Value found on Key " << mid << endl;
			break;
		}
		else {
			if(key<Data[mid]) {
				max = mid-1;
			}
			else {
				min = mid+1;
			}
		}
	}
	getch();
	return 0;
}
*/

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
     system("COLOR C");
     std::cout << "I'm a different color!\n";
	 Sleep(2000);
     system("COLOR A");
     std::cout << "And I'm another color as well.\n";
     system("PAUSE");

	getch();
	return 0;
}