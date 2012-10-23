#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int choice,roomno;
	char ch=' ';
	cout << "What Room do you want?" << endl << endl;
	cout << "[1] Superior Room" << endl;
	cout << "[2] Deluxe Room" << endl;
	cout << "[3] Executive Room" << endl;
	cout << "[4] Corner Suite" << endl << endl;
	cout << "Enter Choice[1-4]: ";
	cin >> choice;
	cout << (choice==1?"Enter Room No[1-30]: ":(choice==2?"Enter Room No[31-50]: ":(choice==3?"Enter Room No[51-60]: ":(choice==4?"Enter Room No[61-65]: ":"Invalid Choice Entered"))));
	cin >> roomno;
	cout << ((roomno>=1&&roomno<=30&&choice==1)?"Room Allocated : ":((roomno>=31&&roomno<=50&&choice==2)?"Room Allocated : ":((roomno>=51&&roomno<=60&&choice==3)?"Room Allocated : ":((roomno>=61&&roomno<=65&&choice==4)?"Room Allocated : ":"Invalid Room Entered"))));
	cout << (((roomno>=1&&roomno<=30&&choice==1)||(roomno>=31&&roomno<=50&&choice==2)||(roomno>=51&&roomno<=60&&choice==3)||(roomno>=61&&roomno<=65&&choice==4))?roomno:ch);
	getch();
	return 0;
}