#include <iostream>
#include <conio.h>

using  namespace std;

int main() {
	int choice,roomno;
	cout << "What Room do you want?" << endl << endl;
	cout << "[1] Superior Room" << endl;
	cout << "[2] Deluxe Room" << endl;
	cout << "[3] Executive Room" << endl;
	cout << "[4] Corner Suite" << endl << endl;
	cout << "Enter Choice[1-4]: ";
	cin >> choice;
	if(choice==1) {
		cout << "Superior Rooms Selected" << endl << endl;
		cout << "1-30 Rooms Available" << endl;
		cout << "Enter Room Number[1-30]: ";
		cin >> roomno;
		if(roomno<=30 && roomno>=1) {
			cout << "Room # " << roomno << " of Superior Room is Allocated" << endl;
		}
		else {
			cout << "Wrong Room Number Entered" << endl;
		}
	}
	else if(choice==2) {
		cout << "Deluxe Rooms Selected" << endl << endl;
		cout << "31-50 Rooms Available" << endl;
		cout << "Enter Room Number[31-50]: ";
		cin >> roomno;
		if(roomno<=50 && roomno>=31) {
			cout << "Room # " << roomno << " of Superior Room is Allocated" << endl;
		}
		else {
			cout << "Wrong Room Number Entered" << endl;
		}
	}
	else if(choice==3) {
		cout << "Executive Rooms Selected" << endl << endl;
		cout << "51-60 Rooms Available" << endl;
		cout << "Enter Room Number[51-60]: ";
		cin >> roomno;
		if(roomno<=60 && roomno>=51) {
			cout << "Room # " << roomno << " of Superior Room is Allocated" << endl;
		}
		else {
			cout << "Wrong Room Number Entered" << endl;
		}
	}
	else if(choice==4) {
		cout << "Corner Suite Selected" << endl << endl;
		cout << "61-65 Rooms Available" << endl;
		cout << "Enter Room Number[61-65]: ";
		cin >> roomno;
		if(roomno<=65 && roomno>=61) {
			cout << "Room # " << roomno << " of Superior Room is Allocated" << endl;
		}
		else {
			cout << "Wrong Room Number Entered" << endl;
		}
	}
	else {
		cout << "Invalid Choice Entered" << endl;
	}
	getch();
	return 0;
}