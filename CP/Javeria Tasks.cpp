#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#define MAX 50
#define MAX2 50

char BookName[MAX][30];
char ISBNNumber[MAX][30];
char PublisherName[MAX][30];
char AuthorName[MAX][30];
int  NumberOfCopies[MAX];
int  PublisherYear[MAX];
int  IssuedBook[MAX] = {0};

void adduser();
void edituser();
void deleteuser();
void menu();

char id[MAX2][15];
char firstname[MAX2][15];
char lastname[MAX2][15];
char field[MAX2][15];
char dateofbirth[MAX2][15];

int usernumber = 1;

int BookNumber = 0;

void AddNewBook();
void EditBook();
void SearchBook();
void DeleteBook();
void IssueBook();
void DeleteIssuedBook();
void searchuser();

void Read() {
	ifstream inFileBooks;
	ifstream inFileUsers;
	inFileBooks.open("Books.txt");
	if(!inFileBooks) {
		
	}
	else {
		inFileBooks >> BookNumber;
		char temp;
		inFileBooks >> temp;
		for(int i = 0; i < BookNumber; i++) {
			inFileBooks.getline(BookName[i], 30);
			inFileBooks.getline(ISBNNumber[i], 30);
			inFileBooks.getline(PublisherName[i], 30);
			inFileBooks.getline(AuthorName[i], 30);
			inFileBooks >> NumberOfCopies[i];
			inFileBooks >> PublisherYear[i];
			inFileBooks >> IssuedBook[i];
		}
		inFileBooks.close();
	}
	inFileUsers.open("Users.txt");
	if(!inFileUsers) {
		
	}
	else {
		inFileUsers >> usernumber;
		for(int i = 1; i <=usernumber; i++) {
			inFileUsers.getline(id[i], 15);
			inFileUsers.getline(firstname[i], 15);
			inFileUsers.getline(lastname[i], 15);
			inFileUsers.getline(field[i], 15);
			inFileUsers.getline(dateofbirth[i], 15);
		}
		inFileUsers.close();
	}
}

void Write() {
	ofstream outFileBooks, outFileUsers;
	if(BookNumber != 0) {
		outFileBooks.open("Books.txt");
		if(!outFileBooks) {
			cout << "Cannot Open Books.txt" << endl;
		}
		else {
			outFileBooks << BookNumber << "\n";
			for(int i = 0; i < BookNumber; i++) {
				outFileBooks << BookName[i] << "\n";
				outFileBooks << ISBNNumber[i] << "\n";
				outFileBooks << PublisherName[i] << "\n";
				outFileBooks << AuthorName[i] << "\n";
				outFileBooks << NumberOfCopies[i] << "\n";
				outFileBooks << PublisherYear[i] << "\n";
				outFileBooks << IssuedBook[i] << "\n";
			}
			outFileBooks.flush();
			outFileBooks.close();
		}
	}
	if(usernumber != 1) {
		outFileUsers.open("Users.txt");
		if(!outFileUsers) {
			cout << "Cannot Open Users.txt" << endl;
		}
		else {
			outFileUsers << usernumber << "\n";
			for(int i = 1; i <= usernumber; i++) {
				outFileUsers << id[i] << "\n";
				outFileUsers << firstname[i] << "\n";
				outFileUsers << lastname[i] << "\n";
				outFileUsers << field[i] << "\n";
				outFileUsers << dateofbirth[i] << "\n";
			}
			outFileUsers.flush();
			outFileUsers.close();
		}
	}
}

void movetomenu() {
	char ch;
	ch = getch();
	if(ch == 27) {
		menu();
	}
}

int main() {
	Read();
	menu();
	cout << "Do you want to Write the Files?(Y / N) : ";
	char ch;
	cin >> ch;
	if(ch == 'y' || ch == 'Y') {
		Write();
	}
	else {

	}
	return 0;
}

