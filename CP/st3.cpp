#include<iostream>

using namespace std;

struct employee
{
	char name[20];
	float salary;
};

int main()
{
	employee *s;
	int size;
	cout<<"Enter size";
	cin>>size;
	s=new employee [size];
	for(int i=0; i<size; i++)
	{
		cout<<"Enter name: ";
		cin>>s[i].name;
		cout<<"Enter salary: ";
		cin>>s[i].salary;
	}
	employee temp;
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(s[j].salary>s[j+1].salary)
			{
				temp = s[j];							// This swaps the whole structure only if their respective salaries
				s[j] = s[j + 1];						// are greater or less according to the type of sort
				s[j + 1] = temp;								
				/*
				temp=s[j].salary;						// This is the main problem
				s[i].salary=s[j+1].salary;				// If you swap salaries, all the employees salaries will be misplaced
				s[j+1].salary=temp;						// because you the location of their names is not sorted
				*/										// so you have to sort the whole structure by the salaries, not just
														// the values of their salaries
			}
		}
	}
	for(int i=0; i<size; i++)
	{
		cout<<"salary: "<<s[i].salary<<endl;
	}
}