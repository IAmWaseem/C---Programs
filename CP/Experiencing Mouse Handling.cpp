
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

HANDLE Hout = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE Hin = GetStdHandle(STD_INPUT_HANDLE);

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(Hout, coord);
	return;
}

inline void SetColor(int Color) {
	SetConsoleTextAttribute(Hout, Color);
	return;
}

void SetCursor(int Size, bool Visibility) {
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.dwSize = Size;
	CursorInfo.bVisible = Visibility;
	SetConsoleCursorInfo(Hout, &CursorInfo);
	return;
}

void SetWindow(int Width, int Height) {
	COORD coord;
	SMALL_RECT Window;
	coord.X = Width;
	coord.Y = Height + 1;
	Window.Top = 0;
	Window.Left = 0;
	Window.Bottom = Height - 1;
	Window.Right = Width - 1;
	SetConsoleScreenBufferSize(Hout, coord);
	SetConsoleWindowInfo(Hout, TRUE, &Window);
}


int main() {
	SetCursor(100, FALSE);
	INPUT_RECORD InputRecord;
	DWORD Events;
	int Row, Column;
	bool States[2][2] = { {1,1}, {1,1} };
	bool DropDownState[1][2] = {1,1};
	while(1) {
		ReadConsoleInput(Hin, &InputRecord, 1, &Events);
		Row = InputRecord.Event.MouseEvent.dwMousePosition.Y;
		Column = InputRecord.Event.MouseEvent.dwMousePosition.X;
		if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			if(Row >= 3 && Row < 8 && Column >= 30 && Column < 51) {
				SetColor(79);
				GotoXY(25, 10);
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 30; j++) {
						GotoXY(j + 25, i + 10);
						cout.put(' ');
						cout.flush();
					}
				}
				GotoXY(5 + 25, 1 + 10);
				string Name;
				SetCursor(10, TRUE);
				fflush(stdin);
				getline(cin, Name);
				SetCursor(100, FALSE);
			}
			if(Row >= 10 && Row < 13 && Column >= 25 && Column < 55) {
				/*SetColor(79);
				GotoXY(25, 10);
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 30; j++) {
						GotoXY(j + 25, i + 10);
						cout.put(' ');
						cout.flush();
					}
				}
				GotoXY(5 + 25, 1 + 10);
				string Name;
				SetCursor(10, TRUE);
				cin >> Name;
				SetCursor(100, FALSE);*/
			}
			if(Row >= 9 && Row < 12 && Column >= 47 && Column < 51)	{
				if(DropDownState[0][0]) {
					SetColor(79);
					for(int i = 0; i < 9; i++) {
						for(int j = 0; j < 21; j++) {
							GotoXY(j + 30, i + 9);
							cout.put(' ');
							cout.flush();
						}
						if(i == 3) {
							GotoXY(7 + 30, i + 9);
							cout << "Male";
						}
						if(i == 5) {
							GotoXY(7 + 30, i + 9);
							cout << "Female";
						}
						if(i == 7) {
							GotoXY(7 + 30, i + 9);
							cout << "Khusra";
						}
					}
					GotoXY(7 + 30, 1 + 9);
					cout << "DropDown";
					GotoXY(47, 1 + 9);
					SetColor(111);
					cout << "  ";
					DropDownState[0][0] = 0;
					DropDownState[0][1] = 1;
				}
				else if(DropDownState[0][1]) {
					SetColor(0);
					for(int i = 0; i < 9; i++) {
						for(int j = 0; j < 21; j++) {
							GotoXY(j + 30, i + 12);
							cout.put(' ');
							cout.flush();
						}
					}
					DropDownState[0][0] = 1;
					DropDownState[0][1] = 0;
				}
			}
		}
		if(!(Row >= 3 && Row < 8 && Column >= 30 && Column < 51)) {
			if(States[0][0]) {
				SetColor(79);
				for(int i = 0; i < 5; i++) {
					for(int j = 0; j < 21; j++) {
						GotoXY(j + 30, i + 3);
						cout.put(' ');
						cout.flush();
					}
				}
				GotoXY(5 + 30, 2 + 3);
				cout << "Login Panel";
				States[0][0] = 0;
				States[0][1] = 1;
			}
		}
		else {
			if(States[0][1]) {
				SetColor(207);
				for(int i = 0; i < 5; i++) {
					for(int j = 0; j < 21; j++) {
						GotoXY(j + 30, i + 3);
						cout.put(' ');
						cout.flush();
					}
				}
				GotoXY(5 + 30, 2 + 3);
				cout << "Login Panel";
				States[0][0] = 1;
				States[0][1] = 0;
			}
		}
		if(!(Row >= 9 && Row < 12 && Column >= 30 && Column < 51)) {
			if(States[1][0]) {
				SetColor(79);
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 21; j++) {
						GotoXY(j + 30, i + 9);
						cout.put(' ');
						cout.flush();
					}
				}
				GotoXY(7 + 30, 1 + 9);
				cout << "DropDown";
				GotoXY(47, 1 + 9);
				SetColor(111);
				cout << "  ";
				States[1][0] = 0;
				States[1][1] = 1;
			}
		}
		else {
			if(States[1][1]) {
				SetColor(207);
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 21; j++) {
						GotoXY(j + 30, i + 9);
						cout.put(' ');
						cout.flush();
					}
				}
				GotoXY(7 + 30, 1 + 9);
				cout << "DropDown";
				GotoXY(47, 1 + 9);
				SetColor(111);
				cout << "  ";
				States[1][0] = 1;
				States[1][1] = 0;
			}
		}
	}
	return 0;
}