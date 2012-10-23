#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int i=1,sumeven=0,sumodd=0;
	while(i<=100) {
		if(i%2==0) {
			sumeven=sumeven+i;
		}
		else {
			sumodd=sumodd+i;
		}
		i++;
	}
	cout << "Sum of Even Values is: " << sumeven << endl;
	cout << "Sum of Odd Values is: " << sumodd << endl;
	getch();
	return 0;
}