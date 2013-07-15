#include <iostream>
#include <conio.h>
#include <Windows.h>	//library used to change the colors of the screen and the output
#include <ctime>

using namespace std;

char a[60][80] = {' '};			//global variable can be used in every function including the main function
int  x = 16;
int score = 0;

void gridstore(void);//user defined function it stores the whole grid i.e the green part and the last ASCII line
void grid(void);
int color(int);
int timer(int);
int conversion(int);
int randomnum(int,int);
void fallingnum(void);
int numbercolor(int);

void SetWindow(int Width, int Height) {
	COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &Rect);
}

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}				//goto function its user defined

int main() {
	SetWindow(79,59);
	int time = 0;
	system("color 1F");
	gridstore();	//Call the gridstore function just once inside the main because u have to print the grid multiple times when u move the man if u call it inside the grid() function then it wud run again n again
	grid();
	while(1) {		
		fallingnum();
		while(kbhit()) {
			char b;
			b = getch();
			if (b == 'd' || b == char(77)) {
				int	c = x + 6;
				if (c >= 79) {
					cout << "\a";
					continue;
				}
				for (int i=44; i<=49; i++) {
					gotoXY(x + 1,i);
					for (int j=16; j<=22; j++) {	
						if(i == 47) {
							color(47);
						}
						if(i == 46) {
							color(287);
						}		//for the rest of the body green background and white foreground.
						cout << a[i][j];
					}
					gotoXY(x,i);
					cout << " ";
					cout << endl;
				}
				gotoXY(0,0);
				x = x + 1;
				break;
			}
			else if(b == 'a' || b == char(75)) {
				if (x == 0) {
					cout << "\a";
					continue;
				}
				for (int i=45; i<=49; i++) {
					gotoXY(x - 1,i);
					for (int j=16; j<=22; j++) {	
						if(i == 47) {
							color(47);
						}
						if(i == 46) {
							color(287);
						}
						cout << a[i][j];
					}
					gotoXY(x + 6,i);
					cout << " ";			// so that multiple robots are not present on the screen
					cout << endl;
				}
				gotoXY(0,0);
				x = x - 1;
				break;
			}
		}
		time += 950;
		if(time > (2 * (((9500 * 2) * 60) + (10 * (9500 * 2))))) {
			break;
		}
	}
}

int color(int i) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	return 0;
}

void gridstore() {
	for (int i=1; i<79; i++) {
		a[53][i] = char(178);
	}	//bottom most dotted line
	a[46][16] = 92;			//TRAY ON FIRST ROW
	a[46][17] = 196;
	a[46][18] = 194;
	a[46][19] = 196;
	a[46][20] = 47;
	a[47][18] = 179;		//2ND ROW
	a[47][20] = 2;
	a[48][18] = 192;		//3RD ROW
	a[48][19] = 196;
	a[48][20] = 186;
	a[48][21] = 196;
	a[48][22] = 170;
	a[49][18] = 95;
	a[49][19] = 47;			//4TH ROW
	a[49][21] = 92;
	a[49][22] = 95;
}

void grid() {
	for (int i=0; i<60; i++) {
		for (int j=0; j<80; j++) {
			if (i == 47)	{			//outputs green color
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47);
			}
			if(i == 53) {			//changes color to yellow
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 239);
			}
			if(i == 54) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 287);
			}
			cout << a[i][j];
		}
	}
	gotoXY(0,0);
}

