/*
#include <iostream>
#include <conio.h>

using namespace std;

int MyIsAlpha(char *);
int MyIsDigit(char *);
int MyIsLower(char *);
int MyIsUpper(char *);
void MyConvertUpper(char *);
void MyConvertLower(char *);

int main() {
	char ch;
	cout << "Enter Character : ";
	cin >> ch;
	if(!MyIsAlpha(&ch)) {
		cout << "Character is an Alphabet" << endl;
		if(!MyIsLower(&ch)) {
			cout << "Character is a Lowercase Alphabet" << endl;
			MyConvertUpper(&ch);
			cout << "Character Converted to Uppercase " << ch;
		}
		else if(!MyIsUpper(&ch)) {
			cout << "Character is an Uppercase Alphabet" << endl;
			MyConvertLower(&ch);
			cout << "Character Converted to Lowercase " << ch;
		}
	}
	else if(!MyIsDigit(&ch)) {
		cout << "Character is a Digit";
	}
	cout << endl;
	getch();
	return 0;
}

int MyIsAlpha(char *chptr) {
	if((*chptr>=65 && *chptr<=90) || (*chptr>=97 && *chptr<=122)) {
		return 0;
	}
	return 1;
}

int MyIsDigit(char *chptr) {
	if(*chptr<=57 && *chptr>=48) {
		return 0;
	}
	return 1;
}

int MyIsLower(char *chptr) {
	if(*chptr>=97 && *chptr<=122) {
		return 0;
	}
	return 1;
}

int MyIsUpper(char *chptr) {
	if(*chptr>=65 && *chptr<=90) {
		return 0;
	}
	return 1;
}

void MyConvertUpper(char *chptr) {
	if(*chptr>=97 && *chptr<=122) {
		*chptr = *chptr - 32;
	}
	return;
}

void MyConvertLower(char *chptr) {
	if(*chptr>=65 && *chptr<=90) {
		*chptr = *chptr + 32;
	}
	return;
}
*/

#include <iostream>
#include <conio.h>

using namespace std;

int MyIsDigit(char *);
int MyIsLower(char *);
int MyIsUpper(char *);
void MyConvertUpper(char *);
void MyConvertLower(char *);

int main() {
	char *Sentence;
	Sentence = new char[];
	cout << "Enter String : ";
	cin.getline(Sentence,500,'\n');
	for(;*Sentence!=NULL;*Sentence++) {
		if(!MyIsLower(Sentence)) {
			MyConvertUpper(Sentence);
			cout << *Sentence;
		}
		else if(!MyIsUpper(Sentence)) {
			MyConvertLower(Sentence);
			cout << *Sentence;
		}
		else if(!MyIsDigit(Sentence)) {
			// Prints Nothing
		}
		else {
			cout << *Sentence;
		}
	}
	getch();
	return 0;
}

int MyIsDigit(char *chptr) {
	if(*chptr<=57 && *chptr>=48) {
		return 0;
	}
	return 1;
}

int MyIsLower(char *chptr) {
	if(*chptr>=97 && *chptr<=122) {
		return 0;
	}
	return 1;
}

int MyIsUpper(char *chptr) {
	if(*chptr>=65 && *chptr<=90) {
		return 0;
	}
	return 1;
}

void MyConvertUpper(char *chptr) {
	if(*chptr>=97 && *chptr<=122) {
		*chptr = *chptr - 32;
	}
	return;
}

void MyConvertLower(char *chptr) {
	if(*chptr>=65 && *chptr<=90) {
		*chptr = *chptr + 32;
	}
	return;
}