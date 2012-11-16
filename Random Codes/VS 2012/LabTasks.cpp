/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int i=0,sum=0;
	while(i<=50) {
		sum=sum+i;
		i++;
	}
	cout << "SUM of Numbers from 0 to 50 is " << sum << endl;
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int start,end,sumeven=0,sumodd=0;
	cout << "Enter Starting Point : ";
	cin >> start;
	cout << "Enter Ending Point : ";
	cin >> end;
	while(start<=end) {
		if(start%2==0) {
			sumeven=sumeven+start;
		}
		else {
			sumodd=sumodd+start;
		}
		start++;
	}
	cout << "SUM of Even Numbers : " << sumeven << endl;
	cout << "SUM of Odd Numbers : " << sumodd << endl;
	getch();
	return 0;
}
*/

/*
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
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int choice,roomno,check=0;
	cout << "What Room do you want?" << endl << endl;
	cout << "[1] Superior Room" << endl;
	cout << "[2] Deluxe Room" << endl;
	cout << "[3] Executive Room" << endl;
	cout << "[4] Corner Suite" << endl << endl;
	cout << "Enter Choice[1-4]: ";
	cin >> choice;
	switch(choice) {
		case 1: {
			cout << "Superior Rooms Selected" << endl << endl;
			cout << "1-30 Rooms Available" << endl;
			cout << "Enter Room Number[1-30]: ";
			cin >> roomno;
			if(roomno<=30 && roomno>=1) {
				check=1;
			}
			switch(check) {
				case 1: {
					cout << "Room # " << roomno << " of Superior Room is Allocated" << endl;
					break;
				}
				default: {
					cout << "Wrong Room Number Entered" << endl;
				}
			}
			break;
		}
		case 2: {
			cout << "Deluxe Rooms Selected" << endl << endl;
			cout << "31-50 Rooms Available" << endl;
			cout << "Enter Room Number[31-50]: ";
			cin >> roomno;
			if(roomno<=50 && roomno>=31) {
				check=1;
			}
			switch(check) {
				case 1: {
					cout << "Room # " << roomno << " of Superior Room is Allocated" << endl;
				}
				default: {
					cout << "Wrong Room Number Entered" << endl;
				}
			}
			break;
		}
		case 3: {
			cout << "Executive Rooms Selected" << endl << endl;
			cout << "51-60 Rooms Available" << endl;
			cout << "Enter Room Number[51-60]: ";
			cin >> roomno;
			if(roomno<=60 && roomno>=51) {
				check=1;
			}
			switch(check) {
				case 1: {
					check=1;
				}
				default: {
					cout << "Wrong Room Number Entered" << endl;
				}
			}
			break;
		}
		case 4: {
			cout << "Corner Suite Selected" << endl << endl;
			cout << "61-65 Rooms Available" << endl;
			cout << "Enter Room Number[61-65]: ";
			cin >> roomno;
			if(roomno<=65 && roomno>=61) {
				 check=1;
			}
			switch(check) {
				case 1: {
					cout << "Room # " << roomno << " of Superior Room is Allocated" << endl;
				}
				default: {
					cout << "Wrong Room Number Entered" << endl;
				}
			}
			break;
		}
		default: {
			cout << "Invalid Choice Entered" << endl;
		}
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
*/

/*
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
	float range,transformation;
	int check=1;
	cout << "Enter Floating Point Value : ";
	cin >> range;
	if(range>=2.2&&range<=5.7) {
		transformation=pow(range,2)-3*range-4;
	}
	else if(range>=0.2&&range<=1.9) {
		transformation=pow(range,2)-4*range+5;
	}
	else if(range>=7.43&&range<=10.3) {
		transformation=pow((range+4),2);
	}
	else if(range>=11.0&&range<=13.0) {
		transformation=pow(range,2);
	}
	else {
		cout << "Wrong Value Entered" << endl;
		check=0;
	}
	if(check) {
		cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
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
	float range,transformation;
	int check;
	cout << "Enter Floating Point Value : ";
	cin >> range;
	if(range>=2.2&&range<=5.7) {
		check=1;
	}
	else if(range>=0.2&&range<=1.9) {
		check=2;
	}
	else if(range>=7.43&&range<=10.3) {
		check=3;
	}
	else if(range>=11.0&&range<=13.0) {
		check=4;
	}
	else {
		check=0;
	}
	switch(check) {
		case 1: {
			transformation=pow(range,2)-3*range-4;
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		case 2: {
			transformation=pow(range,2)-4*range+5;
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		case 3: {
			transformation=pow((range+4),2);
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		case 4: {
			transformation=pow(range,2);
			cout << "The Result of the Transformation Function with input Value " << range << " is " << transformation << endl;
			break;
		}
		default: {
			cout << "Wrong Value Entered" << endl;
		}
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main() {
	float range,transformation;
	int check;
	char ch=' ';
	cout << "Enter Floating Point Value : ";
	cin >> range;
	transformation = ((range<=5.7&&range>=2.2)?pow(range,2)-3*range-4:(range<=1.9&&range>=0.2)?pow(range,2)-4*range+5:(range<=10.3&&range>=7.43)?pow((range+4),2):(range<=13.0&&range>=11.0)?pow(range,2):-500);
	cout << (((range<=5.7&&range>=2.2)||(range<=1.9&&range>=0.2)||(range<=10.3&&range>=7.43)||(range<=13.0&&range>=11.0))?"Result of Transformation Value : ":"Invalid Value Entered");
	cout << ((transformation!=-500)?transformation:ch);
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int i=1,sumeven=0,sumodd=0;
	while(i<=100) {
		if(i%2==0) {
			sumeven=sumeven+i;
		}
		else {
			sumodd=sumodd+i;
		}
		i++;
	}
	cout << "Sum of Even Values is: " << sumeven << endl;
	cout << "Sum of Odd Values is: " << sumodd << endl;
	getch();
	return 0;
}
*/


#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int i=0,sum=0;
	while(i<=100) {
		cout << i << endl;
		sum=sum+i;
		i++;
	}
	cout << "SUM : " << sum;
	getch();
	return 0;
}