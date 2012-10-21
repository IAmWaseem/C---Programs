#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n;
	cout << "Enter the lines to be printed: ";
	cin >> n;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<(n*2)-1;j++) {
			if(j<(n-i)||j>(n+i)-2) {
				cout << " ";
			}
			else {
				cout << "*";
			}	
		}
		cout << endl;
	}
	getch();
	return 0;
}