#include <iostream>
#include <conio.h>

using namespace std;

int main()

{
	int a, b;
	cout<<"ENTER YOUR MARKS"<<endl;
	cin>>a;

	if(a==10)
	{cout<<"grade is A"<<endl;}


	if(a>=8 && a<10)
	cout<<"your grade is B"<<endl;


	if(a>=6 && a<8)
	cout<<"your grade is C"<<endl;


	if(a>=5 && a<6)
	cout<<"your grade is D"<<endl;


	if(a>=0 && a<5)
	cout<<"your grade is F"<<endl;

	if(a>10 || a<0) 
	cout<<"WRONG MARKS ENTERED"<<endl;


	_getch();
	return 0;

}
