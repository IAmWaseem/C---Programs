#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Robot();
void CheckNumber();

char Screen[25][80] = {0};
int x = 0;
int y = 17;

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

int main() {
	for(int i=0;i<80;i++) {
		Screen[24][i] = char(178);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
	for(int i=0;i<18;i++) {
		for(int j=0;j<80;j++) {
			cout << Screen[i][j];
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47);
	for(int i=18;i<24;i++) {
		for(int j=0;j<80;j++) {
			cout << Screen[i][j];
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
	for(int i=0;i<80;i++) {
		cout << Screen[24][i];
	}
	GotoXY(0,0);
	Robot();
	while(1)
		CheckNumber();
	getch();
	return 0;
}

void Robot() {
	char Robot[5][6] = { {0,92,196,194,196,47},	{0,0,0,179,002,0}, {0,0,0,192,186,170}, {0,0,0,218,208,191}, {0,0,0,217,0,195} };
	for(int i=0;i<5;i++) {
		for(int j=0;j<7;j++) {
			if(i==0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
			}
			if(i==1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
			}
			GotoXY(x+j,y+i);
			cout << Robot[i][j];
		}
	}
}


void CheckNumber() {
	while(x>=0 && y>=0)
	{	
		if(GetAsyncKeyState(VK_RIGHT) && x<73)
		{
			Sleep(100);
			GotoXY(x,y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
			cout << " ";
			x=x+1;
			GotoXY(x,y);
			Robot();
			GotoXY(x,y);
		}
		if(GetAsyncKeyState(VK_LEFT) && x>0)
		{
			Sleep(100);
			GotoXY(x+6,y+4);
			cout << " ";
			x=x-1;
			GotoXY(x,y);
			Robot();
			GotoXY(x,y);
		}
	}
}