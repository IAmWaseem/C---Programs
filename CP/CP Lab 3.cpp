/*	Task 1
#include <iostream>
#include <conio.h>

using namespace std;

#define NoOfStudents 100

struct Student {
	char Name[30];
	int Roll_No;
};

int main() {
	Student Students[NoOfStudents];
	for(int i = 0; i < NoOfStudents; i++) {
		cout << "Enter Student " << i + 1 << " Name : ";
		cin.getline(Students[i].Name,30);
		cout << "Enter Student " << i + 1 << " Roll Number : ";
		cin >> Students[i].Roll_No;
	}
	for(int i = 0; i < NoOfStudents; i++) {
		cout << "Student " << i + 1 << " Name : " << Students[i].Name << endl;
		cout << "Student " << i + 1 << " Roll Number : " << Students[i].Roll_No << endl;
	}
	getch();
	return 0;
}
*/

/*	Task 2
#include <iostream>
#include <conio.h>

using namespace std;

#define NoOfStudents 100

struct Student {
	char Name[30];
	int Roll_No;
};

void EnterData(Student[]);
void ViewData(Student[]);
void SearchData(Student[],int);

int main() {
	Student Students[NoOfStudents];
	int Choice, Roll_No;
	MENU:
	system("cls");
	cout << "Main Menu" << endl << endl;
	cout << "[1] Enter All Student Data" << endl;
	cout << "[2] View All Students Data" << endl;
	cout << "[3] Search Student By Roll Number" << endl;
	cout << "[4] Exit the Application" << endl << endl;
	cout << "Enter Choice[1-4] : ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			EnterData(Students);
			goto MENU;
			break;
		case 2:
			ViewData(Students);
			goto MENU;
			break;
		case 3:
			cout << "Enter Roll Number to Search : ";
			cin >> Roll_No;
			SearchData(Students,Roll_No);
			goto MENU;
			break;
		case 4:
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Invalid Choice" << endl << "Enter Again" << endl;
			getch();
			goto MENU;
			break;
	}
	getch();
	return 0;
}

void EnterData(Student Students[]) {
	for(int i = 0; i < NoOfStudents; i++) {
		cout << "Enter Student " << i + 1 << " Name : ";
		cin.getline(Students[i].Name,30);
		cout << "Enter Student " << i + 1 << " Roll Number : ";
		cin >> Students[i].Roll_No;
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}

void ViewData(Student Students[]) {
	for(int i = 0; i < NoOfStudents; i++) {
		cout << "Student " << i + 1 << " Name : " << Students[i].Name << endl;
		cout << "Student " << i + 1 << " Roll Number : " << Students[i].Roll_No << endl;
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}

void SearchData(Student Students[], int Roll_No) {
	int Check = 0, Index;
	for(int i = 0; i < NoOfStudents; i++) {
		if(Roll_No == Students[i].Roll_No) {
			Index = i;
			Check = 1;
			break;
		}
	}
	if(Check) {
		cout << "Roll Number Found, Student's Name is : " << Students[Index].Name << endl;
	}
	else {
		cout << "Roll Number Not Found" << endl;
	}
	cout << "Press any key to Return to Main Menu";
	return;
}
*/

/*	Task 3
#include <iostream>
#include <conio.h>

using namespace std;

struct Student {
	char Name[30];
	int Roll_No;
};

void EnterData(Student[], int);
void ViewData(Student[], int);
void SearchData(Student[],int, int);

int main() {
	Student *Students;
	int Choice, Roll_No, Size;
	cout << "Enter Number of Students : ";
	cin >> Size;
	Students = new Student[Size];
	MENU:
	system("cls");
	cout << "Main Menu" << endl << endl;
	cout << "[1] Enter All Student Data" << endl;
	cout << "[2] View All Students Data" << endl;
	cout << "[3] Search Student By Roll Number" << endl;
	cout << "[4] Exit the Application" << endl << endl;
	cout << "Enter Choice[1-4] : ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			EnterData(Students,Size);
			goto MENU;
			break;
		case 2:
			ViewData(Students,Size);
			goto MENU;
			break;
		case 3:
			cout << "Enter Roll Number to Search : ";
			cin >> Roll_No;
			SearchData(Students,Roll_No,Size);
			goto MENU;
			break;
		case 4:
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Invalid Choice" << endl << "Enter Again" << endl;
			getch();
			goto MENU;
			break;
	}
	getch();
	return 0;
}

void EnterData(Student Students[], int Size) {
	for(int i = 0; i < Size; i++) {
		cout << "Enter Student " << i + 1 << " Name : ";
		fflush(stdin);
		cin.getline(Students[i].Name,30);
		cout << "Enter Student " << i + 1 << " Roll Number : ";
		cin >> Students[i].Roll_No;
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}

void ViewData(Student Students[], int Size) {
	for(int i = 0; i < Size; i++) {
		cout << "Student " << i + 1 << " Name : " << Students[i].Name << endl;
		cout << "Student " << i + 1 << " Roll Number : " << Students[i].Roll_No << endl;
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
	}
	else {
		cout << "Roll Number Not Found" << endl;
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}
*/

/*	Task 4
#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

struct Student {
	char Name[30];
	int Roll_No;
	int Subject_Marks[3];
};

void EnterData(Student[], int);
void ViewData(Student[], int);
int SearchData(Student[], int, int);
bool CopyRecord(Student[], int);

int main() {
	Student *Students;
	int Choice, Roll_No, Size, Count = 0;
	cout << "Enter Number of Students : ";
	cin >> Size;
	Students = new Student[Size];
	MENU:
	system("cls");
	cout << "Main Menu" << endl << endl;
	cout << "[1] Enter All Student Data" << endl;
	cout << "[2] View All Students Data" << endl;
	cout << "[3] Search Student By Roll Number" << endl;
	cout << "[4] Copy a Student Record" << endl;
	cout << "[5] Exit the Application" << endl << endl;
	cout << "Enter Choice[1-5] : ";
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
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Invalid Choice" << endl << "Enter Again" << endl;
			getch();
			goto MENU;
			break;
	}
	getch();
	return 0;
}

void EnterData(Student Students[], int Count) {
	cout << "Enter Student  Name : ";
	fflush(stdin);
	cin.getline(Students[Count].Name,30);
	cout << "Enter Student Roll Number : ";
	cin >> Students[Count].Roll_No;
	for(int i = 0; i < 3; i++) {
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
		for(int j = 0; j < 3; j++) {
			cout << "Student Marks in Subject " << j + 1 << " : " << Students[i].Subject_Marks[j] << endl;
		}
	}
	cout << "Press any key to Return to Main Menu";
	getch();
	return;
}

int SearchData(Student Students[], int Roll_No, int Size) {
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
		for(int j = 0; j < 3; j++) {
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
			Students[Count] = Students[i];
			cout << "Enter New Roll Number : ";
			cin >> Roll_No;
			Students[Count].Roll_No = Roll_No;
			return true;
		}
	}
	cout << "Roll Number Not Found" << endl;
	return false;
}
*/

/*	Task 5
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
	cout << "[5] Exit the Application" << endl << endl;
	cout << "Enter Choice[1-5] : ";
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
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Invalid Choice" << endl << "Enter Again" << endl;
			getch();
			goto MENU;
			break;
	}
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
			Students[Count] = Students[i];
			cout << "Enter New Roll Number : ";
			cin >> Roll_No;
			Students[Count].Roll_No = Roll_No;
			return true;
		}
	}
	cout << "Roll Number Not Found" << endl;
	return false;
}
*/

/*	Task 7
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
			Students[Count] = Students[i];
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