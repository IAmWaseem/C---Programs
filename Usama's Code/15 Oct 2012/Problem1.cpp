#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	float m,x,y,b;
	cout<<"Calculating Slope of Line"<<endl<<endl;
	cout<<"Enter value of x= ";
	cin>>x;
	cout<<endl;
	
	cout<<"Enter value of y= ";
	cin>>y;
	cout<<endl;
	
    cout<<"Enter value of b= ";
	cin>>b;
	cout<<endl;
	
	m=(y-b)/x;
	cout<<"Slope of line m= "<<m<<endl<<endl;

    system ("PAUSE");
	return 0;
}
