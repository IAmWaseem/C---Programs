#include<iostream>
#include<conio.h>
using namespace std;
struct student
{
	char name[30];
	int roll_no;
	char sec;
	int cgpa;
	int batch;
	student  *next;
	student *fptr;
};
//student *fptr=NULL;

void viewdata();
void enterdata_at_middle(int key,student *fptr );
void enterdata_at_tail(student *fptr);
void enterdata_at_head(student *fptr);
void deletedata(int key,student *fptr);
void searchdata(int key,student *fptr);
void modifydata(int key,student *fptr);
void exit(student *fptr);
void enterdata_at_head(student *fptr)
{
	student *node;
	node=new student;
	cout<<"Enter roll number?"<<endl;
	cin>>node->roll_no;
	cout<<"Enter name of student?"<<endl;
	fflush(stdin);
	cin.getline(node->name,30,'\n');
	cout<<"Enter section : "<<endl;
	cin>>node->sec;
	cout<<"Enter CGPA :"<<endl;
	cin>>node->cgpa;
	cout<<"Enter batch: "<<endl;
	cin>>node->batch;
	node->next=fptr;
	fptr=node;
	cout<<endl;	
}

void enterdata_at_tail(student *fptr)
{
	student *node, *n;
	node=new student;
	cout<<"Enter roll number?"<<endl;
	cin>>node->roll_no;
	cout<<"Enter name of student?"<<endl;
	fflush(stdin);
	cin.getline(node->name,30,'\n');
	cout<<"Enter section : "<<endl;
	cin>>node->sec;
	cout<<"Enter CGPA :"<<endl;
	cin>>node->cgpa;
	cout<<"Enter batch: "<<endl;
	cin>>node->batch;
	n=fptr;
	while(n->next!=NULL)
	{
		n=n->next;
	}
	n->next=node;
	node->next=NULL;
	cout<<endl;	
}

void enterdata_at_middle(int key,student *fptr)
{
	student *node, *n;
	node=new student;
	
	n=fptr;

	cout<<"Enter roll number?"<<endl;
	cin>>node->roll_no;
	cout<<"Enter name of student?"<<endl;
	fflush(stdin);
	cin.getline(node->name,30,'\n');
	cout<<"Enter section : "<<endl;
	cin>>node->sec;
	cout<<"Enter CGPA :"<<endl;
	cin>>node->cgpa;
	cout<<"Enter batch: "<<endl;
	cin>>node->batch;
	while(n->roll_no!=key)
	{
		n=n->next;
	}
	n->next=node;
	node->next=n->next;
	cout<<endl;	
}
void viewdata(student *fptr)
{
	student *n;
	n=fptr;
	while(n!=NULL)
	{
		cout<<"Roll no. : "<<n->roll_no<<endl;
		cout<<"Name: "<<n->name<<endl;
		cout<<"Sec: "<<n->sec<<endl;
		cout<<"CGPA: "<<n->cgpa<<endl;
		cout<<"Batch:"<<n->batch<<endl;
		cout<<endl;
		n=n->next;
	}

}
void modifydata(int key,student *fptr)
{
	student  *n;
	n=fptr;
	while(n->roll_no!=key)
	{
		n=n->next;
	}
	cout<<"Enter roll number?"<<endl;
	cin>>n->roll_no;
	cout<<"Enter name of student?"<<endl;
	fflush(stdin);
	cin.getline(n->name,30,'\n');
	cout<<"Enter section : "<<endl;
	cin>>n->sec;
	cout<<"Enter CGPA :"<<endl;
	cin>>n->cgpa;
	cout<<"Enter batch: "<<endl;
	cin>>n->batch;
	cout<<endl;
	n=n->next;
}
void searchdata(int key,student *fptr)
{
	student  *n;
	n=fptr;
	while(n->roll_no!=key)
	{
		if(n->next==NULL)
	{
		cout<<"Key not found."<<endl;
	}
		n=n->next;
	}
	cout<<"Roll no. : "<<n->roll_no<<endl;
	cout<<"Name: "<<n->name<<endl;
	cout<<"Sec: "<<n->sec<<endl;
	cout<<"CGPA: "<<n->cgpa<<endl;
	cout<<"Batch:"<<n->batch<<endl;
	cout<<endl;
}
void deletedata(int key,student *fptr)
{
	student *current,*pre;
	current=fptr;
	while(current->roll_no!=key || current->next!=NULL)
	{ 
		if(current->next==NULL)
	{
		cout<<"Key not found."<<endl;
		return;
	}
		pre=current;
		current=current->next;
	}
	
	 if(current==fptr)
	{
		current=current->next;
		delete fptr;
	}
	else 
	{
	pre=current->next;
	delete current;
	}
	
}
void exit(student *fptr)
{
	student *n,*m;
	n=fptr;
	while(n!=NULL)
	{
		m=n;
		n=n->next;
		delete m;
	}
}
int main()
{
	int number;
	student *first=NULL;
	first=first->fptr;
MENU:
	cout<<"Press 1 to enter new student data."<<endl;
	cout<<"Press 2 to view all students data."<<endl;
	cout<<"Press 3 to delete specific data of specific roll number"<<endl;
	cout<<"Press 4 to modify student data."<<endl;
	cout<<"Press 5 to search student data."<<endl;
	cout<<"Press 6 to EXIT program."<<endl;
	cout<<"ENTER NUMBER: ";
	cin>>number;
	switch(number)
	{
	case 1:
		{
			int number1;
menu:
			cout<<"Press 1 to enter student data at head."<<endl;
			cout<<"Press 2 to enter student data at tail."<<endl;
			cout<<"Press 3 to enter student data at middle."<<endl;
			cout<<"Press 4 to goto main MENU: "<<endl;
			cout<<"ENTER NUMBER: ";
			cin>>number1;
			switch(number1)
			{
			case 1:
				{
					enterdata_at_head( first);
				}
				goto menu;
				break;
			case 2:
				{
					enterdata_at_tail(first);
				}
				goto menu;
				break;
			case 3:
				{
					int rollno;
					cout<<"Enter rollno use as key: ";
					cin>>rollno;
					enterdata_at_middle( rollno,first);
				}
				goto menu;
				break;
			case 4:
				break ;
			}
			goto MENU;
			break;
		}
	case 2:
		{
			viewdata(first);
		}
		goto MENU;
		break;
	case 3:
		{
			int rollno;
			cout<<"Enter rollno use as key: ";
			cin>>rollno;
			deletedata(rollno,first);
		}
		goto MENU;
		break;
	case 4:
		{
			int rollno;
			cout<<"Enter rollno use as key: ";
			cin>>rollno;
			modifydata( rollno,first);
		}
		goto MENU;
		break;
	case 5:
		{
			int rollno;
			cout<<"Enter rollno use as key: ";
			cin>>rollno;
			searchdata( rollno,first);
		}
		goto MENU;
		break;
	case 6:
		{
			cout<<"EXIT program";
		    exit(first);
			(EXIT_SUCCESS);
		}
	}
}
