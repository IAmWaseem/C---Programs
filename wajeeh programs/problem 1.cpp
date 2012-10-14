#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
	MAIN:
	float y, x, b;

	cout<<"****PROGRAM FOR CALCULATING THE SLOPE****"<<endl;
	
	cout<<"equation for slope is\n y=mx + b"<<endl;
	cout<<"enter the value of y: "<<endl;
	cin>>y;

	cout<<"enter the value of x: "<<endl;
	cin>>x;

	cout<<"enter the value of b: "<<endl;
	cin>>b;
	if (x==0)
	{
		cout<<"slope is undefined"<<endl;
	}
	else 
	{
		cout<<"the slope is equal to: "<<(y-b)/x<<endl;
	}

	cout<<"To calculate the another slope press 1 to exit press 2"<<endl;
	cin>>x;
	if (x==1)
		goto MAIN;


	_getch();
	


}