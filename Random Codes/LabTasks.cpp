/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char ch;
	cout << "Enter any Character : ";
	cin >> ch;
	cout << "The ASCII code for Character " << ch << " : " << static_cast<int>(ch) << endl;
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int a=1;
	char b='A';
	float c=2.3;
	double d=2.4;
	cout << "The Size of Integer variable a : " << sizeof(a) << endl;
	cout << "The Size of Character variable b : " << sizeof(b) << endl;
	cout << "The Size of Floating variable c : " << sizeof(c) << endl;
	cout << "The Size of Double variable d : " << sizeof(d) << endl;
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int age1,age2;
	cout << "Enter Age of 1st Person : ";
	cin >> age1;
	cout << "Enter Age of 2nd Person : ";
	cin >> age2;
	if(age1>age2) {
		cout << "Greater Age : " << age1 << endl;
	}
	else {
		cout << "Greater Age : " << age2 << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int age1,age2;
	cout << "Enter Age of 1st Person : ";
	cin >> age1;
	cout << "Enter Age of 2nd Person : ";
	cin >> age2;
	cout << "Greater Age : " << ((age1>age2)?age1:age2);
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	float marks;
	cout << "Enter Marks of Student : ";
	cin >> marks;
	if(marks==10) {
		cout << "Grade is 'A'" << endl;
	}
	else if(marks<10 && marks>=8) {
		cout << "Grade is 'B'";
	}
	else if(marks<8 && marks>=6) {
		cout << "Grade is 'C'";
	}
	else if(marks<6 && marks>=5) {
		cout << "Grade is 'D'";
	}
	else if(marks<5 && marks>=0) {
		cout << "Grade is 'F'";
	}
	else {
		cout << "Invalid Marks Entered";
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char grade;
	cout << "Enter Grade : ";
	cin >> grade;
	if(grade=='a' || grade=='A') {
		cout << "Marks = 10";
	}
	else if(grade=='b' || grade=='B') {
		cout << "Marks = 8";
	}
	else if(grade=='c' || grade=='C') {
		cout << "Marks = 6";
	}
	else if(grade=='d' || grade=='D') {
		cout << "Marks = 5";
	}
	else if(grade=='f' || grade=='F') {
		cout << "Marks = 0";
	}
	else {
		cout << "Wrong Grade Entered";
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int tcd,charges,check=1;
	cout << "Please Enter Total Call Duration in Minutes: ";
	cin >> tcd;
	if(tcd>0 && tcd<=2) {
		charges=12;
	}
	if(tcd>2 && tcd<=5) {
		charges=10;
	}
	if(tcd>5 && tcd<=8) {
		charges=7;
	}
	if(tcd>8 && tcd<=10) {
		charges=5;
	}
	if(tcd>10) {
		charges=3;
	}
	if(tcd<=0) {
		cout << "Wrong Value Entered";
		check=0;
	}
	if(check==1) {
		cout << "Total Call Duration is: " << tcd << endl;
		cout << "Tocal Call Charges are: " << tcd*charges << "Pkr." << endl;
	}
	getch();
	return  0;
}
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char alphabet;
	cout << "Enter any Alphabet : ";
	cin >> alphabet;
	if(alphabet>=65 && alphabet<=90) {
		cout << "Alphabet is Capital" << endl;
		cout << "Alphabet before Conversion : " << alphabet << endl;
		alphabet = alphabet+32;
		cout << "Alphabet After Conversion : " << alphabet << endl;
	}
	else if(alphabet>=97 && alphabet<=122) {
		cout << "Alphabet is Small" << endl;
		cout << "Alphabet before Conversion : " << alphabet << endl;
		alphabet = alphabet-32;
		cout << "Alphabet After Conversion : " << alphabet << endl;
	}
	else {
		cout << "This is not an alphabet" << endl;
	}
	getch();
	return 0;
}