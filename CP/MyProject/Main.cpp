#include "Includes.h"
#include "Prototypes.h"

unsigned char Grid[56][80] = {0};		/* 2D Array That Controls What is Displayed on the Screen */
int InitialCoordinateX = 35;			/* Initial X-Coordinate of Robot */
int InitialCoordinateY = 46;			/* Initial Y-Coordinate of Robot */
int ColorNum[7] = {28,26,30,27,29,22,31};
HANDLE hOUT = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIN = GetStdHandle(STD_INPUT_HANDLE);

int main() {
	srand( time(0) );
	SetConsoleTitle(L"Catch the Numbers - Developer : Waseem Hassan");
	SetWindow(80,57);
	ChangeCursor(100,FALSE);
	Switchboard();
	return 0;
}

void GotoXY(int x, int y) {				/* Definition of GotoXY Function(Used to jump to any Part of the Screen) */
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(hOUT, coord);
	return;
}

void SetWindow(int Width, int Height) {
	COORD coord;
	SMALL_RECT Rect;
	coord.X = Width;
	coord.Y = Height + 1;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	SetConsoleScreenBufferSize(hOUT, coord);
	SetConsoleWindowInfo(hOUT, TRUE, &Rect);
	return;
}

void ChangeCursor(int Size, bool Visibility) {
	CONSOLE_CURSOR_INFO CurInf;
	CurInf.dwSize = Size;
	CurInf.bVisible = Visibility;
	SetConsoleCursorInfo(hOUT, &CurInf);
	return;
}

void SetColor(int x) {					/* Changes the Color According to the Passed Value */
	SetConsoleTextAttribute(hOUT, x);
	return;								/* Returns to the Function from where it was called */
}

void DisplayScreen() {
	GotoXY(0,49);
	for(int i=0;i<7;i++) {
		if(i<6) {
			SetColor(47);
		}
		else {
			SetColor(14);
		}
		for(int j=0;j<80;j++) {
			if(i<6) {
				cout.put(' ');
			}
			else {
				cout.put(char(178));
			}
			cout.flush();
		}
	}
	GotoXY(0,0);
	return;
}

void InitializeRobot() {			/* Initializes the Robot into the Grid on the Bottom Center of Grid */
	unsigned char Robot[5][6] = {		/* 2D Robot Array used to store the Parts of the Robot having Dimensions 5x6 */
		{0,92,196,194,196,47},
		{0,0,0,179,002,0},
		{0,0,0,192,186,170},
		{0,0,0,218,208,191},
		{0,0,0,217,0,192}
	};
	for(int i=InitialCoordinateY+2,k=0;i<53;i++,k++) {
		for(int j=InitialCoordinateX,l=0;j<41;j++,l++) {
			Grid[i][j] = Robot[k][l];
		}
	}
	return;
}

void MoveRobot() {
	int X = InitialCoordinateX + 7;
	int Y = InitialCoordinateY + 7;
	for(int i=InitialCoordinateY;i<Y;i++) {
		if(i==48) {
			SetColor(31);
		}
		if(i==49) {
			SetColor(47);
		}
		for(int j=InitialCoordinateX;j<X;j++) {
			if(i<48 && Grid[i][j]!=0) {
				SetColor(ColorNum[AsciiToNumber(Grid[i][j])]);
			}
			else if(i<48) {
				SetColor(31);
			}
			GotoXY(j,i);
			cout << Grid[i][j];
		}
	}
	return;
}

void UpdateRobotLocation() {
	char ch;
	int X = InitialCoordinateX + 7;
	int Y = InitialCoordinateY + 7;
	int temp;
	ch = getch();
	if((ch=='D' || ch=='d' || ch==KB_RIGHT) && InitialCoordinateX<73) {
		for(int i=InitialCoordinateY;i<Y;i++) {
			for(int j=X;j>InitialCoordinateX;j--) {
				temp = Grid[i][j];
				Grid[i][j] = Grid[i][j-1];
				Grid[i][j-1] = temp;
			}
		}
		InitialCoordinateX++;
		return;
	}
	else if((ch=='A' || ch=='a' || ch==KB_LEFT) && InitialCoordinateX>0) {
		for(int i=InitialCoordinateY;i<Y;i++) {
			for(int j=InitialCoordinateX;j<X;j++) {
				temp = Grid[i][j];
				Grid[i][j] = Grid[i][j-1];
				Grid[i][j-1] = temp;
			}
		}
		InitialCoordinateX--;
		return;
	}
	else if(ch==VK_ESCAPE) {
		exit(1);
	}
	return;
}

