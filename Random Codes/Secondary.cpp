/*
#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main() {
	system("pause");
	char name[50], whattodo[150];
	while(1) {
		cout << "What is your name : ";
		cin >> name;
		cout << "What are you doing right now? ";
		cin >> whattodo;
		FILE *fptr;
		fptr = fopen("data.txt","a");
		while(*name != '.')
		{
			fputc(*name,fptr);
		}

	}
}*/