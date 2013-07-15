#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<iomanip>
#include<Windows.h>
#include<string>
#include<time.h>

using namespace std;

void gotoxy(int, int);													//Prototype of gotoxy() Function
int bot_moving();
void robot(int,int);
void main12 (void);
void SetWindow(int, int);													//Prototype of robot() Function
void randon_numbers_function3 (int);
void main_game(void);
char run;
int score;
int sleep;
char a2;
int noc;
int q=49;
int w=36;
int x=w;
// mixing welcome
char array[5]={0};

int color_change(int);
void color_loop(void);
void gotoxy(int, int);
void Danish(void);
void About(void);

int f=37,g=30;

int tr=0;



void SetWindow (int Width, int Height)
{
COORD coord;
coord.X = Width;
coord.Y = Height;
_SMALL_RECT Rect;
Rect.Top = 0;
Rect.Left = 0;
Rect.Bottom = Height-1;
Rect.Right = Width-1;
SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&Rect);
}




int main()
{
	
	int colorar[]={543,559,575,591,607,623,639,655,543,559,575,591,607,623,639,655,543,559,575,591};

	for(int i=0;i<20;i++)
	{
		color_change(colorar[i]);
		color_loop();
	}

	color_change(575);

	gotoxy(40,30);
	cout<<"w ga";

	gotoxy(40,31);
	cout<<"Help";

	gotoxy(40,32);
	cout<<"Abou";

	gotoxy(40,33);
	cout<<"Exit";

	color_change(591);
	gotoxy(44,30);
	cout<<"me";

	gotoxy(44,31);
	cout<<" ";

	gotoxy(44,32);
	cout<<"t";

	gotoxy(44,33);
	cout<<" ";

	color_change(559);
	gotoxy(38,30);
	cout<<"Ne";

	gotoxy(37,29);
	

	char ch;
	char ar='>';
	//char o1='1',o2='2',o3='3',o4='4';
	char inp;

	/*gotoxy(f,g);
	 o1;

	gotoxy(f,g+1);
	 o2;

	gotoxy(f,g+2);
	 o3;

	gotoxy(f,g+3);
	 o4;*/

	ch = getch();
	
	while(ch!='\r')
	{	
			tr=g;

		ch = getch();
		if (GetAsyncKeyState(VK_DOWN) && g<33)
		{
			
			
			gotoxy(f-1,g);
			

			cout << " ";
			g++;
			gotoxy(f-1,g);
			cout << ar;
			Sleep(200);


			/*if()
			{
				if(inp=='1')
					Danish();
			}*/
			
			
		}

		else if (GetAsyncKeyState(VK_UP) && g>30)
		{
			gotoxy(f-1,g);
			
			cout << " ";
			g--;
			gotoxy(f-1,g);
				cout << ar;
			Sleep(200);

			tr=g;
		}

		
	}
	 


	if(tr==30)
	{
		if(ch=='\r')
		{
			system("cls");
			main_game();
			
		}
	}

	if(tr==31)
	{
		if(ch=='\r')
		{
			cout<<"FAizan";
			
		}
	}

	if(tr==32)
	{
		if(ch=='\r')
		{
			About();
			
		}
	}

	
	getch();
}








void main_game()																// Starting of main Function

{


	char b[65][80]={0};
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<80;j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31); // Blue Color
			cout<<b[i][j];
		}
	}
	for(  i=50;i<55;i++)
	{
		for(int j=0;j<80;j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47); // Green Color
			cout<<b[i][j];

		}
	}
	gotoxy (0,54);														  /* returning to start of row
																		  to print ASCII character 178 */
	for ( i=54;i<55;i++);
	{
		for(int j=0;j<80;j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 270);
			cout<<char(178);
		}
	}

	//for movement



	main12();


	

} //end of main Function




//Goto Function's Defination

void randon_numbers_function3 (int noc)
{


	srand(time(0));
	int y=rand() % 12 + 1;
	int c=0;
	gotoxy(y,c);
	c=0;

	int rna1[200];


	for (int i=0;i<200;i++)
	{
		rna1[i]=rand()% 6 + 0;
	}
	int rsetwa[200];

	for ( i=0;i<200;i++)
	{
		rsetwa[i]=rand()% 12 + 3;
	}

	while(c<51)
	{

		while(kbhit())
		{
			bot_moving();
			break;
		}

		int del=rand() % 100 + 1;
		Sleep(del);


		gotoxy(y,c);

		for (int i=0;i<noc;i++)
		{
			cout<<setw(rsetwa[i])<<rna1[i];




		}




		gotoxy(y,c-1);
		cout<<"                                                                                     ";


		if (c==48)

		{
			gotoxy(0,48);
			cout<<"                                                                                 "; 

			break;
		}


		c++;
	}

}


