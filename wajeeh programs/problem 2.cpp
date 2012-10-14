#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
	float u, v;
	cout<<"****PROBLEM NO 2****"<<endl;

	cout<<"Enter the first angle: ";
	cin>>u;

	cout<<"enter the second angle: ";
	cin>>v;

	
	//C++ Compiler uses angles in radians by default
	//1st equation
	cout<<"\n1st Equation --> Left Hand Side is: "<<pow(sin(u),2)<<" Right Hand Side is: "<<(1-cos(2*u))/2<<endl;

	//2nd equation
	cout<<"\n2nd Equation --> Left Hand Side is: "<<pow(cos(u),2)<<" Right Hand Side is: "<<(1+cos(2*u))/2<<endl;

	//3rd equation
	cout<<"\n3rd Equation --> Left Hand Side is: "<<pow(tan(u),2)<<" Right Hand Side is: "<<(1-cos(2*u))/(1+cos(2*u))<<endl;

	//4th equation
	cout<<"\n4th Equation --> Left Hand Side is: "<<sin(u) + sin(v)<<" Right Hand Side is: "<<2*sin((u+v)/2)*cos((u-v)/2)<<endl;

	//5th equation
	cout<<"\n5th Equation --> Left Hand Side is: "<<sin(u) - sin(v)<<" Right Hand Side is: "<<2*cos((u+v)/2)*sin((u-v)/2)<<endl;

	//6th equation
	cout<<"\n6th Equation --> Left Hand Side is: "<<cos(u) + cos(v)<<" Right Hand Side is: "<<2*cos((u+v)/2)*cos((u-v)/2)<<endl;

	//7th equation
	cout<<"\n7th Equation --> Left Hand Side is: "<<cos(u) - cos(v)<<" Right Hand Side is: "<<-2*sin((u+v)/2)*sin((u-v)/2)<<endl;

	//8th equation
	cout<<"\n8th Equation --> Left Hand Side is: "<<sin(u)*sin(v)<<" Right Hand Side is: "<<(cos(u-v) - cos(u+v))/2<<endl;
	//don't use ((1/2)*the whole equation) it gives a problem

	//9th Equation
	cout<<"\n9th Equation --> Left Hand Side is: "<<cos(u)*cos(v)<<" Right Hand Side is: "<<(cos(u-v) + cos(u+v))/2<<endl;

	//10th Equation
	cout<<"\n10th Equation --> Left Hand Side is: "<<sin(u)*cos(v)<<" Right Hand Side is: "<<(sin(u+v) + sin(u-v))/2<<endl;

	


	return 0;
	_getch();

}