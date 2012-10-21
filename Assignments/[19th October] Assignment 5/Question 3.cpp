#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	char choice;
	cout << setw(45) << "Choose Region" << endl << endl;
	cout << "[A] Asia" << endl;
	cout << "[E] Europe" << endl << endl;
	cout << "Enter Choice: ";
	cin >> choice;
	cout << endl;
	switch(choice) {
		case 'A':
		case 'a': {
			cout << setw(45) << "ASIA Selected" << endl;
			cout << setw(45) << "Choose Country" << endl << endl;
			cout << "[P] Pakistan" << endl;
			cout << "[I] India" << endl;
			cout << "[B] Bangladesh" << endl;
			cout << "[S] Srilanka" << endl << endl;
			cout << "Enter Choice: ";
			cin >> choice;
			cout << endl;
			switch(choice) {
				case 'P':
				case 'p': {
					cout << setw(46) << "PAKISTAN Selected" << endl << endl;
					cout << "What is the Capital of Pakistan?" << endl << endl;
					cout << "[I] Islamabad" << endl;
					cout << "[L] Lahore" << endl;
					cout << "[K] Karachi" << endl;
					cout << "[P] Peshawar" << endl;
					cout << "[R] Rawalpindi" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'I':
						case 'i': {
							cout << "You are right, Islamabad is the Capital of Pakistan" << endl;
							break;
						}
						case 'L':
						case 'l':
						case 'K':
						case 'k':
						case 'P':
						case 'p':
						case 'R':
						case 'r': {
							  cout << "You are Wrong" << endl;
							  break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				case 'I':
				case 'i': {
					cout << setw(45) << "INDIA Selected" << endl << endl;
					cout << "What is the Capital of India?" << endl << endl;
					cout << "[M] Mumbai" << endl;
					cout << "[B] Bangalore" << endl;
					cout << "[H] Hyderabad" << endl;
					cout << "[N] New Delhi" << endl;
					cout << "[A] Ahmedabad" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'N':
						case 'n': {
							cout << "You are right, New Delhi is the Capital of India" << endl;
							break;
						}
						case 'M':
						case 'm':
						case 'B':
						case 'b':
						case 'H':
						case 'h':
						case 'A':
						case 'a': {
							cout << "You are Wrong" << endl;
							break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				case 'B':
				case 'b': {
					cout << setw(48) << "BANGLADESH Selected" << endl << endl;
					cout << "What is the Capital of Bangladesh?" << endl << endl;
					cout << "[C] Chittagong" << endl;
					cout << "[K] Khulna" << endl;
					cout << "[D] Dhaka" << endl;
					cout << "[S] Sylhet" << endl;
					cout << "[N] Narayanganj" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'D':
						case 'd': {
							cout << "You are right, Dhaka is the Capital of Bangladesh" << endl;
							break;
						}
						case 'C':
						case 'c':
						case 'K':
						case 'k':
						case 'S':
						case 's':
						case 'N':
						case 'n': {
							cout << "You are Wrong" << endl;
							break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				case 'S':
				case 's': {
					cout << setw(46) << "SRILANKA Selected" << endl << endl;
					cout << "What is the Capital of Srilanka?" << endl << endl;
					cout << "[C] Colombo" << endl;
					cout << "[K] Kotte" << endl;
					cout << "[M] Moratuwa" << endl;
					cout << "[N] Negombo" << endl;
					cout << "[V] Vavuniya" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'K':
						case 'k': {
							cout << "You are right, Kotte is the Capital of Srilanka" << endl;
							break;
						}
						case 'C':
						case 'c':
						case 'M':
						case 'm':
						case 'N':
						case 'n':
						case 'V':
						case 'v': {
							cout << "You are Wrong" << endl;
							break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				default: {
					cout << "Invalid Choice Entered" << endl;
				}
			}
			break;
		}
		case 'E':
		case 'e': {
			cout << setw(45) << "EUROPE Selected" << endl;
			cout << setw(44) << "Choose Country" << endl << endl;
			cout << "[A] Austria" << endl;
			cout << "[L] Finland" << endl;
			cout << "[F] France" << endl;
			cout << "[G] Germany" << endl << endl;
			cout << "Enter Choice: ";
			cin >> choice;
			switch(choice) {
				case 'A':
				case 'a': {
					cout << setw(45) << "AUSTRIA Selected" << endl << endl;
					cout << "What is the Capital of Austria?" << endl << endl;
					cout << "[G] Graz" << endl;
					cout << "[L] Linz" << endl;
					cout << "[S] Salzburg" << endl;
					cout << "[P] Sankt Polten" << endl;
					cout << "[V] Vienna" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'V':
						case 'v': {
							cout << "You are right, Vienna is the Capital of Austria" << endl;
							break;
						}
						case 'G':
						case 'g':
						case 'L':
						case 'l':
						case 'S':
						case 's':
						case 'P':
						case 'p': {
							cout << "You are Wrong" << endl;
							break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				case 'L':
				case 'l': {
					cout << setw(46) << "FINLAND Selected" << endl << endl;
					cout << "What is the Capital of Finland?" << endl << endl;
					cout << "[H] Helsinki" << endl;
					cout << "[A] Akaa" << endl;
					cout << "[E] Espoo" << endl;
					cout << "[I] Imatra" << endl;
					cout << "[J] Joutseno" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'H':
						case 'h': {
							cout << "You are right, Helsinki is the Capital of Finland" << endl;
							break;
						}
						case 'A':
						case 'a':
						case 'E':
						case 'e':
						case 'I':
						case 'i':
						case 'J':
						case 'j': {
							cout << "You are Wrong" << endl;
							break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				case 'F':
				case 'f': {
					cout << setw(45) << "FRANCE Selected" << endl << endl;
					cout << "What is the Capital of France?" << endl << endl;
					cout << "[M] Marseille" << endl;
					cout << "[R] Reims " << endl;
					cout << "[L] Lille" << endl;
					cout << "[P] Paris" << endl;
					cout << "[S] Saint-Etienne" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'P':
						case 'p': {
							cout << "You are right, Paris is the Capital of France" << endl;
							break;
						}
						case 'M':
						case 'm':
						case 'R':
						case 'r':
						case 'L':
						case 'l':
						case 'S':
						case 's': {
							cout << "You are Wrong" << endl;
							break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				case 'G':
				case 'g': {
					cout << setw(45) << "GERMANY Selected" << endl << endl;
					cout << "What is the Capital of Germany?" << endl << endl;
					cout << "[H] Hamburg" << endl;
					cout << "[M] Munich" << endl;
					cout << "[B] Berlin" << endl;
					cout << "[F] Frankfort" << endl;
					cout << "[S] Stuttgart" << endl << endl;
					cout << "Enter Choice: ";
					cin >> choice;
					cout << endl;
					switch(choice) {
						case 'B':
						case 'b': {
							cout << "You are right, Berlin is the Capital of Germany" << endl;
							break;
						}
						case 'H':
						case 'h':
						case 'M':
						case 'm':
						case 'F':
						case 'f':
						case 'S':
						case 's': {
							cout << "You are Wrong" << endl;
							break;
						}
						default: {
							cout << "Invalid Choice Entered" << endl;
						}
					}
					break;
				}
				default: {
					cout << "Invalid Choice Entered" << endl;
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