#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
using namespace std;
char a[24][80]={' '};			//global variable can be used in every function including the main function
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
	int x=0;
	int c=0;  // for color array
	string dclr[1] = {"    "};
	for (int i=0; i<1; i++)  // number of times to generate colors
	{
		for (int j=0; j<94; j++)
	{
		if(j>=0&&j<55){{gotoXY(0,j);}color(fillcolor[0]);cout<<dclr[0];}
        Sleep(1);
		if(j>2&&j<58){{gotoXY(4,j-3);}color(fillcolor[1]);cout<<dclr[0];}
		Sleep(1);
		if(j>4&&j<60){{gotoXY(8,j-5);}color(fillcolor[2]);cout<<dclr[0];}
		Sleep(1);
		//red color
		if(j>6&&j<62){{gotoXY(12,j-7);}color(fillcolor[3]);cout<<dclr[0];}
		Sleep(1);
		//purple color
		if(j>8&&j<64){{gotoXY(16,j-9);}color(fillcolor[4]);cout<<dclr[0];}
		Sleep(1);
		if(j>10&&j<66){{gotoXY(20,j-11);}color(fillcolor[5]);cout<<dclr[0];}
		Sleep(1);
		if(j>12&&j<68){{gotoXY(24,j-13);}color(fillcolor[6]);cout<<dclr[0];}
		Sleep(1);
		if(j>14&&j<70){{gotoXY(28,j-15);}color(fillcolor[7]);cout<<dclr[0];}
		Sleep(1);

		if(j>16&&j<72){{gotoXY(32,j-17);}color(fillcolor[0]);cout<<dclr[0];}
        Sleep(1);
		if(j>18&j<74){{gotoXY(36,j-19);}color(fillcolor[1]);cout<<dclr[0];}
		Sleep(1);
		if(j>20&&j<76){{gotoXY(40,j-21);}color(fillcolor[2]);cout<<dclr[0];}
		Sleep(1);
		//red color
		if(j>22&&j<78){{gotoXY(44,j-23);}color(fillcolor[3]);cout<<dclr[0];}
		Sleep(1);
		//purple color
		if(j>24&&j<80){{gotoXY(48,j-25);}color(fillcolor[4]);cout<<dclr[0];}
		Sleep(1);
		if(j>26&&j<82){{gotoXY(52,j-27);}color(fillcolor[5]);cout<<dclr[0];}
		Sleep(1);
		if(j>28&&j<84){{gotoXY(56,j-29);}color(fillcolor[6]);cout<<dclr[0];}
		Sleep(1);
		if(j>30&&j<86){{gotoXY(60,j-31);}color(fillcolor[7]);cout<<dclr[0];}
		Sleep(1);

		if(j>32&&j<88){{gotoXY(64,j-33);}color(fillcolor[0]);cout<<dclr[0];}
        Sleep(1);
		if(j>34&j<90){{gotoXY(68,j-35);}color(fillcolor[1]);cout<<dclr[0];}
		Sleep(1);
		if(j>36&&j<92){{gotoXY(72,j-37);}color(fillcolor[2]);cout<<dclr[0];}
		Sleep(1);
		if(j>38&&j<94){{gotoXY(76,j-39);}color(fillcolor[3]);cout<<dclr[0];}
		}
		{gotoXY(0,54);}color(fillcolor[0]);cout<<"    ";
		{gotoXY(4,54);}color(fillcolor[1]);cout<<"    ";
		{gotoXY(8,54);}color(fillcolor[2]);cout<<"    ";
		{gotoXY(12,54);}color(fillcolor[3]);cout<<"    ";
		{gotoXY(16,54);}color(fillcolor[4]);cout<<"    ";
		{gotoXY(20,54);}color(fillcolor[5]);cout<<"    ";
		{gotoXY(24,54);}color(fillcolor[6]);cout<<"    ";
		{gotoXY(28,54);}color(fillcolor[7]);cout<<"    ";
		{gotoXY(32,54);}color(fillcolor[0]);cout<<"    ";
		{gotoXY(36,54);}color(fillcolor[1]);cout<<"    ";
		{gotoXY(40,54);}color(fillcolor[2]);cout<<"    ";
		{gotoXY(44,54);}color(fillcolor[3]);cout<<"    ";
		{gotoXY(48,54);}color(fillcolor[4]);cout<<"    ";
		{gotoXY(52,54);}color(fillcolor[5]);cout<<"    ";
		{gotoXY(56,54);}color(fillcolor[6]);cout<<"    ";
		{gotoXY(60,54);}color(fillcolor[7]);cout<<"    ";
		{gotoXY(64,54);}color(fillcolor[0]);cout<<"    ";
		{gotoXY(68,54);}color(fillcolor[1]);cout<<"    ";
		{gotoXY(72,54);}color(fillcolor[2]);cout<<"    ";
	x=x+4;    // change position of goto to next coloum
	c=c+1;   // color array increment 
	if(c>7){c=0;}  //next bunch of colors 
	}

	}

	

int  main()
{	 
SetWindow(80,55);
menu();	
getch();

}
