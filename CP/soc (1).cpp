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
		for (int j=0; j<135; j++)
	{
		if(j<55){{gotoXY(0,j);}color(fillcolor[0]);cout<<dclr[0];}
        Sleep(2);
		if(j>4&&j<60){{gotoXY(4,j-5);}color(fillcolor[1]);cout<<dclr[0];}
		Sleep(2);
		if(j>8&&j<64){{gotoXY(8,j-9);}color(fillcolor[2]);cout<<dclr[0];}
		Sleep(2);
		//red color
		if(j>12&&j<68){{gotoXY(12,j-13);}color(fillcolor[3]);cout<<dclr[0];}
		Sleep(2);
		//purple color
		if(j>16&&j<72){{gotoXY(16,j-17);}color(fillcolor[4]);cout<<dclr[0];}
		Sleep(2);
		if(j>20&&j<76){{gotoXY(20,j-21);}color(fillcolor[5]);cout<<dclr[0];}
		Sleep(2);
		if(j>24&&j<80){{gotoXY(24,j-25);}color(fillcolor[6]);cout<<dclr[0];}
		Sleep(2);
		if(j>28&&j<84){{gotoXY(28,j-29);}color(fillcolor[7]);cout<<dclr[0];}
		Sleep(2);
		}

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
