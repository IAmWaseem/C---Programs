#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

struct store
{
	int id;
	int quantity;
	char name[50];

	store *nptr;


};


store *fptr=NULL;

void addatstart()
{
	store *node=new store;

	cout<<"Enter ID of Item : ";
	cin>>node->id;
	cin.ignore();

	cout<<"Enter Name of that Item : ";
	cin.getline(node->name,50,'\n');

	cout<<"Enter the quantity of Item : ";
	cin>>node->quantity;
	cout<<endl;

	node->nptr=fptr;

	fptr=node;


}

void addanyplace(int id)
{
	store *n; //temp pointer for checking...

	store *node=new store;

	cout<<"Enter ID of Item: ";
	cin>>node->id;
	cin.ignore();

	cout<<"Enter Name of that Item : ";
	cin.getline(node->name,50,'\n');

	cout<<"Enter the quantity of Item : ";
	cin>>node->quantity;
	cout<<endl;

	n=fptr;


	while(n->id!=id)
	{

		n=n->nptr;

	}
	node->nptr=n->nptr;
	n->nptr=node;

}

void sell(int id,int qty)
{
	store *n,*p;//temp pointer to check .

	n=fptr;

	while((n->id!=id) || n!=NULL)
	{
		p=n;
		n=n->nptr;
	}


	if(n->id!=id)
	{
		cout<<"ID doesn't exist";
	}

	else
	{		
		if(n->quantity!=0)
		{
			n->quantity=n->quantity-qty;

			if(n->quantity==0)
			{
				p->nptr=n->nptr;
				delete n;
			}

			else if(n->quantity<0)
			{
				n->quantity=n->quantity+qty;
				cout<<"Quanity insufficent"<<endl;

			}

		}

		else
		{	p->nptr=n->nptr;
		delete n;
		}



	}


}

void del(int id)
{

	store *n,*p;

	n=fptr;


	while((n->id!=id) || (n!=NULL))
	{
		p=n;
		n=n->nptr;
	}

	if(n->id!=id)
	{

		cout<<"ID doesn't Exist ";

	}

	else if(fptr==n)
	{
		fptr=n->nptr;
		delete n;

	}
	else 
	{
		p->nptr=n->nptr;
		delete n;
	}


}



void modify(int id)
{
	store *n;

	n=fptr;

	while((n->id!=id) || (n!=NULL))
	{
		n=n->nptr;

	}

	if(n->id!=id)
	{
		cout<<"ID Doesn't Exist";

	}

	else
	{

		cout<<"Enter New Id for Item ";
		cin>>n->id;
		cin.ignore();

		cout<<"Enter New Name for Item : ";
		cin.getline(n->name,50,'\n');

		cout<<"Enter Quantity of Item : ";
		cin>>n->quantity;

	}



}

void find(int id)

{

	store *n;

	n=fptr;

	while((n->id!=id) || (n!=NULL))
	{
		n=n->nptr;

	}

	if(n==NULL)
	{
		cout<<"ID doesn't Exist"<<endl;

	}


	else
	{
		cout<<"ID : "<<n->id<<endl;
		cout<<"Name : "<<n->name<<endl;
		cout<<"Quantity : "<<n->quantity<<endl;
	}


}



void main()
{

	int inmenu,id1,id2,id3,id4,id5,qty;

	while(1)
	{
		cout<<"\t\t*****Welcome to my menu******"<<endl<<endl;
		cout<<"Press 1 to Enter new item in Store list at Start"<<endl;
		cout<<"Press 2 to Enter new item in Store anywhere"<<endl;
		cout<<"Press 3 to Sell an Item "<<endl;
		cout<<"Press 4 to Delete an Item from Store List"<<endl;
		cout<<"Press 5 to Modify any of the details of the Item"<<endl;
		cout<<"Press 6 to Find an Item"<<endl;
		cout<<"Press 7 to Print all Item details"<<endl;
		cout<<"Press 8 to Exit"<<endl<<endl;


		cout<<"Your Choice : ";
		cin>>inmenu;

		switch(inmenu)
		{

		case 1:
			{
				system("cls");
				addatstart();
				break;

			}

		case 2:
			{
				system("cls");
				cout<<"Enter the ID after which you want to add ITEM : ";
				cin>>id1;
				addanyplace(id1);
				break;

			}

		case 3:
			{
				system("cls");
				cout<<"Enter Id of Item which Needs to be Sold : ";
				cin>>id2;
				cout<<"Enter Quantity Value : ";
				cin>>qty;
				sell(id2,qty);
				break;


			}

		case 4:
			{
				system("cls");
				cout<<"Enter the Id of Item which u want to delete from Store list : ";
				cin>>id3;
				cout<<endl;



				del(id3);
				break;

			}

		case 5:
			{
				system("cls");
				cout<<"Enter the ID of Item whose data u want to Modify : ";
				cin>>id4;
				cout<<endl;

				modify(id4);
				break;


			}

		case 6:
			{
				system("cls");
				cout<<"Enter the ID which u want to find";
				cin>>id5;
				cout<<endl;

				find(id5);
				break;



			}

		case 8:
			{
				system("cls");
				cout<<"Thanks For Using my prog."<<endl;
				cout<<"\t\t***** THE END *****";
				getch();
				break;



			}


		}

		if(inmenu==8)
		{
			break;

		}


	}
}

