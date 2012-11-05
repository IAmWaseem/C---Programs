#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int x;
	cout << "Enter the number of lines you want: ";
	cin >> x;
	
	for(int a=0;a<x;a++)
    {
		for(int b=a+1;b<x;b++)
        {
			cout << " ";
		}
		for(int b=0;b<=a*2;b++)
        {
			cout << "*";
		}
		cout << endl;
	}
    for(int a=0;a<x-1;a++)
        {
        for(int b=0;b<=a;b++)
        {
			cout << " ";
		}
		for(int b=(x-1)*2;b>(a*2)+1;b--) {
			cout << "*";
		}
		cout << endl;
	}
	
	_getch();
	return 0;
}
