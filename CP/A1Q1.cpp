
#include <iostream>
#include <conio.h>

using namespace std;

bool isSolvable(int[], int);

int main() {
	int *Puzzle;
	int Size;
	cout << "Enter Size of Puzzle : ";
	cin >> Size;
	Puzzle = new int[Size];
	for(int i = 0; i < Size; i++) {
		cout << "Enter Number : ";
		cin >> Puzzle[i];
	}
	if(isSolvable(Puzzle,Size)) {
		cout << "Puzzle is Solvable";
	}
	else {
		cout << "Puzzle is Not Solvable";
	}
	getch();
	return 0;
}

bool isSolvable(int Puzzle[], int Size) {
	static int Location = 0;
	int enddiff = Size - Location - 1;
	int startdiff = Puzzle[Location] - Location;
	cout << "Location : " << Location << endl;
	cout << "StartDiff : " << startdiff << endl;
	cout << "EndDiff : " << enddiff << endl << endl;
	if(Puzzle[Location] == 0) {
		return 1;
	}
	else if((Puzzle[Location] > enddiff) && (startdiff == 1)) {
		return 0;
	}
	if(Puzzle[Location] <= enddiff) {
		Location = Location + Puzzle[Location];
		isSolvable(Puzzle,Size);
	}
	else {
		Location = Location - Puzzle[Location];
		isSolvable(Puzzle,Size);
	}
}