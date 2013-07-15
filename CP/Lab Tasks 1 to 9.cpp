/* Task 1
#include <iostream>
#include <conio.h>

using namespace std;

struct Student {
	int Roll_Number;
	int Phone;
	char Name[20];
	char City[20];
};

int main() {
	Student std;
	Student Students[100];
	cout << "Enter Roll Number : ";
	cin >> std.Roll_Number;
	cout << "Enter the Name of Student : ";
	fflush(stdin);
	cin.getline(std.Name,20);
	cout << "Enter the Name of City of Student : ";
	cin.getline(std.City,20);
	cout << "Enter Phone Number of Student : ";
	cin >> std.Phone;
	cout << endl;
	cout << "Roll Number : " << std.Roll_Number << endl;
	cout << "Name : " << std.Name << endl;
	cout << "City : " << std.City << endl;
	cout << "Phone Number : " << std.Phone << endl;
	getch();
	return 0;
}
*/

#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

struct Student {
	char Name[30];
	int Roll_No;
	int *Subject_Marks;
	int SubjectsSize;
};

void EnterData(Student[], int);
void ViewData(Student[], int);
void SearchData(Student[], int, int);
bool CopyRecord(Student[], int);
bool DeleteRecord(Student[], int);

int main() {
	Student *Students;
	int Choice, Roll_No, Size, Count = 0;
	cout << "Enter Number of Students : ";
	cin >> Size;
	Students = new Student[Size];
	MENU:
	system("cls");
	cout << "Main Menu" << endl << endl;
	cout << "[1] Enter new Student" << endl;
	cout << "[2] View All Students Data" << endl;
	cout << "[3] Search Student By Roll Number" << endl;
	cout << "[4] Copy a Student Record" << endl;
	cout << "[5] Delete a Student Record" << endl;
	cout << "[6] Exit the Application" << endl << endl;
	cout << "Enter Choice[1-6] : ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			EnterData(Students,Count);
			Count++;
			goto MENU;
			break;
		case 2:
			ViewData(Students,Count);
			goto MENU;
			break;
		case 3:
			cout << "Enter Roll Number to Search : ";
			cin >> Roll_No;
			SearchData(Students,Roll_No,Count);
			goto MENU;
			break;
		case 4:
			if(CopyRecord(Students,Count)) {
				Count++;
				cout << "Record Copied Successfully" << endl;
			}
			getch();
			goto MENU;
			break;
		case 5:
			if(DeleteRecord(Students,Count)) {
				cout << "Record Successfully Deleted, press any key to return to main menu";
				Count--;
			}
			else {
				cout << "Roll Number Not Found, Nothing Deleted";
			}
			getch();
			goto MENU;
			break;
		case 6:
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Invalid Choice" << endl << "Enter Again" << endl;
			getch();
			goto MENU;
			break;
	}
	delete [] Students;
	getch();
	return 0;
}

void EnterData(Student Students[], int Count) {
	cout << "Enter Student  Name : ";
	fflush(stdin);
	cin.getline(Students[Count].Name,30);
	cout << "Enter Student Roll Number : ";
	cin >> Students[Count].Roll_No;
	cout << "Enter Number of Subjects : ";
	cin >> Students[Count].SubjectsSize;
	Students[Count].Subject_Marks = new int[Students[Count].SubjectsSize];
	for(int i = 0; i < Students[Count].SubjectsSize; i++) {
		cout << "Enter Student Marks in Subject " << i + 1 << " : ";
		cin >> Students[Count].Subject_Marks[i];
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}

void ViewData(Student Students[], int Size) {
	for(int i = 0; i < Size; i++) {
		cout << "Student " << i + 1 << " Name : " << Students[i].Name << endl;
		cout << "Student " << i + 1 << " Roll Number : " << Students[i].Roll_No << endl;
		for(int j = 0; j < Students[i].SubjectsSize; j++) {
			cout << "Student Marks in Subject " << j + 1 << " : " << Students[i].Subject_Marks[j] << endl;
		}
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}

void SearchData(Student Students[], int Roll_No, int Size) {
	int Check = 0, Index;
	for(int i = 0; i < Size; i++) {
		if(Roll_No == Students[i].Roll_No) {
			Index = i;
			Check = 1;
			break;
		}
	}
	if(Check) {
		cout << "Roll Number Found, Student's Name is : " << Students[Index].Name << endl;
		for(int j = 0; j < Students[Index].SubjectsSize; j++) {
			cout << "Enter Student Marks in Subject " << j + 1 << " : " << Students[Index].Subject_Marks[j] << endl;
		}
	}
	else {
		cout << "Roll Number Not Found" << endl;
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}

bool CopyRecord(Student Students[], int Count) {
	int Roll_No, Check = 0;
	cout << "Enter Roll Number of the Source Student : ";
	cin >> Roll_No;
	for(int i = 0; i < Count; i++) {
		if(Students[i].Roll_No == Roll_No) {
			strcpy(Students[Count].Name,Students[i].Name);
			Students[Count].SubjectsSize = Students[i].SubjectsSize;
			for(int j = 0; j < Students[Count].SubjectsSize; j++) {
				Students[Count].Subject_Marks[j] = Students[i].Subject_Marks[j];
			}
			cout << "Enter New Roll Number : ";
			cin >> Roll_No;
			Students[Count].Roll_No = Roll_No;
			return true;
		}
	}
	cout << "Roll Number Not Found" << endl;
	return false;
}

bool DeleteRecord(Student Students[], int Count) {
	int Roll_No;
	cout << "Enter Roll Number : ";
	cin >> Roll_No;
	Student temp;
	for(int i = 0; i < Count; i++) {
		if(Students[i].Roll_No == Roll_No) {
			for(int j = i; j < Count; j++) {
				temp = Students[j];
				Students[j] = Students[j + 1];
				Students[j + 1] = temp;
			}
			return true;
		}
	}
	return false;
}