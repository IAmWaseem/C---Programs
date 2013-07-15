#include<iostream>
#include<conio.h>
#include<Windows.h>
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
	for (int i=0; i<20; i++)  // number of times to generate colors
	{
		for (int j=0; j<55; j++)
	{
		gotoXY(x,j);    // x is the row position and j is the coloum
		color(fillcolor[c]);  // array will fill the color
		cout<<"    ";
		Sleep(3);
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
