#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

bool check = false;
int r1,r2,c1,c2;
int choice;
int ** matrix;
int ** matrix1;
int ** matrix2;

void AddMatrix(char);
void DisplayMatrix();
void DeterminentMatrix();
void InverseMatrix();
void InitializeMatrix(int,int);
void OrderMatrix();
void CheckOrder();
void SwitchBoard();
void Clrscr();

ostream& Br(ostream& output) {
	return output << '\n' << flush;
}

ostream& Tab(ostream& output) {
	return output << '\t';
}

void Clrscr() {
	cout << setw(1534);
}

int main() {
	cout << Tab << Tab << Tab << Tab << "Welcome" << Br << Br << Br;
	SwitchBoard();
	getch();
	return 0;
}

void SwitchBoard() {
	char op='+';
	int nullify=0;
	cout << "[1] Add Matrix" << Br;
	cout << "[2] Subtract Matrix" << Br;
	cout << "[3] Determinent of a Matrix" << Br;
	cout << "[4] Multiply Matrix" << Br;
	cout << "[5] Inverse of a Matrix" << Br;
	cout << "[6] Exit the Application" << Br << Br << Br;
	cout << "Enter Choice[1-6]: ";
	cin >> choice;
	switch(choice) {
		case 1: {
			OrderMatrix();
			CheckOrder();
			if(check) {
				InitializeMatrix(nullify,2);
				AddMatrix(op);
				DisplayMatrix();
			}
			SwitchBoard();
			break;
		}
		case 2: {
			OrderMatrix();
			CheckOrder();
			if(check) {
				InitializeMatrix(nullify,2);
				op='-';
				AddMatrix(op);
				DisplayMatrix();
			}
			SwitchBoard();
			break;
		}
		case 3: {
			OrderMatrix();
			CheckOrder();
			if(check) {
				InitializeMatrix(nullify,2);
				DeterminentMatrix();
				DisplayMatrix();
			}
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			exit(EXIT_SUCCESS);
			break;
		}
		default: {
			cout << "Invalid Choice Entered" << Br << "Enter Again";
			getch();
			system("cls");
			SwitchBoard();
		}
	}
}

void OrderMatrix() {
	if(choice==1 || choice==2) {
		cout << "Enter Number of Rows for 1st Matrix : ";
		cin >> r1;
		cout << "Enter Number of Columns for 1st Matrix : ";
		cin >> c1;
		cout << "Enter Number of Rows for 2nd Matrix : ";
		cin >> r2;
		cout << "Enter Number of Columns for 2nd Matrix : ";
		cin >> c2;
	}
	else {
		cout << "Enter Number of Rows for Matrix : ";
		cin >> r1;
		cout << "Enter Number of Columns for Matrix : ";
		cin >> c1;
	}
}

void CheckOrder() {
	if((r1==r2) && (c1==c2) && ((choice==1)||(choice==2))) {
		check = true;
	}
	else if(choice==3 && r1==c1) {
		check = true;
	}
	else {
		cout << "Cannot add 2 Matrices having Different Rows/Columns" << Br;
		system("pause");
	}
}

void AddMatrix(char op) {
	for(int i=0;i<r1;i++) {
		for(int j=0;j<c1;j++) {
			if(op=='+') {
				matrix[i][j] = matrix1[i][j] + matrix2[i][j];
			}
			else if(op=='-') {
				matrix[i][j] = matrix1[i][j] - matrix2[i][j];
			}
		}
	}
}

void InitializeMatrix(int nullify, int num) {
	if(num==2) {
		matrix1 = new int*[r1];
		matrix2 = new int*[r2];
		for(int i=0;i<r1;i++) {
			matrix1[i] = new int[c1];
		}
		for(int i=0;i<r2;i++) {
			matrix2[i] = new int[c2];
		}
		for(int i=0;i<r1;i++) {
			for(int j=0;j<c1;j++) {
				matrix1[i][j] = 0;
			}
		}
		for(int i=0;i<r2;i++) {
			for(int j=0;j<c2;j++) {
				matrix2[i][j] = 0;
			}
		}
	}
	matrix = new int*[r1];
	for(int i=0;i<r1;i++) {
		matrix[i] = new int[c1];
	}
	for(int i=0;i<r1;i++) {
		for(int j=0;j<c2;j++) {
			matrix[i][j] = 0;
		}
	}
	if(!nullify) {
		if(choice==1 || choice==2) {
			for(int i=0;i<r1;i++) {
				for(int j=0;j<c1;j++) {
					cout << "Enter Value for Matrix 1 : Row: " << i+1 << "  Column: " << j+1 << "   : ";
					cin >> matrix1[i][j];
				}
			}
			for(int i=0;i<r2;i++) {
				for(int j=0;j<c2;j++) {
					cout << "Enter Value for Matrix 2 : Row: " << i+i << "  Column: " << j+1 << "   : ";
					cin >> matrix2[i][j];
				}
			}
		}
		else if(choice==3) {
			for(int i=0;i<r1;i++) {
				for(int j=0;j<c1;j++) {
					cout << "Enter Value for Matrix : Row: " << i+1	 << "  Column: " << j+1 << "   : ";
					cin >> matrix1[i][j];
				}
			}
		}
	}
}

void DisplayMatrix() {
	cout << Br << Br;
	if(choice==1) {
		cout << "Displaying Addition of 2 Matrices" << Br << Br;
	}
	else if(choice==2) {
		cout << "Displaying Subtraction of 2 Matrices" << Br << Br;
	}
	for(int i=0;i<r1;i++) {
		for(int j=0;j<c1;j++) {
			cout << Tab << matrix[i][j];
		}
		cout << Br;
	}
	system("pause");
	Clrscr();
}

void DeterminentMatrix() {
	float ratio, det=1;
	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < r1; j++) {
			if(j>i) {
				ratio = matrix1[j][i]/matrix1[i][i];
				for(int k = 0; k < r1; k++) {
					matrix1[j][k] -= ratio * matrix1[i][k];
				}
			}
		}
	}
	for (int i=0;i<r1;i++) {
		det *= matrix1[i][i];
	}
}