#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char choice;
	cout << "[V] Visitor" << endl;
	cout << "[U] University" << endl << endl;
	cout << "Enter Choice: ";
	cin >> choice;
	if(choice=='V'||choice=='v') {
		cout << "[M] Male" << endl;
		cout << "[F] Female" << endl << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		if(choice=='M'||choice=='m') {
			cout << "You are a Male Visitor" << endl;
		}
		else if(choice=='F'||choice=='f') {
			cout << "You are a Female Visitor" << endl;
		}
		else {
			cout << "Invalid Choice Entered" << endl;
		}
	}
	else if(choice=='U'||choice=='u') {
		cout << "[S] Student" << endl;
		cout << "[F] Faculty" << endl;
		cout << "[T] Staff" << endl << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		if(choice=='S'||choice=='s') {
			cout << "[M] Male" << endl;
			cout << "[F] Female" << endl << endl;
			cout << "Enter Coice: ";
			cin >> choice;
			if(choice=='M'||choice=='m') {
				cout << "[G] Graduate" << endl;
				cout << "[M] Masters" << endl << endl;
				cout << "Enter Choice: ";
				cin >> choice;
				if(choice=='G'||choice=='g') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Male Student doing Graduate in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Male Student doing Graduate in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Male Student doing Graduate in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else if(choice=='M'||choice=='m') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Male Student doing Masters in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Male Student doing Masters in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Male Student doing Masters in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else {
					cout << "Invalid Choice Entered" << endl;
				}
			}
			else if(choice=='F'||choice=='f') {
				cout << "[G] Graduate" << endl;
				cout << "[M] Masters" << endl << endl;
				cout << "Enter Choice: ";
				cin >> choice;
				if(choice=='G'||choice=='g') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Female Student doing Graduate in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Female Student doing Graduate in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Female Student doing Graduate in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else if(choice=='M'||choice=='m') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Female Student doing Masters in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Female Student doing Masters in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Female Student doing Masters in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else {
					cout << "Invalid Choice Entered" << endl;
				}
			}
			else {
				cout << "Invalid Choice Entered" << endl;
			}
		}
		else if(choice=='F'||choice=='f') {
			cout << "[V] Visiting" << endl;
			cout << "[P] Permanent" << endl << endl;
			cout << "Enter Choice: ";
			cin >> choice;
			if(choice=='V'||choice=='v') {
				cout << "[M] Male" << endl;
				cout << "[F] Female" << endl << endl;
				cout << "Enter Choice: ";
				cin >> choice;
				if(choice=='M'||choice=='m') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Male Visiting Faculty teaching in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Male Visiting Faculty teaching in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Male Visiting Faculty teaching in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else if(choice=='F'||choice=='f') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Female Visiting Faculty Teaching in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Female Visiting Faculty Teaching in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Female Visiting Faculty Teaching in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else {
					cout << "Invalid Choice Entered" << endl;
				}
			}
			else if(choice=='P'||choice=='p') {
				cout << "[M] Male" << endl;
				cout << "[F] Female" << endl << endl;
				cout << "Enter Choice: ";
				cin >> choice;
				if(choice=='M'||choice=='m') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Male Permanent Faculty teaching in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Male Permanent Faculty teaching in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Male Permanent Faculty teaching in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else if(choice=='F'||choice=='f') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Female Permanent Faculty Teaching in Computer Science" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Female Permanent Faculty Teaching in Electrical Engineering" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Female Permanent Faculty Teaching in Business Administration" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else {
					cout << "Invalid Choice Entered" << endl;
				}
			}
			else {
				cout << "Invalid Choice Entered" << endl;
			}
		}
		else if(choice=='T'||choice=='t') {
			cout << "[M] Maintenance" << endl;
			cout << "[A] Administration" << endl;
			cout << "[C] Accounts" << endl;
			cout << "[D] Academics" << endl << endl;
			cin >> choice;
			if(choice=='M'||choice=='m') {
				cout << "You are a Maintenance Staff Member" << endl;
			}
			else if(choice=='A'||choice=='a') {
				cout << "You are an Administration Staff Member" << endl;
			}
			else if(choice=='C'||choice=='c') {
				cout << "You are an Accounts Staff Member" << endl;
			}
			else if(choice=='D'||choice=='d') {
				cout << "[C] Central" << endl;
				cout << "[A] Department Academics" << endl << endl;
				cout << "Enter Choice: ";
				cin >> choice;
				if(choice=='C'||choice=='c') {
					cout << "You are a Staff Member of Central Academics" << endl;
				}
				else if(choice=='A'||choice=='a') {
					cout << "[C] Computer Science" << endl;
					cout << "[E] Electrical Engineering" << endl;
					cout << "[B] Business Administration" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					if(choice=='C'||choice=='c') {
						cout << "You are a Staff Member of Computer Science Academics" << endl;
					}
					else if(choice=='E'||choice=='e') {
						cout << "You are a Staff Member of Electrical Engineering Academics" << endl;
					}
					else if(choice=='B'||choice=='b') {
						cout << "You are a Staff Member of Business Administration Academics" << endl;
					}
					else {
						cout << "Invalid Choice Entered" << endl;
					}
				}
				else {
					cout << "Invalid Choice Entered" << endl;
				}
			}
			else {
				cout << "Invalid Choice Entered" << endl;
			}
		}
		else {
			cout << "Invalid Choice Entered" << endl;
		}
	}
	else {
		cout << "Invalid Choice Entered" << endl;
	}
	getch();
	return 0;
}