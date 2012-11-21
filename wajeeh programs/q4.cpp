#include <iostream>
#include <conio.h>

using namespace std;

int primenum(int);

int main()
{
	
	int num;
	cout << "Enter the number" << endl;
	cin >> num;
	primenum(num);

	_getch();
	return 0;
}







int primenum(int num)
{
	int check=0;

	for (int i=2 ; i < num; i++)
		{
		
			if(num%i==0)
			{
				check=1;
				break;
			}
			
		}
	if(check==1)
	{cout << "The number is not prime" << endl;}

	else 
	{cout << "The number is  prime" << endl;}


	return 0;	

}