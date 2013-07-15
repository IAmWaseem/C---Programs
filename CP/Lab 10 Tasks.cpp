/*
#include <iostream>
#include <string>

using namespace std;

class StudentInfo {
	public:
		void InputInformation();
		void PrintInformation();
	private:
		int RegistrationNumber;
		string Name;
		string Address;
};

void StudentInfo::InputInformation() {
	cout << "Enter Registration Number : ";
	cin >> this -> RegistrationNumber;
	cout << "Enter Name : ";
	fflush(stdin);
	getline(cin, this -> Name);
	cout << "Enter Address : ";
	fflush(stdin);
	getline(cin, this -> Address);
	return;
}

void StudentInfo::PrintInformation() {
	cout << "Registration Number : " << this -> RegistrationNumber << endl
		 << "Name : " << this -> Name << endl
		 << "Address : " << this -> Address << endl;
	return;
}

class StudentResult : public StudentInfo {
	public:
		void InputMarks();
		void PrintMarks();
	private:
		float Subject1;
		float Subject2;
		float Subject3;
		float Average;
		float Total;
};

void StudentResult::InputMarks() {
	cout << "Enter Marks in Subject 1 : ";
	cin >> this -> Subject1;
	cout << "Enter Marks in Subject 2 : ";
	cin >> this -> Subject2;
	cout << "Enter Marks in Subject 3 : ";
	cin >> this -> Subject3;
	this -> Total = this -> Subject1 + this -> Subject2 + this -> Subject3;
	this -> Average = this -> Total / 3;
	return;
}

void StudentResult::PrintMarks() {
	cout << "Marks in Subject 1 : " << this -> Subject1 << endl
		 << "Marks in Subject 2 : " << this -> Subject2 << endl
		 << "Marks in Subject 3 : " << this -> Subject3 << endl
		 << "Total Marks : " << this -> Total << endl
		 << "Average Marks : " << this -> Average << endl;
	return;
}

int main() {
	StudentResult sObj;
	sObj.InputInformation();
	sObj.InputMarks();
	sObj.PrintInformation();
	sObj.PrintMarks();
	return 0;
}
*/

#include <iostream>

using namespace std;

class Point {
	public:
		Point(int = 0, int = 0);
		void setPoint(int, int);
		void getPoint(int&, int&);
		void Print();
	protected:
		int X;
		int Y;
};

Point::Point(int a, int b) {
	X = a; Y = b;
}

void Point::setPoint(int x, int y) {
	X = x, Y = y;
}

void Point::getPoint(int& x, int& y) {
	x = X; y = Y;
}

void Point::Print() {
	cout << "X : " << X << endl
		 << "Y : " << Y << endl;
	return;
}

class Circle : public Point {
	public:

	protected:

};

int main() {
	Point A(2,2);
	return 0;
}