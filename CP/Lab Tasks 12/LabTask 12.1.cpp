#include <iostream>

using namespace std;

class Student_Info {
	private:
		int Reg_Number;
		char Name[15];
		char Address[50];
	public:
		Student_Info(int reg, char name[], char address[]);
		virtual void Input_Info() = 0;
		virtual void Print_Info() = 0;
		void Print() {
			cout << "Reg : " << Reg_Number << endl
				 << "Name : " << Name << endl
				 << "Address : " << Address << endl;
		}
};

Student_Info::Student_Info(int reg, char name[], char address[]) {
	Reg_Number = reg;
	strcpy(Name, name);
	strcpy(Address, address);
}

class Student_Result : public Student_Info {
	private:
		float Sub1;
		float Sub2;
		float Sub3;
		float Average;
		float Total;
	public:
		Student_Result(int reg, char name[], char address[]) : Student_Info(reg, name, address) {
		
		}
		void Input_Info() {
			cout << "Enter Marks 1: ";
			cin >> Sub1;
			cout << "Enter Marks 2: ";
			cin >> Sub2;
			cout << "Enter Marks 3: ";
			cin >> Sub3;
			Total = Sub1 + Sub2 + Sub3;
			Average = Total / 3;
		}
		void Print_Info() {
			cout << "Marks 1 : " << Sub1 << endl
				 << "Marks 2 : " << Sub2 << endl
				 << "Marks 3 : " << Sub3 << endl
				 << "Total : " << Total << endl
				 << "Average : " << Average << endl;
		}
};

int main() {
	Student_Info *ptr;
	Student_Result res(23, "Waseem", "House 14");
	ptr = &res;
	ptr -> Input_Info();
	ptr -> Print_Info();
	ptr ->Print();
	return 0;
}