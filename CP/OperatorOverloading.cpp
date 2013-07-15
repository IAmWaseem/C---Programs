/*
#include <iostream>

using namespace std;

class String {
	public:
		String();
		String(char* N);
		void SetName(char* N);
		char *Name;
		String operator+(String N);
		void operator+=(String N);
		~String();
	private:
		int GetLength(char* N);
};

String::String() {

}

String::String(char* N) {
	SetName(N);
}

void String::SetName(char* N) {
	int i;
	for(i = 0; N[i] != NULL; i++);
	Name = new char[i + 1];
	strcpy(Name,N);
}

int String::GetLength(char* N) {
	int  i;
	for(i = 0; N[i] != NULL; i++);
	i++;
	return i;
}

void String::operator+=(String N) {
	int Size = GetLength(Name);
	char *Temp = new char[Size];
	strcpy(Temp, Name);
	Size += GetLength(N.Name) - 1;
	delete[] Name;
	Name = new char[Size];
	strcpy(Name, Temp);
	strcat(Name, N.Name);
	return;
}

String String::operator+(String N) {
	String New;
	int Count = GetLength(Name);
	Count += GetLength(N.Name) - 1;
	char* Temp;
	Temp = new char[Count];
	strcpy(Temp,Name);
	strcat(Temp,N.Name);
	New.SetName(Temp);
	return New;
}

String::~String() {
	//delete[] Name;
}

int main() {
	String Name1("Waseem Hassan");
	String Name2("Wajeeh Hassan");
	String Name3;
	String Name4("This is Sentence 1");
	String Name5("This is Sentence 2");
	Name3 = Name1 + Name2;
	cout << "Name1 = " << Name1.Name << endl;
	cout << "Name2 = " << Name2.Name << endl;
	cout << "Name3 = " << Name3.Name << endl;
	cout << "Name4 = " << Name4.Name << endl;
	cout << "Name5 = " << Name5.Name << endl;
	cout << "Executing Name4 += Name5" << endl;
	Name4 += Name5;
	cout << "Name4 = " << Name4.Name << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream myFile("Wajeeh.txt");
	string Name;
	char Section;
	int RollNumber;
	while(cin >> Name >> Section >> RollNumber) {
		myFile << RollNumber << ' ' << Name << ' ' << Section << '\n';
	}
	return 0;
}
*/

#include <iostream>

using namespace std;

class Test {
public:
	Test(int a, int b) : a(a), c(b) {
		count++;
	}
	void TestconstFunctioN() const;
	void NormalFunction();
	static int GetCount() {
		return count;
	}
private:
	static int count;
	int a;
	const int c;
};

int Test::count = 0;

void Test::TestconstFunctioN() const {
	cout << "This is a const Function" << endl;
}

void Test::NormalFunction() {
	cout << "This is a Normal Function" << endl;
}


int main() {
	Test nObj(2,3);
	const Test cObj(1,2);
	Test A(1,1),B(1,1),C(1,1),D(1,1);
	cObj.TestconstFunctioN();
	nObj.NormalFunction();
	nObj.TestconstFunctioN();
	cout << "Number of Variables Created : " << Test::GetCount();
	return 0;
}
