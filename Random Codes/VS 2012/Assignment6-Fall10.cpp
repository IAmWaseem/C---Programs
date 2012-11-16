/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n,n1,n2,n3,n4,n5,a,b,c,reverse;
	cout << "Enter 5-Digit Number : ";
	cin >> n;
	n1=n%10;
	a=n/10;
	n2=a%10;
	b=a/10;
	n3=b%10;
	c=b/10;
	n4=c%10;
	n5=c/10;
	reverse=(n1*10000)+(n2*1000)+(n3*100)+(n4*10)+n5;
	cout << "Reversed 5-Digit Number : " << reverse << endl;
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int year;
	cout << "Enter Year : ";
	cin >> year;
	if(year%4==0&&year%100==0&&year%400==0) {
		cout << year << " is a Leap Year" << endl;
	}
	else {
		cout << year << " is not a Leap Year" << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n1,n2,n3,n4,n5,a,b,c;
	long int n,reverse;
	cout << "Enter a 5-Digit Number : ";
	cin >> n;
	cout << endl;
	n1=n%10;
	a=n/10;
	n2=a%10;
	b=a/10;
	n3=b%10;
	c=b/10;
	n4=c%10;
	n5=c/10;
	reverse=(n1*10000)+(n2*1000)+(n3*100)+(n4*10)+n5;
	cout << "You Entered the 5-Digit Number : " << n << endl;
	cout << "Reversed 5-Digit Number : " << reverse << endl;
	if(n==reverse) {
		cout << "Original & Reversed Numbers are the Same" << endl;
	}
	else {
		cout << "Original & Reversed Numbers are not the Same" << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int _age1,_age2,_age3;
	cout << "Enter Age of 1st Person : ";
	cin >> _age1;
	cout << "Enter Age of 2nd Person : ";
	cin >> _age2;
	cout << "Enter Age of 3rd Person : ";
	cin >> _age3;
	if((_age1>_age2)&&(_age1>_age3)) {
		cout << "Age of 1st Person is Greatest i.e., " << _age1 << endl;
	}
	else if((_age2>_age1)&&(_age2>_age3)) {
		cout << "Age of 2nd Person is Greatest i.e., " << _age2 << endl;
	}
	else if((_age3>_age1)&&(_age3>_age2)) {
		cout << "Age of 3rd Person is Greatest i.e., " << _age3 << endl;
	}
	else {
		if(_age1==_age2==_age3) {
			cout << "All Ages Entered are Equal" << endl;
		}
		else if(_age1==_age2) {
			cout << "Age of 1st Person is Equal to Age of 2nd Person" << endl;
		}
		else if(_age2==_age3) {
			cout << "Age of 2nd Person is Equal to Age of 3rd Person" << endl;
		}
		else {
			cout << "Age of 1st Person is Equal to Age of 3rd Person" << endl;
		}
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>						
#include <conio.h>						
										
using namespace std;					
										
int main() {                            
	for(int i=0;i<10;i++) {             
		for(int j=0;j<i;j++) {          
			cout << "*";                
		}								
		cout << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	for(int i=9;i>=0;i--) {
		for(int j=0;j<=i;j++) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	for(int i=0;i<10;i++) {
		for(int j=0;j<i;j++) {
			cout << " ";
		}
		for(int k=10;k>i;k--) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	for(int i=0;i<10;i++) {
		for(int j=10;j>i+1;j--) {
			cout << " ";
		}
		for(int k=0;k<=i;k++) {
			cout << "*";
		}
		cout << endl;
	}
	getch();
	return 0;
}
*/

/*
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
*/

/*
#include <iostream>
#include <conio.h>


using namespace std;

int main() {
	char ch;
	cout << "Enter any Character : ";
	cin >> ch;
	if(ch>=65 && ch<=90) {
		cout << "Character Entered is an Uppercase Letter";
	}
	else if(ch>=97 && ch<=122) {
		cout << "Character Entered is a Lowercase Letter";
	}
	else if(ch>=48 && ch<=57) {
		cout << "Character Entered is a Number";
	}
	else {
		cout << "Character Entered is a Special Symbol";
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char ch=-127;
	cout << "ASCII\tSymbol" << endl;
	while(int(ch)<127) {
		cout << int(ch) << "\t" << ch << endl;
		ch+=1;
	}
	getch();
	return 0;
}
*/


#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
	float points[3][2];
	double side1,side2,side3,s,area;
	for(int i=0;i<3;i++) {
		for(int j=0;j<2;j++) {
			if(!j) {
				cout << "Enter x Co-ordinate of " << i+1 << " Point : ";
				cin >> points[i][0];
			}
			else {
				cout << "Enter y Co-ordinate of " << i+1 << " Point : ";
				cin >> points[i][1];
			}
		}
	}
	side1 = sqrt(pow((points[0][0]-points[1][0]),2)+pow((points[0][1]-points[1][1]),2));
	side2 = sqrt(pow((points[1][0]-points[2][0]),2)+pow((points[1][1]-points[2][1]),2));
	side3 = sqrt(pow((points[0][0]-points[2][0]),2)+pow((points[0][1]-points[2][1]),2));
	s = (side1+side2+side3)/2;
	area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
	if(area==0) {
		cout << "All Points lie on the Same Line";
	}
	else {
		cout << "All Points do not lie on the Same Line";
	}
	getch();
	return 0;
}


/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	for(int i=1;i<=300;i++) {
		if(i==1) {
			cout << i;
		}
		if(i%3!=0 && i%2!=0) {
			
		}
	}
	getch();
	return 0;
}
*/