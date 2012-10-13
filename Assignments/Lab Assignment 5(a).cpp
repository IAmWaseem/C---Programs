#include <iostream> // Pre-processor Directives
#include <conio.h> // Pre-processor Directives

using namespace std; // Using all functions from namespace std

int main() {
	float x,y,b,m; // Initialized variables to be used
	cout << "Enter value of x: ";
	cin >> x; // Prompts user to enter the value of x
	cout << "Enter value of y: ";
	cin >> y; // Prompts user to enter the value of y
	cout << "Enter value of b: ";
	cin >> b; // Prompts user to enter the value of b
	m = (y-b)/x; // Calculates the Actual Slope from formula
	cout << endl << "Slope of the line is " << m << endl; // Displays the Slope
	getch(); // Pauses the Program after successful execution
	return 0;
}