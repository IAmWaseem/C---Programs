#include<iostream>
#include<conio.h>
using namespace std;
struct store
{
	int id;
	char name[30];
	int quantity;
	store *next;
};
store *first=NULL;
void additem_at_head();
void additem_at_middle(int key);
void additem_at_tail();
void sell(int id,int quantity);
void print();
void searchdata(char * key);
void modifydata(int key);
void deletedata(int key);
void exit();
void additem_at_head()
{
	store *node;
	node= new store;
	cout<<"Enter id: ";
	cin>>node->id;
	cout<<"Enter name: ";
	fflush(stdin);
	cin.getline(node->name,30,'\n');
	cout<<"Enter quantity: ";
	cin>>node->quantity;
	cout<<endl;
	node->next=first;
	first=node;
}
void additem_at_middle(int key)
{
	store *node,*current;
	node= new store;
	cout<<"Enter id: ";
	cin>>node->id;
	cout<<"Enter name: ";
	fflush(stdin);
	cin.getline(node->name,30,'\n');
	cout<<"Enter quantity: ";
	cin>>node->quantity;
	cout<<endl;
	current=first;
	while(current->id!=key)
	{
		current=current->next;
	}
	current->next=node;
	node->next=current->next;
	cout<<endl;
}
void additem_at_tail()
{
	store *node,*current;
	node= new store;
	cout<<"Enter id: ";
	cin>>node->id;
	cout<<"Enter name: ";
	fflush(stdin);
	cin.getline(node->name,30,'\n');
	cout<<"Enter quantity: ";
	cin>>node->quantity;
	cout<<endl;
	current=first;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=node;
	node->next=NULL;
}
void sell(int id,int quantity)
{
	store *current,*pre;
	current=first;
	while(current->id!=id)
	{
		pre=current;
		current=current->next;
	}
		pre=current;
	if(current->quantity>=quantity)
		{
			cout<<"Avaliable quantity : "<<current->quantity<<endl;
			cout<< quantity<< " item sold ."<<endl;
			current->quantity=current->quantity-quantity;
			if(current->quantity==0)
			{
				pre->next=current->next;
				delete current;
				
			}
		} 
	else if(current->quantity<quantity)
	{
		cout<<" Item not available."<<endl;
	}
}
void print()
{
	store *current;
	current=first;
	while(current!=NULL)
	{
		cout<<"Id: "<<current->id<<endl;
		cout<<"Name: "<<current->name<<endl;
		cout<<"Quantity: "<<current->quantity<<endl;
		current=current->next;
	}
}
void modifydata(int key)
{
	store  *n;
	n=first;
	while(n->id!=key)
	{
		n=n->next;
	}
	cout<<"Enter id?"<<endl;
	cin>>n->id;
	cout<<"Enter name :"<<endl;
	fflush(stdin);
	cin.getline(n->name,30,'\n');
	cout<<"Enter quantity: "<<endl;
	cin>>n->quantity;
	cout<<endl;
	n=n->next;
}
void searchdata(char * key)
{
	store  *n;
	n=first;
	while(n->name!=key)
	{
		if(n->next==NULL)
	{
		cout<<"Key not found."<<endl;
	}
		n=n->next;
	}
	cout<<"Id : "<<n->id<<endl;
	cout<<"Name: "<<n->name<<endl;
	cout<<"quantity: "<<n->quantity<<endl;
	cout<<endl;
}
void deletedata(int key)
{
	store *current,*pre;
	current=first;
	while(current->id!=key || current->next!=NULL)
	{ 
		if(current->next==NULL)
	{
		cout<<"Key not found."<<endl;
	}
		pre=current;
		current=current->next;
	}
	
	 if(current==first)
	{
		current=current->next;
		delete first;
	}
	else 
	{
	pre=current->next;
	delete current;
	}
	
}
void exit()
{
	store *n,*m;
	n=first;
	while(n!=NULL)
	{
		m=n;
		n=n->next;
		delete m;
	}
}
	
int main ()
{
	int number;
MENU:
	cout<<"Press 1 to add item. "<<endl;
	cout<<"Press 2 to buy an item. "<<endl;
	cout<<"Press 3 view items. "<<endl;
	cout<<"Press 4 to delete specific item ."<<endl;
	cout<<"Press 5 to modify item."<<endl;
	cout<<"Press 6 to search item."<<endl;
	cout<<"Press 7 to EXIT program."<<endl;
	cout<<endl;
	cout<<"Enter choice:";
	cin>>number;
	switch(number)
	{
	case 1:
		{
			int num;
menu:

			cout<<"Press 1 to add item at head. "<<endl;
			cout<<"Press 2 to add item at any position. "<<endl;
			cout<<"Press 3 to add item at tail. "<<endl;
			cout<<"Press 4 to go to main menu.";
			cout<<endl;
			cout<<"Enter choice:";
			cin>>num;
			switch(num)
			{
			case 1:
				{
					additem_at_head();
					goto menu;
				break;
				}
				
			case 2:
				{
					int id;
					cout<<"Enter id as key to add item: ";
					cin>>id;
					additem_at_middle(id);
				}
				goto menu;
				break;
			case 3:
				{
					additem_at_tail();
					goto menu;
				break;
				}
			case 4:
				break;
			}
		}
		goto MENU;
		break;
	case 2:
		{
			int id,quantity;
			cout<<"Enter id of item: ";
			cin>>id;
			cout<<"Enter quantity of item: ";
			cin>>quantity;
			cout<<endl;
			sell( id, quantity);
		}
		goto MENU;
		break;
	case 3:
		{
			print();
		}
		goto MENU;
		break;
		case 4:
		{
			int id;
			cout<<"Enter id use as key: ";
			cin>>id;
			deletedata(id);
		}
		goto MENU;
		break;
	case 5:
		{
			int id;
			cout<<"Enter id use as key: ";
			cin>>id;
			modifydata( id);
		}
		goto MENU;
		break;
	case 6:
		{
			char name[30];
			cout<<"Enter rollno use as key: ";
			fflush(stdin);
			cin.getline(name,30,'\n');
			searchdata( name);
		}
		goto MENU;
		break;
	case 7:
		{
			cout<<"EXIT program";
		    exit();
			(EXIT_SUCCESS);
		}
	}
	getch();
	return 0;
}
