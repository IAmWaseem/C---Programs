#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int a, bat1, bat2, bat3, bat4, bat5, error;
	error = 2;

	cout << "Enter the number of players: ";
	cin >> a;

	switch (a)
	{
	case 1:
		{
			cout << "ONE PLAYER MODE SELECTED" << endl;
			// for 1 player only
			char team; 
			cout << "Press A for ALPHA team" << endl;
			cout << "Press B for BRAVO team" << endl;
			cout << "Press C for CHARLIE team" << endl;
			cout << "Press D for DELTA team" << endl;
			cin >> team;

			switch (team)
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
					error = 0;
					break;
				}
			
			}

			if (error != 0)
				{cout << "IF your score is between (1 - 100) press 1" << endl;
				cout << "IF your score is betweem (101 - 200) press 2" << endl;
				cout << "IF your score is between (201 - 500) press 3" << endl;
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
						bat1 = 0;
						break;}
					}
				cout << "Enter scrore for second battle" << endl;
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
						bat2 = 0;
						break;}
					}
				cout << "Enter score for third battle" << endl;
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
						bat3 = 0;
						break;}
					}	
				cout << "Enter score for fourth battle" << endl;
				cin >> bat4;
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
						bat4 = 0;
						break;}
					}
				cout << "Enter score for fifth battle" << endl;
				cin >> bat5;
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
						bat5 = 0;
						break;}
					}
				if (bat1 == 0 || bat2 == 0 || bat3 == 0 || bat4 == 0 || bat5 == 0)
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
				{
					cout << "Player 1 chose  ALPHA team\n\n\n" << endl;
					break;
				}

			case 'B':
				{
					cout << "Player 1 chose BRAVO team\n\n\n" << endl;
					break;
				}

			case 'C':
				{
					cout << "Player 1 chose CHARLIE team\n\n\n" << endl;
					break;
				}

			case 'D':
				{
					cout << "Player 1 chose DELTA team\n\n\n" << endl;
					break;
				}

			default :
				{
					cout << "Wrong value entered\n\n\n" << endl;
					error = 0;
					break;
				}
			
			}

			
			cout << " CHOSE YOUR TEAM PLAYER 2! " << endl;
			cout << "Press A for ALPHA team" << endl;
			cout << "Press B for BRAVO team" << endl;
			cout << "Press C for CHARLIE team" << endl;
			cout << "Press D for DELTA team" << endl;
			cin >> team2;
			switch (team2)
			{
			case 'A': 
				{
					cout << "Player 2  chose APLHA TEAM\n\n\n" << endl;
					break;
				}

			case 'B':
				{
					cout << "Player 2  chose BRAVO team\n\n\n" << endl;
					break;
				}

			case 'C':
				{
					cout << "Player 2  chose CHARLIE team\n\n\n" << endl;
					break;
				}

			case 'D':
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
			if (error != 0 && error != 1)
				{
					cout << "IF your score is between (1 - 100) press 1" << endl;
				cout << "IF your score is betweem (101 - 200) press 2" << endl;
				cout << "IF your score is between (201 - 500) press 3" << endl;
				cout << "PLAYER 1 ENTER YOUR SCORE!" << endl;
				
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
						bat1 = 0;
						break;}
					}
				cout << "Enter scrore for second battle" << endl;
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
						bat2 = 0;
						break;}
					}
				cout << "Enter score for third battle" << endl;
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
						bat3 = 0;
						break;}
					}	
				cout << "Enter score for fourth battle" << endl;
				cin >> bat4;
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
						bat4 = 0;
						break;}
					}
				cout << "Enter score for fifth battle" << endl;
				cin >> bat5;
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
						bat5 = 0;
						break;}
					}
				if (bat1 == 0 || bat2 == 0 || bat3 == 0 || bat4 == 0 || bat5 == 0)
					{cout << "SCORE NOT POSSIBLE SINCE WRONG VALUE WAS ENTERED!" << endl;}
				else 
					{cout << "PLAYER 1 YOUR TOTAL SCORE IS: " << (bat1+bat2+bat3+bat4+bat5) << endl;}


				cout << "PLAYER 2 ENTER YOUR SCORE!" << endl;
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
						bat1 = 0;
						break;}
					}
				cout << "Enter scrore for second battle" << endl;
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
						bat2 = 0;
						break;}
					}
				cout << "Enter score for third battle" << endl;
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
						bat3 = 0;
						break;}
					}	
				cout << "Enter score for fourth battle" << endl;
				cin >> bat4;
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
						bat4 = 0;
						break;}
					}
				cout << "Enter score for fifth battle" << endl;
				cin >> bat5;
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
						bat5 = 0;
						break;}
					}
				if (bat1 == 0 || bat2 == 0 || bat3 == 0 || bat4 == 0 || bat5 == 0)
					{cout << "SCORE NOT POSSIBLE SINCE WRONG VALUE WAS ENTERED!" << endl;}
				else 
					{cout << "PLAYER 1 YOUR TOTAL SCORE IS: " << (bat1+bat2+bat3+bat4+bat5) << endl;}
			
			}
			else 
			{cout << "WRONG VALUE WAS ENTERED PROGRAM CANT PROCEED!" << endl;}

		
	break;	}
			

		
		
		
		
		
	
	
	
	}




}