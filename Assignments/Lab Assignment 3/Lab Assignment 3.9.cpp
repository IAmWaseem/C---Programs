#include <iostream>
#include <conio.h>

using namespace std;

void DisplayFibonacci();

int main() {
	cout << "First 25 Fibonacci Numbers : " << endl;
	DisplayFibonacci();
	getch();
	return 0;
}

void DisplayFibonacci() {
	int next = 1;
	int prev = 0;
	int temp;
	for(int i=1;i<=25;i++) {
		temp = next;
		next = next + prev;
		if(i!=1)
			prev = temp;
		cout << next << endl;
	}
	return;
}