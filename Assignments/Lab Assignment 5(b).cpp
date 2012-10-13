#include <iostream> // Pre-processor Directives
#include <conio.h> // Pre-processor Directives
#include <math.h> // Pre-processor Directives

using namespace std;

int main() {
	float u,v; // Initialize variables to hold the angles
	cout << "Enter 1st Angle : ";
	cin >> u; // Prompts user to enter the 1st Angle
	cout << "Enter 2nd Angle : ";
	cin >> v; // Prompts user to enter the 2nd Angle
	cout << endl;
	cout << "1st Equation -> Left Hand Side is: " << pow(sin(u),2) << " and Right Hand Side is: " << (1-cos(2*u))/2 << endl << endl;
	cout << "2nd Equation -> Left Hand Side is: " << pow(cos(u),2) << " and Right Hand Side is: " << (1+cos(2*u))/2 << endl << endl;
	cout << "3rd Equation -> Left Hand Side is: " << pow(tan(u),2) << " and Right Hand Side is: " << (1-cos(2*u))/(1+cos(2*u)) << endl << endl;
	cout << "4th Equation -> Left Hand Side is: " << sin(u)+sin(v) << " and Right Hand Side is: " << 2*sin((u+v)/2)*cos((u-v)/2) << endl << endl;
	cout << "5th Equation -> Left Hand Side is: " << sin(u)-sin(v) << " and Right Hand Side is: " << 2*cos((u+v)/2)*sin((u-v)/2) << endl << endl;
	cout << "6th Equation -> Left Hand Side is: " << cos(u)+cos(v) << " and Right Hand Side is: " << 2*cos((u+v)/2)*cos((u-v)/2) << endl << endl;
	cout << "7th Equation -> Left Hand Side is: " << cos(u)-cos(v) << " and Right Hand Side is: " << -2*sin((u+v)/2)*sin((u-v)/2) << endl << endl;
	cout << "8th Equation -> Left Hand Side is: " << sin(u)*sin(v) << " and Right Hand Side is: " << 0.5*(cos(u-v)-cos(u+v)) << endl << endl;
	cout << "9th Equation -> Left Hand Side is: " << cos(u)*cos(v) << " and Right Hand Side is: " << 0.5*(cos(u-v)+cos(u+v)) << endl << endl;
	cout << "10th Equation -> Left Hand Side is: " << sin(u)*cos(v) << " and Right Hand Side is: " << 0.5*(sin(u+v)+sin(u-v)) << endl << endl;
	getch(); // Pauses the Program after successful execution
	return 0;
}