void searchuser() {
	movetomenu();
	char Temp[15];
	int Choice;
	int Check = 0;
	cout << "[1] Search by ID" << endl
		<< "[2] Search By First Name" << endl << endl
		<< "Enter Choice[1-2]: ";
	cin >> Choice;
	switch(Choice) {
	case 1:
		cout << "Enter ID : ";
		fflush(stdin);
		cin.getline(Temp, 15);
		break;
	case 2:
		cout << "Enter First Name : ";
		fflush(stdin);
		cin.getline(Temp, 15);
		break;
	default:
		break;
	}
	for(int i = 1; i <= usernumber; i++) {
		if(Choice == 1) {
			if(strcmp(id[i],Temp) == 0) {
				cout << "ID : " << id[i] << endl;
				cout << "First Name : " << firstname[i] << endl;
				cout << "Last Name : " << lastname[i] << endl;
				cout << "Field : " << field[i] << endl;
				cout << "Date Of Birth : " << dateofbirth[i] << endl << endl;
				Check = 1;
				break;
			}
		}
		else if(Choice == 2) {
			if(strcmp(firstname[i], Temp) == 0) {
				cout << "ID : " << id[i] << endl;
				cout << "First Name : " << firstname[i] << endl;
				cout << "Last Name : " << lastname[i] << endl;
				cout << "Field : " << field[i] << endl;
				cout << "Date Of Birth : " << dateofbirth[i] << endl << endl;
				Check = 1;
				break;
			}
		}
	}
	if(!Check) {
		cout << "User Not Found in the Database" << endl;
	}
}

void menu()
{
	int choice;
	MENU:
	cout<<"      FAST library management system     " << endl;
	cout<<"press option key to activate the required information" << endl;
	cout<<"(0)addnew book" << endl;
	cout<<"(1)edit book" << endl;
	cout<<"(2)delete book" << endl;
	cout<<"(3)search book" << endl;
	cout<<"(4)add library user" << endl;
	cout<<"(5)edit library user" << endl;
	cout<<"(6)delete library user" << endl;
	cout<<"(7)search library user" << endl;
	cout<<"(8)issue book" << endl;
	cout<<"(9)delete issued book" << endl << endl;
	cin>>choice;
	switch(choice)
	{
	case 0:
		{
			AddNewBook();
			goto MENU;
			break;
		}
		case 1:
		{
			EditBook();
			goto MENU;
			break;
		}
		case 2:
		{
			DeleteBook();
			goto MENU;
			break;
		}
		case 3:
		{
			SearchBook();
			goto MENU;
			break;
		}
		case 4:
		{
			adduser();
			goto MENU;
			break;
		}
		case 5:
		{
			edituser();
			goto MENU;
			break;
		}
		case 6:
		{
			deleteuser();
			goto MENU;
			break;
		}
		case 7:
		{
			searchuser();
			goto MENU;
			break;
		}
		case 8:
		{
			IssueBook();
			goto MENU;
			break;
		}
		case 9:
		{
			DeleteIssuedBook();
			goto MENU;
			break;
		}
	}
}

void AddNewBook() {
	if(BookNumber >= MAX) {
		cout << "Cannot add New Book, we are Full" << endl;
		return;
	}
	cout << "Enter Name of Book : ";
	fflush(stdin);
	cin.getline(BookName[BookNumber], 30);
	for(int i = 0; i < BookNumber; i++) {
		if(strcpy(BookName[i], BookName[BookNumber]) == 0) {
			cout << "Duplicate Name Exists" << endl;
			return;
		}
	}
	cout << "Enter ISBN Number : ";
	fflush(stdin);
	cin.getline(ISBNNumber[BookNumber], 30);
	cout << "Enter Publisher Name : ";
	fflush(stdin);
	cin.getline(PublisherName[BookNumber], 30);
	cout << "Enter Author Name : ";
	fflush(stdin);
	cin.getline(AuthorName[BookNumber], 30);
	cout << "Enter Number of Copies : ";
	cin >> NumberOfCopies[BookNumber];
	cout << "Enter Publisher Year : ";
	cin >> PublisherYear[BookNumber];
	++BookNumber;
	cout << "Book Added Successfully" << endl;
}

void EditBook() {
	if(BookNumber == 0) {
		cout << "No Books Present in the Library" << endl;
		return;
	}
	char Temp[30];
	int Check = 0;
	cout << "Enter ISBN Number : ";
	fflush(stdin);
	cin.getline(Temp, 30);
	for(int i = 0; i < BookNumber; i++) {
		if(strcmp(Temp, ISBNNumber[i]) == 0) {
			EDIT:
			int Choice;
			cout << "What do you Want to Edit" << endl << endl
				 << "[1] Book Name" << endl
				 << "[2] ISBN Number" << endl
				 << "[3] Publisher Name" << endl
				 << "[4] Author Name" << endl
				 << "[5] Number of Copies" << endl
				 << "[6] Publisher Year" << endl
				 << "[7] Do Nothing" << endl << endl
				 << "Enter Choice[1-7]: ";
			cin >> Choice;
			switch(Choice) {
				case 1:
					cout << "Enter Name of Book : ";
					fflush(stdin);
					cin.getline(BookName[i], 30);
					goto EDIT;
					break;
				case 2:
					cout << "Enter ISBN Number : ";
					fflush(stdin);
					cin.getline(ISBNNumber[i], 30);
					goto EDIT;
					break;
				case 3:
					cout << "Enter Publisher Name : ";
					fflush(stdin);
					cin.getline(PublisherName[i], 30);
					goto EDIT;
					break;
				case 4:
					cout << "Enter Author Name : ";
					fflush(stdin);
					cin.getline(AuthorName[i], 30);
					goto EDIT;
					break;
				case 5:
					cout << "Enter Number of Copies : ";
					cin >> NumberOfCopies[i];
					goto EDIT;
					break;
				case 6:
					cout << "Enter Publisher Year";
					cin >> PublisherYear[i];
					goto EDIT;
					break;
				case 7:
					break;
				default:
					cout << "Invalid Choice" << endl << "Enter Again" << endl << endl;
					getch();
					goto EDIT;
					break;
			}
			Check = 1;
			break;
		}
	}
	if(!Check) {
		cout << "Book Not Found with ISBN Number " << Temp << endl;
	}
}

