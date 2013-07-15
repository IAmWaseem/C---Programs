/*
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	long int number;
	int i=0;
	int SeparatedDigits[50];
	int EncryptedData[50];
	cout << "Enter Number : ";
	cin >> number;
	while(number!=0) {
		SeparatedDigits[i] = number % 10;
		EncryptedData[i] = (SeparatedDigits[i] + 7) % 10;
		number = number / 10;
		i++;
	}
	cout << "Encryped Number : ";
	for(int j=i-1;j>=0;j--) {
		cout << EncryptedData[j];
	}
	
	getch();
	return 0;
}
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char SomeString[101];
	int Frequency[27][2] = {0};
	for(int i=65, j=1;i<91;i++, j++) {
		Frequency[j][0] = i;
	}
	cout << "Enter String : ";
	cin.getline(SomeString, 100, '\n');
	/*
	for(int i=0;i<100;i++) {
		if(!((SomeString[i]>64 && SomeString[i]<92) || (SomeString[i]>96 && SomeString[i]<124) || SomeString[i]==32)) {
			cout << "Invalid String Entered" << endl;
			getch();
			exit(1);
		}
			
	}*/
	for(int i=0;i<100;i++) {
		switch(SomeString[i]) {
			case 'A':
			case 'a':
				Frequency[1][1]++;
				break;
			case 'B':
			case 'b':
				Frequency[2][1]++;
				break;
			case 'C':
			case 'c':
				Frequency[3][1]++;
				break;
			case 'D':
			case 'd':
				Frequency[4][1]++;
				break;
			case 'E':
			case 'e':
				Frequency[5][1]++;
				break;
			case 'F':
			case 'f':
				Frequency[6][1]++;
				break;
			case 'G':
			case 'g':
				Frequency[7][1]++;
				break;
			case 'H':
			case 'h':
				Frequency[8][1]++;
				break;
			case 'I':
			case 'i':
				Frequency[9][1]++;
				break;
			case 'J':
			case 'j':
				Frequency[10][1]++;
				break;
			case 'K':
			case 'k':
				Frequency[11][1]++;
				break;
			case 'L':
			case 'l':
				Frequency[12][1]++;
				break;
			case 'M':
			case 'm':
				Frequency[13][1]++;
				break;
			case 'N':
			case 'n':
				Frequency[14][1]++;
				break;
			case 'O':
			case 'o':
				Frequency[15][1]++;
				break;
			case 'P':
			case 'p':
				Frequency[16][1]++;
				break;
			case 'Q':
			case 'q':
				Frequency[17][1]++;
				break;
			case 'R':
			case 'r':
				Frequency[18][1]++;
				break;
			case 'S':
			case 's':
				Frequency[19][1]++;
				break;
			case 'T':
			case 't':
				Frequency[20][1]++;
				break;
			case 'U':
			case 'u':
				Frequency[21][1]++;
				break;
			case 'V':
			case 'v':
				Frequency[22][1]++;
				break;
			case 'W':
			case 'w':
				Frequency[23][1]++;
				break;
			case 'X':
			case 'x':
				Frequency[24][1]++;
				break;
			case 'Y':
			case 'y':
				Frequency[25][1]++;
				break;
			case 'Z':
			case 'z':
				Frequency[26][1]++;
				break;
			default:
				break;
		}
	}
	cout << "Before Sorting" << endl << endl;
	for(int i=1;i<27;i++) {
		cout << char(Frequency[i][0]) << "  " << Frequency[i][1] << endl;
	}
	cout << endl << endl;
	cout << "After Sorting in Descending Order" << endl << endl;
	int temp1, temp2;
	for(int i=1;i<27;i++) {
		for(int j=0;j<26;j++) {
			if(Frequency[j][1]>Frequency[j+1][1]) {
				temp1 = Frequency[j][1];
				temp2 = Frequency[j][0];
				Frequency[j][1] = Frequency[j+1][1];
				Frequency[j][0] = Frequency[j+1][0];
				Frequency[j+1][1] = temp1;
				Frequency[j+1][0] = temp2;	
			}
		}
	}
	for(int i=1;i<27;i++) {
		cout << char(Frequency[i][0]) << "  " << Frequency[i][1] << endl;
	}
	getch();
	return 0;
}