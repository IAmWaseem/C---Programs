#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

char Grid[25][80];
int InitialCoordinateX = 30;
int InitialCoordinateY = 19;

void MakeGrid();
void DisplayGrid();
void InitializeRobot();
int KeyPressed();
void UpdateRobotLocation();

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void main()
{
	system("color 17");
	MakeGrid();
	GotoXY(0,0);
	for(;;) {
		InitializeRobot();
		DisplayGrid();
		GotoXY(0,0);
		cout << VK_RIGHT;
		UpdateRobotLocation();
	}
	getch();
}

void MakeGrid() {
	for(int i=19;i<25;i++) {
		for(int j=0;j<80;j++) {
			if(i==24) {
				Grid[i][j] = char(178);
			}
			else {
				Grid[i][j] = char(0);
			}
		}
	}
}

void DisplayGrid() {
	GotoXY(0,19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 17);
	for(int i=19;i<25;i++) {
		for(int j=0;j<80;j++) {
			if(i==19)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47);
			if(i==24)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
			cout << Grid[i][j];
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
}

void InitializeRobot() {
	Grid[InitialCoordinateY][InitialCoordinateX] = char(1);
}

int KeyPressed() {
	char ch;
	int direction=0;
	ch = getch();
	if(ch=='d' || ch==VK_RIGHT) {
		direction = 1;
	}
	else if(ch=='a' || ch==VK_LEFT) {
		direction = 2;
	}
	return direction;
}

void UpdateRobotLocation() {
	int direction;
	direction = KeyPressed();
	if(direction==0) {
		direction = KeyPressed();
	}
	if(direction==1 && InitialCoordinateX<79) {
		Grid[InitialCoordinateY][InitialCoordinateX] = char(0);
		Grid[InitialCoordinateY][InitialCoordinateX+1] = char(1);
		InitialCoordinateX++;
	}
	else if(direction==2 && InitialCoordinateX>0) {
		Grid[InitialCoordinateY][InitialCoordinateX] = char(0);
		Grid[InitialCoordinateY][InitialCoordinateX-1] = char(1);
		InitialCoordinateX--;
	}
}