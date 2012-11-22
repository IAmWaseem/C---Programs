#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main() {
	string Name, FatherName, NIC, Gender, ContactNo, HouseAddress;
	cout << "Enter Your Name : ";
	getline(cin,Name);
	cout << "Enter Your Father's Name : ";
	getline(cin,FatherName);
	cout << "Enter Your NIC Number : ";
	getline(cin,NIC);
	cout << "Enter Your Gender : ";
	getline(cin,Gender);
	cout << "Enter Your Contact Number : ";
	getline(cin,ContactNo);
	cout << "Enter Your House Address : ";
	getline(cin,HouseAddress);
	cout << endl << endl;
	cout << "Name : " << Name << endl;
	cout << "Father's Name : " << FatherName << endl;
	cout << "NIC Number : " << NIC << endl;
	cout << "Gender : " << Gender << endl;
	cout << "Contact Number : " << ContactNo << endl;
	cout << "House Address : " << HouseAddress << endl;
	getch();
	return 0;
}