#include <iostream>

using namespace std;

class Person {
	protected:
		char Name[10];
		char Address[10];
		char NIC_No[10];
		int Cell_No;
	public:
		Person(char n[], char a[], char nic[], int cell) {
			strcpy(Name, n);
			strcpy(Address, a);
			strcpy(NIC_No, nic);
			Cell_No = cell;
		}
		void Print() {
			cout << Name << endl << Address << endl << NIC_No << endl << Cell_No << endl << endl;
		}
};

class Employee {
	protected:
		int Emp_No;
		float Basic_Pay;
		float House_Rent;
		float Medical_Allowance;
		float Conveyance_Allowance;
		float Net_Pay;
	public:
		Employee(int no, float pay) {
			Emp_No = no;
			Basic_Pay = pay;
			House_Rent = 0.45 * Basic_Pay;
			Medical_Allowance = 0.05 * Basic_Pay;
			Conveyance_Allowance = 0.10 * Basic_Pay;
			Net_Pay = Basic_Pay + House_Rent + Medical_Allowance + Conveyance_Allowance;
		}
		void Print() {
			cout << Emp_No << endl << Basic_Pay << endl << Net_Pay << endl << endl;
		}
};

class Faculty : public Person, public Employee {
	protected:
		char Designation[10];
		char Department[10];
		char Course[10];
	public:
		Faculty(char n[], char a[], char nic[], int cell, int emp, float pay, char des[], char dep[], char cou[]) : Person(n, a, nic, cell), Employee(emp, pay) {
			strcpy(Designation, des);
			strcpy(Department, dep);
			strcpy(Course, cou);
		}
		void Print() {
			Person::Print();
			Employee::Print();
			cout << Designation << endl << Department << endl << Course << endl << endl;
		}
};

int main() {
	Faculty F("Waseem", "House", "12434", 12345, 1, 234454, "Head", "CS", "Computer");
	F.Print();
	return 0;
}
