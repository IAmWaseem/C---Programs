#include <iostream>										
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

char game[24][80]={' '};			//  Declare an array of size 24x80 and stores empty spaces in it.

void coloring();
void menucoloring();
void gamestart();
int m=0;		//		m= Movement
int q=0;		//		Row declared globally for catching numbers
int cnvrt(int);	//		for adding to array	
int num[20]={0};//		to store the values of random numbers
int check=0;		//		to check wether the numbers falling are less than 7 
int scr=0;		//		Score
int mcheck=0;

void gotoxy(int x, int y)
{
	HANDLE console_handle;
	COORD cursor_coord;
	cursor_coord.X=x;
	cursor_coord.Y=y;
	console_handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(console_handle,cursor_coord);
}




void main()
{

	
//menucoloring();


int option;

do
{

cout<<endl;
cout<<" 1 - New Game.\n";
cout<<" 2 - About.\n";
cout<<" 3 - Help.\n";
cout<<" 4 - Exit.\n";
cout<<" Enter your choice and press return: ";
cin>>option;

switch (option)
{
case 1:
	{
		gamestart();
		
}


break;
case 2:
									//code to tell about develepors
{
	cout<<"PROJECT --->  PHASE-II\n\n";
	

	cout<<"PROJECT MADE BY :\n";
	
	cout<<"ALI AHSEN MIR (i120160) \n";
	
	cout<<"	AND		\n";
	
	cout<<"BAKHTAWAR NIAZ (i120102) \n\n";
	
	
}
break;

case 3:												//code to help the user like give him

cout<<" In this game the robot has to move and catch numbers.\n If the robot catches 0 all the score will become zero. \n The robot moves with the help of arrow keys.\n THANKYOU for playing this game.\n HAVE A NICE DAY.";
break;

case 4:
{
	cout << "End of Program.\n";
	exit(0);
}
break;

default:
cout << "Not a Valid Choice. \n"
<< "Choose again.\n";
break;
}
getch();
system("cls");
}

while (option !=5);

system("cls");
}

void fallingnumber()
{

	
	static int xcoord=rand()%76;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
	srand(time(0));

	if(xcoord==(29+m) && q==18 )
		{
			check=1;
			game[18][29+m]=num[1];
		}
	else if(xcoord==(30+m) && q==18)
		{
			check=2;
			game[18][30+m]=num[1];
		
		}
	else if(xcoord==(31+m) && q==18)
		{
			check=3;
			game[18][31+m]=num[1];
		}
	
	gotoxy(xcoord, q);
	cout<<num[1];
	gotoxy(xcoord, q-1);
	cout<<' ';
	Sleep(30);
	q++;
	if(q==19)
	{
		for(int w=0; w < 80; w++)
			{
				cout << " ";
			}
		q=0;
		xcoord=rand()%76;
		num[0]=rand()%7;
		for(int e=0; e < 10; e++)
		{
			num[e]=rand() % 7;
		}
	}
																									
}


// -----------------  MENU COLOR -------------------------

void menucoloring()
{

		//	The colors are initialized for use in the array

	for (int x=0; x < 24; x++)				//    ROWS
		{
			for (int y=0; y < 80; y++)		//	  COLUMNS
			{	
				
				if (y==0)	// color is blue 
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);}
				Sleep(1);
				if (y==10)	// color is green
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);}
				Sleep(1);	
				if (y==20)	// color is dull blue
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);}
				Sleep(1);
				if (y==30)	// color is red 
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);} 
				Sleep(1);
				if (y==40)	// color is purple
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);}
				Sleep(1);
				if (y==50)	// color is mustard
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),111);}
				Sleep(1);
				if (y==60)	// color is grey
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),143);}	
				Sleep(1);
				if (y==70)	// color is pink
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),223);}
				Sleep(1);
				if (y==79)	// color is black
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);}
				Sleep(1);	
				
					cout << game[x][y];
					
			}
		

		}
}

//  -------------------  MAIN GAME BACKGROUND COLORS --------------------

void coloring()

