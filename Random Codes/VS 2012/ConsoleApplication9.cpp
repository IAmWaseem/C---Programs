/*
#include <iostream>

using namespace std;

int main()
{
	int year = 0;
	cout << "Enter the year \n";
	cin >> year;
	
	int year_diff = year - 1900;
	
	if (year_diff > 0 )  // after 1900
	{
		int days_ahead = 0;
		if (year_diff <= 3)
			days_ahead = year_diff + 1;		// for leap year
		else if (year_diff % 4 == 0)		// handle leap years 
			days_ahead = year_diff + (year_diff/4);
		else
			days_ahead = year_diff + (year_diff/4) + 1;
		
		// A year is a leap year not only if it is divisible by 4 -- it also has to be divisible by 400 
		// if it is a centurial year. So 1700, 1800 and 1900 were not leap years, but 2000 was. 

		if (year_diff >= 200)
		{
			days_ahead = days_ahead - (year_diff-100)/100;
			days_ahead = days_ahead + (year_diff-100)/100/4;
		}

		int day_of_week = days_ahead % 7;
		cout << "Value of Days Ahead : " << days_ahead << endl;
		switch (day_of_week)
		{
		case 0: cout << "\n It is Sunday on 1st January of the year " << year; break;
		case 1: cout << "\n It is Monday on 1st January of the year " << year; break;	
		case 2: cout << "\n It is Tuesday on 1st January of the year " << year; break;
		case 3: cout << "\n It is Wednesday on 1st January of the year " << year; break;
		case 4: cout << "\n It is Thursday on 1st January of the year " << year; break;
		case 5: cout << "\n It is Friday on 1st January of the year " << year; break;
		case 6: cout << "\n It is Saturday on 1st January of the year " << year; break;
		}
		
	}
	else if (year_diff < 0)	// before 1900
	{
		year_diff = year_diff * -1;
		int days_back = 0;
		if (year_diff <= 3)
			days_back = year_diff;		
		else
			days_back = year_diff + (year_diff/4);
		

		// A year is a leap year not only if it is divisible by 4 -- it also has to be divisible by 400 
		// if it is a centurial year. So 1700, 1800 and 1900 were not leap years, but 2000 was. 

		if (year_diff >= 100)
		{
			days_back = days_back - year_diff/100;
			days_back = days_back + (year_diff+100)/100/4;
		}
		

		int day_of_week = days_back % 7;
		
		switch (day_of_week)
		{
		case 0: cout << "\n It is Monday on 1st January of the year " << year; break;	
		case 6: cout << "\n It is Tuesday on 1st January of the year " << year; break;
		case 5: cout << "\n It is Wednesday on 1st January of the year " << year; break;
		case 4: cout << "\n It is Thursday on 1st January of the year " << year; break;
		case 3: cout << "\n It is Friday on 1st January of the year " << year; break;
		case 2: cout << "\n It is Saturday on 1st January of the year " << year; break;
		case 1: cout << "\n It is Sunday on 1st January of the year " << year; break;
		}
		
	}
	else  // year 1900
		cout << "\n It is Monday on 1st January of the year 1900"; 
	
	
	cout << endl;
	system("pause");
	return 0;
	
}
*/

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	for(int i=1;i<=10;i++) {
		cout << setw(10);
		for(int j=1;j<=i;j++) {
			cout << "*";
		}
		cout << setw(10);
		for(int j=10;j>=i;j--) {
			cout << "*";
		}
		for(int j=1;j<=i;j++) {
			cout << " ";
		}
		cout << setw(10);
		for(int j=10;j>=i;j--) {
			cout << " ";
		}
		for(int j=i;j<=10;j++) {
			cout << "*";
		}
		for(int j=10;j>=1;j--) {
			cout << " ";
		}
		for(int j=1;j<=i;j++) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}