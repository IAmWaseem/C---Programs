#include<iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include<stdio.h>
#include<conio.h>
using namespace std;
#include <string>
void background(); //function for background
void robot(int x); //function for body
void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    
    SetConsoleCursorPosition( hStdout, position ) ;
}
int score=0;



HANDLE hOUT = GetStdHandle(STD_OUTPUT_HANDLE);

void SetWindow(int Width, int Height) {
	COORD coord;
	coord.X = Width;
	coord.Y = Height;
	SetConsoleScreenBufferSize(hOUT, coord);
	SMALL_RECT CurInfo;
	CurInfo.Top = 0;
	CurInfo.Left = 0;
	CurInfo.Bottom = Height - 1;
	CurInfo.Right = Width - 1;
	SetConsoleWindowInfo(hOUT, TRUE, &CurInfo);
	return;
}



void counter(int score)
{	
	gotoxy(0,27);
	cout<<"Score: "<<score;
}
void main() //main body

{
	SetWindow(80,28);
	counter(score);

	int i,j;
char falln[19][80];
	char temmp[19][80];
	int delay=0;

	srand (time(0));
	int location,value;

	for (i=0; i<19; i++)
		{
           	for ( j=0; j<80; j++)
			{
				falln[i][j]=' ';
			}
		}
	 counter(score);

	int x;
	int y;
    int count=0;
	x=40;
	y=20;
		
	char grid[25][80]; //Main Grid
	background();
	robot(x);
	while(1)
	{
	
	
		gotoxy(0,0);


		location = rand () % 78;
		value = rand () % 6;

		for ( j=0; j<80; j++)
			{
               if(j==location && delay==5)
			   {
                	temmp[0][j]=value+48;
					delay=0;
					
			   }
			   else
				temmp[0][j]=' ';
			}

		delay++;
		for (i=1; i<19; i++)
		{
           	for ( j=0; j<80; j++)
			{
				temmp[i][j]=falln[i-1][j];
			}
		}
////////////////////////printing
		
		for ( i=0; i<19; i++)
		{
           	for ( j=0; j<80; j++)
			{
				falln[i][j]=temmp[i][j];
			cout << temmp[i][j];
			}
		}///////////////////////////////////
		/////////////////////

   

		if(GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState(100)||GetAsyncKeyState(68)) //For movement towards RIGHT
		{
			x=x+1;
			count=1;
			
		}
		else if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(97)||GetAsyncKeyState(65)) //For movement towards LEFT

		{
			x=x-1;
			count=1;
		}

		else
		count=0; //For voiding any other key input
	
	
		if(x>77)
		{
		    counter(score);
			x=77;
			cout<<"\a"; //If it exceeds boundary
		}
		else if(x<4)
		{	counter(score);
			x=4;
			cout<<"\a"; //If it exceeds boundary
		}


		if(count==1)
		{

		
			robot(x);
		
		}

		Sleep(30);

	}

  
}

void background() //Background Function
{

	char grid[25][80]; 
		HANDLE hOut;

		system("color 17");
//		system ("cls");
		gotoxy (0,20);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); //Color change
	SetConsoleTextAttribute(hOut,
	BACKGROUND_GREEN);



	for(int i=19; i<23; i++) //Grid 1
	{
		for (int j=0; j<80; j++)
		{

			grid[i][j]=' ';
			cout << grid[i][j];


		}
	
	}

	SetConsoleTextAttribute(hOut, //Color set
	BACKGROUND_RED | BACKGROUND_GREEN );

	for (int i=0; i<80;i++) //Grid3 for design
	{
		cout<<grid[24][i];
	
		
		cout<<grid[24][i];
		grid[24][i]=char ( 176);
	}

	
}

 
void robot(int x) //Robot function 
{


   
	int y=20;
    char a;
    HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
	BACKGROUND_GREEN|FOREGROUND_RED|FOREGROUND_GREEN | FOREGROUND_BLUE ); //For green color

	gotoxy (x-3,y); //characters for displaying robot
	cout<<' ';
    a=179;
    cout<<a;
   
	cout<<' ';
	a=1;
	cout<<a;
	cout<<' ';
	gotoxy (x-3,y+1);

	cout<<' ';
	a=192;
	cout<<a;
   	a=196;
	cout<<a;
	a=186;
	cout<<a;
    a=196;
	cout<<a;
	a=191;
	cout<<a;
	cout<<' ';
   	gotoxy (x-2,y+2);
	cout<<' ';
	a=218;
	cout<<a;	
   	a=208;
    cout<<a;	
   	a=191;
    cout<<a;
	cout<<' ';
	gotoxy (x-2,y+3);
	cout<<' ';
	a=217;
    cout<<a;
	cout<<' ';	
	a=192;
    cout<<a;
	cout<<' ';
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
	BACKGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN | FOREGROUND_BLUE ); //For tray (blue/white)

	gotoxy (x-5,y-1);
	cout<<' ';
	a=92;
    cout<<a;

	a=196;
    cout<<a;
	a=194;
    cout<<a;
	a=196;
    cout<<a;

    a=47;
    cout<<a;
	cout<<' ';


}




