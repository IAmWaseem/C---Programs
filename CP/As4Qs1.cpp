#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>
using namespace std;

class sparse_vector
{
	int *matrix;
	static int index;
	struct node
	{
		int value;
		node *next;
	}*head_ptr;
	node *obj;
	int size1;
public:
	sparse_vector();
	void add_node(int *);
	void display();
	sparse_vector(const int size);
	sparse_vector(const sparse_vector &sv);
	//~sparse_vector();
	int getsize()const;
	int get_element(int col=0)const
	{
		for (col = 0; col < size1; col++)
			return col;
	}
	void set_element(int col, int value);
	friend ostream& operator<< (ostream&, sparse_vector&);
	void operator= (const sparse_vector&);
	void operator+= (const sparse_vector&);
	void operator-= (const sparse_vector&);
	sparse_vector operator+ (const sparse_vector&)const;
	sparse_vector operator- (const sparse_vector&)const;
	bool operator== (const sparse_vector&)const;
	bool operator!= (const sparse_vector&)const;
	sparse_vector operator* (const sparse_vector&);
};
//Defining & initializing the static member
int sparse_vector::index=0;

void main()
{
	
	int size = 3;
	sparse_vector obj(size);
	sparse_vector obj1(size);
	obj1=obj;
	cout << obj1 << endl;
	system("pause");
}



sparse_vector::sparse_vector()
{
	matrix = NULL;
	head_ptr=NULL;
}
sparse_vector::sparse_vector(int size) //taking size from main
{
	size1=size;
	if (size > pow(2,31)-1){
		cout << "Too large size\n";
		return;}
	else
	{
		head_ptr=NULL;
		matrix = new int [size];
		for (int i=0; i<size; i++)
		{
			cout << "Enter data at index" << i+1 << endl;
			cin  >> matrix[i];
			cout << endl;
		}
		for (int j=0; j<size; j++)
		{
			if (matrix[j]== 0)
				continue;
			else
			{
				add_node(matrix+j);
			}

		}

	}
}
sparse_vector::sparse_vector(const sparse_vector &sv)
{
	
}
void sparse_vector::operator= (const sparse_vector &sv)
{
	obj = head_ptr;
	while ((obj->next != NULL)&& (sv.head_ptr->next != NULL))
	{
		obj->value = sv.get_element();
	}
}

void sparse_vector::add_node(int *ptr)
{
		node *new_node = new node;
		if (head_ptr == NULL){
			++index;
			new_node->value = *ptr;
			new_node->next = head_ptr;
			head_ptr = new_node;
			cout << "ADDED SUCCESSFULLY AT INDEX: " << index << endl;}
		else
		{
			node *current_ptr = head_ptr;
			new_node->value = *ptr;
			++index;
			while (current_ptr->next != NULL)
				current_ptr = current_ptr->next;
			current_ptr->next = new_node;
			new_node->next = NULL;
			cout << "ADDED Successfully at INdex: " << index << endl;
		}
		
}
void sparse_vector::display()
{
	obj->next= head_ptr;
	while (obj->next !=NULL)
	{
		cout << setw(2) << obj->value;
		obj=obj->next;
	}
}
ostream& operator << (ostream& out, sparse_vector& display)
{
	while (display.obj->next != NULL)
		out << display.obj;
	return out;
}