#include <iostream>
#include <conio.h>

using namespace std;

void CheckIndex(int, int);
void Display(int, int, int);

int main() {
	int Number;
	cout << "Enter Number : ";
	cin >> Number;
	int isMinus = 0;
	if(Number < 0) {
		isMinus = 1;
		Number = -Number;
	}
	int count = 0;
	int temp = Number;
	while(temp != 0) {
		temp = temp / 10;
		count++;
	}
	int *NumberArray;
	NumberArray = new int[count];
	for(int i = 0; i < count; i++) {
		NumberArray[i] = Number % 10;
		Number = Number / 10;
	}
	for(int i = count - 1; i >= 0; i--) {
		Display(NumberArray[i],i + 1,isMinus);
	}
	getch();
	return 0;
}

void CheckIndex(int x, int Location) {
	switch(x) {
		case 1:
			cout << " one ";
			break;
		case 2:
			if(Location == 2)
				cout << " twenty ";
			else
				cout << " two ";
			break;
		case 3:
			if(Location == 2)
				cout << " thirty ";
			else
				cout << " three ";
			break;
		case 4:
			if(Location == 2)
				cout << " forty ";
			else
				cout << " four ";
			break;
		case 5:
			if(Location == 2)
				cout << " fifty ";
			else
				cout << " five ";
			break;
		case 6:
			if(Location == 2)
				cout << " sixty ";
			else
				cout << " six ";
			break;
		case 7:
			if(Location == 2)
				cout << " seventy ";
			else
				cout << " seven ";
			break;
		case 8:
			if(Location == 2)
				cout << " eighty ";
			else
				cout << " eight ";
			break;
		case 9:
			if(Location == 2)
				cout << " ninty ";
			else
				cout << " nine ";
			break;
		case 0:
			break;
		default:
			break;
	}
}

void Display(int Number, int Location, int isMinus) {
	static int check = 1;
	if(isMinus && check) {
		cout << " Minus ";
		check = 0;
	}
	CheckIndex(Number,Location);
	switch(Location) {
	case 3:
		cout << " Hundred ";
		break;
	case 4:
		cout << " Thousand ";
		break;
	default:
		break;
	}
}