/*
#include <iostream>

using namespace std;

struct Numbers {
	int Number;
	Numbers *Next;
	Numbers(int);
};

Numbers::Numbers(int N) {
	Number = N;
	return;
}

void SwitchBoard(Numbers *&);
void InsertNumber(Numbers *&);
Numbers* StoreInformation(void);
void DisplayNumbers(Numbers *&);
void DeleteNumber(Numbers *&);
void DeleteAll(Numbers *&);

int main() {
	Numbers *Start = NULL;
	SwitchBoard(Start);
}

void SwitchBoard(Numbers *&Start) {
	system("cls");
	int Choice;
	cout << "MAIN MENU" << endl << endl;
	cout << "[1] Insert a Number" << endl;
	cout << "[2] Delete a Number" << endl;
	cout << "[3] Display all Numbers" << endl;
	cout << "[4] Exit the Application" << endl << endl;
	cout << "Enter Choice[1-4]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			InsertNumber(Start);
			system("pause");
			SwitchBoard(Start);
			break;
		case 2:
			DeleteNumber(Start);
			system("pause");
			SwitchBoard(Start);
			break;
		case 3:
			DisplayNumbers(Start);
			system("pause");
			SwitchBoard(Start);
			break;
		case 4:
			cout << "Exiting" << endl;
			system("pause");
			DeleteAll(Start);
			break;
		default:
			cout << "Invalid Choice" << endl;
			system("pause");
			SwitchBoard(Start);
			break;
	}
}

Numbers* StoreInformation() {
	Numbers *Node;
	int Number;
	cout << "Enter Number : ";
	cin >> Number;
	Node = new Numbers(Number);
	return Node;
}

void InsertNumber(Numbers *&Start) {
	Numbers *Node;
	Node = StoreInformation();
	if(Start == NULL) {
		Node -> Next = Start;
		Start = Node;
	}
	else {
		Numbers *Current = Start, *Previous = Start;
		while(Current -> Next != NULL && Current -> Number < Node -> Number) {
			if(Current -> Number == Node -> Number) {
				cout << "Number Already Exists" << endl;
				return;
			}
			Previous = Current;
			Current = Current -> Next;
		}
		if(Current -> Number == Node -> Number) {
			cout << "Number Already Exists" << endl;
			return;
		}
		if(Previous == Start) {
			Node -> Next = Start;
			Start = Node;
		}
		else {
			Node -> Next = Previous -> Next;
			Previous -> Next = Node;
		}
	}
	cout << "Number Added Successfully" << endl;
	return;
}

void DisplayNumbers(Numbers *&Start) {
	Numbers *Current = Start;
	if(Current == NULL) {
		cout << "No Number in the List" << endl;
		return;
	}
	while(Current != NULL) {
		cout << "Number : " << Current -> Number << endl;
		Current = Current -> Next;
	}
	return;
}

void DeleteNumber(Numbers *&Start) {
	Numbers *Current = Start, *Previous = Start;
	int Number;
	cout << "Enter Number to Delete : ";
	cin >> Number;
	while(Current != NULL && Number != Current -> Number)
	{
		Previous = Current;
		Current = Current -> Next;
	}
	if(Current == NULL) {
		cout << "Number Not Found" << endl;
		return;
	}
	if(Current == Start) {
		Start = Start -> Next;
	}
	else {
		Previous -> Next = Current -> Next;
	}
	delete Current;
	cout << "Number Deleted" << endl;
	return;
}

void DeleteAll(Numbers *&Start) {
	Numbers *Current = Start, *Previous = Start;
	while(Current != NULL) {
		Previous = Current;
		Current = Current -> Next;
		delete Previous;
	}
	delete Current;
}
*/


#include <iostream>

using namespace std;
typedef long long LONG;

struct AddressBook {
	char *Name;
	LONG Telephone;
	LONG CellPhone;
	char *Email;
	char *HomeAddress;
	char *OfficeAddress;
	AddressBook *Next;

	AddressBook();
	AddressBook(char*,LONG,LONG,char*,char*,char*);
	~AddressBook();
};

AddressBook::AddressBook() {
	return;
}

AddressBook::AddressBook(char *N, LONG Tele, LONG Cell, char *email, char *home, char *office) {
	N = new char[ strlen(N) + 1 ];
	strcpy_s(Name,strlen(N),N);
	Telephone = Tele;
	CellPhone = Cell;
	Email = new char[ strlen(email) + 1 ];
	strcpy(Email,email);
	HomeAddress = new char[ strlen(home) + 1 ];
	strcpy(HomeAddress,home);
	OfficeAddress = new char[ strlen(office) + 1 ];
	strcpy(OfficeAddress,office);
}

AddressBook::~AddressBook() {
	delete[] Name;
	delete[] Email;
	delete[] HomeAddress;
	delete[] OfficeAddress;
}

void SwitchBoard(AddressBook *&);
void AddEntry(AddressBook *&);
AddressBook* StoreInformation();
void DeleteEntry(AddressBook *&);

int main() {
	AddressBook *Start = NULL;
	SwitchBoard(Start);
	return 0;
}

void SwitchBoard(AddressBook *&Start) {
	int Choice;
	cout << "Main Menu" << endl << endl;
	cout << "[1] Add an Entry" << endl;
	cout << "[2] Delete an Entry" << endl;
	cout << "[3] Delete all Entries" << endl;
	cout << "[4] Find an Entry" << endl;
	cout << "[5] Display all Entries" << endl;
	cout << "[6] Exit" << endl << endl;
	cout << "Enter Choice[1-6]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			AddEntry(Start);
			system("pause");
			SwitchBoard(Start);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
	}

	return;
}

void AddEntry(AddressBook *&Start) {
	AddressBook *Node;
	Node = StoreInformation();
	if(Start == NULL) {
		Node -> Next = Start;
		Start = Node;
	}
	else {
		AddressBook *Current = Start;
		while(Current -> Next != NULL) {
			Current = Current -> Next;
		}
		Node -> Next = Current -> Next;
		Current -> Next = Node;
	}
	cout << "Entry Added Successfully" << endl;
	return;
}

AddressBook* StoreInformation() {
	char *Name, *Email, *Home, *Office;
	LONG Telephone, Cell;
	AddressBook *Node;
	Name = new char[100];
	Email = new char[50];
	Home = new char[100];
	Office = new char[100];
	cout << "Enter Name : ";
	fflush(stdin);
	cin.getline(Name,100);
	cout << "Enter Email : ";
	cin.getline(Email,50);
	cout << "Enter Telephone Number : ";
	cin >> Telephone;
	cout << "Enter Cellphone Number : ";
	cin >> Cell;
	cout << "Enter Home Address : ";
	fflush(stdin);
	cin.getline(Home,100);
	cout << "Enter Office Address : ";
	cin.getline(Office,100);
	Node = new AddressBook(Name,Telephone,Cell,Email,Home,Office);
	return Node;
}

void DeleteEntry(AddressBook *&Start) {
	char *SearchString;
	SearchString = new char[100];
	cout << "Enter String to Search : ";
	fflush(stdin);
	cin.getline(SearchString,100);
	if(Start == NULL) {
		cout << "No Record Exists" << endl;
		return;
	}
	AddressBook *Current = Start, *Previous = Start;
	while(Current != NULL) {

		Previous = Current;
		Current = Current -> Next;
	}
	if(Current == NULL) {
		cout << "No Record Found" << endl;
		return;
	}
}