void GenerateRandomNumbers() {
	SetColor(31);
	int SpeedNum[7] = {100, 10, 20, 30, 40, 50, 60};
	int maxnum = 1 + rand() % 10;
	int *NumColumns;
	NumColumns = new int[maxnum + 1];
	int *NumValues;
	NumValues = new int[maxnum + 1];
	for(int i=1;i<=maxnum;i++) {
		NumColumns[i] = 2 + rand() % 76;
		NumValues[i] = rand() % 7;
		for(int j=0;j<i;j++) {
			if(NumColumns[i]==NumColumns[j]) {
				i--;
				break;
			}
		}
	}
	for(int i=1;i<=maxnum;i++) {
		GotoXY(NumColumns[i],0);
		cout << NumValues[i];
	}
	for(int rows=1;rows<=48;rows++) {
		for(int i=1;i<=maxnum;i++) {
			Timer(180);
			while(kbhit()) {
				UpdateRobotLocation();
				MoveRobot();
				break;
			}
			Sleep(SpeedNum[i]);
			GotoXY(NumColumns[i],rows);
			//GotoXY(NumColumns[i],rows-1);
			SetColor(ColorNum[NumValues[i]]);
			cout << NumValues[i];
			CatchNumbers(rows,NumValues[i],NumColumns[i]);
			Sleep(10);
		}
		for(int j=1;j<=maxnum;j++) {
			GotoXY(NumColumns[j],rows-1);
			cout << char(NULL);
		}
	}
	delete[] NumColumns;
	delete[] NumValues;
	return;
}

void CatchNumbers(const int Row, const int Number, const int Column ) {
	if(Row==47 && Grid[Row+1][Column]==194) {
		Grid[Row-1][Column] = NumberToAscii(Number);
		Score(Number);
	}
	else if(Row==48 && Grid[Row][Column]==196) {
		Grid[Row-1][Column] = NumberToAscii(Number);
		Score(Number);
	}
	else {
		// Error Prevention
	}
	return;
}

char NumberToAscii(int Number) {
	char ch;
	ch = Number + 48;
	return ch;
}

int AsciiToNumber(char ch) {
	int num;
	num = ch - 48;
	return num;
}

void Timer(int StartTime) {
	clock_t Timer;
	Timer = StartTime - clock() / CLOCKS_PER_SEC;
	SetColor(31);
	GotoXY(0,56);
	cout << "Time Elapsed : " << Timer;
	//StartTime = StartTime - clock() / CLOCKS_PER_SEC - 1;
	if(Timer==0) {
		Sleep(2000);
		exit(1);
	}
	return;
}

void Score(int Number) {
	static int Score = 0;
	Score = Score + Number;
	if(!Number) {
		Score = Score - Score;
	}
	SetColor(31);
	GotoXY(69,56);
	cout << "Score : ";
	cout.flags(ios::right);
	cout.width(2);
	cout << Score;
	return;
}

void Switchboard() {
	INPUT_RECORD InputRecord;
	DWORD Events;
	int row, col;
	int check_normal[4] = {1,1,1,1};
	int check_hover[4] = {1,1,1,1};
	int Item = 0;
	while(1) {
		ReadConsoleInput(hIN, &InputRecord, 1, &Events);
		col = InputRecord.Event.MouseEvent.dwMousePosition.X;
		row = InputRecord.Event.MouseEvent.dwMousePosition.Y;
		if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			if(row<10 && row>=5 && col<50 && col>=30) {
				system("cls");
				system("Color 1F");					/* Turns Background to Blue & Foreground to White */
				DisplayScreen();
				InitializeRobot();
				MoveRobot();
				Score(0);
				for( ; ; ) {
					GenerateRandomNumbers();
				}
			}
			else if(row<17 && row>=12 && col<50 && col>=30) {
				
			}
			else if(row<24 && row>=19 && col<50 && col>=30) {
				exit(1);
			}
		}
		if(!(row<10 && row>=5 && col<50 && col>=30)) {
			if(check_normal[Item]) {
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
				check_normal[Item] = 0;
				check_hover[Item] = 1;
			}
		}
		else {
			if(check_hover[Item]) {
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
				check_normal[Item] = 1;
				check_hover[Item] = 0;
			}
		}
		Item++;
		if(!(row<17 && row>=12 && col<50 && col>=30)) {
			if(check_normal[Item]) {
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
				check_normal[Item] = 0;
				check_hover[Item] = 1;
			}
		}
		else {
			if(check_hover[Item]) {
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
				check_normal[Item] = 1;
				check_hover[Item] = 0;
			}
		}
		Item++;
		if(!(row<24 && row>=19 && col<50 && col>=30)) {
			if(check_normal[Item]) {
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
				check_normal[Item] = 0;
				check_hover[Item] = 1;
			}
		}
		else {
			if(check_hover[Item]) {
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
				check_normal[Item] = 1;
				check_hover[Item] = 0;
			}
		}
		Item++;
		if(!(row<24 && row>=19 && col<50 && col>=30)) {
			if(check_normal[Item]) {
				SetColor(97);

			}

		}

		Item = 0;
	}
	return;
}