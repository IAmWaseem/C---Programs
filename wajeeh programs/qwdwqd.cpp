#include<iostream>
#include<conio.h>
using namespace std;

int main ()
{
	MAIN:
	int a; 
	float b, c, d, e;
	//U CANNOT USE A FLOAT TO DECLARE LOOPS LIKE IN SWITCH

	
	
	cout <<"****CALCULATOR PROGRAM****\n\n"<<endl;
	cout <<"For multiplication press 1\n"<<endl;
	cout <<"For division press 2\n"<<endl;
	cout <<"For addition press 3\n"<<endl;
	cout <<"For subtraction press 4\n"<<endl;
	cout <<"for precentage press 5\n"<<endl;
	cout <<"To use equality operators on any two integers press 6\n"<<endl;
	cout <<"To solve quadratic equations press 7\n"<<endl;
	cin >>a;

	if (a==1 || a==2 || a==3 || a==4 || a==6)
		{cout <<"enter the value of the first integer integer"<<endl;
	cin>>b;
	cout <<"enter the value of the second integer"<<endl;
	cin>>c;}

	//DO NOT use else untill or unless there is another condition that u want the compiler to follow!!!!!
	//try using ELSE in this program it wont work
	

	
	switch(a)
	{
	case 1:
		{
			cout <<"****MULTIPLICATION****\n"<<endl;
			cout <<"the product of the two is: " <<(b*c) <<"\n" <<endl;
			
			break;
		}
	


	case 2:
		{
			cout <<"****DIVISION****\n"<<endl;
			if (c==0)
				cout <<"INVALID VAlUE OF THE DENOMINATOR!"<<endl;
			
			cout <<"The value of a/b: "<<b/c<<"\n"<<endl;
			

			break;
		}



	case 3:
		{
			cout <<"****ADDITION****\n"<<endl;
			cout <<"the sum of the two value is: "<<b+c<<endl;
			
			break;
		}



	case 4:
		{
			cout <<"****SUBTRACTION****\n"<<endl;
			cout <<"b-c= "<<b-c<<endl;
			
			break;
		}



	case 5:
		{
			cout <<"****PERCENTAGE****\n"<<endl;
			cout <<"enter the maximum marks"<<endl;
			cin >>b;
			cout <<"enter your obtained marks"<<endl;
			cin >>c;
			cout <<"your obtained percentage is: "<<(c/b)*100<<endl;
			
			break;
		}



	case 6:
		
		{
			cout <<"****EQUALLITY OPERATORS****\n"<<endl;
			if (b==c)
				cout <<"the two integers are equal to each other"<<endl;
			else if (b>c)
				cout <<"the first integer is greater than the second"<<endl;
			else if (b<c)
				cout <<"the first integer is less than the second"<<endl;
			
			break;
		
		}



	case 7:
		{
			float A, B, C, X1, X2;
	cout<<"****SOLVING QUADRATIC EQUATIONS****"<<endl;
		
			cout <<"enter the value of a"<<endl;
	        cin  >>A;
	        cout <<"enter the value of b"<<endl;
	        cin  >>B;
	        cout <<"enter the value of c"<<endl;
	        cin  >>C;
	X1= sqrt(pow(B,2) - 4*A*C);
		

	if ((pow(B,2) - 4*A*C) < 0)
	{
		cout <<"THE ANSWER WILL BE COMPLEX\nThis program doesn't supports complex answers\n"<<endl;
	
	}


	else if ( (pow(B,2) - 4*A*C)> 0)
	{   cout <<"X1 = "<< (-B+X1)/(2*A) <<endl;
		cout <<"X2 = "<< (-B-X1)/(2*A) <<endl;}
	

	else if ((pow(B,2) - 4*A*C) == 0)
		{   X1= -B/(2*A);
            cout <<"ROOTS ARE EQUAL SO THERE WILL BE ONLY ONE ANSWER"<<endl;
			cout <<"X1 ="<<X1<<endl;       }

		     break;
		}
		


		
		


	default:
		{
			cout <<"ENTER A VALUE THAT RANGES FROM 1 TO 7 ALL OTHER VALUES ARE INVALID"<<endl;
			goto MAIN;
		
		}

		
		

	
	}

	cout <<"TO perform some other calculation press 1\nTo exit press any other key"<<endl;
		cin >>d;
		if(d==1)
			goto MAIN;
		else 
			cout <<"thank you for using my program GOOD BYE"<<endl;


	_getch();



}