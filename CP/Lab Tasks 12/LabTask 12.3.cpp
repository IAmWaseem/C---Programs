#include <iostream>
#include <ctime>

using namespace std;

class Die {
	protected:
		int Value;
	public:
		void RollDie() {
			Value = 1 + rand() % 6;
		}
		int getValue() {
			return Value;
		}
};

class Player {
	protected:
		int Score;
		Die Die1;
		Die Die2;
		int Money;
	public:
		Player() {
			Score = 0;
			Money = 7000;
		}
		int GetMoney() {
			return Money;
		}
		int Round() {
			Die1.RollDie(); Die2.RollDie();
			Score = Score + Die1.getValue() + Die2.getValue();
			if(Score == 5 || Score == 15 || Score == 25 || Score == 35) {
				if(Money < 5000) {
					Money = 0;
				}
				else {
					Money = Money - 5000;
				}
			}
			if(Score == 10 || Score == 20 || Score == 30 || Score == 40) {
				Money += 10000;
			}
			return Score;
		}
};

class Game {
	protected:
		Player* Players;
		int Size;
	public:
		Game(int size) {
			Players = new Player[size];
			Size = size;
		}
		void StartGame() {
			int MaxScore = 0;
			int PlayerNumber;
			int *Scores;
			Scores = new int[Size];
			while(MaxScore < 40) {
				for(int i = 0; i < Size; i++) {
					Scores[i] = Players[i].Round();
				}
				MaxScore = 0;
				for(int i = 0; i < Size; i++) {
					if(MaxScore < Scores[i]) {
						MaxScore = Scores[i];
						PlayerNumber = i + 1;
					}
				}
			}
			int *Money;
			Money = new int[Size];
			int MaxMoney = 0;
			for(int i = 0; i < Size; i++) {
				Money[i] = Players[i].GetMoney();
				if(MaxMoney < Money[i]) {
					MaxMoney = Money[i];
				}
			}
			for(int i = 0; i < Size; i++) {
				if(MaxMoney == Players[i].GetMoney()) {
					cout << "Player " << i + 1 << " Won!!" << endl;
				}
			}
			delete[] Scores;
			delete[] Money;
		}
		~Game() {
			delete[] Players;
		}
};


int main() {
	srand( time(0) );
	int Number;
	cout << "Enter Number of Players : ";
	cin >> Number;
	if(Number < 2 || Number > 6) {
		cout << "Invalid Players" << endl;
	}
	else {
		Game Game1(Number);
		Game1.StartGame();
	}
	return 0;
}
