#include <iostream>
#include <conio.h>
using namespace std;

struct integer
{
	int key;
	integer *ptr;
}*head_ptr=NULL;

void add();

void main()
{
	do
	{
		
		add();
	}while (1);
	
}

void add()
{
	integer *node=new integer;
	integer *tail=head_ptr;
	integer *pre = head_ptr;
	cout << "Enter Integer : ";
	cin >> node -> key;
	if(head_ptr == NULL) {
		node -> ptr = head_ptr;
		head_ptr = node;
		return;
	}
	while (tail != NULL)
	{
		if (tail->key == node->key)
		{
			cout << "MAtch found\n";
			return;
		}
		pre = tail;
		tail = tail -> ptr;
	}
	node -> ptr = pre -> ptr;
	pre -> ptr = node;
}