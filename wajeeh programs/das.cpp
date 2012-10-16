#include <iostream>
#include <conio.h>

using namespace std;

int main()

{
	MAIN:
	char a;
	int b;
	cout<<"Enter any Character, I will tell you it's ASCII: ";
	cin>>a;

	cout<<"ASCII Value is: "<<int(a)<<endl;

	cout<<"to enter any other value press 1 to exit press 2"<<endl;
	cin>>b;
	
	if(b==1)
		goto MAIN;


	_getch();
	return 0;


}