#include<iostream>
#include <conio.h>
using namespace std;

int main()

{

int i=0, j=0, k=15;

for(i=-k; i<=0; i++)
{

for(j=-k; j<=k; j++)

{

if( abs(i)+abs(j)<=k)

{ cout<<"*"; }

else { cout<<" ";}

}

cout<<endl;

}
getch();
return 0;
}