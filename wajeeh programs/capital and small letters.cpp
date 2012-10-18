#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	char a;
	int b;
	
	cout<<"enter the any character"<<endl;
	cin>>a;


	if ( int(a)>=97 && int(a)<=122)
	{b=int(a)-32;  
	cout<<"in small: "<<a<<endl;
	cout<<"in capital: "<<char(b)<<endl;
	}

	else if (int(a)>=65 && int(a)<=90)
	{b=int(a)+32;
	  cout<<"in capital: "<<a<<endl;
	  cout<<"in small: "<<char(b)<<endl;
	}

	else 
	{cout<<"wrong value has been entered"<<endl;}

	

	_getch();

	return 0;
	



}