//sajjal hafeez
//12-0317
#include<iostream>
#include<conio.h>
using namespace std;
#include "complex.h"
complex::complex()
{
	real=0;
	img=0;
}
complex::complex(double r)
{
	real=r;
	img=0;
}
complex::complex(double r,double i)
{
	real=r;
	img=i;
}
complex complex::add(complex c)
{
	complex sum;
	sum.real=c.real + real;
	sum.img=c.img + img;
	return sum;
}
complex complex::subtract(complex c)
{
	complex diff;
	diff.real=c.real-real;
	diff.img=c.img-img;
	return diff;
}
complex complex::multiply(complex c)
{
	complex prod;
	prod.real=((real*c.real)-(img*c.img));
	prod.img=((real*c.real)+(img*c.img));
	return prod;
}
complex complex::division(complex c)
{
	complex quotient;
	quotient.real=((real*c.real)+(c.img*img))/((real*real)+(img*img));
	quotient.img=((real*c.real)-(c.img*img))/((real*real)+(img*img));
	return quotient;
}
void complex::print()
{
	if(img<0)
	{
		cout<<"\nComplex number is: "<<real<<" + "<<img<<"i"<<endl;
	}
	else
	{
		cout<<"\nComplex number is: "<<real<<" "<<img<<"i"<<endl;
	}
}
void complex::setreal(double r)
{
	real=r;
}
void complex::setimg(double i)
{
	img=i;
}
double complex::getreal()
{
	return real;
}
double complex::getimg()
{
	return img;
}
int main()
{
	int option;
	cout<<"Enter the Complex numbers please"<<endl;
	complex num1,num2;
	double r1,i1,r2,i2;
	cout<<"For The First Number"<<endl;
	cout<<"\nEnter the real value: ";
	cin>>r1;
	num1.setreal(r1);
	cout<<"Enter the imaginary value: ";
	cin>>i1;
	num1.setimg(i1);
	cout<<"\nFor The Second Number"<<endl;
	cout<<"\nEnter the real value: ";
	cin>>r2;
	num2.setreal(r2);
	cout<<"Enter the imaginary value: ";
	cin>>i2;
	num2.setimg(i2);
Menu:
	cout<<"\nPress 1 to add the numbers"<<endl<<
		"\nPress 2 to subtract the numbers"<<endl<<
		"\nPress 3 to multiply the numbers"<<endl<<
		"\nPress 4 to divide the numbers"<<endl;
	cin>>option;
	switch(option)
	{
	case 1:
		{
			complex ans;
			ans=num1.add(num2);
			cout<<"\nAfter Addition"<<endl;
			ans.print();
			goto Menu;
		}
	case 2:
		{
			complex ans;
			ans=num1.subtract(num2);
			cout<<"\nAfter Subtraction"<<endl;
			ans.print();
			goto Menu;
		}
	case 3:
		{
			complex ans;
			ans=num1.multiply(num2);
			cout<<"\nAfter Multiplication"<<endl;
			ans.print();
			goto Menu;
		}
	case 4:
		{
			complex ans;
			ans=num1.division(num2);
			cout<<"\nAfter Division"<<endl;
			ans.print();
			goto Menu;
		}
	default:
		{
			cout<<"\nEnter the correct number please"<<endl;
			goto Menu;
		}
	}
	getch();
	return 0;
}
