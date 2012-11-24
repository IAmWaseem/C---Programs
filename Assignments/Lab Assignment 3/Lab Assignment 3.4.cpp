#include <iostream>
#include <conio.h>

using namespace std;

bool PrimeCheck(int);
void PrimeFactors(int);

int main() {
	int n;
	cout << "Enter Number : ";
	cin >> n;
	cout << endl << "Prime Factors : ";
	PrimeFactors(n);
	getch();
	return 0;
}

void PrimeFactors(int n) {
	for(int i=2;i<=n;i++) {
		if(n%i==0) {
			n = n / i;
			if(PrimeCheck(i)) {
				cout << i << " ";
			}
		}
	}
}

bool PrimeCheck(int n) {
	int check = 1;
	for(int i=2;i<=n;i++) {
		if(n%i==0 && i!=n) {
			check = 0;
			return false;
		}
	}
	if(check) {
		return true;
	}
}