#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void GotoXY(int x, int y) {
	COORD coord = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void SetColor(int Color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void ChangeCursor(int Size, bool Visibility) {
	CONSOLE_CURSOR_INFO CurInf;
	CurInf.dwSize = Size;
	CurInf.bVisible = Visibility;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInf);
	return;
}

int main() {
	ChangeCursor(100, FALSE);
	INPUT_RECORD InputRecord;
	DWORD Events;
	int row, col;
	int check_normal[3] = {1,1,1};
	int check_hover[3] = {1,1,1};
	int i = 0;
	while(1) {
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &InputRecord, 1, &Events);
		col = InputRecord.Event.MouseEvent.dwMousePosition.X;
		row = InputRecord.Event.MouseEvent.dwMousePosition.Y;
		if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && row<24 && row>=19 && col<50 && col>=30) {
			exit(1);
		}
		if(!(row<10 && row>=5 && col<50 && col>=30)) {
			if(check_normal[i]) {
				SetColor(79);
				GotoXY(30,5);
				for(int i=0;i<5;i++) {
					for(int j=0;j<20;j++) {
						cout.put(' ');
						cout.flush();
						GotoXY(30+j,5+i);
					}
				}
				cout << " ";
				GotoXY(35,7);
				cout << "Start Game";
				check_normal[i] = 0;
				check_hover[i] = 1;
			}
		}
		else {
			if(check_hover[i]) {
				SetColor(207);
				GotoXY(30,5);
				for(int i=0;i<5;i++) {
					for(int j=0;j<20;j++) {
						cout.put(' ');
						cout.flush();
						GotoXY(30+j,5+i);
					}
				}
				cout << " ";
				GotoXY(35,7);
				cout << "Start Game";
				check_normal[i] = 1;
				check_hover[i] = 0;
			}
		}
		i++;
		if(!(row<17 && row>=12 && col<50 && col>=30)) {
			if(check_normal[i]) {
				SetColor(79);
				GotoXY(30,12);
				for(int i=0;i<5;i++) {
					for(int j=0;j<20;j++) {
						cout.put(' ');
						cout.flush();
						GotoXY(30+j,12+i);
					}
				}
				cout << " ";
				GotoXY(34,14);
				cout << "Instructions";
				check_normal[i] = 0;
				check_hover[i] = 1;
			}
		}
		else {
			if(check_hover[i]) {
				SetColor(207);
				GotoXY(30,12);
				for(int i=0;i<5;i++) {
					for(int j=0;j<20;j++) {
						cout.put(' ');
						cout.flush();
						GotoXY(30+j,12+i);
					}
				}
				cout << " ";
				GotoXY(34,14);
				cout << "Instructions";
				check_normal[i] = 1;
				check_hover[i] = 0;
			}
		}
		i++;
		if(!(row<24 && row>=19 && col<50 && col>=30)) {
			if(check_normal[i]) {
				SetColor(79);
				GotoXY(30,19);
				for(int i=0;i<5;i++) {
					for(int j=0;j<20;j++) {
						cout.put(' ');
						cout.flush();
						GotoXY(30+j,19+i);
					}
				}
				cout << " ";
				GotoXY(38,21);
				cout << "Exit";
				check_normal[i] = 0;
				check_hover[i] = 1;
			}
		}
		else {
			if(check_hover[i]) {
				SetColor(207);
				GotoXY(30,19);
				for(int i=0;i<5;i++) {
					for(int j=0;j<20;j++) {
						cout.put(' ');
						cout.flush();
						GotoXY(30+j,19+i);
					}
				}
				cout << " ";
				GotoXY(38,21);
				cout << "Exit";
				check_normal[i] = 1;
				check_hover[i] = 0;
			}
		}
		i = 0;
	}
	getch();
	return 0;
}