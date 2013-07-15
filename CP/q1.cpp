#include<iostream>
#include<conio.h>
using namespace std;
void functn1();
void function2(int *a,int b);
int main()
{
	int a[8]={1,3,4,65,2,3,43,4};
	functn1();
	function2(a ,8);
	getch();
	return 0;
}
void functn1()
{
	int *array1,size;
	cout<<"enter size of array:";
	cin>>size;
	array1=new int [size];
	cout<<"Enter array:"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>*(array1+i);
	}
	cout<<"ARRAY:"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<*(array1+i)<<endl;
	}

}
void function2(int a[],int b)
{
	int *ptr=a;
	for(int i=0;i<b;i++)
	{
		for(int k=0; k<b-1-k;k++)
		{
			
				if(*ptr >*(ptr+k))
				{
					int b=0;
					int *temp=&b;
					*temp= *ptr;
					*ptr=*(ptr+k);
					*(ptr+k)=*ptr;
				}
		
		}
	}
	cout<<"SORTED:"<<endl;
	for(int i=0;i<b;i++)
	{
		cout<<*(a+i)<<endl;
	}

}