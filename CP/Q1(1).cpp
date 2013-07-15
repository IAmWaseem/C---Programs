#include <iostream>
#include <conio.h>
#include <cstring>
#include <Windows.h>

using namespace std;

void RemoveSpecialCharacters(char *);
char* PhoneticVersion(char *);

int main() {
	char *Sentence;
	int Length, i;
	MAIN:
	cout << "Enter Length of String : ";
	cin >> Length;
	if(Length > 20) {
		cout << "Invalid Length Entered, Enter Again.";
		goto MAIN;
	}
	Sentence = new char[Length];
	cout << "Enter String : ";
	for(i = 0; i < Length - 1; i++) {
		if((Sentence[i] = getche()) == '\r') {
			Sentence[i] = NULL;
			cout << endl;
			break;
		}
	}
	RemoveSpecialCharacters(Sentence);
	char *Phonetic = 0;
	Phonetic = PhoneticVersion(Sentence);
	cout << "Phonetic Version : " << Phonetic;
	delete[] Sentence;
	getch();
	return 0;
}

void RemoveSpecialCharacters(char *Sentence) {
	for(int i = 0; Sentence[i] != NULL; i++) {
		if((Sentence[i] > 32 && Sentence[i] < 65) || (Sentence[i] > 90 && Sentence[i] < 97) || (Sentence[i] > 122 && Sentence[i] < 128)) {
			Sentence[i] = ' ';
		}
	}
	return;
}

char* PhoneticVersion(char *Sentence) {
	char *Phonetic;
	int i;
	Phonetic = new char[50];
	for(i = 0; i < 50; i++) {
		Phonetic[i] = 0;
	}
	for(i = 0; Sentence[i] != NULL; i++) {
		switch(Sentence[i]) {
			case 'A':
			case 'a':
				strcat(Phonetic, "Alpha ");
				break;
			case 'B':
			case 'b':
				strcat(Phonetic, "Bravo ");
				break;
			case 'C':
			case 'c':
				strcat(Phonetic, "Charlie ");
				break;
			case 'D':
			case 'd':
				strcat(Phonetic, "Delta ");
				break;
			case 'E':
			case 'e':
				strcat(Phonetic, "Echo ");
				break;
			case 'F':
			case 'f':
				strcat(Phonetic, "Foxtrot ");
				break;
			case 'G':
			case 'g':
				strcat(Phonetic, "Golf ");
				break;
			case 'H':
			case 'h':
				strcat(Phonetic, "Hotel ");
				break;
			case 'I':
			case 'i':
				strcat(Phonetic, "India ");
				break;
			case 'J':
			case 'j':
				strcat(Phonetic, "Juliet ");
				break;
			case 'K':
			case 'k':
				strcat(Phonetic, "Kilo ");
				break;
			case 'L':
			case 'l':
				strcat(Phonetic, "Lima ");
				break;
			case 'M':
			case 'm':
				strcat(Phonetic, "Mike ");
				break;
			case 'N':
			case 'n':
				strcat(Phonetic, "November ");
				break;
			case 'O':
			case 'o':
				strcat(Phonetic, "Oscar ");
				break;
			case 'P':
			case 'p':
				strcat(Phonetic, "Papa ");
				break;
			case 'Q':
			case 'q':
				strcat(Phonetic, "Quebec ");
				break;
			case 'R':
			case 'r':
				strcat(Phonetic, "Romeo ");
				break;
			case 'S':
			case 's':
				strcat(Phonetic, "Sierra ");
				break;
			case 'T':
			case 't':
				strcat(Phonetic, "Tango ");
				break;
			case 'U':
			case 'u':
				strcat(Phonetic, "Uniform ");
				break;
			case 'V':
			case 'v':
				strcat(Phonetic, "Victor ");
				break;
			case 'W':
			case 'w':
				strcat(Phonetic, "Whiskey ");
				break;
			case 'X':
			case 'x':
				strcat(Phonetic, "X-Ray ");
				break;
			case 'Y':
			case 'y':
				strcat(Phonetic, "Yankee ");
				break;
			case 'Z':
			case 'z':
				strcat(Phonetic, "Zulu ");
				break;
			default:
				break;	
		}
	}
	return Phonetic;
}
