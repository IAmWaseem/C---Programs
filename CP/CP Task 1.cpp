#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void Nullify(char*, int);

int main() {
	int iSize;
	cout << "Enter Size of Sentence : ";
	cin >> iSize;
	char* Sentence;
	Sentence = new char[iSize];
	if(Sentence == NULL) {
		cout << "Sentence : Memory Allocation Error" << endl;
	}
	else {
		char *Word;
		cout << "Enter Sentence : ";
		Nullify(Sentence,iSize);
		fflush(stdin);
		gets(Sentence);
		Word = new char[20];
		if(Word == NULL) {
			cout << "Word : Memory Allocation Error" << endl;
			delete [] Sentence;
		}
		else {
			cout << "Enter Word to Search For : ";
			Nullify(Word,iSize);
			gets(Word);
			char *temp;
			temp = new char[20];
			if(temp == NULL) {
				cout << "temp : Memory Allocation Error" << endl;
				delete [] Sentence;
				delete[] Word;
			}
			else {
				temp = strtok(Sentence, " ");
				while(temp != NULL) {
					int i = 0, check = 1;
					while(temp[i] != NULL || Word[i] != NULL) {
						if(temp[i] != Word[i]) {
							check = 0;
							break;
						}
						i++;
					}
					if(check) {
						cout << "Word Exists in the Sentence" << endl;
						break;
					}
					temp = strtok(NULL, " ");
				}
				delete [] Sentence;
				delete [] Word;
				delete [] temp;
			}
		}
	}
	getch();
	return 0;
}

void Nullify(char* Var, int iSize) {
	for(int i = 0; i < iSize; i++) {
		Var[i] = NULL;
	}
	return;
}