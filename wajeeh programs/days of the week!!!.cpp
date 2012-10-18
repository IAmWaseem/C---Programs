#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	char a, b;


	 cout<<"Enter the first letter of the day"<<endl;
	 cin>>a;
	 

	 switch(a)
	 {
	 case 'm':
	 case 'M':
		 {
			 cout<<"monday"<<endl;
			 break;
		 }

	 case 'T':
	 case 't':
		 {
			 cout<<"tueday"<<endl;
			 break;
		 }

	 case 'W':
	 case 'w':
		 {
			 cout<<"wednesday"<<endl;
			 break;
		 
		 }

	 case 'F':
	 case 'f':
		 {
			 cout << "Friday" <<endl;
			 break;

		 }
 
	 case 'S':
	 case 's':
		 {
			 cout << "Saturday" <<endl;
			 break;
		 
		 }

	 default:
		 {
			 cout <<"wrong value entered" <<endl;
			 break;
		 
		 }

	}

	 if (a== 't' || a== 'T' || a== 's' || a== 'S')
	 {cout << "was the day right? Enter y for yes and n for no" <<endl;
	 cin >> b;

	 if (b== 'n')
			 {if (a== 't' || a== 'T')
				 cout << "the right day is thursday"<<endl;

			 else 
				 cout << "the day is sunday" <<endl;}
	 else 
		 cout << "thankyou for using my program" << endl;
	 
	 }



	 _getch();
	 return 0;

}