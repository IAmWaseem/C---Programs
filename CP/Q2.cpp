#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

HANDLE hOUT = GetStdHandle(STD_OUTPUT_HANDLE);
char Grid[25][80] = {0};

void ChangeColor(int);

void ChangeCursor(int Size, bool Visibility) {
	CONSOLE_CURSOR_INFO CurInf;
	CurInf.dwSize = Size;
	CurInf.bVisible = Visibility;
	SetConsoleCursorInfo(hOUT, &CurInf);
	return;
}

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(hOUT, coord);
	return;
}

int main() {
	ChangeCursor(100,FALSE);
	int i;
	ChangeColor(71);
	for(i = 0; i < 80; i++) {
		GotoXY(i,0);
		cout.put(' ');
		cout.flush();
		Sleep(10);
	}
	for(i = 0; i < 25; i++) {
		GotoXY(79,i);
		cout.put(' ');
		cout.flush();
		Sleep(10);
	}
	for(i = 79; i >= 0; i--) {
		GotoXY(i,24);
		cout.put(' ');
		cout.flush();
		Sleep(10);
	}
	for(i = 24; i >= 0; i--) {
		GotoXY(0,i);
		cout.put(' ');
		cout.flush();
		Sleep(10);
	}
	ChangeColor(2);
	int Fx = 5, Fy = 3;
	int Ax = 74, Ay = 3;
	int Sx = 5, Sy = 21;
	int Tx = 74, Ty = 21;
	GotoXY(5,3);
	cout << (Grid[Fy][Fx] = 'F');
	GotoXY(74,3);
	cout << (Grid[Ay][Ax] = 'A');
	GotoXY(5,21);
	cout << (Grid[Sy][Sx] = 'S');
	GotoXY(74,21);
	cout << (Grid[Ty][Tx] = 'T');
	GotoXY(0,0);
	while(1) {
		char ch;
		ch = getch();
		if(ch == 'A' || ch == 'a') {
			while(Fy!=13 && Ay!=13 && Sy!=12 && Ty!=12) {
				for(int i = 1; i < 24; i++) {
					for(int j = 1; j < 79; j++) {
						GotoXY(j,i);
						cout << Grid[i][j];
					}
				}
				Grid[Fy + 1][Fx + 4] = Grid[Fy][Fx];
				Grid[Ay + 1][Ax - 4] = Grid[Ay][Ax];
				Grid[Sy - 1][Sx + 4] = Grid[Sy][Sx];
				Grid[Ty - 1][Tx - 4] = Grid[Ty][Tx];
				Grid[Fy][Fx] = ' ';
				Grid[Ay][Ax] = ' ';
				Grid[Sy][Sx] = ' ';
				Grid[Ty][Tx] = ' ';
				Fy++; Fx = Fx + 4;
				Ay++; Ax = Ax - 4;
				Sy--; Sx = Sx + 4;
				Ty--; Tx = Tx - 4;
				Sleep(20);
			}
			GotoXY(Fx - 4,Fy - 1);
			cout << " ";
			GotoXY(Ax + 4,Ay - 1);
			cout << " ";
			GotoXY(Sx - 4,Sy + 1);
			cout << " ";
			GotoXY(Tx + 4,Ty + 1);
			cout << " ";
			GotoXY(Fx - 4,Fy);
			cout << "FAST";
		}
		else {
			// Error Prevention
		}
	}
	getch();
	return 0;
}

void ChangeColor(int Color) {
	SetConsoleTextAttribute(hOUT, Color);
	return;
}