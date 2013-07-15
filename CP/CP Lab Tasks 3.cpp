/*
#include <iostream>
#include <conio.h>

using namespace std;

struct PhoneNumber {
	int AreaCode;
	int Exchange;
	int Number;
};

int main() {
	PhoneNumber *Phone;
	int Number;
	cout << "How many Phone Numbers you want to store : ";
	cin >> Number;
	Phone = new PhoneNumber[Number];
	for(int i = 0; i < Number; i++) {
		cout << "Enter AreaCode : ";
		cin >> Phone[i].AreaCode;
		cout << "Enter Exchange Number : ";
		cin >> Phone[i].Exchange;
		cout << "Enter Number : ";
		cin >> Phone[i].Number;
	}
	for(int i = 0; i < Number; i++) {
		cout << "(" << Phone[i].AreaCode << ") " << Phone[i].AreaCode << "-" << Phone[i].Number << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

struct Time {
	int Hours;
	int Minutes;
	int Seconds;
};

int main() {
	Time Time1, Time2;
	cout << "Enter Time 1" << endl;
	cout << "Enter Hours : ";
	cin >> Time1.Hours;
	cout << "Enter Minutes : ";
	cin >> Time1.Minutes;
	cout << "Enter Seconds : ";
	cin >> Time1.Seconds;
	cout << endl;
	cout << "Enter Time 2" << endl;
	cout << "Enter Hours : ";
	cin >> Time2.Hours;
	cout << "Enter Minutes : ";
	cin >> Time2.Minutes;
	cout << "Enter Seconds : ";
	cin >> Time2.Seconds;
	int temp[2];
	temp[0] = (60 * 60 * Time1.Hours) + (60 * Time1.Minutes) + Time1.Seconds;
	temp[1] = (60 * 60 * Time2.Hours) + (60 * Time2.Minutes) + Time2.Seconds;
	temp[0] = temp[0] + temp[1];
	Time NewTime;
	NewTime.Hours = temp[0] / 3600;
	temp[0] %= 3600;
	NewTime.Minutes = temp[0] / 60;
	temp[0] %= 60;
	NewTime.Seconds = temp[0];
	cout << "New Time" << endl;
	cout << "Hours : " << NewTime.Hours << endl << "Minutes : " << NewTime.Minutes << endl << "Seconds : " << NewTime.Seconds;
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

struct Employee {
	char Name[30];
	int Salary;
};

int main() {
	int Size;
	cout << "Enter the Number of Employees : ";
	cin >> Size;
	Employee *Employees;
	Employees = new Employee[Size];
	for(int i = 0; i < Size; i++) {
		cout << "Enter Employee Name : ";
		fflush(stdin);
		cin.getline(Employees[i].Name,30);
		cout << "Enter Salary : ";
		cin >> Employees[i].Salary;
	}
	Employee temp;
	for(int i = 0; i < Size; i++) {
		for(int j = 0; j < Size - i - 1; j++) {
			if(Employees[j].Salary > Employees[j + 1].Salary) {
				temp = Employees[j];
				Employees[j] = Employees[j + 1];
				Employees[j + 1] = temp;
			}
		}
	}
	for(int i = 0; i < Size; i++) {
		cout << "Employee Name : " << Employees[i].Name << endl;
		cout << "Employee Salary : " << Employees[i].Salary << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

struct Employee {
	int Emp_No;
	int Basic_Pay;
	int House_Rent;
	int Medical_Allowance;
	int Conveyence_Allowance;
	int Net_Pay;
};


int main() {
	Employee Emp;
	cout << "Enter Employee Number : ";
	cin >> Emp.Emp_No;
	cout << "Enter Basic Pay : ";
	cin >> Emp.Basic_Pay;
	Emp.House_Rent = (45 * Emp.Basic_Pay) / 100;
	Emp.Medical_Allowance = (5 * Emp.Basic_Pay) / 100;
	Emp.Conveyence_Allowance = (10 * Emp.Basic_Pay) / 100;
	Emp.Net_Pay = Emp.Basic_Pay + Emp.House_Rent + Emp.Medical_Allowance + Emp.Conveyence_Allowance;
	cout << "Basic Pay : " << Emp.Basic_Pay << endl;
	cout << "House Rent : " << Emp.House_Rent << endl;
	cout << "Medical Allowance : " << Emp.Medical_Allowance << endl;
	cout << "Conveyence Allowance : " << Emp.Conveyence_Allowance << endl;
	cout << "Net Pay : " << Emp.Net_Pay << endl;
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

struct Fraction {
	float Numerator;
	float Denominator;
};

int main() {
	Fraction fraction1, fraction2;
	char op;
	cout << "Enter Fraction 1" << endl << endl;
	cout << "Enter Numerator : ";
	cin >> fraction1.Numerator;
	cout << "Enter Denominator : ";
	cin >> fraction1.Denominator;
	cout << endl;
	cout << "Enter Operator : ";
	cin >> op;
	cout << endl;
	cout << "Enter Fraction 2" << endl << endl;
	cout << "Enter Numerator : ";
	cin >> fraction2.Numerator;
	cout << "Enter Denominator : ";
	cin >> fraction2.Denominator;
	Fraction Result;
	switch(op) {
		case '+':
			Result.Numerator = fraction1.Numerator * fraction2.Denominator + fraction1.Denominator * fraction2.Numerator;
			Result.Denominator = fraction1.Denominator * fraction2.Denominator;
			cout << "Result is : " <<  Result.Numerator << "/" << Result.Denominator;
			break;
		case '-':
			Result.Numerator = fraction1.Numerator * fraction2.Denominator - fraction1.Denominator * fraction2.Numerator;
			Result.Denominator = fraction1.Denominator * fraction2.Denominator;
			cout << "Result is : " <<  Result.Numerator << "/" << Result.Denominator;
			break;
		case '*':
			Result.Numerator = fraction1.Numerator * fraction2.Numerator;
			Result.Denominator = fraction1.Denominator * fraction2.Denominator;
			cout << "Result is : " <<  Result.Numerator << "/" << Result.Denominator;
			break;
		case '/':
			Result.Numerator = fraction1.Numerator * fraction2.Denominator;
			Result.Denominator = fraction1.Denominator * fraction2.Numerator;
			cout << "Result is : " <<  Result.Numerator << "/" << Result.Denominator;
			break;
		default:
			cout << "Invalid Choice";
			break;
	}
	getch();
	return 0;
}
*/


#include<iostream>
using namespace std;
void odd_div(int);
int main()
{
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	if(num%2!=0)
		cout<<"please enter an even number\n";
	else
	{
		odd_div(num);
	}}
void odd_div(int num)
{
	if(num % 2 == 0) {
		num = num / 2;
		odd_div(num);
	}
	else {
		cout<<"Largest odd divisor is "<<num;
		cout<<endl;
	}
}
