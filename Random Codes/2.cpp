#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int n=0 ,sum=0;
	cout << "Enter the number for sum of series: ";
	cin >> n;
	for(int i=1;i<=n;i++) {
		sum=sum+(i*i);
	}
	cout<<"Sum of series is: "<<sum<<endl;
	getch();
	return 0;
}