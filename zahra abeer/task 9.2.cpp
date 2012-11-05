#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int y=7,z=5,i=1,j=1;
 
    for (; i<8; i+=2)
    {
        for (; j<=y; j++)
        {
            cout << " ";
        }
        for(int k=1; k<=i; k++)
        {
            cout<<"*";
        }
        cout<<endl;
        y-=1;
    }
    int k=5;
    for (int i=5;i>=1;i-=2)
    {
        for( int a=1; a<=k; a++)
        {
            cout<<" ";
        }
        k++;
        for ( int b=i; b>0; b--)
 
 
        { 
            cout<<"*";
        }
        cout<<endl;
        z-=1;
    }
  _getch();
}

 
