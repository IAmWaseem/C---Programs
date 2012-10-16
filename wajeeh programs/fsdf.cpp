#include <iostream>
#include <conio.h>

using namespace std;

int main()

{

	char a;
	int b;
	cout<<"enter your grade"<<endl;
	cin>>a;

	if(a=='A')
		cout<<"you got 10 marks"<<endl;

	else if(a=='B')
		cout<<"you got 8 marks"<<endl;

	else if(a=='C')
		cout<<"you got 6 marks"<<endl;

	else if(a=='D')
		cout<<"you got 5 marks"<<endl;

	else if(a=='F')
		cout<<"you got 0 marks"<<endl;

	else if(a!='A' && a!='B' && a!='C' && a!='D' && a!='F')
		cout<<"wrong grade entered"<<endl;

	cout<<"to enter any other grade press 1 else press 2"<<endl;
	cin>>a;


	_getch();
	return 0;



}