void SearchBook() {
	if(BookNumber == 0) {
		cout << "No Books Present in the Library" << endl;
		return;
	}
	char Temp[30];
	int Check = 0;
	int Choice;
	int Temp1;
	cout << "[1] Search by ISBN Number" << endl
		 << "[2] Search by Author Name" << endl
		 << "[3] Search by Book Name" << endl
		 << "[4] Search by Publisher Name" << endl
		 << "[5] Search by Publisher Year" << endl << endl
		 << "Enter Choice[1-5]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			cout << "Enter ISBN Number : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 2:
			cout << "Enter Author Name : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 3:
			cout << "Enter Book Name : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 4:
			cout << "Enter Publisher Name : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 5:
			cout << "Enter Publisher Year : ";
			cin >> Temp1;
			break;
		default:
			break;
	}
	for(int i = 0; i < BookNumber; i++) {
		if(Choice == 1) {
			if(strcmp(Temp, ISBNNumber[i]) == 0) {
				cout << "Book Name : " << BookName[i] << endl
					<< "ISBN Number : " << ISBNNumber[i] << endl
					<< "Publisher Name : " << PublisherName[i] << endl
					<< "Author Name : " << AuthorName[i] << endl
					<< "Number of Copies : " << NumberOfCopies[i] << endl
					<< "Publisher Year : " << PublisherYear[i] << endl << endl;
				Check = 1;
			}
		}
		else if(Choice == 2) {
			if(strcmp(Temp, AuthorName[i]) == 0) {
				cout << "Book Name : " << BookName[i] << endl
					<< "ISBN Number : " << ISBNNumber[i] << endl
					<< "Publisher Name : " << PublisherName[i] << endl
					<< "Author Name : " << AuthorName[i] << endl
					<< "Number of Copies : " << NumberOfCopies[i] << endl
					<< "Publisher Year : " << PublisherYear[i] << endl << endl;
				Check = 1;
			}
		}
		else if(Choice == 3) {
			if(strcmp(Temp, BookName[i]) == 0) {
				cout << "Book Name : " << BookName[i] << endl
					<< "ISBN Number : " << ISBNNumber[i] << endl
					<< "Publisher Name : " << PublisherName[i] << endl
					<< "Author Name : " << AuthorName[i] << endl
					<< "Number of Copies : " << NumberOfCopies[i] << endl
					<< "Publisher Year : " << PublisherYear[i] << endl << endl;
				Check = 1;
			}
		}
		else if(Choice == 4) {
			if(strcmp(Temp, PublisherName[i]) == 0) {
				cout << "Book Name : " << BookName[i] << endl
					<< "ISBN Number : " << ISBNNumber[i] << endl
					<< "Publisher Name : " << PublisherName[i] << endl
					<< "Author Name : " << AuthorName[i] << endl
					<< "Number of Copies : " << NumberOfCopies[i] << endl
					<< "Publisher Year : " << PublisherYear[i] << endl << endl;
				Check = 1;
			}
		}
		else if(Choice == 5) {
			if(Temp1 == PublisherYear[i]) {
				cout << "Book Name : " << BookName[i] << endl
					<< "ISBN Number : " << ISBNNumber[i] << endl
					<< "Publisher Name : " << PublisherName[i] << endl
					<< "Author Name : " << AuthorName[i] << endl
					<< "Number of Copies : " << NumberOfCopies[i] << endl
					<< "Publisher Year : " << PublisherYear[i] << endl << endl;
				Check = 1;
			}
		}
	}
	if(!Check) {
		cout << "Book Not Found with ISBN Number " << Temp << endl;
	}
}

