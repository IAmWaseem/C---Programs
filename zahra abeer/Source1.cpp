#include <iostream>
using namespace std;
int main()
{
	char a;
	cout<<"Enter a character:"<<endl;
	cin>>a;
	if((a>=65) && (a<=90))
		cout<<"You entered an uppercase letter"<<endl<<endl;
	else if((a>=97) && (a<=122))
		cout<<"You entered a lowercase letter"<<endl<endl;
	else 
                cout<<"Wrong character entered"<<endl<<endl;
        system("PAUSE");  
        return 0;
		
}
