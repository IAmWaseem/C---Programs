/*
#include <iostream>

using namespace std;

class Point {
public:
	Point();
	~Point();
	Point(int);
	Point(int, int);
	void SetValue(int, int);
	void PrintValue();
private:
	int X;
	int Y;
};

Point::Point() {

}

Point::~Point() {
	cout << "Destructor is Executing" << endl;
}


Point::Point(int Coordinates) {
	X = Y = Coordinates;
}

Point::Point(int x, int y) {
	SetValue(x,y);
}

void Point::SetValue(int x, int y) {
	X = x;
	Y = y;
}

void Point::PrintValue() {
	cout << "X = " << X << endl;
	cout << "Y = " << Y << endl;
}

int main() {
	Point Point1;
	Point Point2(2);
	Point Point3(3,4);
	Point1.SetValue(5,6);
	Point1.PrintValue();
	Point2.PrintValue();
	Point3.PrintValue();
	return 0;
}
*/

/*
#include <iostream>
#include <string>

using namespace std;

class CRecord {
public:
	CRecord();
	~CRecord();
	int GetRecord(string,int);
	void PutRecord();
private:
	string Name;
	int ItemNumber;
};

CRecord::CRecord() {

}

CRecord::~CRecord() {

}

int CRecord::GetRecord(string name, int number) {
	if(number == 0) {
		return 1;
	}
	Name = name;
	ItemNumber = number;
	return 0;
}

void CRecord::PutRecord() {
	cout << "Name : " << Name << endl;
	cout << "Item Number : " << ItemNumber << endl;
	cout << endl;
}

int main() {
	CRecord object;
	int Number;
	string Name;
	do {
		cout << "Enter Name : ";
		fflush(stdin);
		getline(cin,Name);
		cout << "Enter Item Number : ";
		cin >> Number;
		if(object.GetRecord(Name,Number)) {
			cout << "Item Number is Zero" << endl;
		}
		else {
			object.PutRecord();
		}
	}
	while(Number != 0);
	return 0;
}
*/

/*
#include <iostream>

using namespace std;

class Rectangle {
public:
	Rectangle();
	void Init();
	double* AccessX();
	double* AccessY();
	~Rectangle();
private:
	double X[4];
	double Y[4];
};

Rectangle::Rectangle() {

}

Rectangle::~Rectangle() {

}

double* Rectangle::AccessX() {
	return X;
}

double* Rectangle::AccessY() {
	return Y;
}

void Rectangle::Init() {
	for(int i = 0; i < 4; i++) {
		cout << "Enter X Coordinate " << i + 1 << " : ";
		cin >> this -> X[i];
	}
	cout << endl;
	for(int i = 0; i < 4; i++) {
		cout << "Enter Y Coordinate " << i + 1 << " : ";
		cin >> this -> Y[i];
	}
}

class RectDrawing {
public:
	RectDrawing();
	void Init(int);
	int HasBeenInitialized(Rectangle*,int);
	void Test(RectDrawing*);
	~RectDrawing();
private:
	Rectangle *Coordinates;
};

RectDrawing::RectDrawing() {

}

RectDrawing::~RectDrawing() {

}

int RectDrawing::HasBeenInitialized(Rectangle* Coords, int i) {
	double *X, *Y;
	double *CurrentX = Coords[i].AccessX();
	double *CurrentY = Coords[i].AccessY();
	if(i == 0) {
		return 0;
	}
	for(int j = 0; j < i; j++) {
		X = Coords[j].AccessX();
		Y = Coords[j].AccessY();
		for(int k = 0; k < 4; k++) {
			if(X[k] != CurrentX[k] || Y[k] != CurrentY[k]) {
				return 0;
			}
		}
	}
	return 1;
}

void RectDrawing::Init(int Size) {
	Coordinates = new Rectangle[Size];
	for(int i = 0; i < Size; i++) {
		cout << "Enter Coordinates for Rectangle " << i + 1 << " : " << endl << endl;
		Coordinates[i].Init();
		if(HasBeenInitialized(Coordinates,i)) {
			cout << "Coordinates are Already Initialized. Enter Again" << endl << endl;
			i--;
		}
	}
}

int main() {
	RectDrawing A;
	int Size;
	cout << "Enter Size of Rectangles : ";
	cin >> Size;
	A.Init(Size);
	return 0;
}
*/

#include <iostream>

using namespace std;

class BankAccount {
public:
	BankAccount();
	void Initialize(char *name, int an, char *actype, int am);
	~BankAccount();
private:
	char *Name;
	int   AccountNumber;
	char *AccountType;
	int   Amount;
};

BankAccount::BankAccount() {

}

void BankAccount::Initialize(char *name, int an, char *actype, int am) {
	int size = 0;
	for(int i = 0; name[i] != NULL; size++, i++);
	size++;
	Name = new char[size];
	size = 0;
	for(int i = 0; actype[i] != NULL; size++, i++);
	size++;
	AccountType = new char[size];
	strcpy(Name, name);
	strcpy(AccountType, actype);
	AccountNumber = an;
	Amount = am;
}

BankAccount::~BankAccount() {
	delete[] Name;
	delete[] AccountType;
}

int main() {
	BankAccount A;
	A.Initialize("Waseem Hassan", 234, "Savings", 20000);
	return 0;
}
