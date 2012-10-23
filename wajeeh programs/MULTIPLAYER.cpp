#include <iostream>
#include <conio.h>    //pre process directives

using namespace std;

int main()
{
	int a, bat1, bat2, bat3, bat4, bat5, error;   // initialization of integers
	int score1, score2;
	score1 = 0;
	score2 = 0;
	error = 0;

	cout << "Enter the number of players: ";                  // number of players entered
	cin >> a;

	switch (a)
	{
	case 1:
		{
			cout << "ONE PLAYER MODE SELECTED" << endl;         // ONE PLAYER MODE SELECTED
			
			char team; 
			cout << "Press A for ALPHA team" << endl;
			cout << "Press B for BRAVO team" << endl;
			cout << "Press C for CHARLIE team" << endl;
			cout << "Press D for DELTA team" << endl;
			cin >> team;

			switch (team)                                // switch applied on team selection
			{
			case 'A':
			case 'a':
				{
					cout << "You chose ALPHA team" << endl;
					break;
				}

			case 'B':
			case 'b':
				{
					cout << "You choose BRAVO team" << endl;
					break;
				}

			case 'C':
			case 'c':
				{
					cout << "You chose CHARLIE team" << endl;
					break;
				}

			case 'D':
			case 'd':
				{
					cout << "You chose DELTA team" << endl;
					break;
				}

			default :
				{
					cout << "Wrong value entered" << endl;
					error = 1;                                             // program wont run further if wrong value is entered
					break;
				}
			
			}

			if (error == 0)                                                       // if statement applied so when error is 0 only then the program will proceed further
				{cout << "IF your score is between (1 - 100) press 1" << endl;
				cout << "IF your score is betweem (101 - 200) press 2" << endl;
				cout << "IF your score is between (201 - 500) press 3" << endl;			// Range of Score
				cout<< "Enter score for first battle" << endl;
				cin >> bat1;
				switch (bat1)                                                  
					{									// Score for first battle
					case 1:
						{bat1 = 10;
						break;}
					case 2:
						{bat1 = 20;
						break;}
					case 3:
						{bat1= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}			
					}
				cout << "Enter scrore for second battle" << endl;                   // Score for 2nd battle
				cin >> bat2;
				switch (bat2)
					{
					case 1:
						{bat2 = 10;
						break;}
					case 2:
						{bat2 = 20;
						break;}
					case 3:
						{bat2= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter score for third battle" << endl;
				cin >> bat3;																// Score for third battle
				switch (bat3)
					{
					case 1:
						{bat3 = 10;
						break;}
					case 2:
						{bat3 = 20;
						break;}
					case 3:
						{bat3= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}	
				cout << "Enter score for fourth battle" << endl;
				cin >> bat4;
				switch (bat4)													//Score for 4th battle
					{
					case 1:
						{bat4 = 10;
						break;}
					case 2:
						{bat4 = 20;
						break;}
					case 3:
						{bat4= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter score for fifth battle" << endl;
				cin >> bat5;														// Score for 5th battle
				switch (bat5)
					{
					case 1:
						{bat5 = 10;
						break;}
					case 2:
						{bat5 = 20;
						break;}
					case 3:
						{bat5 = 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				if (error == 1)								// Program wont proceed if any wrong value is entered since it would change the value of error to 1
					{cout << "SCORE NOT POSSIBLE SINCE WRONG VALUE WAS ENTERED!" << endl;}
				else 
					{cout << "YOUR TOTAL SCORE IS: " << (bat1+bat2+bat3+bat4+bat5) << endl;}
			
			}
			else 
			{cout << "WRONG VALUE WAS ENTERED PROGRAM CANT PROCEED!" << endl;}
			
		break;}



	   case 2:
		{
			//two players mode 
			char team1, team2;
			cout << " CHOOSE YOUR TEAM PLAYER 1! " << endl;
			cout << "TWO PLAYERS MODE " << endl;
			cout << "Press A for ALPHA team" << endl;
			cout << "Press B for BRAVO team" << endl;
			cout << "Press C for CHARLIE team" << endl;
			cout << "Press D for DELTA team" << endl;
			cin >> team1;
			
			
		    switch (team1)
			{
			case 'A': 
			case 'a':
				{
					cout << "Player 1 chose  ALPHA team\n\n\n" << endl;
					break;
				}

			case 'B':
			case 'b':
				{
					cout << "Player 1 chose BRAVO team\n\n\n" << endl;
					break;
				}

			case 'C':
			case 'c':
				{
					cout << "Player 1 chose CHARLIE team\n\n\n" << endl;
					break;
				}

			case 'D':
			case 'd':
				{
					cout << "Player 1 chose DELTA team\n\n\n" << endl;
					break;
				}

			default :
				{
					cout << "Wrong value entered\n\n\n" << endl;
					error = 1;
					break;
				}
			
			}

			if ( error == 0)
			{cout << " CHOSE YOUR TEAM PLAYER 2! " << endl;
			cout << "Press A for ALPHA team" << endl;											// Player 2 selects team
			cout << "Press B for BRAVO team" << endl;
			cout << "Press C for CHARLIE team" << endl;
			cout << "Press D for DELTA team" << endl;
			cin >> team2;
			switch (team2)
			{
			case 'A':
			case 'a':
				{
					cout << "Player 2  chose APLHA TEAM\n\n\n" << endl;
					break;
				}

			case 'B':
			case 'b':
				{
					cout << "Player 2  chose BRAVO team\n\n\n" << endl;
					break;
				}

			case 'C':
			case 'c':
				{
					cout << "Player 2  chose CHARLIE team\n\n\n" << endl;
					break;
				}

			case 'D':
			case 'd':
				{
					cout << "Player 2  chose DELTA team\n\n\n" << endl;
					break;
				}

			default :
				{
					cout << "Wrong value entered\n\n\n" << endl;
					error = 1;
					break;
				}
			
			}
			if (error == 0)
				{
					cout << "IF your score is between (1 - 100) press 1" << endl;	              // Battle score is entered
				cout << "IF your score is betweem (101 - 200) press 2" << endl;
				cout << "IF your score is between (201 - 500) press 3" << endl;
				cout << "PLAYER 1 ENTER YOUR SCORE!" << endl;
				
				cout<< "Enter score for first battle" << endl;							// Score for First battle
				cin >> bat1;
				switch (bat1)
					{
					case 1:
						{bat1 = 10;
						break;}
					case 2:
						{bat1 = 20;
						break;}
					case 3:
						{bat1= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter scrore for second battle" << endl;
				cin >> bat2;
				switch (bat2)													// Score for 2nd battle
					{
					case 1:
						{bat2 = 10;
						break;}
					case 2:
						{bat2 = 20;
						break;}
					case 3:
						{bat2= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter score for third battle" << endl;
				cin >> bat3;											//Score for #rd battle
				switch (bat3)
					{
					case 1:
						{bat3 = 10;
						break;}
					case 2:
						{bat3 = 20;
						break;}
					case 3:
						{bat3= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}	
				cout << "Enter score for fourth battle" << endl;
				cin >> bat4;											//Score for $th battle
				switch (bat4)
					{
					case 1:
						{bat4 = 10;
						break;}
					case 2:
						{bat4 = 20;
						break;}
					case 3:
						{bat4= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter score for fifth battle" << endl;
				cin >> bat5;											//Score for 5TH BATTLE
				switch (bat5)
					{
					case 1:
						{bat5 = 10;
						break;}
					case 2:
						{bat5 = 20;
						break;}
					case 3:
						{bat5 = 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				score1 = (bat1+bat2+bat3+bat4+bat5);
				if (error == 1)																		// The total score wont be computed if wrong value is entered in any of the inputs
					{cout << "SCORE NOT POSSIBLE SINCE WRONG VALUE WAS ENTERED!" << endl;}
				else 
					{cout << "PLAYER 1 YOUR TOTAL SCORE IS: " << score1 << endl;}


				cout << "PLAYER 2 ENTER YOUR SCORE!" << endl;						//Player 2 Enters score
				cout<< "Enter score for first battle" << endl;
				cin >> bat1;
				switch (bat1)
					{
					case 1:
						{bat1 = 10;
						break;}
					case 2:
						{bat1 = 20;
						break;}
					case 3:
						{bat1= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter scrore for second battle" << endl;
				cin >> bat2;											//Score for 2nd Battle
				switch (bat2)
					{
					case 1:
						{bat2 = 10;
						break;}
					case 2:
						{bat2 = 20;
						break;}
					case 3:
						{bat2= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter score for third battle" << endl;				// Score for 3rd battle
				cin >> bat3;
				switch (bat3)
					{
					case 1:
						{bat3 = 10;
						break;}
					case 2:
						{bat3 = 20;
						break;}
					case 3:
						{bat3= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}	
				cout << "Enter score for fourth battle" << endl;
				cin >> bat4;											//Score for 4th battle
				switch (bat4)
					{
					case 1:
						{bat4 = 10;
						break;}
					case 2:
						{bat4 = 20;
						break;}
					case 3:
						{bat4= 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				cout << "Enter score for fifth battle" << endl;
				cin >> bat5;
				switch (bat5)												//Score for 5th battle
					{
					case 1:
						{bat5 = 10;
						break;}
					case 2:
						{bat5 = 20;
						break;}
					case 3:
						{bat5 = 50;
						break;}
					default:
						{cout << "Wrong value entered" << endl;
						error = 1;
						break;}
					}
				score2 = (bat1+bat2+bat3+bat4+bat5);
				if (error == 1)																		//PRogram wont run since the value of error will be changed to 1 whenever wrong value will be entered and the program wont proceed
					{cout << "SCORE NOT POSSIBLE SINCE WRONG VALUE WAS ENTERED!" << endl;}
				else 
					{cout << "PLAYER 2 YOUR TOTAL SCORE IS: " << score2 << endl;}
				
				if ( error == 0)
				{
			    if ( score1 > score2)
					{cout << "PLAYER 1 IS THE WINNER!" << endl;}
				else if (score2 > score1)
					{cout << "PLAYER 2 IS THE WINNER!" << endl;}
				else
					{cout << "THE MATCH WAS A DRAW" << endl;}
				}
				else 
					{cout << "unable to compute the result" << endl;}
			}
			else 
			{cout << "WRONG VALUE WAS ENTERED PROGRAM CANT PROCEED!" << endl;}

		
	break;	}

			}
			

		
		
		default:
			{cout << "WRONG VALUE ENTERED!" << endl;
			break;}
		
		
	
	
	
	}




}