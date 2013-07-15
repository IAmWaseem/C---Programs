#include<iostream>
#include<conio.h>
using namespace std;
int draw_asterisks(int);
int main()
{
	int x=9;
	draw_asterisks(x);
	getch();
	return 0;
}
int draw_asterisks(int x)
{
	for(int i=0;i<5;i++)
	{ 
		for(int j=x;j>0;j=j-2)
		{ 
			cout<<"*";
		}
		cout<<endl;
	}
	
	return 0;
}