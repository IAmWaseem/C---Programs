#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
double circle(double *);
double triangle(double *,double *,double *,double *);
double rectangle(double *, double*);
int main()
{
	double base,radius,height,lenght,width,side1, side2;
	cout<<"Enter radius of circle :";
	cin>>radius;
	cout<<"Enter base of triangle:";
	cin>>base;
	cout<<"Enter side1 value of triangle :";
	cin>>side1;
	cout<<"Enter side2 value of triangle:";
	cin>>side2;
	cout<<"Enter height of triangle :";
	cin>>height;
	cout<<"Enter lenght of rectangle:";
	cin>>lenght;
	cout<<"Enter width of rectangle :";
	cin>>width;
	double *b, *r, *h, *s,*l,*w, *s2;
	b=&base;
	r=&radius;
	h=&height;
	s=&side1;
	s2=&side2;
	l=&lenght;
	w=&width;
	 circle( &radius);
     triangle(&base, &height, &side1, &side2);
     rectangle(&lenght, &width);
	
	getch();
	return 0;
}
double circle(double *r)
{
	double area, P;
	area=3.14*(pow(r,2));
	P=2*3.14*r;
	cout <<"Area of circle="<<area<<endl;
	cout<<"Perimeter of circle="<<P<<endl;
	return 0;
  
}
double triangle(double *b,double *h,double *a,double *c)
{
	double area, P;
	area=0.5*(b*h);
	P=b+a+c;
	cout <<"Area of triangle="<<area<<endl;
	cout<<"Perimeter of triangle="<<P<<endl;
	return 0;
}
double rectangle(double *l, double *w)
{  
	double area, P;
	area=l*w;
	P=(2*l)+(2*w);
	cout <<"Area of circle="<<area<<endl;
	cout<<"Perimeter of circle="<<P<<endl;
	return 0;
}