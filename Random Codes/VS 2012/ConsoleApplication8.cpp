#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool Array[24][79] = {false};
int HeadX = 0;
int HeadY = 0;
int TailX = 0;
int TailY = 0;
int direction = 1;  // 1 right, 2 up, 3 left, 4 down

int SnakeXCoordinates[200]={0};
int SnakeYCoordinates[200]={0};
int SnakeSize=0;

bool egg = false;
int eggX = 0;
int eggY = 0;
int Score = 0;

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}

void Clear_Box(int x1, int y1, int x2, int y2) // Coordinates of the inside box
{
	GotoXY(5,1);
	cout << "Introduction to Computer Science - Fall 2012 Semester - NUCES, Islamabad" << endl;

	GotoXY(10,2);
	cout << "Score: " << Score << "   a : Left  d : right  w : up  s : down" << endl;
	
	int x,y;
	for (y=y1+1;y<y2;y++)
	{
		for (x=x1+1;x<x2;x++)
		{
			GotoXY(x,y);
			cout.put(' ');
			cout.flush();
		}
	}
	
}

void Make_Box()
{
	GotoXY(0,0);
	int j=4;
	for (int i=5; i <= 75;i++)
	{
		GotoXY(i,j);
		cout.put((char) 205);
		cout.flush();
	}
	
	j=22;
	for (int i=5; i <= 75;i++)
	{
		GotoXY(i,j);
		cout.put((char) 205);
		cout.flush();
	}
	
	int i=5;
	for (j=4; j <= 22;j++)
	{
		GotoXY(i,j);
		cout.put((char) 186);
		cout.flush();
	}

	i=75;
	for (j=4; j <= 22;j++)
	{
		GotoXY(i,j);
		cout.put((char) 186);
		cout.flush();
	}


	return;
}

void Initialize_Snake()
{
	Score = 0;
	egg = false;
	int x,y;
	for (y=0;y<24;y++)
		for (x=0;x<79;x++)
			Array[y][x]=false;
			
	Array[10][50] = true;
	Array[10][51] = true;
	Array[10][52] = true;
	TailX = 50;
	TailY = 10;
	HeadX = 52;
	HeadY = 10;
	direction = 1;

	SnakeSize=3;
	SnakeXCoordinates[0]=50;
	SnakeXCoordinates[1]=51;
	SnakeXCoordinates[2]=52;
	SnakeYCoordinates[0]=10;
	SnakeYCoordinates[1]=10;
	SnakeYCoordinates[2]=10;

}

void Key_Pressed()
{
	char ch;
	if ( kbhit() )
	{
		ch = getch();
     	if ( (ch == 'd') && (direction != 1 ) && (direction != 3) )
		{
			direction = 1;

		}
     	else if ( (ch == 'a') && (direction != 1 ) && (direction != 3) )
		{
			direction = 3;

		}
     	if ( (ch == 'w') && (direction != 2 ) && (direction != 4) )
		{
			direction = 2;

		}
     	if ( (ch == 's') && (direction != 2 ) && (direction != 4) )
		{
			direction = 4;

		}

		if (ch == (char) 27)  // Escape key to exit
			exit(1);
	}

}

void Update_Snake_Location()
{
	Array[TailY][TailX] = false;
	for (int i=0;i<SnakeSize-1;i++)
	{
		SnakeXCoordinates[i]= SnakeXCoordinates[i+1];
		SnakeYCoordinates[i]= SnakeYCoordinates[i+1];	
	}

	if (direction == 1)
		HeadX++;
	else if (direction == 2)
		HeadY--;
	else if (direction == 3)
		HeadX--;
	else
		HeadY++;

	SnakeXCoordinates[SnakeSize-1]=HeadX;
	SnakeYCoordinates[SnakeSize-1]=HeadY;
			
	TailX=SnakeXCoordinates[0];
	TailY=SnakeYCoordinates[0];
			
	Array[HeadY][HeadX] = true;
	
	// check eating of egg
	if (HeadX == eggX && HeadY == eggY)
	{
		SnakeSize++;
		for (int i=SnakeSize-1;i>=1;i--)
		{
			SnakeXCoordinates[i]= SnakeXCoordinates[i-1];
			SnakeYCoordinates[i]= SnakeYCoordinates[i-1];	
		}

		Score = Score + 10;

		GotoXY(10,2);
		cout << "                                                                         ";
		cout.flush();
		GotoXY(10,2);
		cout << "Score: " << Score << "   a : Left  d : right  w : up  x : down" << endl;
	
	
		egg = false;
	}
}


void Display_Snake()
{
	int x,y;
	for (y=4;y<=22;y++)
	{
		for (x=5;x<=75;x++)
		{
			if (Array[y][x])
			{
				GotoXY(x,y);

				if (x==TailX && y==TailY)
				{
					cout.put((char) 177);
					cout.flush();
				}
				else if (x == HeadX && y ==HeadY)
				{
					cout.put((char) 178);
					cout.flush();
				}
				else
				{
					cout.put((char) 219);
					cout.flush();
				}
			}
		}
	}

}

void Check_Collision()
{
	// Collision with boundary
	if (HeadX == 5 || HeadX == 75 || HeadY == 4 || HeadY == 22)
	{
		GotoXY(15,10);
		cout << "The snake has hit the boundary" << endl;
		GotoXY(10,15);
		cout << "Want to play again, Press y key to continue, any other to exit" << endl;
		char ch = getch();
		if (ch == 'y')
		{
			Clear_Box(5,4,75,22);	
			Initialize_Snake();
			return;
		}
		else
			exit(1);
	}

	// Collision of Snake with itself
	for (int i=0;i<SnakeSize-1;i++)
	{
		if ( SnakeXCoordinates[i] == HeadX && SnakeYCoordinates[i] == HeadY )
		{
			GotoXY(15,10);
			cout << "The snake has hit itself" << endl;
			GotoXY(10,15);	
			cout << "Want to play again, Press y key to continue, any other to exit" << endl;
			char ch = getch();
			if (ch == 'y')
			{
				Clear_Box(5,4,75,22);	
				Initialize_Snake();
				return;
			}
			else
				exit(1);
		}
	}

}

void Clear_from_Tail()
{
	GotoXY(TailX,TailY);
	cout.put(' ');
	cout.flush();

}

void Create_Egg()
{
	bool overlapping = false;
	do
	{
		eggX = (rand()%66) + 7;
		eggY = (rand()%15) + 6;
		// check it does not overlap with snake coordinates
		for (int i=0;i<SnakeSize;i++)
		{
			if ( SnakeXCoordinates[i] == eggX && SnakeYCoordinates[i] == eggY )
			{
				overlapping = true;
				break;
			}
		}
	} while (overlapping);
}

void Check_Egg_Update_Score()
{
	if (!egg)
	{
		Create_Egg();
		egg = true;
	}
	GotoXY(eggX,eggY);
	cout.put( (char) 232 );
	cout.flush();

}


int main()
{
	srand( time(NULL));
    system("color A0");
	Initialize_Snake(); // Initialize the snake at its initial coordinates
	

	system("cls");
	Make_Box();
	Clear_Box(5,4,75,22);
	for ( ; ; )
	{
		Display_Snake();
		Key_Pressed();
		Sleep(150); // Parameter is duration in milliseconds
		Clear_from_Tail();		
		Update_Snake_Location();
		Check_Collision();  // Check collision of snake with boundary of box and with itself
		Check_Egg_Update_Score();
	}
	return 0;
}