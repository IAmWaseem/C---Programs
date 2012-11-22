#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

char Grid[25][80] = {0};

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

int main() {
	srand(time(0));
	/*
	int n,i = 0;
	for(;;) {
		n = rand()%10;
		int col = rand()%80;
		GotoXY(col,i);
		cout << n;
		Sleep(100);
		GotoXY(col,i);
		cout << " ";
		GotoXY(col,i + 1);
		cout << n;
		i++;
	}
	*/
	int columns[10] = {0};
	int k = 0;
	for(int i=0;i<10;i++) {
		int n = 48 + rand() % 10;
		int rc = rand() % 80;
		columns[i] = rc;
		Grid[k][rc] = n;
	}
	for(int m=0;m<18;m++) {
		for(int i=0;i<24;i++) {
			for(int j=0;j<80;j++) {
				cout << Grid[i][j];
			}
		}
		int temp;
		for(int i=0;i<10;i++) {
			temp = Grid[k+1][columns[i]];
			Grid[k+1][columns[i]] = Grid[k][columns[i]];
			Grid[k][columns[i]] = temp;
		}
		k++;
		Sleep(100);
		GotoXY(0,0);
	}
	getch();
	return 0;
}