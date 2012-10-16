#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	char alphabet;
	cout << "Enter any Alphabet : ";
	cin >> alphabet;
	if(alphabet>=65 && alphabet<=90) {
		cout << "Alphabet is Capital" << endl;
		cout << "Alphabet before Conversion : " << alphabet << endl;
		alphabet = alphabet+32;
		cout << "Alphabet After Conversion : " << alphabet << endl;
	}
	else if(alphabet>=97 && alphabet<=122) {
		cout << "Alphabet is Small" << endl;
		cout << "Alphabet before Conversion : " << alphabet << endl;
		alphabet = alphabet-32;
		cout << "Alphabet After Conversion : " << alphabet << endl;
	}
	else {
		cout << "This is not an alphabet" << endl;
	}
	getch();
	return 0;
}