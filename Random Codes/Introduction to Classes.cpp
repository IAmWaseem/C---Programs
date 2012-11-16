/*

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Gradebook {
	public:
		void SetCourseName(string Name) {
			CourseName = Name;
		}
		string GetCourseName() {
			return CourseName;
		}
	private:
		string CourseName;
};

int main() {
	int n;
	Gradebook GBookObject;
	string Name;
	MENU:
	cout << "MAIN MENU" << endl << endl;
	cout << "[1] Set Course Name" << endl;
	cout << "[2] Get Current Course Name" << endl;
	cout << "[3] Exit" << endl << endl;
	cout << "Enter Choice[1-3]: ";
	cin >> n;
	switch(n) {
		case 1: {
			cout << "Enter Course Name : ";
			getline(cin,Name);
			GBookObject.SetCourseName(Name);
			cout << endl << "Successfully Set the Course Name" << endl;
			goto MENU;
			break;
		}
		case 2: {
			Name = GBookObject.GetCourseName();
			cout << Name << endl;
			goto MENU;
			break;
		}
		case 3: {
			cout << "Exiting...";
			break;
		}
		default: {
			cout << "Invalid Choice" << "Enter Again";
			goto MENU;
		}
	}
	getch();
	return 0;
}

*/

#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	system("cls");
	int i,j;
	char ch=' ';

	// Rectangle Starts
	for (i=0;i<=8;i++)
	{
		cout << "*";
	}
	cout << endl;
	for (i=0;i<=7;i++)
	{
		cout << "*";
		for (j=0;j<=6;j++)
		{
			cout << ch;
		}
		cout << "*" << endl;
	}
	for (i=0;i<=8;i++)
	{
		cout << "*";
	}
	// Rectangle Ends
	
	cout << endl << endl << endl;
	
	// Oval Starts
	cout << "   ***   " << endl;
	cout << " *     * " << endl;
	for (i=0;i<=7;i++)
	{
		cout << "*";
		for (j=0;j<=6;j++)
		{
			cout << ch;
		}
		cout << "*" << endl;
	}
	cout << " *     * " << endl;
	cout << "   ***   " << endl;
	// Oval Ends

	cout << endl << endl << endl;

	// Arrow Starts
	cout << "    *   " << endl;
	cout << "   ***  " << endl;
	cout << "  ***** " << endl;
	cout << "    *   " << endl;
	cout << "    *   " << endl;
	cout << "    *   " << endl;
	cout << "    *   " << endl;
	cout << "    *   " << endl;
	cout << "    *   " << endl;
	cout << "    *   " << endl;
	// Arrow Ends

	cout << endl << endl << endl;

	//Diamond Starts
	cout << "    *    " << endl;
	cout << "   * *   " << endl;
	cout << "  *   *  " << endl;
	cout << " *     * " << endl;
	cout << "*       *" << endl;
	cout << " *     * " << endl;
	cout << "  *   *  " << endl;
	cout << "   * *   " << endl;
	cout << "    *    " << endl;
	//Diamond Ends

	cout << endl << endl << endl;
	system("pause");
	return 0;
}