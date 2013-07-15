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
void exit(number *&fptr);
void addnumber(number *&fptr)
{
	number *node;
	node=new number;
	cout<<"Enter number: ";
	cin>>node->num;
	number *current, *previous;
	current=fptr;
	previous = fptr;
	if(current == NULL) 
	{
		node -> next = fptr;
		fptr = node;
		cout << "Number Added" << endl;
		return;
	}
	while(current!=NULL)
	{
		if(current->num==node->num)
		{
			cout<<"Number already exist ."<<endl;
			return;
		}
		else
		{
			if(current -> num < node -> num) {
				previous = current;
				current = current -> next;
				continue;
			}
			else {
				break;
			}
		}
	}
	node -> next = previous -> next;
	previous -> next = node;
}
void deletenumber(number *&fptr,int num)
{
	number *pre,*current = fptr;
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
void exit(number *&fptr)
{
	number *pre,*current = fptr;
	if(current == NULL) {
		return;
	}
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
	number *fptr=NULL;
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
			addnumber(fptr);
		
		goto MENU;
		break;
		}
	case 2:
		{
			int num;
			cout<<"Enter number you want to delete: ";
			cin>>num;
			deletenumber(fptr,num);
		
		goto MENU;
		break;
		}
	case 3:
		{
			display(fptr);
		goto MENU;
		break;
		}
	case 4:
		{
			exit(fptr);
		break;
		}
	}
	getch();
	return 0;
}