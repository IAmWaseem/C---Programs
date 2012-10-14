#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main()
{
	cout<<"****MODIFIED CALCULATOR****"<<endl;

	int a, b;
	char op;

	cout<<"enter the expression"<<endl;
	cin>>a>>op>>b;

	//for addition
	if(op=='+')
		cout<<a<<op<<b<<" = "<<a+b<<endl;

	//for subtraction
	else if(op=='-')
		cout<<a<<op<<b<<" = "<<a-b<<endl;

	//for multiplication
	else if(op=='*')
		cout<<a<<op<<b<<" = "<<a*b<<endl;

	//for division
	else if(op=='/')
		{if(b==0)
			cout<<"math error any number divided by zero is equal to infinity"<<endl;
		else
			cout<<a<<op<<b<<" = "<<a/b<<endl;}


	return 0;

		_getch();
}