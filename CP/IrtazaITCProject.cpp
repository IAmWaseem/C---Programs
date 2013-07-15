#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;

HANDLE hOUT = GetStdHandle(STD_OUTPUT_HANDLE);


char grid[25][80]={0}; //2d array wid spaces

char robot[5][7] = {  // array for robot. 
	{92,196,194,196,47},
	{0,0,179,0,1},
	{0,0,192,196,186,196,191},
	{0,0,0,218,208,191},
	{0,0,0,217,0,192}
};
int x=0,y=18; //starting ..


void gotoxy(int x,int y) //meine gotoxy declare kia.. 

{
	COORD coord_name;  
	coord_name.X = x; 
	coord_name.Y = y; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord_name);
}

void SetWindow(int Width, int Height) //console window ka size setting..
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size

}

void setcolor() //1st colour scheme..
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |FOREGROUND_INTENSITY | 1);
}

void setcolor2() //2nd colour schemeeee...
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,BACKGROUND_RED |BACKGROUND_GREEN | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
}

void blue() //blue wala
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |FOREGROUND_INTENSITY | 1);
}

void colors() //printing of colors.
{
	gotoxy(0,0);
	for(int i=0;i<25;i++) //for the y-axis 
	{
		for (int j=0;j<80;j++) //for the x-axis
		{
			if (i==0)
			{ 
				blue(); 
			}
			if (i==19)
			{
				setcolor();
			}
			if (i==24)
			{
				setcolor2();
				cout<<char(grid[i][j]=176);
			}
			else {
				cout<<grid[i][j];
			}
		}
	}
}

void displayrobot()  //robot display
{  
	for(int i=0;i<5;i++) {
		for(int j=0;j<7;j++) {
			if(i==0)
				blue();
			if(i==1)
				setcolor();
			gotoxy(x+j,y+i);
			cout << robot[i][j];
		}
	}
}



void setcolor3() //1st colour scheme..
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED |FOREGROUND_INTENSITY | 1);
}

void Gotoxy(int x, int y) 
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(hOUT, coord);
	return;
}

void SetColor(int n) //declaring the function for color ...

{
	SetConsoleTextAttribute(hOUT, n);
	return;
}

