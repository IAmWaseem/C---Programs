#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

int main() {
	int Data[10][10];
	srand(time(0));
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			Data[i][j] = 1 + rand() % 9;
		}
	}
	int key, check = 0;
	cout << "Enter Value To Search : ";
	cin >> key;
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			if(key==Data[i][j]) {
				cout << "Value " << key << " Found at : " << "[" << i << "] [" << j << "] Location" << endl;
				check = 1;
			}
			if(!check && i==9 && j==9) {
				cout << "Value Not Found";
			}
		}
	}
	getch();
	return 0;
}