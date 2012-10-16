#include <iostream>

using namespace std;

int main ()
{
	int x;
	int y;
	cout<<"Please Enter Total Call Duration in Minutes: ";
	cin>>x;
	cout<<endl;

    if(x>0&&x<=2)
    y = 12*x;

    if(x>2&&x<=5)
    y = 10*x;

    if(x>5&&x<=8)
    y = 7*x;

    if(x>8&&x<=10)
    y = 5*x;

    if(x>10)
    y = 3*x;
    
    cout<<"Total Call Duration is: "<<x<<endl<<endl;

    cout<< "Total call charges are: "<<y<<"Pkr"<<endl<<endl;

    system("PAUSE");
    return 0;
}
