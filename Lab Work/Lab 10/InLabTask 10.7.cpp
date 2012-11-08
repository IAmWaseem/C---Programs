#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int max=0,arr[5],sum=0;
	for(int i=0;i<5;i++) {
		cout << "Enter Integer Value : ";
		cin >> arr[i];
	}
	int min=arr[0];
	for(int i=0;i<5;i++) {
		sum=sum+arr[i];
		if(arr[i]>max) {
			max = arr[i];
		}
		if(arr[i]<min) {
			min = arr[i];
		}
	}
	cout << "Average of Numbers : " <<sum/5 << endl;
	cout << "Maximum Value : " << max << endl;
	cout << "Minimum Value : " << min << endl;
	getch();
	return 0;
}