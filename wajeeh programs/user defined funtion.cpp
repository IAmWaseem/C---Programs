#include <iostream>
#include <conio.h>
#include <cmath>


void myfun (int);



int main()
{
	using namespace std;
	
	int a;
	cout << "Enter the value of a: ";
	cin >> a;

	myfun(a);


	_getch();
	return 0;


}


void myfun (int x) 
{
	using namespace std;


	cout << "****Start of my function****" << endl;
	cout << " the new numvber is :" << x * 9 <<endl;
	

}