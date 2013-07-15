/*
#include <iostream>
#include <conio.h>

using namespace std;

void Draw_Asterisks();

int main() {
Draw_Asterisks();
getch();
return 0;
}

void Draw_Asterisks() {
for(int i=0;i<5;i++) {
for(int j=9;j>i*2;j--) {
cout << "*";
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

int PerfectNumbers(int);

int main() {
	int n, sum;
	cout << "Enter Number : ";
	cin >> n;
	sum = PerfectNumbers(n);
	if(sum==n) {
		cout << "Number " << n << " is a Perfect Number";
	}
	else {
		cout << "Number " << n << " is not a Perfect Number";
	}
	cout << endl << endl << "Perfect Numbers Between 1 and 1000" << endl << endl;
	for(int i=1;i<=1000;i++) {
		sum = PerfectNumbers(i);
		if(sum==i) {
			cout << i << endl;
		}
	}
	getch();
	return 0;
}

int PerfectNumbers(int n) {
	int sum = 0, i = 1;
	while(n!=1) {
		if(n%i==0) {
			sum = sum + i;
			n = n / i;
		}
		i++;
	}
	return sum;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

bool Prime(int);

int main() {
	int n;
	cout << "Enter Number : ";
	cin >> n;
	if(Prime(n)) {
		cout << "Number is Prime";
	}
	else {
		cout << "Number is Not Prime";
	}
	cout << endl << endl << "Listing Prime Numbers Between 2 and 20" << endl << endl;
	for(int i=2;i<20;i++) {
		if(Prime(i)) {
			cout << i << endl;
		}
	}
	getch();
	return 0;
}

bool Prime(int n) {
	for(int i=2;i<=sqrt(n);i++) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int MaximumCheck(int, int, int);

int main() {
	int a, b, c, max;
	cout << "Enter 1st Number : ";
	cin >> a;
	cout << "Enter 2nd Number : ";
	cin >> b;
	cout << "Enter 3rd Number : ";
	cin >> c;
	max = MaximumCheck(a,b,c);
	cout << "Maximum Number : " << max;
	getch();
	return 0;
}

int MaximumCheck(int a, int b, int c) {
	if(a>b && a>c)
		return a;
	else if(b>a && b>c)
		return b;
	else if(c>a && c>b)
		return c;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int GCD(int, int);

int main() {
	int m, n, gcd;
	cout << "Enter 1st Number : ";
	cin >> m;
	cout << "Enter 2nd Number : ";
	cin >> n;
	gcd = GCD(m,n);
	cout << "GCD is : " << gcd;
	getch();
	return 0;
}

int GCD(int m, int n) {
	int i = 2;
	int gcd = 1;
	int check1, check2, great = m;
	if(m<n) {
		great = m;
	}
	for(int j=0;j<great;j++) {
		check1 = 0;
		check2 = 0;
		if(m%i==0) {
			m = m / i;
			check1 = 1;
		}
		if(n%i==0) {
			m = n / i;		
			check2 = 1;
		}
		if(check1 && check2) {
			gcd = gcd * i;
		}
	}
	return gcd;
}
*/

/*
#include <iostream>
#include <conio.h>

int QualityPoints(int);

using namespace std;

int main() {
	int AverageMarks;
	cout << "Enter Average Marks : ";
	cin >> AverageMarks;
	cout << "Quality Points : " << QualityPoints(AverageMarks);
	getch();
	return 0;
}

int QualityPoints(int AverageMarks) {
	if(AverageMarks>=90 && AverageMarks<=100)
		return 4;
	else if(AverageMarks>=70 && AverageMarks<90)
		return 3;
	else if(AverageMarks>=50 && AverageMarks<70)
		return 2;
	else if(AverageMarks>=40 && AverageMarks<50)
		return 1;
	else if(AverageMarks<40)
		return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

char Grade(int);

using namespace std;

int main() {
	int AverageMarks;
	cout << "Enter Average Marks : ";
	cin >> AverageMarks;
	cout << "Grade : " << Grade(AverageMarks);
	getch();
	return 0;
}

char Grade(int AverageMarks) {
	if(AverageMarks>=90 && AverageMarks<=100)
		return 'A';
	else if(AverageMarks>=70 && AverageMarks<90)
		return 'B';
	else if(AverageMarks>=50 && AverageMarks<70)
		return 'C';
	else if(AverageMarks>=40 && AverageMarks<50)
		return 'D';
	else if(AverageMarks<40)
		return 'F';
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

long int Factorial(int);

int main() {
	int n;
	cout << "Enter Number : ";
	cin >> n;
	int fact = Factorial(n);
	cout << "Factorial of " << n << " is " << fact;
	getch();
	return 0;
}

long int Factorial(int n) {
	int fact = 1;
	for(int i=2;i<=n;i++) {
		fact = fact * i;
	}
	return fact;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

float KG(float);

int main() {
	float pounds;
	cout << "Enter Weight in Pounds : ";
	cin >> pounds;
	cout << "Weight in KG is : " << KG(pounds);
	getch();
	return 0;
}

float KG(float pounds) {
	return pounds * 0.453;
}
*/

/*
#include <iostream>
#include <conio.h>

#define PIE 3.14

using namespace std;

float Circle_Area(float);

int main() {
	float r;
	cout << "Enter Radius of Circle : ";
	cin >> r;
	cout << "Area of Circle : " << Circle_Area(r);
	getch();
	return 0;
}

float Circle_Area(float r) {
	return PIE * r * r;
}
*/

#include <iostream>
#include <conio.h>

using namespace std;

float Power(float,int);

int main() {
	float base;
	int exponent;
	cout << "Enter Base : ";
	cin >> base;
	cout << "Enter Exponent : ";
	cin >> exponent;
	cout << "Power : " << Power(base,exponent);
	getch();
	return 0;
}

float Power(float base, int exponent) {
	float result = 1;
	for(int i=1;i<=exponent;i++) {
		result = result * base;
	}
	return result;
}