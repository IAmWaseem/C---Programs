#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int arr[5][5];
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			cout << "Enter Value to Store in Row : " << i+1 << " Column : " << j+1 << " : ";
			cin >> arr[i][j];
		}
	}
	int min = arr[0][0], max = arr[0][0];
	int indeximin,indexjmin,indeximax,indexjmax;
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			if(arr[i][j]>max) {
				max = arr[i][j];
				indeximax = i;
				indexjmax = j;
			}
			if(arr[i][j]<min) {
				min = arr[i][j];
				indeximin = i;
				indexjmin = j;
			}
		}
	}
	cout << "Maximum Value is : " << max << " Located at Index : " << indeximax << " " << indexjmax << endl;
	cout << "Minimum Value is : " << min << " Located at Index : " << indeximin << " " << indexjmin << endl;
	getch();
	return 0;
}