#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int perfect(int );
int main()
{
	int x,sum=0;
	cout<<"Enter number:";
	cin>>x;
	sum=perfect(x);
	if(sum==x)
	{
		cout <<"NUMBER is PERFECT"<<endl;
	}
	else
		cout <<"NUMBER is not PERFECT"<<endl;

	getch();
	return 0;
}
int perfect(int a)
{
	int sum=0;
	for(int i=1;i<a;i++)
	{ 
			if(a%i==0)
		{
			a=a/i;
			cout<<i<<" ";
			sum+=i;
			i=1;
		}
	}
	/*if(sum==a)
	{
		cout <<"NUMBER is PERFECT"<<endl;
	}
	else
		cout <<"NUMBER is not PERFECT"<<endl;*/
	return sum;
}