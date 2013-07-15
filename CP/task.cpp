#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
int main()
{
	char *sentence ,*search_word;
	sentence=new char[50];
	cout<<"Enter sentence:  ";
	cin.getline(sentence,50,'\n');
	cout<<"Enter search word :  ";
	search_word=new char[10];
	cin.getline(search_word,10,'\n');
	char *token;
	token=new char[20];
	token=strtok(sentence," ");
	while(token!=NULL)
	{
		token=strtok(sentence,NULL);
		if(token==search_word)
		{
			cout<<"\n search word is found ";
		}
		else
			cout<<"not found";
	}
	getch();
	return 0;
}