void IssueBook() {
	if(BookNumber == 0) {
		cout << "No Books Present in the Library" << endl;
		return;
	}
	int Check = 0;
	char Temp[30];
	cout << "Enter Book ISBN Number to Issue Book : ";
	fflush(stdin);
	for(int i = 0; i < BookNumber; i++) {
		if(strcmp(Temp, ISBNNumber[i]) == 0) {
			if(IssuedBook[i] == 1) {
				cout << "Book Already Issued" << endl;
			}
			else {
				cout << "Book Issued" << endl;
				IssuedBook[i] = 1;
			}
			Check = 1;
			break;
		}
	}
	if(!Check) {
		cout << "Book Not Found with ISBN Number " << Temp << endl;
	}
}

void DeleteIssuedBook() {
	if(BookNumber == 0) {
		cout << "No Books Present in the Library" << endl;
		return;
	}
	int Check = 0;
	char Temp[30];
	cout << "Enter Book ISBN Number to Delete Issued Book : ";
	fflush(stdin);
	for(int i = 0; i < BookNumber; i++) {
		if(strcmp(Temp, ISBNNumber[i]) == 0) {
			if(IssuedBook[i] == 1) {
				cout << "Deleted Issued Book" << endl;
				IssuedBook[i] = 0;
			}
			else {
				cout << "Book Not Issued" << endl;
			}
			Check = 1;
			break;
		}
	}
	if(!Check) {
		cout << "Book Not Found with ISBN Number " << Temp << endl;
	}
}

void DeleteBook() {
	if(BookNumber == 0) {
		cout << "No Books Present in the Library" << endl;
		return;
	}
	int Check = 0;
	char Temp[30];
	int Choice;
	int Temp1;
	cout << "[1] Delete by ISBN Number" << endl
		 << "[2] Delete by Author Name" << endl
		 << "[3] Delete by Book Name" << endl
		 << "[4] Delete by Publisher Name" << endl
		 << "[5] Delete by Publisher Year" << endl << endl
		 << "Enter Choice[1-5]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			cout << "Enter ISBN Number : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 2:
			cout << "Enter Author Name : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 3:
			cout << "Enter Book Name : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 4:
			cout << "Enter Publisher Name : ";
			fflush(stdin);
			cin.getline(Temp, 30);
			break;
		case 5:
			cout << "Enter Publisher Year : ";
			cin >> Temp1;
			break;
		default:
			break;
	}
	cout << "Enter ISBN Number of Book to Delete : ";
	fflush(stdin);
	cin.getline(Temp, 30);
	for(int i = 0; i < BookNumber; i++) {
		if(Choice == 1) {
			if(strcmp(Temp, ISBNNumber[i]) == 0) {
				for(int j = i; j < BookNumber - 1; j++) {
					strcpy(BookName[j], BookName[j + 1]);
					strcpy(ISBNNumber[j], ISBNNumber[j + 1]);
					strcpy(PublisherName[j], PublisherName[j + 1]);
					strcpy(AuthorName[j], AuthorName[j + 1]);
					NumberOfCopies[j] = NumberOfCopies[j + 1];
				}
				--BookNumber;
				cout << "Book Delete with ISBN Number " << Temp << endl;
				Check = 1;
				break;
			}
		}
		else if(Choice == 2) {
			if(strcmp(Temp, AuthorName[i]) == 0) {
				for(int j = i; j < BookNumber - 1; j++) {
					strcpy(BookName[j], BookName[j + 1]);
					strcpy(ISBNNumber[j], ISBNNumber[j + 1]);
					strcpy(PublisherName[j], PublisherName[j + 1]);
					strcpy(AuthorName[j], AuthorName[j + 1]);
					NumberOfCopies[j] = NumberOfCopies[j + 1];
				}
				--BookNumber;
				cout << "Book Delete with Author Name " << Temp << endl;
				Check = 1;
				break;
			}
		}
		else if(Choice == 3) {
			if(strcmp(Temp, BookName[i]) == 0) {
				for(int j = i; j < BookNumber - 1; j++) {
					strcpy(BookName[j], BookName[j + 1]);
					strcpy(ISBNNumber[j], ISBNNumber[j + 1]);
					strcpy(PublisherName[j], PublisherName[j + 1]);
					strcpy(AuthorName[j], AuthorName[j + 1]);
					NumberOfCopies[j] = NumberOfCopies[j + 1];
				}
				--BookNumber;
				cout << "Book Delete with Book Name " << Temp << endl;
				Check = 1;
				break;
			}
		}
		else if(Choice == 4) {
			if(strcmp(Temp, PublisherName[i]) == 0) {
				for(int j = i; j < BookNumber - 1; j++) {
					strcpy(BookName[j], BookName[j + 1]);
					strcpy(ISBNNumber[j], ISBNNumber[j + 1]);
					strcpy(PublisherName[j], PublisherName[j + 1]);
					strcpy(AuthorName[j], AuthorName[j + 1]);
					NumberOfCopies[j] = NumberOfCopies[j + 1];
				}
				--BookNumber;
				cout << "Book Delete with Publisher Name " << Temp << endl;
				Check = 1;
				break;
			}
		}
		else if(Choice == 5) {
			if(Temp1 == PublisherYear[i]) {
				for(int j = i; j < BookNumber - 1; j++) {
					strcpy(BookName[j], BookName[j + 1]);
					strcpy(ISBNNumber[j], ISBNNumber[j + 1]);
					strcpy(PublisherName[j], PublisherName[j + 1]);
					strcpy(AuthorName[j], AuthorName[j + 1]);
					NumberOfCopies[j] = NumberOfCopies[j + 1];
				}
				--BookNumber;
				cout << "Book Delete with Publisher Year " << Temp << endl;
				Check = 1;
				break;
			}
		}
	}
	if(!Check) {
		cout << "Book Not Found with ISBN Number " << Temp << endl;
	}
}

