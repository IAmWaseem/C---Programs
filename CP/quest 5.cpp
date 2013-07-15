
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int factorial1(int);
int factorial2(int);
int factorial3(int ,int);
void binomial(int ,int);
int main()
{
	int n,m;
	cout<<"Enter first value:";
	cin>>n;
	cout<<"Enter second value:";
	cin>>m;
	binomial(n,m);
	getch();
	return 0;
}
int factorial1(int n)
{
	int x=1;
	while(n>0)
	{
		x=x*n;
		n--;
	}
	return x;
}
int factorial2(int m)
{
	
	int y=1;
	while(m>0)
	{
		y=y*m;
		m--;
	}
	return y;
}
int factorial3(int n ,int m)
{
	int v=0;
	v=n-m;
	int w=1;
	while(v>0)
	{
		w=w*v;
		v--;
	}
	return w;
}
void binomial(int n, int m)
{  
	factorial1(n);
	factorial2( m);
	factorial3(n , m);
	int b,x,y,w;
	b=(x)/(y*w);
	cout <<"Binomial coefficent is "<<b;
}