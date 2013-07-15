#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;
int fillcolor[8]={30,34,63,69,89,111,118,135};
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X=x; coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}	

void  SetWindow(int Width, int Height)
{
COORD coord;
coord.X=Width;
coord.Y=Height;
_SMALL_RECT  Rect;
Rect.Top=0;
Rect.Left=0;
Rect.Bottom=Height-1;
Rect.Right=Width-1;
SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord);
SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&Rect);}
int color(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	return 0;
}

	void menu()
{
	string dclr[1] = {"    "};
		for (int j=0; j<100; j++)
	{
		if(j>=0&&j<61){{gotoXY(0,j);}color(fillcolor[0]);cout<<dclr[0];}
        Sleep(1);
		if(j>2&&j<64){{gotoXY(4,j-3);}color(fillcolor[1]);cout<<dclr[0];}
		Sleep(1);
		if(j>4&&j<66){{gotoXY(8,j-5);}color(fillcolor[2]);cout<<dclr[0];}
		Sleep(1);
		//red color
		if(j>6&&j<68){{gotoXY(12,j-7);}color(fillcolor[3]);cout<<dclr[0];}
		Sleep(1);
		//purple color
		if(j>8&&j<70){{gotoXY(16,j-9);}color(fillcolor[4]);cout<<dclr[0];}
		Sleep(1);
		if(j>10&&j<72){{gotoXY(20,j-11);}color(fillcolor[5]);cout<<dclr[0];}
		Sleep(1);
		if(j>12&&j<74){{gotoXY(24,j-13);}color(fillcolor[6]);cout<<dclr[0];}
		Sleep(1);
		if(j>14&&j<76){{gotoXY(28,j-15);}color(fillcolor[7]);cout<<dclr[0];}
		Sleep(1);

		if(j>16&&j<78){{gotoXY(32,j-17);}color(fillcolor[0]);cout<<dclr[0];}
        Sleep(1);
		if(j>18&&j<80){{gotoXY(36,j-19);}color(fillcolor[1]);cout<<dclr[0];}
		Sleep(1);
		if(j>20&&j<82){{gotoXY(40,j-21);}color(fillcolor[2]);cout<<dclr[0];}
		Sleep(1);
		//red color
		if(j>22&&j<84){{gotoXY(44,j-23);}color(fillcolor[3]);cout<<dclr[0];}
		Sleep(1);
		//purple color
		if(j>24&&j<86){{gotoXY(48,j-25);}color(fillcolor[4]);cout<<dclr[0];}
		Sleep(1);
		if(j>26&&j<88){{gotoXY(52,j-27);}color(fillcolor[5]);cout<<dclr[0];}
		Sleep(1);
		if(j>28&&j<90){{gotoXY(56,j-29);}color(fillcolor[6]);cout<<dclr[0];}
		Sleep(1);
		if(j>30&&j<92){{gotoXY(60,j-31);}color(fillcolor[7]);cout<<dclr[0];}
		Sleep(1);

		if(j>32&&j<94){{gotoXY(64,j-33);}color(fillcolor[0]);cout<<dclr[0];}
        Sleep(1);
		if(j>34&&j<96){{gotoXY(68,j-35);}color(fillcolor[1]);cout<<dclr[0];}
		Sleep(1);
		if(j>36&&j<98){{gotoXY(72,j-37);}color(fillcolor[2]);cout<<dclr[0];}
		Sleep(1);
		if(j>38&&j<100){{gotoXY(76,j-39);}color(fillcolor[3]);cout<<dclr[0];}
		}
		{gotoXY(0,60);}color(fillcolor[0]);cout<<"    ";
		{gotoXY(4,60);}color(fillcolor[1]);cout<<"    ";
		{gotoXY(8,60);}color(fillcolor[2]);cout<<"    ";
		{gotoXY(12,60);}color(fillcolor[3]);cout<<"    ";
		{gotoXY(16,60);}color(fillcolor[4]);cout<<"    ";
		{gotoXY(20,60);}color(fillcolor[5]);cout<<"    ";
		{gotoXY(24,60);}color(fillcolor[6]);cout<<"    ";
		{gotoXY(28,60);}color(fillcolor[7]);cout<<"    ";
		{gotoXY(32,60);}color(fillcolor[0]);cout<<"    ";
		{gotoXY(36,60);}color(fillcolor[1]);cout<<"    ";
		{gotoXY(40,60);}color(fillcolor[2]);cout<<"    ";
		{gotoXY(44,60);}color(fillcolor[3]);cout<<"    ";
		{gotoXY(48,60);}color(fillcolor[4]);cout<<"    ";
		{gotoXY(52,60);}color(fillcolor[5]);cout<<"    ";
		{gotoXY(56,60);}color(fillcolor[6]);cout<<"    ";
		{gotoXY(60,60);}color(fillcolor[7]);cout<<"    ";
		{gotoXY(64,60);}color(fillcolor[0]);cout<<"    ";
		{gotoXY(68,60);}color(fillcolor[1]);cout<<"    ";
		{gotoXY(72,60);}color(fillcolor[2]);cout<<"    ";
	}
	void welcome()
{
	system("color 3F");
	gotoXY(15,13);
	color(70);
	cout << "W      W  EEEE  L      CCCC   OOO   M     M  EEEE " << endl;
	color(71), Sleep(300), gotoXY(15,14);
	cout << "W  W   W  E     L     C      O   O  M M M M  E    " << endl;
	color(72), Sleep(300), gotoXY(15,15);
	cout << "W W  W W  EEEE  L     C      O   O  M  M  M  EEEE " << endl;
	color(73), Sleep(300), gotoXY(15,16);
	cout << "WW    WW  E     L     C      O   O  M     M  E    " << endl;
	color(74), Sleep(300), gotoXY(15,17);
	cout << "W      W  EEEE  LLLLL  CCCC   OOO   M     M  EEEE " << endl;
	color(10), Sleep(1000);

	char robot[3][50]={ {"               Project R.O.B.O.T             "},
						{"Dvelopers: WAJEEH UL HASSAN AND RAMEESHA RANA"},
						{"                  ENJOY ^__^                 "}};
	for (int i=0; i < 3; i++)
		{
			gotoXY(15,23+i);
			for (int j=0 ; j < 50; j++)
				{
					cout << robot[i][j];
					Sleep(100);
				}
			cout << endl;
		}
	Sleep(1000);
}

    void list()
	{
		/*char arr[4][9]={{"New game"},
		                  {"  Help  "},
		                  {" About  "},
		                  {"  Exit  "}};
		for(int i=0; i<4; i++)
		{
			gotoXY(38,27+i);
			for(int j=0; j<9; j++)
			{
               cout<<arr[i][j];
			}
		}}*/
		gotoXY(34,27);
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 287);
		cout<<"Ne";
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 303);
		cout<<"w ga";
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 319);
		cout<<"me";
		gotoXY(36,28);
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 303);
		cout<<"Help";
		gotoXY(36,29);
		cout<<"Abou";
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 319);
		cout<<"t";
		gotoXY(36,30);
		SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 303);
		cout<<"Exit";
	}
int  main()
{	 
SetWindow(80,61);
//welcome();
menu();
list();
getch();
}
