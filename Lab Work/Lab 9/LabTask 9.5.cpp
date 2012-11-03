#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	int i=1,j=1,k=1;
	while(i<=10) {
		if(i==10) {
			cout << i << ":00:00" << endl;
			break;
		}
		while(j<=60) {
			while(k<=60) {
				cout << "Hour : " << i << " Minute : " << j << " Second : " << k << endl;
				Sleep(1000);
				k++;
			}
			j++;
		}
		i++;
	}
	getch();
	return 0;
}