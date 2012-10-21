#include <iostream>
#include <conio.h>

using namespace std;

int main ()					// Program to calculate the average of a class 
{
	int students;
	cout << "Enter the number of students: ";
	cin >> students;

	int marks, total, average, counter;
		
	total = 0;			//intialize values of variables before using them
	average = 0;
	counter = 0;
	marks = 0;

	while ( counter < students ) // modified to allow different number of students it depends on the user
		{
			cout << "\nEnter your marks(out of 100): ";
			cin >> marks;
			if (marks > 100)
				{cout << "Wrong marks entered" << endl;
			exit (EXIT_FAILURE);}		//exit command will terminate the program 
			else 

			total = total + marks; 
			counter = counter + 1; // so that the loop can end
		}

	average = total/students;
	cout << "The total number of students in the class are: " << students << endl;
	cout << "The Average marks are: " << average << endl;

	_getch();
	return 0;


}