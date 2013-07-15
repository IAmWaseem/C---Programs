#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
struct employee
{
	float salary;
	char name[20];
};
int main()
{
	int n;
	employee *ptr;
	float temp1;
	char temp2[20];
	cout<<"\nHow many records do you want to store: ";
	cin>>n;
	ptr=new employee[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the name of "<<i<<"employee: ";
		cin>>ptr[i].name;
		cout<<"\nEnter the salary of "<<i<<"employee: ";
		cin>>ptr[i].salary;
	}
	
	for(int j=0;j<n;j++)
	{
		for(int k=0;k=n-1;k++)
		{
			if(ptr[k].salary>ptr[k+1].salary)
			{
				temp1=ptr[k].salary;
				ptr[k].salary=ptr[k+1].salary;
				ptr[k+1].salary=temp1;
				/*strcpy(temp2,ptr[k].name);
				strcpy(ptr[k].name,ptr[k+1].name);
				strcpy(ptr[k+1].name,temp2);*/
			}
		}
	}
	for(int m=0;m<n;m++)
	{
		cout<<ptr[m].name<<"'s Salary is: "<<ptr[m].salary<<endl;
	}
	delete [] ptr;

	getch();
	return 0;
}