{			
	//	The colors are initialized for use in the array

	for (int x=0; x < 24; x++)				//    ROWS
		{
			for (int y=0; y < 80; y++)		//	  COLUMNS
			{	
				
				if (x==0)	// If Rows are greater than or equal to 0 then color is blue 
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),287);}		// 287 is the ASCII for Blue background and white foreground
				
				if (x==19)	// If Rows are greater than or equal to 19 then color is green
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);}		// 47 is the ASCII for Green background and white foreground

				if(x==23)	// If Rows are greater than or equal to 23 then color is yellow
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),232);}		// 232 is the ASCII for Yellow background and black foreground
				
					cout << game[x][y];
			}
		

		}

}

void gamestart()
{
			
			
		char y=0;			//		y= Character defined for input keys
		
		for ( int a=0; a < 80; a++)		// Columns
		{
			game[23][a]=char(178);		//  For the lining design in last row of the array
		}

        
	
		
		

/*			-----------     Movement Structure of the Robot Body -------------
		

		  The movement of robot body is done by the pressing of Left Arrow Key or the Right Arrow Key.
		  
			
																															*/

		
			
		time_t timeout;
        time(&timeout);				
        timeout = timeout + 180;  //180 sec = 3 min
		 while(timeout != time(0))
			

			

		


			for ( ; (timeout != time(0));)			// Infinite Loop
			{
					gotoxy(0,24);
		 cout << "Score is: " << scr;
				fallingnumber();
				gotoxy(0,0);	// For the movement of cursor


				while(kbhit())
				{
			y=getch();		//    Waiting for the input by user

			
			
					if(y==char(75))			// If the pressed key is 'Left Arrow'  the robot moves left
					{
						m--;
			
						if (m==-36)				// Setting the value of left boundary so that the robot does not go out of bounds
						{
							m++;
						}
					}	

	
					if(y==char(77))			// If the pressed key is 'Right Arrow'  the robot moves right

					{
						m++;
	
						if (m==39)			// Setting the value of right boundary so that the robot does not go out of bounds

						{
							m--;
						}
					}

		//		--------------	ROBOT'S MOVING BODY  -------------				
		
	
					
	for(int i=18; i<=22; i++)
	{
		for(int j=0; j<=80; j++)
		{

		
			game[i][j] = 32;	// ASCII value of space = 32 , this is stored bcz all the array except the declared values will be blank



			game[18][35+m]= char(92);	// tray	
			game[18][36+m]= char(196);	// tray	
			game[18][37+m]= char(194);	// tray	
			game[18][38+m]= char(196);	// tray	
			game[18][39+m]= char(47);	// tray	
			game[19][37+m]= char(179);	// tray
			game[19][39+m]= char(2);	// head
			game[20][37+m]= char(192);	// left arm
			game[20][38+m]= char(196);	// left arm
			game[20][39+m]= char(186);	// upper body
			game[20][40+m]= char(196);	// right arm
			game[20][41+m]= char(191);	// right arms
			game[21][39+m]= char(202);	// lower body
			game[21][38+m]= char(218);	// left leg
			game[21][40+m]= char(191);	// right leg
			game[22][38+m]= char(190);	// left foot
			game[22][40+m]= char(212);	// right foot

			if(check==1)
			{
			game[18][36+m]=cnvrt(num[1]); 	// tray	
			}
			else if(check==2)
			{
			game[18][37+m]=cnvrt(num[1]);	// tray
			}
			else if(check==3)
			{
			game[18][38+m]=cnvrt(num[1]);	// tray	
			}
			}
		}

		
	coloring();


	
			


			break;}

}
			
}




  //  Used for stoeing the score

int cnvrt(int x)		// Numberint convert(int num)
	{
		switch (x)
			{
		case 0:
			{
				if(mcheck==0)
				{
				scr=0;
				mcheck=1;
				}
				return 48; 
	
			}
		case 1:
			{
				if(mcheck==0)
				{
				scr=scr+1;
				mcheck=1;
				}
				return 49;
			}
		case 2:
			{
				if(mcheck==0)
				{
				scr=scr+2;
				mcheck=1;
				}
				return 50;
			}
		case 3:
			{
				if(mcheck==0)
				{
				scr=scr+3;
				mcheck=1;
				}
				return 51;
			}
		case 4:
			{
				if(mcheck==0)
				{
				scr=scr+4;
				mcheck=1;
				}
				return 52;
			}
		case 5:
			{
				if(mcheck==0)
				{
				scr=scr+5;
				mcheck=1;
				}
				return 53;
			}
		case 6:
			{
				if(mcheck==0)
				{
				scr=scr+6;
				mcheck=1;
				}
				return 54;
			}

			}
	}