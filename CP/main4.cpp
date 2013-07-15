#include <iostream>
#include <conio.h>
using namespace std;

class matrix
{
	int max_x; //columns
	int max_y; //rows
	int **ptr;

public:
	matrix();
	matrix(int,int);
	matrix operator+ (matrix &obj);
	matrix operator- (matrix &obj);
	matrix operator* (matrix &obj);
	//void operator= (matrix &obj);
	matrix(matrix &obj);
	~matrix();
	friend matrix add(const matrix &m1, const matrix &m2);
	void display();
	void input();
};

void main()
{
	matrix p1(2,2),p2(2,2),p3(2,2);
	p1.input();
	p2.input();
	p3=p1+p2;
	p3.display();
	system("pause");
}
matrix::matrix(){
	max_x =0;
	max_y =0;
	ptr = NULL;}
matrix::matrix(int columns, int rows)
{
	max_x = columns;
	max_y = rows;
	ptr = new int *[max_y];
	for (int i=0; i<max_y; i++){
		ptr[i] = new int [max_x];}
	cout << "Memory Alloted successfully. Now enter the data of matrix\n";
	/*for (int i=0; i<max_y;i++) //for input
	{
		for (int j=0; j<max_x;j++){
			cout << "Enter data at row" << i << "column" << j << endl;
			cin  >> ptr[i][j];
			cout << endl;}
	}*/
}
void matrix::input()
{
	for (int i=0; i<max_y;i++) //for input
	{
		for (int j=0; j<max_x;j++){
			cout << "Enter data at row" << i << "column" << j << endl;
			cin  >> ptr[i][j];
			cout << endl;}
	}
}
matrix::~matrix(){
	for (int i =0 ;i< max_y;i++)
		delete ptr[i];
	delete ptr;}
matrix::matrix(matrix &obj)
{
	for (int i=0; i<max_y; i++)
	{
		for (int j=0; j<max_x; j++)
		{
			ptr[i][j] = obj.ptr[i][j];
		}
	}
}
matrix matrix::operator+ (matrix &obj)
{
	matrix sum(2,2);

	if ((max_y == obj.max_y) && (max_x == obj.max_x))
	{
		for (int i=0; i<max_y; i++)
		{
			for (int j=0; j<max_x; j++)
			{
				sum.ptr[i][j] = ptr[i][j] + obj.ptr[i][j];
			}
		}
		return sum;
	}
	else
		cout << "Caution!!!Matrix are not of same order\n\n";
}
matrix matrix::operator- (matrix &obj)
{
	if ((max_y == obj.max_y) && (max_x == obj.max_x))
	{
		matrix diff;
		for (int i=0; i<max_y; i++)
		{
			for (int j=0; j<max_x; j++)
			{
				diff.ptr[i][j] = ptr[i][j] - obj.ptr[i][j];
			}
		}
		return diff;
	}
	else
		cout << "Caution!!!Matrix are not of same order\n\n";
}
void matrix::display()
{
	cout << "******HENCE THE RESULT IS******\n\n";
	for (int i=0; i<max_y;i++)
	{
		cout << endl;
		for (int j=0; j<max_x;j++)
		{
			cout << "\t" << ptr[i][j];
		}
	}
}

/*void matrix::operator= (matrix &obj)
{
	for (int i=0; i<max_y;i++)
	{
		for (int j=0; j<max_x;j++)
		{
			ptr[i][j] = obj.ptr[i][j];
		}
	}
}*/
