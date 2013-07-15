/*
#include <iostream>
#include <conio.h>

using namespace std;

float Product(int, float);

int main() {
	int num1;
	float num2;
	int Result;
	cout << "Enter Integer Number : ";
	cin >> num1;
	cout << "Enter Floating Number : ";
	cin >> num2;
	Result = Product(num1,num2);
	cout << endl << "The Product of " << num1 << " and " << num2 << " is " << Result << endl;

	getch();
	return 0;
}

float Product(int x, float y) {
	return x*y;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

float SumAndAverage(int, int, int, int, int);

int main() {
	int num1, num2, num3, num4, num5;
	cout << "Enter 1st Number : ";
	cin >> num1;
	cout << "Enter 2nd Number : ";
	cin >> num2;
	cout << "Enter 3rd Number : ";
	cin >> num3;
	cout << "Enter 4th Number : ";
	cin >> num4;
	cout << "Enter 5th Number : ";
	cin >> num5;
	int Sum = static_cast<int>(SumAndAverage(num1,num2,num3,num4,num5));
	float Average = SumAndAverage(num1,num2,num3,num4,num5);
	cout << "Sum of Numbers : " << Sum << endl << endl;
	cout << "Average of Numbers : " << Average << endl;
	getch();
	return 0;
}

float SumAndAverage(int num1, int num2, int num3, int num4, int num5) {
	int Sum = num1 + num2 + num3 + num4 + num5;
	static int check = 0;
	if(!check) {
		check = 1;
		return Sum;
	}
	else {
		return static_cast<float>(Sum)/5;
	}
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int sum(int);

int main() {
	int num;
	cout << "Enter a 5-Digit Number : ";
	cin >> num;
	int Sum;
	Sum = sum(num);
	cout << "Sum of Digits : " << Sum;
	getch();
	return 0;
}

int sum(int n) {
	int sum = 0;
	while(n!=0) {
		sum = sum + n % 10;
		n = n / 10;
	}
	return sum;
}
*/

/*
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
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

long int Factorial(int);
double BinomialCoefficient(int, int);

int main() {
	int N, K;
	cout << "Enter Value of N : ";
	cin >> N;
	cout << "Enter Value of K : ";
	cin >> K;
	double Result;
	Result = BinomialCoefficient(N,K);
	cout << "Result of Binomial Coefficient : " << Result;
	getch();
	return 0;
}

double BinomialCoefficient(int N, int K) {
	return static_cast<double>(Factorial(N)) / (Factorial(K) * Factorial(N - K));
}

long int Factorial(int N) {
	long int fact = 1;
	for(int i=1;i<=N;i++) {
		fact = fact * i;
	}
	return fact;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int MyPower(int, int);
long int Factorial(int);

int main() {
	int n, b, e;
	cout << "Enter Number : ";
	cin >> n;
	cout << "Factorial is : " << Factorial(n) << endl;
	cout << "Enter Base : ";
	cin >> b;
	cout << "Enter Exponent : ";
	cin >> e;
	cout << "Result of MyPower Function : " << MyPower(b,e);
	getch();
	return 0;
}

int MyPower(int b, int e) {
	int Result = 1;
	for(int i=0;i<e;i++) {
		Result = Result * b;
	}
	return Result;
}

long Factorial(int n) {
	long int fact = 1;
	for(int i=1;i<=n;i++) {
		fact = fact * i;
	}
	return fact;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

void Circulate(int &, int &, int &);

int main() {
	int x, y, z;
	cout << "Enter x : ";
	cin >> x;
	cout << "Enter y : ";
	cin >> y;
	cout << "Enter z : ";
	cin >> z;
	cout << endl << "Values Before Circulation" << endl << endl;
	cout << "x = " << x << endl << "y = " << y << endl << "z = " << z << endl;
	Circulate(x,y,z);
	cout << endl << "Values After Circulation" << endl << endl;
	cout << "x = " << x << endl << "y = " << y << endl << "z = " << z << endl;
	getch();

	return 0;
}

void Circulate(int &a, int &b, int &c) {
	int temp1, temp2;
	temp1 = c;
	c = b;
	temp2 = a;
	a = temp1;
	b = temp2;
	return;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

void DecimalToBinary(int);

int main() {
	int num;
	cout << "Enter a Decimal Integer : ";
	cin >> num;
	DecimalToBinary(num);
	getch();
	return 0;
}

void DecimalToBinary(int n) {
	int test[100], count=0;
	while(n!=0) {
		test[count] = n%2;
		n = n / 2;
		count++;
	}
	cout << "Binary Equivalent : ";
	for(int i=count-1;i>=0;i--) {
		cout << test[i];
	}
	return;
}
*/

/*
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
*/

#include <iostream>
#include <conio.h>

using namespace std;

double Sin(int);
long int Factorial(int);

int main() {
	int x;
	double sum;
	cout << "Enter Value of x : ";
	cin >> x;
	sum = Sin(x);
	cout << "Sum of Series : " << sum;
	getch();
}

double Sin(int x) {
	int i=1;
	double sum = 0;
	while(i<30) {
		if(i%2!=0)
			sum = sum + (pow(x,i) / Factorial(i));
		else
			sum = sum - (pow(x,i) / Factorial(i));
		i++;
	}
	return sum;
}

long int Factorial(int N) {
	long int fact = 1;
	for(int i=1;i<=N;i++) {
		fact = fact * i;
	}
	return fact;
}