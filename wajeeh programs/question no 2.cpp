#include <iostream>
#include <conio.h>

using namespace std;

int main ()

{

	cout << "*****ASSIGNMENT 5.2*****" << endl;

	char grade1, grade2, grade3, grade4, grade5;

	cout << "Enter first person's grade" << endl;
	cin >> grade1;
	cout << "Enter second person's grade" << endl;
	cin >> grade2;
	cout << "Enter third person's grade" << endl;
	cin >> grade3;
	cout << "Enter fourth person's grade" << endl;
	cin >> grade4;
	cout << "Enter fifth person's grade" << endl;
	cin >> grade5;

	cout << ( grade1 == 'A' ? "First person get's 10 Marks" : (grade1 == 'B' ? "First person gets 8 marks": (grade1 == 'C' ? "First person gets 6 marks" : (grade1 == 'D' ? "First preson gets 5 marks" : "wrong value entered" ) ))) << endl;
	cout << ( grade2 == 'A' ? "Second person get's 10 Marks" : (grade2 == 'B' ? "Second person gets 8 marks": (grade2 == 'C' ? "Second person gets 6 marks" : (grade2 == 'D' ? "Second preson gets 5 marks" : "wrong value entered" ) ))) << endl;
	cout << ( grade3 == 'A' ? "third person get's 10 Marks" : (grade3 == 'B' ? "third person gets 8 marks": (grade3 == 'C' ? "third person gets 6 marks" : (grade3 == 'D' ? "third preson gets 5 marks" : "wrong value entered" ) ))) << endl;
	cout << ( grade4 == 'A' ? "Fourth person get's 10 Marks" : (grade4 == 'B' ? "fourth person gets 8 marks": (grade4 == 'C' ? "fourth person gets 6 marks" : (grade4 == 'D' ? "fourth preson gets 5 marks" : "wrong value entered" ) ))) << endl;
	cout << ( grade5 == 'A' ? "fifth person get's 10 Marks" : (grade5 == 'B' ? "fifth person gets 8 marks": (grade5 == 'C' ? "Fifth person gets 6 marks" : (grade5 == 'D' ? "fifth preson gets 5 marks" : "wrong value entered" ) ))) << endl;

	_getch();
	return 0;
}