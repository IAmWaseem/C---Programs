#include <iostream>
#include <conio.h>

using namespace std;

struct Student {
	 char Name[30];
	 int RollNumber;
	 int Age;
	 double CGPA;
	 Student *Next;
};

union SearchStudent {
	char Name[30];
	int RollNumber;
};


Student *First = NULL;

void SwitchBoard();
void EnterData(char*, int*, int*, double*);
void AddRecord();
void AddRecordInStart();
void AddRecordInMiddle();
void AddRecordInEnd();
void SearchRecord();
void SearchByName();
void SearchByRollNumber();
void AddRecordInMiddle();
void DeleteRecord();
void ViewAllRecords();

int main() {
	SwitchBoard();
	getch();
	return 0;
}

void SwitchBoard() {
	system("cls");
	int Choice;
	cout << "Main Menu" << endl << endl;
	cout << "[1] Add Record" << endl;
	cout << "[2] Delete Record" << endl;
	cout << "[3] Search Record" << endl;
	cout << "[4] Update Record" << endl;
	cout << "[5] View All Records" << endl;
	cout << "[6] Exit The Application" << endl << endl;
	cout << "Enter Choice[1-6]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			AddRecord();
			SwitchBoard();
			break;
		case 2:
			DeleteRecord();
			SwitchBoard();
			break;
		case 3:
			SearchRecord();
			SwitchBoard();
			break;
		case 4:
			break;
		case 5:
			ViewAllRecords();
			SwitchBoard();
			break;
		case 6:
			break;
		default:
			cout << "Invalid Choice Entered" << endl;
			system("pause");
			SwitchBoard();
			break;
	}
	return;
}

void AddRecord() {
	system("cls");
	int Choice;
	cout << "Add Record" << endl << endl;
	cout << "[1] Add Record in Start" << endl;
	cout << "[2] Add Record in Middle" << endl;
	cout << "[3] Add Record in End" << endl;
	cout << "[4] Back To Main Menu" << endl << endl;
	cout << "Enter Choice[1-4]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			AddRecordInStart();
			cout << "Record Successfully Added in Start" << endl;
			system("pause");
			AddRecord();
			break;
		case 2:
			AddRecordInMiddle();
			cout << "Record Successfully Added after the Required Record" << endl;
			system("pause");
			AddRecord();
			break;
		case 3:
			AddRecordInEnd();
			break;
		case 4:
			SwitchBoard();
			break;
		default:
			cout << "Invalid Choice Entered" << endl;
			system("pause");
			AddRecord();
			break;
	}
	return;
}

void DeleteRecord() {
	Student *ptrCurrent = First, *ptrPrevious;
	int Key;
	cout << "Enter Roll Number : ";
	cin >> Key;
	while (ptrCurrent != NULL && ptrCurrent->RollNumber != Key) {
		ptrPrevious = ptrCurrent;
		ptrCurrent = ptrCurrent -> Next;
	}
	if (ptrCurrent == NULL) {
		cout << "Not Found";
		return;
	}
	if (ptrCurrent == First) {
		First = First -> Next;
	}
	else {
		ptrPrevious -> Next = ptrCurrent -> Next;
	}
	delete ptrCurrent;
	return;
}

void EnterData(char *Name, int *RollNumber, int *Age, double *CGPA) {
	cout << "Enter Name : ";
	cin.getline(Name,20);
	cout << "Enter Roll Number : ";
	cin >> *RollNumber;
	cout << "Enter Age : ";
	cin >> *Age;
	cout << "Enter CGPA : ";
	cin >> *CGPA;
	return;
}

void AddRecordInStart() {
	Student *Node;
	Node = new Student;
	EnterData(Node -> Name,&Node -> RollNumber,&Node -> Age,&Node -> CGPA);
	Node -> Next = First;
	First = Node;
	return;
}

void AddRecordInMiddle() {
	int Key;
	cout << "Enter Roll Number : ";
	cin >> Key;
	Student *Node;
	Node = new Student;
	
}

void AddRecordInEnd() {
	Student *Node = new Student, *ptrTemp = First;
	EnterData(Node -> Name,&Node -> RollNumber,&Node -> Age,&Node -> CGPA);
	Node -> Next = NULL;
	if (First == NULL) {
		First = Node;
		return;
	}
	while (ptrTemp -> Next != NULL)
		ptrTemp = ptrTemp -> Next;
	ptrTemp -> Next = Node;	
	return;
}


void SearchRecord() {
	int Choice;
	cout << "Search Record" << endl << endl;
	cout << "[1] Search By Name" << endl;
	cout << "[2] Search By Roll Number" << endl;
	cout << "[3] Back to Main Menu" << endl << endl;
	cout << "Enter Choice[1-3]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			SearchByName();
			system("pause");
			SearchRecord();
			break;
		case 2:
			SearchByRollNumber();
			system("pause");
			SearchRecord();
			break;
		case 3:
			SearchRecord();
			break;
		default:
			cout << "Invalid Choice Entered" << endl;
			system("pause");
			SearchRecord();
			break;
	}

	return;
}

void SearchByName() {
	int Check = 0;
	SearchStudent Key;
	cout << "Enter Name to Search : ";
	cin.getline(Key.Name,30);
	Student *Search;
	Search = First;
	while(Search -> Next != NULL) {
		if(strcmp(Search -> Name, Key.Name) == 0) {
			Check = 1;
			break;
		}
		Search = Search -> Next;
	}
	if(Check) {
		cout << "Record Found" << endl << endl;
		cout << "Name : " << Search -> Name << endl;
		cout << "Roll Number : " << Search -> RollNumber << endl;
		cout << "Age : " << Search -> Age << endl;
		cout << "CGPA : " << Search -> CGPA << endl;
	}
	else {
		cout << "Record not Found";
	}
	return;
}

void SearchByRollNumber() {
	int Check = 0;
	SearchStudent Key;
	cout << "Enter Roll Number to Search : ";
	cin >> Key.RollNumber;
	Student *Search;
	Search = First;
	while(Search -> Next != NULL) {
		if(Search -> RollNumber == Key.RollNumber) {
			Check = 1;
			break;
		}
		Search = Search -> Next;
	}
	if(Check) {
		cout << "Record Found" << endl << endl;
		cout << "Name : " << Search -> Name << endl;
		cout << "Roll Number : " << Search -> RollNumber << endl;
		cout << "Age : " << Search -> Age << endl;
		cout << "CGPA : " << Search -> CGPA << endl;
	}
	else {
		cout << "Record not Found";
	}
	return;
}

void ViewAllRecords() {
	Student *ptrTemp = First;
	cout << endl;
	while (ptrTemp != NULL) {
		cout << "Name : " << ptrTemp -> Name << endl;
		cout << "Roll Number : " << ptrTemp -> RollNumber << endl;
		cout << "Age : " << ptrTemp -> Age << endl;
		cout << "CGPA : " << ptrTemp -> CGPA << endl;
		ptrTemp = ptrTemp -> Next;
	}
	return;
}
