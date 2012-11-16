/*
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	int mode,check=1,value,points1=0,points2=0;
	char player1,player2;
	cout << "  *****        *       *       *  ******" << endl;
	cout << " *     *      * *      * *   * *  *     " << endl;
	cout << "*            *   *     *  * *  *  *     " << endl;
	cout << "*    ***    * * * *    *   *   *  ******" << endl;
	cout << " *     *   *       *   *       *  *     " << endl;
	cout << "  *****   *         *  *       *  ******" << endl << endl << endl;
	cout << "How many Players want to Play?" << endl << endl;
	cout << "[1] Single Player" << endl;
	cout << "[2] 2 Player" << endl << endl;
	cout << "Enter Choice[1-2]: ";
	cin >> mode;
	if(mode==1) {
		cout << endl << "\t\t\tSINGLE PLAYER MODE SELECTED" << endl << endl;
		cout << "Availabe Heroes: " << endl << endl;
		cout << "[A] ALPHA Hero" << endl;
		cout << "[B] BRAVO Hero" << endl;
		cout << "[C] CHARLIE Hero" << endl;
		cout << "[D] DELTA Hero" << endl << endl;
		cout << "Select your Hero[A-D]: ";
		cin >> player1;
		cout << endl;
		if(player1=='A'||player1=='a') {
			cout << "ALPHA Hero Selected" << endl;
		}
		else if(player1=='B'||player1=='b') {
			cout << "BRAVO Hero Selected" << endl;
		}
		else if(player1=='C'||player1=='c') {
			cout << "CHARLIE Hero Selected" << endl;
		}
		else if(player1=='D'||player1=='d') {
			cout << "DELTA Hero Selected" << endl;
		}
		else {
			cout << "Invalid Choice" << endl;
			check=0;
		}
		cout << endl;
		if(check) {
			for(int i=1;i<=5;i++) {
				cout << "Enter any Value Between 1 and 500: ";
				cin >> value;
				if(value>=1&&value<=100) {
					points1+=10;
				}
				else if(value>=101&&value<=200) {
					points1+=20;
				}
				else if(value>=201&&value<=500) {
					points1+=50;
				}
				else {
					cout << "Invalid Value Entered" << endl;
				}
			}
			cout << "Total Points for Player : " << points1 << endl;
		}
	}
	else if(mode==2) {
		cout << endl << "\t\t\t2 PLAYER MODE SELECTED" << endl << endl;
		cout << "Available Heroes: " << endl << endl;
		cout << "[A] ALPHA Hero" << endl;
		cout << "[B] BRAVO Hero" << endl;
		cout << "[C] CHARLIE Hero" << endl;
		cout << "[D] DELTA Hero" << endl << endl;
		cout << "Select Hero for Player 1[A-D]: ";
		cin >> player1;
		cout << endl;
		cout << "Select Hero for Player 2[A-D]: ";
		cin >> player2;
		cout << endl;
		if(player1=='A'||player1=='a') {
			cout << "ALPHA Hero Selected for Player 1" << endl;
		}
		else if(player1=='B'||player1=='b') {
			cout << "BRAVO Hero Selected for Player 1" << endl;
		}
		else if(player1=='C'||player1=='c') {
			cout << "CHARLIE Hero Selected for Player 1" << endl;
		}
		else if(player1=='D'||player1=='d') {
			cout << "DELTA Hero Selected for Player 1" << endl;
		}
		else {
			cout << "Invalid Choice" << endl;
			check=0;
		}
		if(player2=='A'||player2=='a') {
			cout << "ALPHA Hero Selected for Player 2" << endl;
		}
		else if(player2=='B'||player2=='b') {
			cout << "BRAVO Hero Selected for Player 2" << endl;
		}
		else if(player2=='C'||player2=='c') {
			cout << "CHARLIE Hero Selected for Player 2" << endl;
		}
		else if(player2=='D'||player2=='d') {
			cout << "DELTA Hero Selected for Player 2" << endl;
		}
		else {
			cout << "Invalid Choice" << endl;
			check=0;
		}
		if(player1==player2) {
			cout << "Cannot Select Same Heroes for both Players" << endl;
			check=0;
		}
		if(check) {
			for(int i=0;i<=9;i++) {
				if(i%2==0) {
					cout << "Enter any value between 1 and 500 for Player 1 : ";
					cin >> value;
				}
				else {
					cout << "Enter any value between 1 and 500 for Player 2 : ";
					cin >> value;
				}
				if(value>=1&&value<=100) {
					if(i%2==0) {
						points1+=10;
					}
					else {
						points2+=10;
					}
				}
				else if(value>=101&&value<=200) {
					if(i%2==0) {
						points1+=20;
					}
					else {
						points2+=20;
					}
				}
				else if(value>=201&&value<=500) {
					if(i%2==0) {
						points1+=50;
					}
					else {
						points2+=50;
					}
				}
				else {
					cout << "Invalid Value Entered" << endl;
					i--;
					continue;
				}
			}
			cout << "Player 1 Points : " << points1 << endl;
			cout << "Player 2 Points : " << points2 << endl << endl;
			if(points1>points2) {
				cout << "Player 1 Wins" << endl;
			}
			else if(points2>points1) {
				cout << "Player 2 Wins" << endl;
			}
			else {
				cout << "Game Draws" << endl;
			}
		}
	}
	else {
		cout << endl << "Invalid Choice Entered" << endl;
	}
	getch();
	return 0;
}
*/