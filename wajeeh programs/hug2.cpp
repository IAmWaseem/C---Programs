#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int a;
		float temp;
	MAIN:
	cout<<"To convert from fahrenheit to celsius press 1"<<endl;
	cout<<"To convert from celsius to fahrenheit press 2"<<endl;
	cout<<"TO exit press 3"<<endl;
	cin>>a;
	if(a==1 || a==2)
	{
		cout << "Enter Temperature : ";
		cin >> temp;
	}

	switch(a)
	{
	case 1:
		{
			cout<<"the temperature is: "<<(temp-32)*5/9<<endl;
			break;
		}

	case 2:
		{
			cout<<"the temperature is: "<<temp*9/5+32<<endl;
			break;

		
		}
	case 3:
		{
			cout<<"EXITING THE PROGRAM"<<endl;
			break;
		
		}

	default:
		{
			cout<<"BITCH PICK FROM 1-3"<<endl;
			goto MAIN;
		
		
		}
	

	}

	getch;
	return 0;

}