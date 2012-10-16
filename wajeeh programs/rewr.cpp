#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int a, b;

	cout<<"enter the age of first person"<<endl;
	cin>>a;

	cout<<"enter the age of the second person"<<endl;
	cin>>b;

	if(a>b)
	{cout<<"the first person is elder"<<endl;}

	else if(a<b)
	{cout<<"the second person is elder"<<endl;}

	else 
		cout<<"both have the same ages"<<endl;
	_getch();
	return 0;



}