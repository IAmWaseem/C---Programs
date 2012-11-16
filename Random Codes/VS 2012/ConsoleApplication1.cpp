#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main() {
	int players,i=0,total=0,points;
	cout << "Enter Number of Players : ";
	cin >> players;
	switch(players) {
		case 1: {
			char player;
			cout << "SINGLE PLAYER MODE SELECTED" << endl << endl;
			cout << "[A] ALPHA Character" << endl;
			cout << "[B] BRAVO Character" << endl;
			cout << "[C] CHARLIE Character" << endl;
			cout << "[D] DELTA Character" << endl << endl;
			cout << "Enter Choice[A-D]: ";
			cin >> player;
			switch(player) {
				case 'A':
				case 'a': {
					cout << "ALPHA Character Selected" << endl;
					break;
				}
				case 'B':
				case 'b': {
					cout << "BRAVO Character Selected" << endl;
					break;
				}
				case 'C':
				case 'c': {
					cout << "CHARLIE Character Selected" << endl;
					break;
				}
				case 'D':
				case 'd': {
					cout << "DELTA Character Selected" << endl;
					break;
				}
				default: {
					cout << "INVALID Character Selected" << endl;		 
				}
			}
			while(i<5) {
				cout << "Enter Points 1-500 : ";
				cin >> points;
				if(points>0 && points<101) {
						points=10;
				}
				else if(points>100 && points<201) {
						points=20;
				}
				else if(points>200 && points<501) {
					points=50;
				}
				else {
					cout << "Invalid Points Entered" << endl;
					i--;
				}
				total=total+points;
				i++;
			}
			cout << "Total Points of Player : " << total << endl;
			break;
		}
		case 2: {
			char player1,player2;
			cout << "TWO PLAYER MODE SELECTED" << endl << endl;
			cout << "[A] ALPHA Character" << endl;
			cout << "[B] BRAVO Character" << endl;
			cout << "[C] CHARLIE Character" << endl;
			cout << "[D] DELTA Character" << endl << endl;
			cout << "Enter Choice for Player 1[A-D]: ";
			cin >> player1;
			cout << "Enter Choice for Player 2[A-D]: ";
			cin >> player2;
			if(player1==player2) {
				cout << "Cannot Select Same Characters for both Players" << endl;
				break;
			}
			switch(player1) {
				case 'A':
				case 'a': {
					cout << "ALPHA Character Selected for Player 1" << endl;
					break;
				}
				case 'B':
				case 'b': {
					cout << "BRAVO Character Selected for Player 1" << endl;
					break;
				}
				case 'C':
				case 'c': {
					cout << "CHARLIE Character Selected for Player 1" << endl;
					break;
				}
				case 'D':
				case 'd': {
					cout << "DELTA Character Selected for Player 1" << endl;
					break;
				}
				default: {
					cout << "INVALID Character Selected for Player 1" << endl;		 
				}
			}
			switch(player2) {
				case 'A':
				case 'a': {
					cout << "ALPHA Character Selected for Player 2" << endl;
					break;
				}
				case 'B':
				case 'b': {
					cout << "BRAVO Character Selected for Player 2" << endl;
					break;
				}
				case 'C':
				case 'c': {
					cout << "CHARLIE Character Selected for Player 2" << endl;
					break;
				}
				case 'D':
				case 'd': {
					cout << "DELTA Character Selected for Player 2" << endl;
					break;
				}
				default: {
					cout << "INVALID Character Selected for Player 2" << endl;		 
				}
			}
			int total1=0,j=1;
			while(j<=2) {
				while(i<5) {
					cout << "Enter Points for player " << j << " 1-500 : ";
					cin >> points;
					if(points>0 && points<101) {
							points=10;
					}
					else if(points>100 && points<201) {
							points=20;
					}
					else if(points>200 && points<501) {
						points=50;
					}
					else {
						cout << "Invalid Points Entered" << endl;
						i--;
					}
					total=total+points;
					i++;
				}
				cout << "Total Points for Player" << j << " : " << total << endl;
				if(j==1) {
					total1=total;
				}
				j++;
			}
			if(total1>total) {
				cout << "Player 1 WINS" << endl;
			}
			else if(total>total1) {
				cout << "Player 2 WINS" << endl;
			}
			else if(total==total1) {
				cout << "DRAW" << endl;
			}
			break;
		}
		default: {
			cout << "INVALID Number of Players Selected" << endl;		 
		}
	}
	getch();
	return 0;
}