
#include <iostream>
#include <conio.h>

using namespace std;

int isPalindrome(char*,int,int);

int main() {
	char* Sentence;
	int Size;
	cout << "Enter Size of String : ";
	cin >> Size;
	Sentence = new char[Size];
	cout << "Enter String : ";
	fflush(stdin);
	cin.getline(Sentence,Size);
	int i;
	for(i = 0; Sentence[i] != NULL; i++);
	if(isPalindrome(Sentence,Size,i)) {
		cout << "String is Palindrome"; 
	}
	else {
		cout << "String is Not Palindrome";
	}
	getch();
	return 0;
}

int isPalindrome(char* Sentence, int Size, int i) {
	static int Check = 0;
	static int Count = 0;
	if(Sentence[Count] == Sentence[i - 1]) {
		Check = 1;
	}
	else {
		return Check;
	}
	Count++;
	if(Count == i) {
		return Check;
	}
	return isPalindrome(Sentence, Size - 1, i);
}
