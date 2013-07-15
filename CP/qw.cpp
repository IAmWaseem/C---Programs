#include <iostream>

using namespace std;

int** dynamic(int , int);
int main()
{
		
	int rows1, columns1;

	cout << "Enter the number of rows for first matrix: ";
	cin >> rows1;

	cout << "Enter the nubmer of columns for the first matrix: ";
	cin >> columns1;
	int** p1=dynamic(rows1,columns1);


	int rows2, columns2;
	cout << "Enter the number of rows for the second matrix: ";
	cin >> rows2;

	cout << "Enter the number of columns for the second matrix: ";
	cin >> columns2;
	int **p2=dynamic(rows2,columns2);

	char op;
	cout << "Press + to add" << endl;
	cout << "Press - to subtract" << endl;
	cin >> op;



	for(int i=0; i < rows1; i++)
		{
			for(int j=0; j < columns1; j++)
				{
					if(op=='+')
					{
						p1[i][j]=p1[i][j] + p2[i][j];
					}
					else if(op=='-')
					{
						p1[i][j]=p1[i][j] - p2[i][j];
					}
				}
		}

	cout << "The result is" << endl;

	for(i=0; i < rows1; i++)
		{
			for(int j=0; j < columns1; j++)
				{
					cout << p1[i][j] << "   ";
				}
			cout << endl;
		}




	


		for(int k=0; k < rows1; k++)
			{
				delete []p1[k];
			}
		delete[] p1;

			for( k=0; k < rows2; k++)
			{
				delete []p2[k];
			}
		delete[] p2;

		return 0;

}

int** dynamic(int rows , int columns)
{
		int** p;					// here u use to ** because p will point towards to adresses one to the number of rows of pointers who's name will be p
					//and second that each starting index of row will point towards the number of columns so ur making two 1d arrays and linking them to form 2d

		p=new int *[rows];

	for(int i=0; i < rows; i++)
		{
			p[i]= new int[columns];
		}

	for( i=0; i < rows; i++)
		{
			for(int j=0; j < columns ; j++)
				{
					p[i][j]=0;
				}
		}

	for( i=0; i < rows; i++)
		{
			cout << "Enter the elements in the " << i << " row" << endl;
			for(int j=0; j < columns; j++)
				{
					cin >> p[i][j];
				}
		}
	
		for( i=0; i < rows; i++)
		{
			for(int j=0; j < columns ; j++)
				{
					cout << p[i][j] << "  ";
				}
			cout << endl;
		}
	return p;

}





