void fallingnum() {
	srand(time(0));
	static int limit = 0;
	static int j = randomnum(0,79);
	static int counter = 0;
	static int xcord = randomnum(1,74);
	static int x1cord = randomnum(1,74);
	static int x2cord = randomnum(1,74);
	static int x3cord = randomnum(1,74);
	static int x4cord = randomnum(1,74);
	static int x5cord = randomnum(1,74);
	static int x6cord = randomnum(1,74);
	static int x7cord = randomnum(1,74);
	static int x8cord = randomnum(1,74);
	static int j1 = randomnum(1,74);
	static int j2 = randomnum(1,74);
	static int j3 = randomnum(1,74);
	static int j4 = randomnum(1,74);
	static int j5 = randomnum(1,74);
	static int j6 = randomnum(1,74);
	static int j7 = randomnum(1,74);
	static int j8 = randomnum(1,74);
	static int ycord = 0;
	static int y1cord = 0;
	static int y2cord = 0;
	static int y3cord = 0;
	static int y4cord = 0;
	static int y5cord = 0;
	static int y6cord = 0;
	static int y7cord = 0;
	static int y8cord = 0;
	if(limit == 0 || (limit % 80)==0) {
		j = 0;
		for(int i=0; i<80; i++) {
			a[0][i] = char(randomnum(48,57));
		}
	}
	int colors = randomnum(282,287);
	color(colors);
	if(ycord == 67) {
		MAIN:
			for(int i=0; i<=2; i++) {
				gotoXY(0,43 + i);
				for (int j=0; j<80; j++) {
					if(j == x + 1 || j == x + 2 || j == x + 3) {
						continue;
					}
					cout << " ";
				}
				cout << endl;
			}
	}
	gotoXY(xcord,ycord);			//first number.
	cout << a[0][j];
	numbercolor(a[0][j]);
	gotoXY(xcord,ycord-1);
	cout << " " << endl;
	gotoXY(x3cord,y3cord);			//4th number
	cout << a[0][j3];				
	gotoXY(x3cord,y3cord-1);
	cout << " ";	
	gotoXY(x6cord,y6cord);			//7th number
	cout << a[0][j6];
	numbercolor(a[0][j6]);
	gotoXY(x6cord,y6cord-1);
	cout << " ";
	if((ycord == 45 && xcord == x + 1) || (y3cord == 45 && x3cord == x + 1) || (y6cord == 45 && x6cord == x + 1)) {
		a[45][17] = a[0][j];
		conversion(a[0][j]);
		ycord = 0;
		j = randomnum(0,79);
		xcord = randomnum(1,74);
		a[45][17] = a[0][j3];
		conversion(a[0][j3]);
		y3cord = 0;
		j3 = randomnum(0,79);
		x3cord = randomnum(1,74);
		a[45][17] = a[0][j6];
		conversion(a[0][j6]);
		y6cord = 0;
		j6 = randomnum(0,79);
		x6cord = randomnum(1,74);
		goto MAIN;
	}
	else if((ycord == 45 && xcord == x + 2) || (y3cord == 45 && x3cord == x + 2) || (y6cord == 45 && x6cord == x + 2)) {
		a[45][18] = a[0][j];
		conversion(a[0][j]);
		ycord = 0;
		j = randomnum(0,79);
		xcord = randomnum(1,74);
		a[45][18] = a[0][j3];
		conversion(a[0][j3]);
		y3cord = 0;
		j3 = randomnum(0,79);
		x3cord = randomnum(1,74);
		a[45][18] = a[0][j6];
		conversion(a[0][j6]);
		j6 = randomnum(0,79);
		y6cord = 0;
		x6cord = randomnum(1,74);
		goto MAIN;
	}
	else if((ycord == 45 && xcord == x + 3) || (y3cord == 45 && x3cord == x + 3) || (y6cord == 45 && x6cord == x + 3)) {
		a[45][19] = a[0][j];
		conversion(a[0][j]);
		ycord = 0;
		j = randomnum(0,79);
		xcord = randomnum(1,74);
		a[45][19] = a[0][j3];
		conversion(a[0][j3]);
		y3cord = 0;
		j3 = randomnum(0,79);
		x3cord = randomnum(1,74);
		a[45][19] = a[0][j6];
		conversion(a[0][j6]);
		j6 = randomnum(0,79);
		y6cord = 0;
		x6cord = randomnum(1,74);
		goto MAIN;
	}
	else if((ycord == 45) && (y3cord == 45) && (y3cord == 45)) {
		gotoXY(xcord,ycord);
		cout << " ";
		xcord = randomnum(1,74);
		j = randomnum(0,79);
		ycord = 0;
		limit++;
		gotoXY(x3cord,y3cord);
		cout << " ";
		y3cord = 0;
		x3cord = randomnum(1,74);
		j3 = randomnum(0,79);
		gotoXY(x6cord,y6cord);
		cout << " ";
		y6cord = 0;
		x6cord = randomnum(1,74);
		j6 = randomnum(0,79);
	}
	gotoXY(x1cord,y1cord);			//2nd number
	cout << a[0][j1];	
	gotoXY(x1cord,y1cord-2);
	cout << " ";
	gotoXY(x4cord,y4cord);			//5th number
	cout << a[0][j4];
	gotoXY(x4cord,y4cord-2);
	cout << " ";
	gotoXY(x7cord,y7cord);			//8th number
	cout << a[0][j7];
	numbercolor(a[0][j7]);
	gotoXY(x7cord,y7cord-2);
	cout << " ";
	if((y1cord == 44 && x1cord == x + 1) || (y4cord == 44 && x4cord == x + 1) || (y7cord == 44 && x7cord == x + 1)) {
		a[45][17] = a[0][j1];
		conversion(a[0][j1]);
		y1cord = 0;
		j1 = randomnum(0,79);
		x1cord = randomnum(1,74);
		a[45][17] = a[0][j4];
		conversion(a[0][j4]);
		y4cord = 0;
		j4 = randomnum(0,79);
		x4cord = randomnum(1,74);
		a[45][17] = a[0][j7];
		conversion(a[0][j7]);
		y7cord = 0;
		j7 = randomnum(0,79);
		x7cord = randomnum(1,74);
		goto MAIN;
	}
	else if((y1cord == 44 && x1cord == x + 2) || (y4cord == 44 && x4cord == x + 2) || (y7cord == 44 && x7cord == x + 2)) {
		a[45][18] = a[0][j1];
		conversion(a[0][j1]);
		y1cord = 0;
		j1 = randomnum(0,79);
		x1cord = randomnum(1,74);
		a[45][18] = a[0][j4];
		conversion(a[0][j4]);
		y4cord = 0;
		j4 = randomnum(0,79);
		x4cord = randomnum(1,74);
		a[45][18] = a[0][j7];
		conversion(a[0][j7]);
		y7cord = 0;
		j7 = randomnum(0,79);
		x7cord = randomnum(1,74);
		goto MAIN;
	}
	else if((y1cord == 44 && x1cord == x + 3) || (y4cord == 44 && x4cord == x + 3) || (y7cord == 44 && x7cord == x + 3)) {
		a[45][19] = a[0][j1];
		conversion(a[0][j1]);
		y1cord = 0;
		j1 = randomnum(0,79);
		x1cord = randomnum(1,74);
		a[45][19] = a[0][j4];
		conversion(a[0][j4]);
		y4cord = 0;
		j4 = randomnum(0,79);
		x4cord = randomnum(1,74);
		a[45][19] = a[0][j7];
		conversion(a[0][j7]);
		y7cord = 0;
		j7 = randomnum(0,79);
		x7cord = randomnum(1,74);
		goto MAIN;
	}
	else if((y1cord == 44) && (y4cord == 44) && (y7cord == 44)) {
		gotoXY(x1cord,y1cord);
		cout << " ";
		x1cord = randomnum(1,74);
		j1 = randomnum(0,79);
		y1cord = 0;
		limit++;
		gotoXY(x4cord,y4cord);
		cout << " ";
		x4cord = randomnum(1,74);
		j4 = randomnum(0,79);
		y4cord = 0;
		gotoXY(x7cord,y7cord);
		cout << " ";
		x7cord = randomnum(1,74);
		j7 = randomnum(0,79);
		y7cord = 0;
	}
	gotoXY(x2cord,y2cord);			//3rd number
	cout << a[0][j2];
	numbercolor(a[0][j2]);
	gotoXY(x2cord,y2cord-3);
	cout << " ";
	gotoXY(x5cord,y5cord);			//6th number
	cout << a[0][j5];
	gotoXY(x5cord,y5cord-3);
	cout << " ";
	gotoXY(x8cord,y8cord);
	cout << a[0][j8];
	gotoXY(x8cord,y8cord-3);
	cout << " ";
	if((y2cord == 45 && x2cord == x + 1) ||  (y5cord == 45 && x5cord == x + 1) || (y8cord == 45 && x8cord == x + 1)) {
		a[45][17] = a[0][j2];
		conversion(a[0][j2]);
		y2cord = 0;
		j2 = randomnum(0,79);
		x2cord = randomnum(1,74);
		a[45][17] = a[0][j5];
		conversion(a[0][j5]);
		y5cord = 0;
		j5 = randomnum(0,79);
		x5cord = randomnum(1,74);
		a[45][17] = a[0][j8];
		conversion(a[0][j8]);
		y8cord = 0;
		j8 = randomnum(0,79);
		x8cord = randomnum(1,74);
		goto MAIN;
	}
	else if((y2cord == 45 && x2cord == x + 2)	|| (y5cord == 45 && x5cord == x + 2) || (y8cord == 45 && x8cord == x + 2)) {
		a[45][18] = a[0][j2];
		conversion(a[0][j2]);
		y2cord = 0;
		j2 = randomnum(0,79);
		x2cord = randomnum(1,74);
		a[45][18] = a[0][j5];
		conversion(a[0][j5]);
		j5 = randomnum(0,79);
		y5cord = 0;
		x5cord = randomnum(1,74);
		a[45][18] = a[0][j8];
		conversion(a[0][j8]);
		y8cord = 0;
		j8 = randomnum(0,79);
		x8cord = randomnum(1,74);
		goto MAIN;
	}
	else if((y2cord == 45 && x2cord == x + 3) || (y5cord == 45 && x5cord == x + 3) || (y8cord == 45 && x8cord == x + 3)) {
		a[45][19] = a[0][j2];
		conversion(a[0][j2]);
		y2cord = 0;
		j2 = randomnum(0,79);
		x2cord = randomnum(1,74);
		a[45][19] = a[0][j5];
		conversion(a[0][j5]);
		y5cord = 0;
		j5 = randomnum(0,79);
		x5cord = randomnum(1,74);
		a[45][19] = a[0][j8];
		conversion(a[0][j8]);
		y8cord = 0;
		j8 = randomnum(0,79);
		x8cord = randomnum(1,74);
		goto MAIN;
	}
	else if((y2cord == 45) && (y5cord == 45) && (y8cord == 45)) {
		gotoXY(x2cord,y2cord);
		cout << " ";
		x2cord = randomnum(1,74);
		j2 = randomnum(0,79);
		y2cord = 0;
		limit++;
		gotoXY(x5cord,y5cord);
		cout << " ";
		x5cord = randomnum(0,69);
		j5 = randomnum(0,79);
		y5cord = 0;
		gotoXY(x8cord,y8cord);
		cout << " ";
		x8cord = randomnum(4,70);
		j8 = randomnum(0,79);
		y8cord = 0;
	}
	ycord++;
	y1cord += 2;
	y2cord += 3;
	y3cord++;
	y4cord += 2;
	y5cord += 3;
	y6cord++;
	y7cord += 2;
	y8cord += 3;
	gotoXY(25,55);
	cout << score;
	if(score == 0) {
		gotoXY(25,55);
		cout << "   ";
		gotoXY(25,55);
		cout << score;
	}
	gotoXY(0,0);
	counter++;
	Sleep(50);
}

