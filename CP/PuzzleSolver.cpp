#include <iostream>
#include <conio.h>

using namespace std;

int Solvable(int start, int squares[], int size,int position);

int main()
{
	int *squares;
	int size=0;

	cout << "Enter the size of the squares: ";
	cin >> size;

	squares=new int [size];

	for (int i=0;i < size ;i++)
	{
		cout << "Enter data in the " << i+1 << " entry" << endl;
		cin >> squares[i];
	}

	cout << "You entered the followng squares" << endl;
	for (int i=0;i < size ;i++)
	{
		cout << " " << squares[i];
	}
	cout << endl;
	if (Solvable(squares[0],squares,size-1,0))
	{
		cout << "Puzzle is solvable " << endl;
	}
	else
	{
		cout << "The puzzle is not solvable " << endl;
	}

	delete[] squares;
	return 0;
}

int Solvable(int start, int squares[], int size,int position)
{
	if ( (position+start) < size && squares[position]==squares[position+start])
	{
		return 0;
	}

	if ((position+start) == size)
	{
		if(squares[position+start]==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}

	if((position+start) < size && (position+start) > size)
	{
		return (Solvable(squares[position],squares,size,position+start)) + (Solvable(squares[position],squares,size,position-start));
	}

	else if ((position+start) < size)
	{
		return Solvable(squares[position],squares,size,position+start);
	}
	else if ((position+start) > size)
	{
		return Solvable(squares[position],squares,size,position-start);
	}
}