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