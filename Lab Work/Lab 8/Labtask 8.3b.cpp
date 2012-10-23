#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int start,end,sumeven=0,sumodd=0;
	cout << "Enter Starting Point : ";
	cin >> start;
	cout << "Enter Ending Point : ";
	cin >> end;
	while(start<=end) {
		if(start%2==0) {
			sumeven=sumeven+start;
		}
		else {
			sumodd=sumodd+start;
		}
		start++;
	}
	cout << "SUM of Even Numbers : " << sumeven << endl;
	cout << "SUM of Odd Numbers : " << sumodd << endl;
	getch();
	return 0;
}