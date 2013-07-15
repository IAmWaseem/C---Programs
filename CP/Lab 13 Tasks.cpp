/*
#include <iostream>
#include <conio.h>

using namespace std;

float sum(float, float, float);

int main() {
	float a,b,c;
	cout << "Enter 1st Value : ";
	cin >> a;
	cout << "Enter 2nd Value : ";
	cin >> b;
	cout << "Enter 3rd Value : ";
	cin >> c;
	cout << "Sum of " << a << " " << b << " " << c << " is " << sum(a,b,c);
	getch();
	return 0;
}

float sum(float x, float y, float z) {
	return x + y + z;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

void Square(int);

int main() {
	int n;
	cout << "Enter Size of Square : ";
	cin >> n;
	Square(n);
	getch();
	return 0;
}

void Square(int n) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout << "* ";
		}
		cout << endl;
	}
	return;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

void Even_Odd(int);

int main() {
	int n;
	cout << "Enter Number : ";
	cin >> n;
	Even_Odd(n);
	getch();
	return 0;
}

void Even_Odd(int n) {
	if(n % 2 == 0) {
		cout << "Number is EVEN";
	}
	else {
		cout << "Number is ODD";
	}
	return;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

void Swap(int &, int &);

int main() {
	int a, b;
	cout << "Enter Value of a : ";
	cin >> a;
	cout << "Enter Value of b : ";
	cin >> b;
	cout << "Value of a Before Swapping : " << a << endl;
	cout << "Value of b before Swapping : " << b << endl;
	Swap(a,b);
	cout << "Value of a After Swapping : " << a << endl;
	cout << "Value of b After Swapping : " << b << endl;
	getch();
	return 0;
}

void Swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

void Time(int = 10,int = 30,int = 50);

int main() {
	int h, m, s;
	cout << "Enter Hour : ";
	cin >> h;
	cout << "Enter Minutes : ";
	cin >> m;
	cout << "Enter Seconds : ";
	cin >> s;
	Time();
	Time(h);
	Time(h,m);
	Time(h,m,s);
	getch();
	return 0;
}

void Time(int h, int m, int s) {
	cout << "The Time is : " << h << ":" << m << ":" << s << endl;
	return;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

void Square();
void Square(char);
void Square(char, int);

int main() {
	int size;
	char ch;
	cout << "Enter Size of Square : ";
	cin >> size;
	cout << "Enter Character : ";
	cin >> ch;
	Square();
	Square(ch);
	Square(ch,size);
	getch();
	return 0;
}

void Square() {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void Square(char ch) {
	for(int i=0;i<6;i++) {
		for(int j=0;j<6;j++) {
			cout << ch;
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void Square(char ch, int size) {
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			cout << ch;
		}
		cout << endl;
	}
	cout << endl;
	return;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int Sum(int[], int);

int main() {
	int size;
	cout << "Enter Size of Array : ";
	cin >> size;
	int *arr;
	arr = new int[size];
	for(int i=0;i<size;i++) {
		cout << "Enter Number : ";
		cin >> arr[i];
	}
	cout << "Sum : " << Sum(arr,size);
	delete arr;
	getch();
	return 0;
}

int Sum(int arr[], int size) {
	int sum = 0;
	for(int i=0;i<size;i++) {
		sum = sum + arr[i];
	}
	return sum;
}
*/

#include <iostream>
#include <conio.h>

using namespace std;

int Sum(int[][5], int);

int main() {
	int arr[5][5];
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			cout << "Enter Value : ";
			cin >> arr[i][j];
		}
	}
	cout << "Sum : " << Sum(arr, 5);
	getch();
	return 0;
}

int Sum(int arr[][5], int size) {
	int sum = 0;
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			sum = sum + arr[i][j];
		}
	}
	return sum;
}