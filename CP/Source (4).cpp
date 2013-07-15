#include<iostream> 
#include<iomanip> 
#include <windows.h> 
#include <conio.h> 
#include<cstdlib> 
using namespace std; 
  
void GotoXY(int x, int y) { 
    COORD coord; 
    coord.X = x; coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); 
    return; 
} 
  
void main () 
{ 
    char robot[25][80]={0}; //defined array for robot placement 
    int inf=0; //variable to be used for infinite loop 
    char m0; //variable to allow movement by 'a' or 's' key 
    int m1=0,m2=1,m3=2,m4=3,m5=4,m6=5,m7=6;  //various variables to be used in robot array index manipulation 

    do
    {                 // Start of infinite "Do-While" loop, so constant user input can be taken, in order to manipulate array index values to move robot 
        robot[19][m1]=92; 
        robot[19][m2]=196; 
        robot[19][m3]=194; 
        robot[19][m4]=196; 
        robot[19][m5]=47; 
      
        robot[20][m3]=179; 
        robot[20][m5]=1; 
  
        robot[21][m3]=192; 
        robot[21][m4]=196; 
        robot[21][m5]=215; 
        robot[21][m6]=196; 
        robot[21][m7]=170; 
  
        robot[22][m4]=218; 
        robot[22][m5]=208; 
        robot[22][m6]=191; 
  
        robot[23][m4]=217; 
        robot[23][m6]=192; 
        for (int r=0;r<25;r++)        // loop to display robot 
        { 
            for (int c=0;c<80;c++) 
            { 
                if(r==0) 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31); 
                if(r==20) 
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47); 
                if(r==24) 
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 270);
					for (int i=24;r<25;r++)
					{
						for(int j=0;c<80;c++)
						{
							cout<<char(178);
						}
					}
				}
                cout<<robot[r][c]; 
            } 
        } 
        GotoXY(0,0); 
        m0 = getch();        //user input 
        if (GetAsyncKeyState(VK_RIGHT) )     // condition on what to do if user inputs 'S' or 's' 
        { 
            //system ("cls"); 
            Sleep(1); 
            //GotoXY(0,0); 
            for (int r=0;r<25;r++)     // loop to store "blank spaces" or '0' in all indexes of charecter array 
            { 
                for (int c=0;c<80;c++) 
                { 
                    robot[r][c]=0; 
                } 
            } 
            m1++;                    // various increments in index vlaues of robot  
            m2++; 
            m3++; 
            m4++; 
            m5++; 
            m6++; 
            m7++; 
  
            robot[19][m1]=92; 
            robot[19][m2]=196; 
            robot[19][m3]=194; 
            robot[19][m4]=196; 
            robot[19][m5]=47; 
      
            robot[20][m3]=179; 
            robot[20][m5]=1; 
  
            robot[21][m3]=192; 
            robot[21][m4]=196; 
            robot[21][m5]=215; 
            robot[21][m6]=196; 
            robot[21][m7]=170; 
  
            robot[22][m4]=218; 
            robot[22][m5]=208; 
            robot[22][m6]=191; 
  
            robot[23][m4]=217; 
            robot[23][m6]=192; 
              
            if (m1>72)             // condition if the robot tries to move top far to the right 
            { 
                for (int r=0;r<25;r++)       // loop to store "blank spaces" or '0' in all indexes of charecter array 
                { 
                    for (int c=0;c<80;c++) 
                    { 
                        robot[r][c]=0; 
                    } 
                } 
                m1=73;              // index values stores constant values if robot moves beyond the intended limit 
                m2=74; 
                m3=75; 
                m4=76; 
                m5=77; 
                m6=78; 
                m7=79; 
                  
                cout<<"\a";  //sound plays if user tries again to move beyond the intended limit 
            } 
        } 
        else if (GetAsyncKeyState(VK_LEFT))    // condition on what to do if user inputs 'A' or 'a' 
        { 
            //system ("cls"); 
            Sleep(1); 
            GotoXY(0,0); 
            for (int r=0;r<25;r++)        // loop to store "blank spaces" or '0' in all indexes of charecter array 
            { 
                for (int c=0;c<80;c++) 
                { 
                    robot[r][c]=0; 
                } 
            } 
            m1--;                       // various decrements in index vlaues of robot  
            m2--; 
            m3--;                      
            m4--; 
            m5--; 
            m6--; 
            m7--; 
  
            robot[19][m1]=92; 
            robot[19][m2]=196; 
            robot[19][m3]=194; 
            robot[19][m4]=196; 
            robot[19][m5]=47; 
      
            robot[20][m3]=179; 
            robot[20][m5]=1; 
  
            robot[21][m3]=192; 
            robot[21][m4]=196; 
            robot[21][m5]=215; 
            robot[21][m6]=196; 
            robot[21][m7]=170; 
  
            robot[22][m4]=218; 
            robot[22][m5]=208; 
            robot[22][m6]=191; 
  
            robot[23][m4]=217; 
            robot[23][m6]=192; 
              
              
            if (m1<1)   // condition if the robot tries to move top far to the right 
            { 
                for (int r=0;r<25;r++)     // loop to store "blank spaces" or '0' in all indexes of charecter array 
                { 
                    for (int c=0;c<80;c++) 
                    { 
                        robot[r][c]=0; 
                    } 
                } 
                m1=1;           // index values stores constant values if robot moves beyond the intended limit 
                m2=2; 
                m3=3; 
                m4=4; 
                m5=5; 
                m6=6; 
                m7=7; 
                  
                cout<<"\a";     //sound plays if user tries again to move beyond the intended limit 
            } 

			
			
        } 
        GotoXY(0,0); 
    } 
    while (inf==0);   //condition for infinite loop repitition for whole program repition 
}