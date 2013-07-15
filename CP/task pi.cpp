#include <iostream>
#include <conio.h>

using namespace std;

double pi(int);

int main()
{
	int number;

	cout<<"Enter a positive odd number:"<<endl;
	cin>>number;
	cout<<pi(number);

	_getch();
	return 0;

}

