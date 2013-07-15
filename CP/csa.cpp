#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;
char a[24][80]={' '};
int xcord=40;
int ycord=6;
int space=1;
int x;
int y;
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X=x; coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void gridstore();
void gridprint();
void move();
void food();
void swapright();
void swapleft();
void swapup();
void swapdown();


int main()
{
	system("color 1F");

		food();
	
		move();
	
	
	return 0;
}

void gridstore()
{
	for(int i=0; i < 24; i++)
		{
			for(int j=0; j < 80; j++)
				{
					if(j==xcord && i==ycord)
						{continue;}
					if(j==y && i==x)
						{continue;}
					a[i][j]=' ';
				}
		}
}

void food()
{
	srand(time(0));
	y=1 + rand() % 79;
	x=1 + rand() % 23;
	a[x][y]=3;
}
void gridprint()
{

		a[ycord][xcord]=char(178);
	for(int i=0; i < 24; i++)
		{
			for(int j=0; j < 80; j++)
				{
					cout << a[i][j];
				}
		}
	gotoXY(0,0);
}

void move()
{
	static char move;
MAIN:
	gridstore();
	move=_getch();
	

	if(move=='a')			//left movement
		{
			while(1)
			{
				if(xcord==0)
				{goto MAIN;}

				--xcord;
				if(xcord==y && ycord==x)
				{
					space++;
					food();
				}
				swapleft();
				gridprint();
				if(_kbhit())
				{break;}
			}
			
		}
	else if(move=='d')		//right movement
		{
			while(1)
			{
				
				if(xcord==79)
				{goto MAIN;}

				++xcord;
				if(xcord==y && ycord==x)
				{
					space++;
					food();
				}
				swapright();
				gridprint();
				if(_kbhit())
				{break;}
			}
		}
	else if(move=='w')		//upward movement
		{
			while(1)
			{
				if(ycord==0)
				{goto MAIN;}

				--ycord;
				if(ycord==x && xcord==y)
				{
					space++;
					food();
				}
				swapup();
				gridprint();
				if(_kbhit())
				{break;}
			}
		}
	else if(move=='s')		//downward movement
		{
			while(1)
			{
				if(ycord==23)
				{goto MAIN;}

				++ycord;
				if(ycord==x && xcord==y)
				{
					food();
				}
				swapdown();
				gridprint();
				if(_kbhit())
				{break;}
			}
		}
	goto MAIN;
}

void swapright()
{
	a[ycord][xcord-space]=32;

}
void swapleft()
{
	a[ycord][xcord+space]=32;
}
void swapup()
{
	a[ycord+space][xcord]=32;
}
void swapdown()
{
	a[ycord-space][xcord]=32;
}