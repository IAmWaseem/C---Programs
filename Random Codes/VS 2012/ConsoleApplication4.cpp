#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

char explode(string str,int i) {
	char ch;
	ch=str[i];
	return ch;
}

int main() {
	string str;
	char ch,exp;
	cout << "Enter the Question : ";
	getline(cin,str);
	cout << "On which character you want to explode : ";
	cin >> exp;
	for(int i=0;i<str.length();i++) {
		ch = explode(str,i);
		if(ch==exp) {
			break;
		}
		cout << ch << endl;
	}
	/*for(int i=0;i<str.length();i++) {
		ch[i]=str[i];
	}
	for(int i=0;i<str.length();i++) {
		cout << ch[i] << endl;
	}*/
	getch();
	return 0;
}