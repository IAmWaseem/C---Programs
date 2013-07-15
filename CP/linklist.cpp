#include<iostream>
using namespace std;

struct linklist
{
	linklist *next;
	char subject[20];
	int marks;
	int roll_no;
} *first=NULL;


void add_head(char sub[], int val2, int val3);
void add_tail(char sub[], int val2, int val3);
void add_middle(char sub[], int val2, int val3,int key);
void search(int roll_no);
void add_delete(int key);
void display_val();

int main()
{
	int mark,cmd,roll_no,choice2,key;
	char choice,sub[20];

	while(1)
	{
MAIN:

		cout<<"Press '1' to enter student's record\n";
		cout<<"Press '2' to search student by roll number\n";
		cout<<"Press '3' to display all record\n";
		cout<<"Press '4' to exit\n";
		cin>>cmd;

		switch(cmd)
		{
		case 1:
			{
				cout<<"Press '1' to add data at the start\n"
					<<"Press '2' to add data at the end\n"
					<<"Press '3' to add data at the middle\n";
				cin>>choice2;

				switch(choice2)
				{
				case 1:
					{
						cout<<"Enter subject: ";
						fflush(stdin);
						cin.getline(sub,20,'\n');
						cout<<"Enter marks: ";
						cin>>mark;
						cout<<"Enter roll number: ";
						cin>>roll_no;
						add_head(sub,mark,roll_no);
						break;
					}
				case 2:
					{
						cout<<"Enter subject: ";
						fflush(stdin);
						cin.getline(sub,20,'\n');
						cout<<"Enter marks: ";
						cin>>mark;
						cout<<"Enter roll number: ";
						cin>>roll_no;
						add_tail(sub,mark,roll_no);
						break;
					}
				case 3:
					{
						cout<<"Enter subject: ";
						fflush(stdin);
						cin.getline(sub,20,'\n');
						cout<<"Enter marks: ";
						cin>>mark;
						cout<<"Enter roll number: ";
						cin>>roll_no;
						cout<<"Enter roll number of the student after which you want to enter new data : ";
						cin>>key;
						add_middle(sub,mark,roll_no,key);
						break;
					}
				default:
					{
						cout<<"Invalid input\n";
						break;
					}
				}
				break;

			}

		case 2:
			{
				cout<<"Enter roll_number to search data: ";
				cin>>roll_no;
				search(roll_no);
				break;
			}

		case 3:
			{
				display_val();
				break;
			}

		case 4:
			{
				int n;
				add_delete(n);
				break;
			}
		default:
			{
				cout<<"Invalid input\n";
				break;
			}
		}
		cout<<"Do you want to search again? <y/n> ";
		cin>>choice;
		if(choice=='y')
		{
			goto MAIN;
		}
		else
		{
			break;
		}
	}


	return 0;
}


void add_head(char sub[], int val2, int val3)
{
	linklist *node;
	node=new linklist;
	strcpy(node->subject,sub);
	node->marks=val2;
	node->roll_no=val3;
	node->next=first;
	first=node;
}


void display_val()
{
	linklist *n;
	n = first;
	while(n!= NULL)
	{
		cout << "Subject : " << n->subject << endl;
		cout << "Marks : " << n->marks<<endl;
		cout << "roll_no: "<< n->roll_no <<endl;
		n = n->next;
	}
}

void add_tail(char sub[], int val2, int val3)
{
	linklist *node,*n;
	node=new linklist;
	strcpy(node->subject,sub);
	node->marks=val2;
	node->roll_no=val3;
	node->next=NULL;
	n=first;
	while(n->next!=NULL)
	{
		n=n->next;
	}
	n->next=node;
}

void add_middle(char sub[], int val2, int val3,int key)
{
	linklist *node,*n;
	node=new linklist;
	strcpy(node->subject,sub);
	node->marks=val2;
	node->roll_no=val3;
	n=first;
	while(n->roll_no!=key)
	{
		n=n->next;
		node->next=n;
		n->next=node;
	}
}

void search (int roll_no)
{
	linklist *current;
	current=first;
	while(current!=NULL)
	{
		if(current->roll_no==roll_no)
		{
			cout << "Subject : " << current->subject << endl;
			cout << "Marks : " << current->marks<<endl;
			cout << "roll_no: "<< current->roll_no <<endl;
		}
		current=current->next;
		//first=current;
	}
}

void add_delete(int key)
{

	cout<<"Enter roll number after which u want to delete the data: ";
	cin>>key;
	linklist *ptrCurrent=first,*ptrPrevious;

	while (ptrCurrent!=NULL && ptrCurrent->roll_no!=key)
	{
		ptrPrevious = ptrCurrent;
		ptrCurrent = ptrCurrent->next;
	}

	if (ptrCurrent == NULL)
	{
		cout<<"\nElement to delete not found in the list";
		return;
	}

	if (ptrCurrent == first) //node to delete is first node
		first = first->next;
	else //node to delete is in middle or at end of list
		ptrPrevious->next = ptrCurrent->next;

	delete ptrCurrent;
}