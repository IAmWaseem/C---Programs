#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	char player,mode,player1,player2;
	int score1,score2,bat1,bat2,bat3,bat4,bat5;
	cout << "Enter mode of game:" << endl;
	cout<<"single player or 2 players"<<endl;
	cin>>mode;
	if(mode==1)
	{
		cout<<"single player mode"<<endl;
		cout<<"Select player:";
		cin>>player;
		if(player=='A')
		{
			cout<<"Player is ALPHA"<<endl;
		}
		else if(player=='B')
		{
			cout<<"Player is BRAVO"<<endl;
		}
		else if(player=='C')
		{
			cout<<"Player is CHARLE"<<endl;
		}
		else if(player=='D')
		{
			cout<<"Player is DELTA"<<endl;
		}
		else
		{
			cout<<"Plz enter correct chioce "<<endl;
		}
	}
	cout<<"Enter score for battle 1:";
	cin>>bat1;
	if(bat1>=0 && bat1<=100)
	{
		bat1=10;
	}
	else if(bat1>=101 && bat1<=200)
	{
		bat1=20;
	}
	else if(bat1>=201 && bat1<=500)
	{
		bat1=50;
	}
	else
	{
		cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 2:";
	cin>>bat2;
	if(bat2>=0 && bat2<=100)
	{
		bat2=10;
	}
	else if(bat2>=101 && bat2<=200)
	{
		bat2=20;
	}
	else if(bat2>=201 && bat2<=500)
	{
		bat2=50;
	}
	else
	{
		cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 3:";
	cin>>bat3;
	if(bat3>=0 && bat3<=100)
	{
		bat3=10;
	}
	else if(bat3>=101 && bat3<=200)
	{
		bat3=20;
	}
	else if(bat3>=201 && bat3<=500)
	{
		bat3=50;
	}
	else
	{
		cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 4:";
	cin>>bat4;
	if(bat4>=0 && bat4<=100)
	{
		bat4=10;
	}
	else if(bat4>=101 && bat4<=200)
	{
		bat4=20;
	}
	else if(bat4>=201 && bat4<=500)
	{
		bat4=50;
	}
	else
	{
		cout<<"Plz enter correct chioce "<<endl;
	}


	cout<<"Enter score for battle 5:";
	cin>>bat5;
	if(bat5>=0 && bat5<=100)
	{
		bat5=10;
	}
	else if(bat5>=101 && bat5<=200)
	{
		bat5=20;
	}
	else if(bat5>=201 && bat5<=500)
	{
		bat5=50;
	}
	else
	{ 
		cout<<"Plz enter correct chioce "<<endl;
	}

	score1=bat1+bat2+bat3+bat4+bat5;
	cout<<" Score of player :"<< score1<<endl;

	if(mode==2)
	{
	cout<<"2 players mode"<<endl;
	cout<<"Select players:";
	cout<<"Enter player 1 :";
	cin>>player1;

	if(player1=='A')
	{
	cout<<"Player 1 is ALPHA"<<endl;
	}
	else if(player1=='B')
	{
	cout<<"Player 1 is BRAVO"<<endl;
	}
	else if(player1=='C')
	{
	cout<<"Player 1 is CHARLE"<<endl;
	}
	else if(player1=='D')
	{
	cout<<"Player 1 is DELTA"<<endl;
	}
	else
	{
	cout<<"Plz enter correct chioce "<<endl;
	}

	cout<<"Enter player 2 :";
	cin>>player2;
	if(player2=='A')
	{
	cout<<"Player 2 is ALPHA"<<endl;
	}
	else if(player2=='B')
	{
	cout<<"Player 2 is BRAVO"<<endl;
	}
	else if(player2=='C')
	{
	cout<<"Player 2 is CHARLE"<<endl;
	}
	else if(player2=='D')
	{
	cout<<"Player 2 is DELTA"<<endl;
	}
	else
	{
	cout<<"Plz enter correct chioce "<<endl;
	}

	}
	cout<<"Enter score for battle 1 of player 1:";
	cin>>bat1;
	if(bat1>=0 && bat1<=100)
	{
	bat1=10;
	}
	else if(bat1>=101 && bat1<=200)
	{
	bat1=20;
	}
	else if(bat1>=201 && bat1<=500)
	{
	bat1=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 2 of player1:";
	cin>>bat2;
	if(bat2>=0 && bat2<=100)
	{
	bat2=10;
	}
	else if(bat2>=101 && bat2<=200)
	{
	bat2=20;
	}
	else if(bat2>=201 && bat2<=500)
	{
	bat2=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 3 of player1:";
	cin>>bat3;
	if(bat3>=0 && bat3<=100)
	{
	bat3=10;
	}
	else if(bat3>=101 && bat3<=200)
	{
	bat3=20;
	}
	else if(bat3>=201 && bat3<=500)
	{
	bat3=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 4 of player1:";
	cin>>bat1;
	if(bat4>=0 && bat4<=100)
	{
	bat4=10;
	}
	else if(bat4>=101 && bat4<=200)
	{
	bat4=20;
	}
	else if(bat4>=201 && bat4<=500)
	{
	bat4=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}


	cout<<"Enter score for battle 5 of player1:";
	cin>>bat5;
	if(bat5>=0 && bat5<=100)
	{
	bat5=10;
	}
	else if(bat5>=101 && bat5<=200)
	{
	bat5=20;
	}
	else if(bat5>=201 && bat5<=500)
	{
	bat5=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}

	score1=bat1+bat2+bat3+bat4+bat5;
	cout<<" Score of player 1:"<< score1<<endl;

	cout<<"Enter score for battle 1 of player2:";
	cin>>bat1;
	if(bat1>=0 && bat1<=100)
	{
	bat1=10;
	}
	else if(bat1>=101 && bat1<=200)
	{
	bat1=20;
	}
	else if(bat1>=201 && bat1<=500)
	{
	bat1=50;
	}
	else
	{
	cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 2 of player2:";
	cin>>bat2;
	if(bat2>=0 && bat2<=100)
	{
	bat2=10;
	}
	else if(bat2>=101 && bat2<=200)
	{
	bat2=20;
	}
	else if(bat2>=201 && bat2<=500)
	{
	bat2=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 3 of player2:";
	cin>>bat3;
	if(bat3>=0 && bat3<=100)
	{
	bat3=10;
	}
	else if(bat3>=101 && bat3<=200)
	{
	bat3=20;
	}
	else if(bat3>=201 && bat3<=500)
	{
	bat3=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}
	cout<<"Enter score for battle 4 of player2:";
	cin>>bat1;
	if(bat4>=0 && bat4<=100)
	{
	bat4=10;
	}
	else if(bat4>=101 && bat4<=200)
	{
	bat4=20;
	}
	else if(bat4>=201 && bat4<=500)
	{
	bat4=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}


	cout<<"Enter score for battle 5 of player 2:";
	cin>>bat5;
	if(bat5>=0 && bat5<=100)
	{
	bat5=10;
	}
	else if(bat5>=101 && bat5<=200)
	{
	bat5=20;
	}
	else if(bat5>=201 && bat5<=500)
	{
	bat5=50;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}

	score2=bat1+bat2+bat3+bat4+bat5;
	cout<<" Score of player 2 :"<< score2<<endl;
	if(score1>score2)
	{
	cout<<"Player 1 is winner"<<endl;
	}
	if(score2>score1)
	{
	cout<<"Player 2 is winner"<<endl;
	}
	else
	{ cout<<"Plz enter correct chioce "<<endl;
	}

	getch();
	return 0;
}