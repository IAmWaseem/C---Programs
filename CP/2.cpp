#include <iostream>
using namespace std;

int binomial (int);

int main ()
{
	int pow;

	cout<< "Enter the power of the binomial: ";
	cin>> pow;

	for (int i=0;i<n;i++)
	{
		binomial(pow,array);
	}

	return 0;
}

int binomial (int n)
{
	if (n==0)
		return 1;

	cout<< n + binomial(n-1);
}