void gotoxy( int column, int line )
{
	COORD coord;
	coord.X = column; 
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}


//Robot Funtion's Defination


void robot(int q,int w)
{
	char b[65][80]={0};


	gotoxy(w,q);
	cout<<char(0);
	cout<<(b[q][w]=92);
	cout<<(b[q][w+1]=196);
	cout<<(b[q][w+2]=194);
	cout<<(b[q][w+3]=196);
	cout<<(b[q][w+4]=47);
	cout<<char(0);


	// w=36 ||||  q=49

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47); //  Right arm and face
	gotoxy(w+2,q+1);
	cout<<char(0);
	cout<<(b[q+1][w+2]=179);
	cout<<" ";
	cout<<(b[q+1][w+4]=1);
	cout<<char(0);

	// w=36 ||||  q=49
	gotoxy(w+2,q+2);											// The Middle Body
	cout<<char(0);
	cout<<(b[q+2][w+2]=192);
	cout<<(b[q+2][w+3]=196);
	cout<<(b[q+2][w+4]=215);
	cout<<(b[q+2][w+5]=196);
	cout<<(b[q+2][w+6]=170);
	cout<<char(0);

	// w=36 ||||  q=49
	gotoxy(w+3,q+3);											//The Lower body
	cout<<char(0);
	cout<<(b[q+3][w+3]=218);
	cout<<(b[q+3][w+4]=208);
	cout<<(b[q+3][w+5]=191);
	cout<<char(0);

	// w=36 ||||  q=49
	gotoxy(w+3,q+4);											//Legs
	cout<<char(0);
	cout<<(b[q+4][w+3]=217);
	cout<<" ";
	cout<<(b[q+4][w+5]=192);
	cout<<char(0);

	gotoxy(0,0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
	getch();
}

// robot moving

int bot_moving()
{


	robot(q,x);																//calling robot function
	if ((GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(68) ) && x<72)			
	{

		x++;
		return 0;//Using GetAsyncKeyState() for Assigning direction
	}

	else if((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(65) )&& x>0 )
	{

		x--;
		return 0;
	}

	if(x<1)
	{
		cout<<"\a";
	}

	if(x>71)
	{
		cout<<"\a";
	}

} 





void main12 ()

{
	SetWindow(80,50);
	do {


		int c=1;
		int tm1=0,tm2=0;
		while (c<6)


		{

			c++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			srand(time(0));
			int a = rand()% 6 +1;
			randon_numbers_function3 (a);
			gotoxy(25,55);

			cout<<"Timer in seconds, will run for 180 seconds : "<<tm2;
			tm2++;
		
		}

		gotoxy(10,45);
		cout<<"\nyour score\n"<<score;
		gotoxy(11,46);
		cout<<"\nRun the game again ? ( press 'Y' for yes or 'N' for no )" ;
		cin>>run;

		if (run == 'y' || run == 'Y')
		{
			gotoxy(0,46);
			cout<<"                                                                   ";
			gotoxy(0,47);
			cout<<"                                                                   ";

		}

		if (run == 'N' || run == 'n')
		{	
			cout<<"\nThanks for playing  ^__^  \n\n\n";
			getch();
		}

	}

	while ( run == 'y' || run == 'Y');


}


// Welcome Mixing

int color_change(int x)
{
	int y;
	y=SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);

	return y;
}

void color_loop()
{
	static int x=0;
	for (int i=0 ; i<60 ; i++)
	{
		for (int j=0;j<4;j++)
		{
			cout<<array[j];
		}
		
		
		cout<<endl;
		gotoxy(x,i);
	}

	x+=4;
	
}

void Danish()
{
	system("cls");
	cout<<"DANISH";
}

void About()
{
			gotoxy(f-2,g-2);
			cout<<"\tMade By\t";
			gotoxy(f-3,g-1);
			cout<<"DANISH MUHAMMAD ARIF";
			gotoxy(f,g);
			cout<<"\tAND\t";
			gotoxy(f-1,g+1);
			cout<<"USAMA AHMAD";
}
