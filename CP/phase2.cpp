#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
char grid[56][80];
int x=0;             //x used as x coordinate of the grid
int y=42;
int direction = 0;
void background();
void numberfall();
void man();
void move();
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
	GotoXY(5,53);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
	cout<<"Score:";
	GotoXY(0,42);
	man();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
	numberfall();
	getch();
	return 0;
}
void move()
{
			if(x<73)                         //the man stays in the boundary of the grid
			if(GetAsyncKeyState(VK_RIGHT))    //if the user press -> key
			{

				direction = 0;
				x= x+1;
				man();
			}
			if(x>=1)               //the man stays in the boundary of the grid
				if(GetAsyncKeyState(VK_LEFT) )    //if the user press <- key
				{        
					direction = 1;
					x=x-1;
					man();
				}
	
				if(GetAsyncKeyState(VK_ESCAPE))    //when the user press escape key
				{
					exit(1);                        //exit the program
				}
	return ;
}
void background()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
	GotoXY(0,45);       // for shifting cursor 
	for(int i=45;i<49;i++)  //loop for rows
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),02);
		for(int j=0;j<80;j++)  //loop for colomns
		{

			cout<<char(219); // for green color
		}
	}
	for(int i=49;i<50;i++)    //loop for rows
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
	clock_t timer;
	while(1) 
	{
		GotoXY(0,0);
		int a[15]={0};
		int speed[15]={0};
		int column[15];
		for(int i=0;i<15;i++)
		{
			int f;
			f=rand()%100;
			speed[i]=f;
		}
		for(int i=0;i<15;i++)
		{
			int n;
			n=rand()%10;
			a[i]=n;
		}
		for(int j=0;j<15;j++)
		{
			int x;
			x=rand()%79;
			column[j]=x;
		}
	
			for(int k=0;k<15;k++)
			{
				for(int y=0;y<45;y++)
				{
					GotoXY(column[k],y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 95);
					cout<<a[k];
					GotoXY(column[k],y-1);
					cout<<" ";
					if(y==44)
					{
						GotoXY(column[k],y);
						cout<<" ";
					}
					int t;
					GotoXY(56,53);
					cout<<"Timer:";
					t = clock()/CLOCKS_PER_SEC;
					cout << t;
					GotoXY(67,53);
					cout<<"sec";
					if (t==180)
					{
						Sleep(5000);
						exit(1);
					}
					while(kbhit())
					{
						move();
						break;
					}
					Sleep(speed[k]);
				}
			}
	}
}
void man()
{
		GotoXY(x-1,y);                  //shifts the cursor
	//so the first character is not repeated when the man is in new forward position is printed
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);   
		cout<<" ";
		GotoXY(x-2,y);
		cout <<" ";
	//moves one place forward on one press
	GotoXY(x,y);    //the value of x changed cursor moves to new position
	char robot[7][7]={{0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0},
						{92,196,194,196,47,0,0},
						{0,0,179,0,1,0,0},
						{0,0,192,196,186,196,191},
						{0,0,0,218,208,191,0},	
						{0,0,0,217,0,192,0}};//robot array intializing characters for the body of robot
	//for printing robot without changing the background colors
	for(int i=0;i<7;i++)       //for rows
	{
		for(int j=0;j<7;j++)   //for columns
		{
			if(i==0)          //for the first row display purple color
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
			if(i==3)          //for the third row display yellow color
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
			GotoXY(x+j,y+i);   //for the shifting of cursor 
			cout << robot[i][j];   //printing of the man

		}
	}
	GotoXY(0,0);//cursor move back to the top of the grid
	if(direction == 1) {
		GotoXY(x+7,y+2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
		cout<<"  ";
		GotoXY(x+7,y+3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
		cout <<" ";
		GotoXY(x+7,y+4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
		cout <<" ";
	}
	if(direction==0){
			GotoXY(x-1,y+2);                  //shifts the cursor
			//so the first character is not repeated when the man is in new forward position is printed
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);   
			cout<<" ";
			//moves one place forward on one press
	}



	GotoXY(x,y);    //cursor back to the first character of the man
}