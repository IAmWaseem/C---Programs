#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
struct number
{
	int num;
	number *next;
};
void addnumber(number *&fptr);
void deletenumber(number *&fptr,int num);
void display(number *&fptr);
void exit();
void addnumber(number *&fptr)
{
	number *node;
	node=new number;
	cout<<"Enter number: ";
	cin>>node->num;
	number *current;
	current=fptr;
	if(fptr == NULL) 
	{
		node -> next = fptr;
		fptr = node ;
		return;
	}
	while(current->next!=NULL)
	{
		if(current->num==node->num)
		{
			cout<<"Number already exist ."<<endl;
			return;
		}
		else if (current->num>node->num)
		{
			node->next=current->next;
			current=node;
		}
	}
}
void deletenumber(number *&fptr,int num)
{
	number *pre,*current;
	while(current->num!=num)
	{
		pre=current;
		current=current->next;
	}
	pre=current;
	pre=pre->next;
	delete current;
}
void display(number *&fptr)
{
	number *current;
	current=fptr;
	cout<<"Numbers are : ";
	while(current!=NULL)
	{
		cout<<current->num<<setw(6);
		current=current->next;
	}
}
void exit()
{
	number *pre,*current;
	while(current->num!=NULL)
	{
		pre=current;
		current=current->next;
		delete pre;
	}
}
int main()
{
	int choice;
MENU:
	cout<<"Press 1 to add number. "<<endl;
	cout<<"Press 2 to delete specific item ."<<endl;
	cout<<"Press 3 display numbers. "<<endl;
	cout<<"Press 4 to EXIT program."<<endl;
	cout<<endl;
	cout<<"Enter choice:";
	cin>>choice;
	switch(choice)
	{
	case 1:
		{
			number *fptr=NULL;
			addnumber(*&fptr);
		}
		goto MENU;
		break;
	case 2:
		{
			int num;
			cout<<"Enter number you want to delete: ";
			cin>>num;
			number *fptr=NULL;
			deletenumber(fptr,num);
		}
		goto MENU;
		break;
	case 3:
		{
			number *fptr=NULL;
			display(fptr);
		}
		goto MENU;
		break;
	case 4:
		{
			exit();
		}
		break;
	}
	getch();
	return 0;
}