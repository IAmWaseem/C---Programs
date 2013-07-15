#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>


int* wholedata(int);
float* decimal(int);
int power(int*,int*);
int power(float*,float*);
int halffact(int*);

int rounding(float);

#define ROWS 20
#define COLUMNS 50

char ReservedWords[][5] =  {
	"var",
	"take",
	"show"
};

using namespace std;

int main() {
	int *IntegerVariables;
	float *FloatVariables;
	char **SourceCode;
	int i, j,PresentColumn = 0, PresentRow = 0;
	int checkfloat = 0, checkint = 0;
	int Traverse;
	char Line[50];
	char *vtype;
	SourceCode = new char*[ROWS];
	for(i=0;i<ROWS;i++) {
		SourceCode[i] = new char[COLUMNS];
	}
	for(i=0;i<ROWS;i++) {
		for(j=0;j<COLUMNS;j++) {
			SourceCode[i][j] = 0;
		}
	}
	while(PresentRow<=ROWS) {
		cin.getline(Line,50,'\n');
		for(Traverse=0;(SourceCode[PresentRow][Traverse]=Line[Traverse])!=NULL;Traverse++);
		SourceCode[PresentRow][Traverse] = NULL;
		if(SourceCode[PresentRow][0]==']') {
			break;
		}
		PresentRow++;
		PresentColumn = 0;
	}
	char *RowPtr = &SourceCode[0][0];
	cout << endl;
	PresentRow = 0;
	PresentColumn = 0;
	char *checkvar;
	cout << endl << endl << "What do you want to do with this code?";
	cout << endl << endl ;
	getch();
	while(SourceCode[PresentRow][PresentColumn]!=']') {
		if(SourceCode[0][0]!='[') {
			cout << "Syntax Error Line 1";
			break;
		}
		checkvar = strtok(RowPtr," ");
		//cout << checkvar;
		while(checkvar!=NULL) {
			for(int words=0;words<3;words++) {
				if(checkvar==ReservedWords[words]) {
					switch(words) {
					case 1: {
						checkvar = strtok(NULL, " ");
						int check, c;
						for(check=0;checkvar[check]!=':';check++);
						check++;
						for(c=0;(vtype[c]=checkvar[check])!=NULL;c++,check++);
						vtype[c] = NULL;
						if(vtype=="whole") {
							checkint++;
						}
						else if(vtype=="decimal") {
							checkfloat++;
						}
						IntegerVariables = wholedata(checkint);
						FloatVariables = decimal(checkfloat);
						break;
							}
					case 2: {
						for(int var=0;var<checkint;var++) {
							cin >> IntegerVariables[var];
						}
						for(int var2=0;var2<checkfloat;var2++) {
							cin >> FloatVariables[var2];
						}
						break;
							}
					case 3: {
						checkvar = strtok(NULL," ");
						int cc = 0;
						int ccc = 0;
						while(checkvar[cc]!=NULL) {
							if(checkvar[cc]=='^') {
								cout << power(&FloatVariables[ccc],&FloatVariables[ccc+1]);
								ccc++;
							}
							else if(checkvar[cc]=='!') {
								cout << halffact(&IntegerVariables[ccc]);
								ccc++;
							}
							else if(checkvar[cc]=='~') {
								cout << rounding(FloatVariables[ccc]);
								ccc++;
							}
							cc++;
						}
						break;
							}
					}
				}
			}
			checkvar = strtok(NULL, " ");
		}
		PresentRow++;
		RowPtr = &SourceCode[PresentRow][0];
		if(SourceCode[PresentRow][PresentColumn]==NULL) {
			PresentColumn = 0;
			cout << endl;
		}
		//cout << SourceCode[PresentRow][PresentColumn];
	}
	for(i=0;i<ROWS;i++) {
		delete [] SourceCode[i];
	}
	delete [] SourceCode;
	getch();
	return 0;
}



int* wholedata(int a)
{
	int* whole=new int[a];
	return whole;
}

float* decimal(int a)
{
	float* decimal=new float[a];
	return decimal;
}

int power(int* a,int* b)
{
	int power=1;
	for(int i=0; i < *b; i++)
	{
		power=power*(*a);
	}
	return power;
}

int power(float* a, float* b)
{
	int power=1;
	for(int i=0; i < *b; i++)
	{
		power=float(power)*(*a);
	}
	return int(power);
}

int halffact(int* a)
{
	int fact=1;
	for(int i=1; i <= *a; i++)
	{
		fact=fact*(i);
	}
	return (fact/2);
}
int rounding(float a)
{
	float newnum=a;
	for(int i=0; i < a; i++)
	{
		newnum-=1;
		if(newnum>0 && newnum<1)
		{
			if(newnum==0.5)
			{
				a+=1;
				return static_cast<int>(a);
			}
			if(newnum>0.5)
			{
				a=static_cast<float>(a);
				return a+1;
			}
			else if(newnum < 0.5)
			{
				return static_cast<int>(a);
			}


		}
	}

	int b= a * 10;

	if(b % 5==0)
	{
		return a+0.5;
	}
	else 
	{
		return static_cast<int>(a);
	}
}