void adduser()
{
	if(usernumber==15)
	{
		cout<<"sorry we don't have more place for any user";
		system("cls");
		return;
	}
	cout<<"enter first name   :   ";
	cin.ignore();
	cin.getline(firstname[usernumber],15);
	cout<<"enter last name   :   ";
    cin.getline(lastname[usernumber],15);
	cout<<"enter whether you are a student or employer   :   ";
	cin.getline(field[usernumber],15);
	cout<<"enter date of birth   :   ";
	cin.getline(dateofbirth[usernumber],15);
    system("cls");
	cout<<"library user was added successfully and your user ID is   :   "<<usernumber<<endl;
	++usernumber;
	return;
}
void edituser() {
	if(usernumber == 0) {
		cout << "there is no user of this library" << endl;
		return;
	}
	char Temp[30];
	int Check = 0;
	cout << "Enter ID of user : ";
	cin.ignore();
	cin.getline(Temp, 30);
	for(int i = 0; i < usernumber; i++) {
		if(strcmp(Temp, id[i]) == 0) {
			EDIT:
			int Choice;
			cout << "What do you Want to Edit" << endl << endl
				 << "[1] first name" << endl
				 << "[2] last name" << endl
				 << "[3] date of birth" << endl
				 << "[4] field" << endl
				 << "Enter Choice[1-4]: ";
			cin >> Choice;
			switch(Choice) {
				case 1:
					cout << "Enter user's first name : ";
					cin.getline(firstname[i], 30);
					goto EDIT;
					break;
				case 2:
					cout << "Enter last name : ";
					cin.getline(lastname[i], 30);
					goto EDIT;
					break;
				case 3:
					cout << "Enter date of birth : ";
					cin.getline(dateofbirth[i], 30);
					goto EDIT;
					break;
				case 4:
					cout << "Enter field : ";
					cin.getline(field[i], 30);
					goto EDIT;
					break;
				default:
					cout << "Invalid Choice" << endl << "Enter Again" << endl << endl;
					getch();
					goto EDIT;
					break;
			}
			Check = 1;
			break;
		}
	}
	if(!Check) {
		cout << "no user found with this ID " << Temp << endl;
	}
}
void deleteuser() {
	if(usernumber == 0) {
		cout << "there is no user of this library" << endl;
		return;
	}
	int Check = 0;
	char Temp[30];
	cout << "Enter ID of user to Delete : ";
	cin.getline(Temp, 30);
	for(int i = 0; i < usernumber; i++) {
		if(strcmp(Temp, id[i]) == 0) {
			for(int j = i; j < usernumber - 1; j++) {
				strcpy(field[j], field[j + 1]);
				strcpy(dateofbirth[j], dateofbirth[j + 1]);
				strcpy(firstname[j], firstname[j + 1]);
				strcpy(lastname[j], lastname[j + 1]);
				strcpy(id[j], id[j + 1]);
			}
			--usernumber;
			cout << "user Deleted with ID  :  " << Temp << endl;
			Check = 1;
			break;
		}
	}
	if(!Check) {
		cout << "no user found with this ID " << Temp << endl;
	}
}