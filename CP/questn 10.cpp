#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
double sin(int);
int factorial(int);

int main() 
{
	int x;
	double y;
	cout << "Enter Value of x : ";
	cin >> x;
	 y= Sin(x);
	cout << "Series: "<<y;
	getch();
}

double Sin(int x)
{
	int i=1;
	double f= 0;
	while(i<20) 
	{
		if(i%2!=0)
			f = f+(pow(x,i) / factorial(i));
		else
			f = f-(pow(x,i) / factorial(i));
		i=i+2;
	}
	return f;
}

 int factorial(int x)
 {
	int z= 1;
	for(int i=1;i<=x;i++) 
	{
		z=z*i;
	}
	return z;
 }