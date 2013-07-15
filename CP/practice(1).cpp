#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int **string1;
	int **string2;
	int **array3;
	int row=3,coloumn=3;
	string1=new int *[row];
	string2=new int *[row];
	array3=new int *[row];
	for(int i=0;i<row;i++)
	{
		string1[i]=new int [coloumn];
	}
	for(int i=0;i<row;i++)
	{
		string2[i]=new int [coloumn];
	}
	for(int i=0;i<row;i++)
	{
		array3[i]=new int [coloumn];
	}
	cout<<"ENTER first array:"<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			cin>>string1[i][j];
		}
		cout<<endl;
	}
	cout<<"ENTER second array:"<<endl;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			cin>>string2[i][j];
		}
		cout<<endl;
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			array3[i][j]=(string1[i][j]+string2[i][j]);
		}
	}
	cout<<"Addition of matrixes"<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			cout<<array3[i][j]<<endl;
		}
		cout<< endl;
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			array3[i][j]=(string1[i][j]-string2[i][j]);
		}
	}
	cout<<"Subtraction of matrixes"<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			cout<<array3[i][j]<<endl;
		}
		cout<< endl;
	}

	getch();
	return 0;
}