#include<iostream>
using namespace std;
void odd_div(int);
int main()
{
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	if(num%2!=0)
		cout<<"please enter an even number\n";
	else
	{
		odd_div(num);
	}}
void odd_div(int num)
{
	if(num % 2 == 0) {
		num = num / 2;
		odd_div(num);
	}
	else {
		cout<<"Largest odd divisor is "<<num;
		cout<<endl;
	}
}
