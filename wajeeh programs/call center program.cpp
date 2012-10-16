#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    MAIN:
	
	int a, b;
	cout<<"****CALL CENTER PROGRAM****"<<endl;
	
	cout<<"enter the the duration of the call: ";
	cin>>a;

	if (a>0 && a<=2)
	cout<<"\ntotal call charges are: "<<a*12<<"pkr"<<endl;

	else if (a>2 && a<=5)
		cout<<"\ntotal call charges are: "<<a*10<<"pkr"<<endl;
	
	else if (a>5 && a<=8)
		cout<<"\ntotal call charges are: "<<a*7<<"pkr"<<endl;
	
	else if (a>8 && a<=10)
		cout<<"\ntotal call charges are: "<<a*5<<"pkr"<<endl;
	
	else if (a>10)
		cout<<"\ntotal call charges are: "<<a*3<<"pkr\n"<<endl;

	cout<<"to calculate other call charges press 1 otherwise press 2"<<endl;
	cin>>b;

	if(b==1)
		{system("cls");
	goto MAIN;}

	else 


	

	return 0;
	_getch();


	
	



}