#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int year,years_diff,leap_years=0,non_leap,day;
	unsigned long int total_days=0;
	cout << "Enter Year : ";
	cin >> year;
	if(year==1900) {
		cout << "The Day on 1st January " << year << " : Monday" << endl;
	}
	else if(year>1900) {
		years_diff = year-1900;
		for(int i=1900;i<year;i++) {
			if(i%400==0 || i%4==0 || i%100==0) {
				leap_years++;
			}
		}
		non_leap = years_diff-leap_years;
		for(int i=1;i<=non_leap;i++) {
			for(int j=1;j<=365;j++) {
				total_days++;
			}
		}
		for(int i=1;i<=leap_years;i++) {
			for(int j=1;j<=366;j++) {
				total_days++;
			}
		}
		day = total_days%7;
		switch(day) {
			case 0: {
				cout << "The Day on 1st January " << year << " : Monday" << endl;
				break;
			}
			case 1: {
				cout << "The Day on 1st January " << year << " : Tuesday" << endl;
				break;
			}
			case 2: {
				cout << "The Day on 1st January " << year << " : Wednesday" << endl;
				break;
			}
			case 3: {
				cout << "The Day on 1st January " << year << " : Thursday" << endl;
				break;
			}
			case 4: {
				cout << "The Day on 1st January " << year << " : Friday" << endl;
				break;
			}
			case 5: {
				cout << "The Day on 1st January " << year << " : Saturday" << endl;
				break;
			}
			case 6: {
				cout << "The Day on 1st January " << year << " : Sunday" << endl;
				break;
			}
		}
	}
	getch();
	return 0;
}