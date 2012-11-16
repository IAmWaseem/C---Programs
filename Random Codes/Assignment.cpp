#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int InitializeMatrix(int rows, int columns) {
	int ** matrix;
	matrix = new int*[rows];
	for(int i=0;i<rows;i++) {
		matrix[i] = new int[columns];
	}
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			matrix[i][j] = 0;
		}
	}
	srand(time(0));
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			matrix[i][j] = rand()%10;
		}
	}
	cout << "Displaying Matrix " << rows << "x" << columns << " in tabular form" << endl << endl;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			cout << "\t" << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
	return 0;
}

int AddMatrix(int rows, int columns) {
	int ** matrix1;
	int ** matrix2;
	matrix1 = new int*[rows];
	matrix2 = new int*[rows];
	for(int i=0;i<rows;i++) {
		matrix1[i] = new int[columns];
		matrix2[i] = new int[columns];
	}
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			matrix1[i][j] = 0;
			matrix2[i][j] = 0;
		}
	}
	cout << "Enter Matrix 1 Data" << endl;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			cout << "Enter Data : ";
			cin >> matrix1[i][j];
		}
	}
	cout << endl << "Enter Matrix 2 Data" << endl;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			cout << "Enter Data : ";
			cin >> matrix2[i][j];
		}
	}
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	cout << "Displaying SUM in tabular form" << endl << endl;
	for(int i=0;i<rows;i++) {
		for(int j=0;j<columns;j++) {
			cout << "\t" << matrix1[i][j];
		}
		cout << endl;
	}
	return 0;
}

int MultiplyMatrix() {
	int r1,r2,c1,c2;
	cout << "Enter Rows of 1st Matrix : ";
	cin >> r1;
	cout << "Enter Columns of 1st Matrix : ";
	cin >> c1;
	cout << "Enter Rows of 2nd Matrix : ";
	cin >> r2;
	cout << "Enter Columns of 2nd Matrix : ";
	cin >> c2;
	if(c1 == r2) {
		const int fc = c2;
		const int fr = r1;
		int ** matrix1;
		int ** matrix2;
		int ** result;
		matrix1 = new int*[r1];
		matrix2 = new int*[r2];
		result = new int*[fr];
		for(int i=0;i<r1;i++) {
			matrix1[i] = new int[c1];
		}
		for(int i=0;i<r2;i++) {
			matrix2[i] = new int[c2];
		}
		for(int i=0;i<fr;i++) {
			result[i] = new int[fc];
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
		for(int i=0;i<fr;i++) {
			for(int j=0;j<fc;j++) {
				result[i][j] = 0;
			}
		}
		for(int i=0;i<fr;i++) {
			for(int j=0;j<fc;j++) {
				result[i][j]=0;
				for(int k=0;k<2;k++) {
					result[i][j] = result[i][j] + (matrix1[i][k] * matrix2[k][j]);
				}
			}
		}
		cout << "Result is ";
		for(int i=0;i<fr;i++) {
			for(int j=0;j<fc;j++) {
				cout << "\t" << result[i][j];
			}
			cout << endl;
		}
	}
	else {
		cout << "Multiplication Not Possible with such type of Matrices" << endl;
	}
	return 0;
}

int InverseMatrix() {
	int rows,columns;
	cout << "Enter Rows : ";
	cin >> rows;
	cout << "Enter Columns : ";
	cin >> columns;
	if(rows!=columns) {
		cout << "The Inverse of the Following Matrix is Not Possible as it is not a square matrix" << endl;
	}
	else {
		int ** matrix,temp;
		matrix = new int*[rows];
		for(int i=0;i<rows;i++) {
			matrix[i] = new int[columns];
		}
		for(int i=0;i<rows;i++) {
			for(int j=0;j<columns;j++) {
				matrix[i][j] = 0;
			}
		}
		for(int i=0;i<rows;i++) {
			for(int j=0;j<columns;j++) {
				cout << "Enter Value For Row " << i+1 << " Column " << j+1 << " : ";
				cin >> matrix[i][j];
			}
		}
		for(int i=0;i<rows;i++) {
			for(int j=0;j<columns;j++) {
				if(i==j) {
					if(matrix[i][j]==1 && i==1 && j==1) {
						break;
					}
					else if(matrix[i][j]!=1 && i==1 && j==1){
						for(int k=0;k<j;k++) {
							temp = matrix[i][1];
							matrix[i][k]=matrix[i][k]/temp;
						}
						break;
					}
					else {
						if(matrix[i][j]==0 && i!=j) {
							for(int i=0;i<rows;i++) {
								for(int j=0;j<columns;j++) {
									if(matrix[i][j]!=0 && i!=j) {
										temp=matrix[i][j];
										for(int k=0;k<rows;k++) {
											matrix[i][k]=matrix[i][k]/temp;	
											
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	int r,c,n;
	MENU:
	cout << "MAIN MENU" << endl;
	cout << "[1] Initialize and Display Random Matrix in Tabular Form" << endl;
	cout << "[2] Add 2 Matrices" << endl;
	cout << "[3] Multiply 2 Matrices" << endl;
	cout << "[4] Inverse of a Matrix" << endl;
	cout << "[5] Exit The Program" << endl;
	cout << "Enter Choice[1-5]: ";
	cin >> n;
	if(n>0 && n<3) {
		MAIN:
		cout << "Enter Number of Rows : ";
		cin >> r;
		if(r<2 || r==4) {
			cout << "Invalid Rows. Must Enter a value between 2 and 9." << endl;
			goto MAIN;
		}
		cout << "Enter Number of Columns : ";
		cin >> c;
		if(c<2) {
			cout << "Invalid Columns. Must Enter a value between 2 and 9." << endl;
			goto MAIN;
		}
	}
	switch(n) {
		case 1: {
			InitializeMatrix(r,c);
			break;
		}
		case 2: {
			AddMatrix(r,c);
			break;
		}
		case 3: {
			MultiplyMatrix();
			break;
		}
		case 4: {
			InverseMatrix();
			break;
		}
		case 5: {
			goto END;
			break;
		}
		default: {
			cout << "Invalid Choice" << endl << endl;
			getch();
			goto MENU;	
		}
	}
	END:
	getch();
	return 0;
}