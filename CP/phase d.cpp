#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<Windows.h>
using namespace std;
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
	srand(time(0));
	int a[15]={0};
	char space[15]={" "};
	int column[15];
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
	while(1)
	{
		for(int k=0;k<15;k++)
		{
			for(int y=0;y<40;y++)
			{
				/*GotoXY(column[k],y);
				cout<<" ";*/
				GotoXY(column[k],y);
				cout<<a[k];
				//Sleep(10);
				GotoXY(column[k],y-1);
				cout<<" ";
				Sleep(50);
			
			}
		}
	}
		
		/*for(int i=0;i<40;i++)
		{
			int temp;
			GotoXY(column[k],i);
			temp =space[1];
			space[1]=a[k];
			a[k]=temp;
			
		}*/
	

	getch();
	return 0;
}