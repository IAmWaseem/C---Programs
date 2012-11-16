/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	float n;
	cout << "Enter any Value : ";
	cin >> n;
	while(n>0) {
		cout << n << endl;
		n-=0.5;
	}
	getch();
	return 0;
}
*/

/*
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
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n,i=1,fact=1;
	AGAIN:
	cout << "Enter Number : ";
	cin >> n;
	if(n<0) {
		cout << "Wrong Value Entered" << endl;
		goto AGAIN;
	}
	else if(n>=1) {
		while(i<=n) {
			fact *= i;
			i++;
		}
		cout << "Factorial of " << n << " is : " << fact << endl;
	}
	else {
		cout << "Factorial of 0 is : 1" << endl;
	}
	getch();
	return 0;
}
*/

/*
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
*/

/*
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main() {
	int i=1,j=1,k=1;
	while(i<=10) {
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
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n;
	cout << "Enter the Length of Pyramid : ";
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			cout << " ";
		}
		for(int j=0;j<=i*2;j++) {
			cout << "*";
		}
		cout << endl;
	}
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<=i;j++) {
			cout << " ";
		}
		for(int j=(n-1)*2;j>(i*2)+1;j--) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}
*/