void endcolor() //change of color ... for about change.
{

	int cx=0;
	int Colors[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //colours of each line

	Gotoxy(0,0);
	for(int lines=1;lines<=20;lines++) //no. of colors.... lines to be printed

	{	

		cout<<char(0)<<char(0)<<char(0)<<char(0);

		SetColor(Colors[lines-1]); 
		for(int i=0;i<26;i++) //rows.
		{
			for(int j=0;j<4;j++)  //spacing btwn the  colors.
			{
				cout << char(0); //puting a space 
			}

			Gotoxy(cx,i);
			Sleep(10);
		}

		Gotoxy(cx,0);
		cx = cx + 4; //gapping btwn the colours..
	}

}





void startcolor()  // start screen coloring...
{

	int cx=0;
	int Colors[] = {31,47,63,79,95,111,127,143,159,175,191,207,223,239,31,47,63,79,95,111,127}; //colours of each line

	Gotoxy(0,0);
	for(int lines=1;lines<=20;lines++) //no. of colors.... lines to be printed

	{	

		cout<<char(0)<<char(0)<<char(0)<<char(0);

		SetColor(Colors[lines-1]); 
		for(int i=0;i<26;i++) //rows.
		{
			for(int j=0;j<4;j++)  //spacing btwn the  colors.
			{
				cout << char(0); //puting a space 
			}

			Gotoxy(cx,i);
			Sleep(10);
		}

		Gotoxy(cx,0);
		cx = cx + 4; //gapping btwn the colours..
	}

}

void numbfall()
{
	int x,y,z;
	x=rand()%79;
	z=rand()%7;
	gotoxy(x,0);
	cout<<z;
	for(int i=0;i<19;i++)
	{
		while(kbhit()) {
		if((GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(68)) && ::x<73) //for input keys for right and limits.
				{	
					Sleep(100);
					blue();
					gotoxy(::x,::y);
					cout << " ";
					::x=::x+1;
					gotoxy(::x,::y);
					displayrobot();
					gotoxy(::x,::y);
				}
				if((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(65)) && ::x>0) //for input keys for left and limits.
				{	
					Sleep(100);
					gotoxy(::x+6,::y+2);
					cout << " ";
					blue();
					::x=::x-1;
					gotoxy(::x,::y);
					displayrobot();
					gotoxy(::x,::y);
				}
				break;
	}
		blue();
		gotoxy(x,i++);
		cout<<z;
		if(z==0)
		{ 
			Sleep(100);
		}
		if(z==1)
		{
			Sleep(500);
		}
		if(z==2)
		{
			Sleep(400);
		}
		if(z==3)
		{	
			Sleep(350);
		}
		if(z==4)
		{
			Sleep(250);
		}
		if(z==5)
		{
			Sleep(200);
		}
		if(z==6)
		{
			Sleep(120);
		}
		gotoxy(x,i-1);
		cout << char(NULL);
		clock_t t = 0;
		t = clock()/CLOCKS_PER_SEC;			
		t = t - 19;
		gotoxy(24,0);
		cout<<t;
		gotoxy(0,0);
	}
}

void startmenu() //menu ha . wid coloured back ground :p
{
	SetWindow(80,27);
	startcolor();
	int d,t;
	char c,b;
	SetColor(6);
	Gotoxy(31,10);
	cout<<"Welcome to My Game "<<endl;  // main screen p jo likha ha 
	Gotoxy(31,11);
	cout<<"                   ";
	Gotoxy(31,12);
	cout<<"1. Start Game      ";
	Gotoxy(31,13);
	cout<<"2. About           ";
	Gotoxy(31,14);
	cout<<"3. HELP !!         ";
	Gotoxy(31,15);
	cout<<"4. Exit            ";
	while(1)
	{
		b=getch();
		t=b;
		if((t==49)||(t==50)||(t==51)||(t==52))
		{
			break;
		}
	}
	switch(b)
	{
		case '1':   //case for starting game...
		{ 
			endcolor();		
			colors();
			displayrobot();		
			gotoxy(0,0);
			while(1)
			{
				numbfall();	
			}
		}
		case '2':  // about page..
		{
			endcolor();
			startcolor();
			SetColor(6);
			Gotoxy(30,10);
			cout<<"Made By: M.Irtaza & Ahad Aamir ";
			Gotoxy(30,11);
			cout<<"Enjoy Playing Game             ";
			Gotoxy(30,12);
			cout<<"                               ";
			Gotoxy(30,13);
			cout<<"Press Esc/Back-space to Return ";
			while(1)
			{
				c=getch();
				d=c;
				if((d==27) ||(d==8)) //checking for ESC key. and Back space.
				{
					endcolor();
					startmenu();
					break;
				}
			}
		}
		case '3':
		{
			endcolor();
			startcolor();
			SetColor(6);
			Gotoxy(28,10);
			cout<<"Press A and D key to basket a number.";
			Gotoxy(28,11);
			cout<<"You must prevent 0 to be basket      ";
			Gotoxy(28,12);
			cout<<"You have Limited Time.               ";
			Gotoxy(28,13);
			cout<<"                                     ";
			Gotoxy(28,14);
			cout<<"Press Esc/Back-space to Return       ";
			while(1)
			{
				c=getch();
				d=c;
				if((d==27) ||(d==8)) //checking for ESC key. and Back space.
				{
					endcolor();
					startmenu();
					break;
				}
			}
		}
		case '4':
		{
			system("cls");
			exit(1);  // exits the console window .. onli when .exe 
		}
	}
	Gotoxy(0,0);
	setcolor();
}

void main() 

{
	startmenu();
}