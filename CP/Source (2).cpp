#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;

char a[25][80]={' '};
void falooda()//output screen display before starting the game
{
	cout<<"Tehreem Arif i12-0229 HAsnain Ali i120080 \n";
}
/* copying the goto xy function here to be called later on in the main function.
used only once in the main function*/
void gotoxy(int x, int y)
{
	HANDLE console_handle;
	COORD cursor_coord;
	cursor_coord.X=x;
	cursor_coord.Y=y;
	console_handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(console_handle,cursor_coord);
}

void fallingnumber(void);
int xcoord=rand()%70;
int i=0;
int strafe=0;
int number[10]={0};
int check=0;
int convert(int);
int score=0;

void main()
{
	falooda();//calling the function before the game to display
//array for the robot visible for easier translation when movement is executed		
a[19][34]=char(1);//head
a[20][34]=char(186);//upper body
a[20][33]=char (196);//left arm
a[20][35]=char (196);//right arm
a[20][36]=char (191);//right hand
a[20][32]=char (192);//left arm extensnion
a[19][32]=char (179);//left hand
a[18][32]=char (194);//tray body
a[18][31]=char (196);//tray extension left
a[18][33]=char (196);//tray extension right
a[18][30]=char (92);//tray boundary (left)
a[18][34]=char (47);//tray boundary (right)
a[21][34]=char (186);//lower body
a[22][34]=char (208);//lower body connection with the limbs
a[22][33]=char (218);//left knee
a[22][35]=char (191);//right knee
a[23][33]=char (217);//left foot
a[23][35]=char (192);//right foot

//initializing variable which adds to the movement in array locations for the robot
char m;//varaible declared to take input from the user


//can use either a while loop or a for loop (both should be infinte)
		//for (;;)

		time_t timeout;
         time(&timeout);   /// get Current time;
         timeout = timeout + 180;  /// one minute is equal to 60 sec 6 mins are added to timeout
		 while(timeout != time(0))
			{

				fallingnumber();
				gotoxy(0,0);//initializing the cursor at array location [0][0]
				
			while(_kbhit())
			{
				m=getch();//takes the input key from the user
			
				

			
			if(m==char(97)|| m==char(75))//left side movement "a" and left arrow key
			{
					strafe--;
								
			 
		//FIRST CHECK
			if (strafe==-31)//checks the left boundary, if movement exceeds, robot stops
				{
					strafe++;
				
				}
			}

		if(m==char(100)|| m==char(77))//right side movement, "d" and right arrow key
		{
			strafe++;
			//SECOND CHECK
			if (strafe==44)//checks the right boundary, if robot's movement exceeds, stops the robot
			{
				strafe--;
			
			}
		}
			
/* as the robot is only required to move horizontally, we will only add the movement variable 
in the column array locations, so that the robot moves only horizontally. A similar variable and 
function can be introduced if we want to move the robot vertically too*/

		for(int t1=17; t1<=25; t1++)
			{
			for(int p1=0; p1<=80; p1++)
			{
				if(p1==(32+strafe) || p1==(31+strafe) || p1==(33+strafe))
				{
					if(t1==18)
					{
					continue;
					}
				}
				a[t1][p1] =char (32);
			}
			}
		for(int t=0; t<=25; t++)
		{
			for(int p=0; p<=80; p++)
			{
		
			
			
			a[19][34+strafe]=char (1);//head
			a[20][34+strafe]=char (186);//upper body
			a[20][33+strafe]=char (196);//left arm
			a[20][35+strafe]=char (196);//right arm
			a[20][36+strafe]=char (191);//right hand
			a[20][32+strafe]=char (192);//left arm extensnion
			a[19][32+strafe]=char (179);//left hand
			a[18][32+strafe]=char (194);//tray body
			
			a[18][31+strafe]=char (196);//tray extension left
			
			a[18][33+strafe]=char (196);//tray extension right
			
			a[18][30+strafe]=char (92);//tray boundary (left)
			a[18][34+strafe]=char (47);//tray boundary (right)
			a[21][34+strafe]=char (186);//lower body
			a[22][34+strafe]=char (208);//lower body connection with the limbs
			a[22][33+strafe]=char (218);//left knee
			a[22][35+strafe]=char (191);//right knee
			a[23][33+strafe]=char (217);//left foot
			a[23][35+strafe]=char (192);//right foot

			
				if(check==1)
				{
				a[17][32+strafe]=convert(number[0]);
				check=0;
				}
				else if(check==2)
				{
				a[17][31+strafe]=convert(number[0]);
				check=0;
				}
				else if(check==3)
				{
				a[17][33+strafe]=convert(number[0]);
				check=0;
				}
			

			}	

			gotoxy(0,25);
			cout << "Score: " << score;
			gotoxy(0,0);
			
		}
			
/*Colour setting on the screen, the colour code can be cut and copied into a function
and that particular function can be called into the main function later on */


	for (int u=0; u < 25; u++)
		{
			for (int v=0; v < 80; v++)
			{
				if (u==0)//starts the first color background from array 0
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),287);}

				if (u==19)//starts the second color background from array 19
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);}
				if(u==24)//starts the third colour background at last row array
					{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),78);}
				cout << a[u][v];//displaying the whole grid
			}
		}

	break;}

}
/* displaying the foreground boundaries on the screen boundaries are not in working condition yet because the array locations in which the ascii is being stored are overwritten with a space ascii(32)*/		
	for (int i=0; i < 25; i++)
		{
			for (int j=0; j < 80; j++)
				{
					if(i==0 || i==24)
						{
							a[i][j]=char(219);//219 is the ASCII code for a solid block character
						}
					if (j==0 || j==79)
						{
							a[i][j]=char(219);//the column loop, progressing horizontally
						}

				}
			for (int i=0; i < 80; i++)//introducing another loop for the modified boundary at row 24
				{
					a[24][i]=char(176);
				}
		}
		

	}

	void fallingnumber()
	{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
	srand(time(0));


		/*	a[18][32+strafe]=char (194);//tray body
			a[18][31+strafe]=char (196);//tray extension left
			a[18][33+strafe]=char (196);//tray extension right
			*/
	if(xcoord==(31+strafe) && i==17 )
		{
			check=1;
			a[17][31+strafe]=number[0];
		}
	else if(xcoord==(32+strafe) && i==17)
		{
			check=2;
			a[17][32+strafe]=number[0];
		}
	else if(xcoord==(33+strafe) && i==17)
		{
			check=3;
			a[17][33+strafe]=number[0];
		}
	
	gotoxy(xcoord, i);
	cout<<number[0];
	gotoxy(xcoord, i-1);
	cout<<' ';
	Sleep(50);
	i++;
	if(i==19)
	{
		for(int k=0; k < 80; k++)
			{
				cout << " ";
			}
		i=0;
		xcoord=rand()%70;
		number[0]=rand()%7;
		for(int l=0; l < 10; l++)
		{
			number[l]=rand() % 7;
		}
	}
																									
}

	int convert(int num)
	{
		switch (num)
			{
		case 0:
			{
				score=0;
				return 48; 
				break;
			}
		case 1:
			{
				score+=1;
				return 49;
				break;
			}
		case 2:
			{
				score+=2;
				return 50;
				break;
			}
		case 3:
			{
				score+=3;
				return 51;
				break;
			}
		case 4:
			{
				score+=4;
				return 52;
				break;
			}
		case 5:
			{
				score+=5;
				return 53;
				break;
			}
		case 6:
			{
				score+=6;
				return 54;
				break;
			}

			}
	}
