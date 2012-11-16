//Question 1
#include <iostream>
#include <conio.h>

using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int x,y;
	x = 10;
	y = 20;
	cout << "Before Swapping" << endl;
	cout << "x = " << x << endl << "y = " << y << endl << endl;
	swap(x,y);
	cout << "After Swapping" << endl;
	cout << "x = " << x << endl << "y = " << y << endl;
	getch();
	return 0;
}

//Question 2
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int x,y,temp,r=1;
	cout << "Enter 1st Number : ";
	cin >> x;
	cout << "Enter 2nd Number : ";
	cin >> y;
	if(y>x)
	{
		temp = x;
		x = y;
		y = temp;
	}
	while(r!=0)
	{
		if((r=x%y)==0)
		{
			cout << "GCD of These two numbers is " << y;
			break;
		}
		y = r;
	}
	getch();
	return 0;
}


//Question 3
#include <iostream>
#include <conio.h>

using namespace std;

bool CheckPrime(int num)
{
	int check;
	if(num>1000 || num<=2)
	{
		return false;
	}
	else
	{
		for (int i=2;i<num;i++)
		{
			if (num%i==0 && num!=i)
			{
				check = 0;
				break;
			}
			else
			{
				check = 1;
			}
		}
		if(check)
			return true;
		else
			return false;
	}
}

int main()
{
	int num;
	bool check;
	cout << "Enter Number : ";
	cin >> num;
	check = CheckPrime(num);
	if(check)
	{
		cout << "Number is Prime";
	}
	else
	{
		cout << "Number is not Prime";
	}
	getch();
	return 0;
}

//Question 5
#include <iostream>
#include <conio.h>

using namespace std;

void Sum(double &sum, int N)
{
	for(int i=1;i<=N;i++)
	{
		sum = sum + (1/static_cast<double>(i));
	}
}

int main()
{
	int n;
	double sum=0;
	cout << "Enter a Positive Integer : ";
	cin >> n;
	Sum(sum,n);
	cout << "Sum is : " << sum;
	getch();
	return 0;
}