#include <iostream>
#include <conio.h>

using namespace std;

class fraction 
{
	int denominator, numerator;

public:
	fraction();
	fraction(int a, int b);
	int getnumerator(int);
	int getdenominator(int);
	void operator+(fraction);

};

fraction::fraction()
{
	numerator=0;
	denominator=0;
}

fraction::fraction(int a, int b)
{
	numerator = a;
	denominator = b;
}

int fraction::getnumerator(int a)
{
	return numerator;
}

int fraction::getdenominator(int a)
{
	return denominator;
}

void fraction::operator+(fraction n1)
{
	numerator= numerator + n1.numerator;
	cout<<"numerator:"<<numerator;
}

int main()
{
    fraction p1(2,4),p2(4,65);
	p1.operator+(p2);
	_getch();
	return 0;
}
