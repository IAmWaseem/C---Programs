/*
#include <iostream>

using namespace std;

class String {
	public:
		String();
		String(char* N);
		void SetValue(char* N);
		char *Name;
		String operator+(String N);
};

String::String() {

}

String::String(char* N) {
	SetValue(N);
}

void String::SetValue(char* N) {
	int i;
	for(i = 0; N[i] != NULL; i++);
	Name = new char[i + 1];
	strcpy(Name,N);
}

String String::operator+(String N) {
	String New;
	int i;
	for(i = 0; Name[i] != NULL; i++);
	int Count = i;
	for(i = 0; N.Name[i]; i++);
	Count += i + 1;
	char* Temp;
	Temp = new char[Count];
	strcpy(Temp,Name);
	strcat(Temp,N.Name);
	New.SetValue(Temp);
	return New;
}

int main() {
	String Name1("Waseem Hassan");
	String Name2("Ifrah Nazli");
	String Name3;
	Name3 = Name1 + Name2;
	cout << "Name1 = " << Name1.Name << endl;
	cout << "Name2 = " << Name2.Name << endl;
	cout << "Name3 = " << Name3.Name << endl;
	return 0;
}
*/

/*
#include <iostream>

using namespace std;

template <class T>

class Waseem {
	T First;
	T Second;
	public:
		Waseem(T a, T b) {
			First = a; Second = b;
		}
		T Bigger();
		T Smaller();
};

template <class T>
T Waseem<T>::Bigger() {
	return (First > Second ? First : Second);
}

template <class T>
T Waseem<T>::Smaller() {
	return (First < Second ? First : Second);
}

int main() {
	Waseem<int> A(2,3);
	cout << A.Bigger() << endl;
	cout << A.Smaller() << endl;
	return 0;
}
*/

/*
#include <iostream>

using namespace std;

template <class T>

class Spunky {
	public:
		Spunky(T x) {
			cout << x << " is not a character" << endl;
		}
};

template <>						// Template Specialization
class Spunky<char> {
	public:
		Spunky(char x) {
			cout << x << " is a character" << endl;
		}
};

int main() {
	Spunky<int> Obj1(7);
	Spunky<double> Obj2(5.435);
	Spunky<char> Obj3('Q');
	return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main() {
	try {
		int momsage = 59, sonsage = 34;
		if(sonsage > momsage) {
			throw 99;
		}
	}
	catch(int x) {
		cout << "Son Cannot be Older than MOM" << endl << "Error Code : " << x << endl;
	}
	return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main() {
	try {
		int num1;
		cout << "Enter Number 1 : ";
		cin >> num1;
		int num2;
		cout << "Enter Number 2 : ";
		cin >> num2;
		if(num2 == 0) {
			throw 0;
		}
		cout << num1 / num2 << endl;
	}
	catch(...) {
		cout << "Divide by Zero Exception" << endl;
	}
	return 0;
}
*/

/*
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream myFile;
	myFile.open("Waseem.txt");
	myFile << "This is some text!\n";
	myFile.close();
	return 0;
}
*/

/*
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream myFile("Test.txt");
	myFile << "I hate myself!\n";
	if(myFile.is_open()) {
		cout << "File is Opened" << endl;
	}
	else {
		cout << "File not Opened" << endl;
	}

	myFile.close();
	return 0;
}
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream myFile("Players.txt");
	cout << "Enter Player's ID, Name, and Money" << endl;
	cout << "Press Ctrl + Z to Quit" << endl;
	int ID;
	string Name;
	double Money;
	while( cin >> ID >> Name >> Money) {
		myFile << ID << ' ' << Name << ' ' << Money << endl;
	}

	return 0;
}
