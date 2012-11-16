#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int i=0,j=0,check=1;
	double num=0;
	char sentence[999],number[999];
	cout << "Enter Sentence : ";
	cin.getline(sentence,999,'\n');
	while(sentence[i]!='\0') {
		if((sentence[i]<=57 && sentence[i]>=48) || sentence[i]==46) {
			number[j]=sentence[i];
			j++;
		}
		i++;
	}
	for(int i=0;i<j;i++) {
		int a=1;
		switch(number[i]) {
			case '0': {
				if(check) {
					num = num + 0*pow(10,i);
				}
				else {
					num = num + 0/pow(10,a);
					a++;
				}
				break;
			}
			case '1': {
				if(check) {
					num = num + 1*pow(10,i);
				}
				else {
					num = num + 1/pow(10,a);
					a++;
				}
				break;
			}
			case '2': {
				if(check) {
					num = num + 2*pow(10,i);
				}
				else {
					num = num + 2/pow(10,a);
					a++;
				}
				break;
			}
			case '3': {
				if(check) {
					num = num + 3*pow(10,i);
				}
				else {
					num = num + 3/pow(10,a);
					a++;
				}
				break;
			}
			case '4': {
				if(check) {
					num = num + 4*pow(10,i);
				}
				else {
					num = num + 4/pow(10,a);
					a++;
				}
				break;
			}
			case '5': {
				if(check) {
					num = num + 5*pow(10,i);
				}
				else {
					num = num + 5/pow(10,a);
					a++;
				}
				break;
			}
			case '6': {
				if(check) {
					num = num + 6*pow(10,i);
				}
				else {
					num = num + 6/pow(10,a);
					a++;
				}
				break;
			}
			case '7': {
				if(check) {
					num = num + 7*pow(10,i);
				}
				else {
					num = num + 7/pow(10,a);
					a++;
				}
				break;
			}
			case '8': {
				if(check) {
					num = num + 8*pow(10,i);
				}
				else {
					num = num + 8/pow(10,a);
					a++;
				}
				break;
			}
			case '9': {
				if(check) {
					num = num + 9*pow(10,i);
				}
				else {
					num = num + 9/pow(10,a);
					a++;
				}
				break;
			}
			case '.': {
				check=0;
				break;
			}
			default: {
				// Error Prevention
			}
		}
	}
	cout << "Number is : " << num << endl;
	getch();
	return 0;
}