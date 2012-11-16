
/*
#include <iostream>
#include <conio.h>

using namespace std;

int total() {
	int total=0,n;
	while(1) {
		cout << "Enter any Number[Negative Number to Finish] : ";
		cin >> n;
		if(n<0) {
			break;
		}
		total=total+n;
	}
	return total;
}

int main() {
	int sum;
	while(1) {
		cout << "Enter Next Sequence" << endl << endl;
		sum = total();
		if(sum==0) {
			break;
		}
		cout << "Total : " << sum << endl << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

double square(double n) {
	return n*n;
}

double sum() {
	double n,sum=0,sq;
	while(1) {
		cout << "Enter Number[Negative Number to Exit] : ";
		cin >> n;
		if(n<0) {
			break;
		}
		sq=square(n);
		sum=sum+sq;
	}
	return sum;
}

int main() {
	double total;
	while(1) {
		cout << "Enter Next Sequence" << endl << endl;
		total=sum();
		if(total<=0.0) {
			break;
		}
		cout << "The Total of Squared Values : " << total << endl << endl;
	}
	getch();
	return 0;
}
*/

/*
#include <iostream>
#include <conio.h>

using namespace std;

int sumArray(int arr[],int sizeofarr);
void displayArray(int arr[],int sizeofarr);

int main() {
	int arr[128],n,size=0;
	for(int i=0;i<128;i++) {
		cout << "Enter Number[Negative Number to Exit]: ";
		cin >> n;
		if(n<0) {
			break;
		}
		size++;
		arr[i] = n;
	}
	displayArray(arr,size);
	cout << "Sum of Array Data : " << sumArray(arr,size);
	getch();
	return 0;
}

void displayArray(int arr[],int sizeofarray) {
	for(int i=0;i<sizeofarray;i++) {
		cout.width(3);
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

int sumArray(int arr[],int sizeofarray) {
	int sum=0;
	for(int i=0;i<sizeofarray;i++) {
		sum = sum + arr[i];
	}
	return sum;
}
*/

/*
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cout << "Enter a Decimal Value : ";
	cin >> n;
	cout << n << " in Octal : " << oct << n << endl;
	cout << dec << n << " in Hexadecimal : " << hex << n << endl;
	getch();
	return 0;
}
*/


#include <iostream>
#include <conio.h>

using namespace std;

ostream& endLine(ostream& output) {
	return output << '\n' << flush;
}

ostream& carraigeReturn(ostream& output) { // Function for Carraige Return
	return output << '\r';
}

ostream& tab(ostream& output) {
	return output << '\t';
}

int main() {
	cout << "My" << endLine << "Own" << endLine << "endLine" << endLine << "Function";
	cout << "Using" << tab <<  "Carraige" << tab << "Return on this cout" << carraigeReturn;
	cout << "This is overwriting the line";
	getch();
	return 0;
}