#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
char grid[56][80];
int x=0;             //x used as x coordinate of the grid
int y=44;
void background();
void numberfall();
void man();
void GotoXY(int x,int y)
{
		COORD coord;
		coord.X=x;coord.Y=y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
		return;
}

void SetWindow(int Width,int Height)
{
	COORD coord;
	coord.X=Width;
	coord.Y=Height;
	_SMALL_RECT Rect;
	Rect.Top=0;
	Rect.Left=0;
	Rect.Bottom=Height-1;
	Rect.Right=Width-1;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&Rect);

}
int main()
{
	system("color 5F");
	SetWindow(80, 56);
	background();
	GotoXY(0,45);
	man();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95); 
	numberfall();
		getch();
	return 0;
}
void move()
	{
	while(1)                             //condition always true
	{		
		if(x<73)                         //the man stays in the boundary of the grid
		if(GetAsyncKeyState(VK_RIGHT))    //if the user press -> key
		{
			
			
			GotoXY(x,y);                  //shifts the cursor
			//so the first character is not repeated when the man is in new forward position is printed
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);   
			cout<<" ";
			//moves one place forward on one press
			x=x+1;
			GotoXY(x,y);    //the value of x changed cursor moves to new position
			man();          //man printed in new position
			GotoXY(x,y);    //cursor back to the first character of the man
		}
		if(x>=1)               //the man stays in the boundary of the grid
		if(GetAsyncKeyState(VK_LEFT) )    //if the user press <- key
		{        
			
			GotoXY(x,y);             //shifts the cursor
			x=x-1;
			GotoXY(x,y);            //the value of x changed cursor moves to new position
			man();                     //man printed in new position
			//so the last character is not repeated when the man is in new previous position is printed
			GotoXY(x+7,y+2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
			cout<<" ";
			GotoXY(x,y);    //cursor back to the first character of the man
		}
		if(GetAsyncKeyState(VK_ESCAPE))    //when the user press escape key
		{
        exit(1);                        //exit the program
        }
	}

	
	getch();
	return ;
}
void background()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
	GotoXY(0,46);       // for shifting cursor 
	for(int i=46;i<50;i++)  //loop for rows
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),02);
		for(int j=0;j<80;j++)  //loop for colomns
		{
		
			cout<<char(219); // for green color
		}
	}
	for(int i=50;i<51;i++)    //loop for rows
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),78);
		for(int j=0;j<80;j++)   //loop for colomns
		{
			cout<<char(178);  // for displaying yellow color 
		}
	}
	
}
void numberfall()
{
	srand(time(0));
	int columns[10] = {0};
	int k = 0;
	for(int i=0;i<10;i++)
	{
		int n = 48 + rand() % 10;
		int rc = rand() % 80;
		columns[i] = rc;
		grid[k][rc] = char(n);
	}
	for(int m=0;m<45;m++) 
	{
		for(int i=0;i<44;i++) 
		{
			for(int j=0;j<80;j++) 
			{ 
				cout << grid[i][j];
				
			}
		}
		int temp;
		for(int i=0;i<10;i++)
		{
			temp = grid[k+1][columns[i]];
			grid[k+1][columns[i]] = grid[k][columns[i]];
			grid[k][columns[i]] = temp;
			
		}
		//move();
		k++;
		Sleep(100);
		GotoXY(0,0);
		//move();
	}
	move();
}
void man()
{
	char robot[5][7]={{92,196,194,196,47,0,0},{0,0,179,0,1,0,0},{0,0,192,196,186,196,191},{0,0,0,218,208,191,0},{0,0,0,217,0,192,0}};//robot array intializing characters for the body of robot
	//for printing robot without changing the background colors
	for(int i=0;i<6;i++)       //for rows
	{
		for(int j=0;j<7;j++)   //for columns
		{
			if(i==0)          //for the first row display purple color
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
			if(i==1)          //for the second row display yellow color
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
			GotoXY(x+j,y+i);   //for the shifting of cursor 
			cout << robot[i][j];   //printing of the man
			
		}
	}
	GotoXY(0,0);//cursor move back to the top of the grid
}