int conversion(int num) {
	switch(num) {
		case 48: {
			score = 0;
			break;
		}
		case 49: {
			score += 1;
			break;
		}
		case 50: {
			score += 2;
			break;
		}
		case 51: {
			score += 3;
			break;
		}
		case 52: {
			score += 4;
			break;
		}
		case 53: {
			score += 5;
			break;
		}
		case 54: {
			score += 6;
			break;
		}
		case 55: {
			score += 7;
			break;
		}
		case 56: {
			score += 8;
			break;
		}
		case 57: {
			score += 9;
			break;
		}
	}
	return 0;
}

int randomnum(int min, int max) {
	int no = (rand() % (max + 1 - min)) + min;
	return no;
}

int numbercolor(int number) {
	switch(number) {
		case 48: {
			color(282);
			break;
		}
		case 49: {
			color(283);
			break;
		}
		case 50: {
			color(284);
			break;
		}
		case 51: {
			color(285);
			break;
		}
		case 52: {
			color(286);
			break;
		}
		case 53: {
			color(287);
			break;
		}
		case 54: {
			color(284);
			break;
		}
		case 55: {
			color(283);
			break;
		}
		case 56: {
			color(287);
			break;
		}
		case 57: {
			color(282);
			break;
		}
	}
	return 0;
}