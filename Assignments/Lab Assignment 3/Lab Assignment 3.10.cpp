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