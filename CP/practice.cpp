
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;int main()
{  
	int m;
	int response[21]={1,2,3,5,2,6,2,3,4,5,7,1,2,3,5,7,8,4,5,6,7};
	m=mean(response,21);
	cout<<"mean is "<<m;
	getch();
	return 0;
}
int mean(const int a[] ,int b)
{
	int counter;
    int total=0,m;
	for(int i=0; i<b;i++)
	{
		
		total=total+a[i];
		counter++;
	}
	m=total/counter;
	return m;
}