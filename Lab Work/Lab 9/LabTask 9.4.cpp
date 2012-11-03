#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	for(int i=1;i<=10;i++) {
		if(i==10) {
			cout << i << ":00:00" << endl;
			break;
		}
		for(int j=0;j<=59;j++) {
			for(int k=0;k<=59;k++) {
				cout << i << ":" << j << ":" << k;
				Sleep(1000);
				system("cls");
			}
		}
	}
	getch();
	return 0;
}