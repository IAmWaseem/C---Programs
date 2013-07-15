// Danish Muhammad Arif				i12-0235
//Problem 2

#include<iostream>
#include<conio.h>

using namespace std;

struct entry
{
	char Name[50];
	int Telephone;
	int Cellphone;
	char Email[50];
	char Hadress[50];
	char Oadress[50];
	entry *next;
	
};

void Add(int);
void Find();
void print(void);
void Del();
void Delall();

entry *Head=NULL;

int main()
{
	int choice;
	
	cout<<"Enter Choice"
		<<"1. Add Entry\n"
		<<"2. Find Entry\n"
		<<"3. Display All\n"
		<<"4. Delete Entry\n"
		<<"5. Delete All\n"
		<<"0. Exit\n\n";
	
	cin>>choice;
/*	
	do
	{
		switch(choice)
		{
		case 1:
			{
				Add();
				break;
			}
			
		case 2:
			{
				Find();
				break;
			}
			
		case 3:
			{
				Print();
				break;
			}
			
		case 4:
			{
				Del();
				break;
			}
			
		case 5:
			{
				Delall();
				break;
			}
		}
	}
	while(inp!=0);
*/
	getch();
}


void Add();
{
	entry *point;
	point = new entry;

	cout<<"Name : ";
	cout<<"Telephone : ";
	cout<<"Cell Phone : ";
	cout<<"Email : ";
	cout<<"Home Address : ";
	cout<<"Office Adress : ";
}
