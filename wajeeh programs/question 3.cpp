#include <iostream>
#include <conio.h>

using namespace std;

int main ()

{
	cout << "*****ASSIGNMENT NO 5.3*****" << endl;

	char cont, country, city;

	cout << "Press A for Asia" << endl;
	cout << "Press E for Europe" << endl;
	cin >> cont;

	switch (cont) 
		{
		case 'A':    //for asia
		case 'a':
			{
				cout << "YOU CHOSE ASIA!\n" << endl;
				cout << "Press P for Pakistan" << endl;
				cout << "Press B for Bangladesh" << endl;
				cout << "Press I for India" << endl;
				cout << "Press S for Sirilanka" << endl;
				cin >> country;

				switch (country)
					{
					case 'P':
					case 'p':
						{
							cout << "YOU CHOSE PAKISTAN!\n" << endl;
							cout << "What is the Capital of Pakistan?" << endl;
							cout << "Press I for Islamabad" << endl;
							cout << "Press R for Rawalpindi" << endl;
							cout << "Press K for Karachi" << endl;
							cout << "Press P for Peshawar" << endl;
							cout << "Press L for Lahore" << endl;
							cin >> city;

							switch (city)
								{
								case 'I':
								case 'i':
									{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
									break;}
								case 'R':
								case 'r':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
									break;}
								case 'K':
								case 'k':
									{cout << "YOU GOT THE WRONG ANSWER! " << endl;
									break;}
								case 'P':
								case 'p':
									{cout << "YOU GOT THE WRONG ANSWER! " << endl;
									break;}
								case 'L':
								case 'l':
									{cout << "YOU GOT THE WRONG ANSWER! " << endl;
									break;}
								default:
									{cout << "Wrong Value Entered!" << endl;
									break;}
								}
						break;}
					case 'B': //for bangladesh capital is dhaka
					case 'b':
						{
							cout << "YOU CHOSE BANGLADESH!" << endl;
							cout << "What is the Capital of Bangladesh?" << endl;
							cout << "Press R for Rangpur" << endl;
							cout << "Press S for Saidpur" << endl;
							cout << "Press H for Dhali" << endl;
							cout << "Press D for Dhaka" << endl;
							cout << "Press K for Khulna" << endl;
							cin >> city;

							switch (city)
								{
								case 'R':
								case 'r':
									{cout << "YOU GOT THE WRONG ANSWER! :(" << endl;
									break;}
								case 'S':
								case 's':
									{cout << "YOU GOT THE WRONG ANSWER! :(" << endl;
									break;}
								case 'H':
								case 'h':
									{cout << "YOU GOT THE WRONG ANSWER! :(" << endl;}
								case 'D':
								case 'd':
									{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
									break;}
								case 'K':
								case 'k':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
									break;}
								default:
									{cout << "Wrong Value Entered!" << endl;
									break;}


								}
					
							break;}					
				
				
					case 'I': //for india capital is Delhi
					case 'i':
						{
							cout << "YOU CHOSE INDIA" << endl;
							cout << "What is the Capital of India?" << endl;
							cout << "Press D for Delhi" << endl;
							cout << "Press L for Lucknow" << endl;
							cout << "Press R for Ranchi" << endl;
							cout << "Press A for Banglore" << endl;
							cout << "Press C for Calcutta" << endl;
							cin >> city;

							switch (city)
								{
								case 'D':
								case 'd':
									{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
									break;}
								case 'L':
								case 'l':
									{cout << "YOU GOT THE WRONG ASNWER! :(" << endl;
									break;}
								case 'R':
								case 'r':
									{cout << "YOU GOT THE WRONG ASNWER! :(" << endl;
									break;}
								case 'A':
								case 'a':
									{cout << "YOU GOT THE WRONG ASNWER! :(" << endl;
									break;}
								case 'C':
								case 'c':
									{cout << "YOU GOT THE WRONG ASNWER! :(" << endl;
									break;}
								}

							break;
						}
					case 'S': //For Sri Lanka capital is Colombo
					case 's':
						{
							cout << "YOU CHOSE SRI LANKA!" << endl;
							cout << "What is the capital of Sri Lanka?" << endl; 
							cout << "Press C for Colombo" << endl;
							cout << "Press A for Badulla" << endl;
							cout << "Press K for Kandy" << endl;
							cout << "Press M for Meho" << endl;
							cout << "Press G for Galle" << endl;
							cin >> city;

							switch (city)
							{
						case 'C':
						case 'c':
							{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
							break;}
						case 'K':
						case 'k':
							{cout << "YOU GOT THE WRONG ANSWER! :(" << endl; 
							break;}
						case 'A':
						case 'a':
							{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
						case 'M':
						case 'm':
							{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
						case 'G':
						case 'g':
							{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
						default:
							{cout << "Wrong Value entered" << endl;
							break;}
							break;
						}

					
					}
				break;	}
				break;}
			

		case 'E':    //for europe
		case 'e':
			   {
				cout << "YOU CHOSE EUROPE!" << endl;
				cout << "Press A for Austria" << endl;
				cout << "Press L for Finland" << endl;
				cout << "Press F for France" << endl;
				cout << "Press G for Germany" << endl;
				cin >> country;
				
				switch (country)
					{
					case 'A': // for austria capital is vienna
					case 'a': // Vienna, Graz, Linz, Salzburg, Innsbruck
						{
							cout << "YOU CHOSE AUSTRIA!" << endl;
							cout << "What is the capital of Austria?" << endl;
							cout << "Press V for Vienna" << endl;
							cout << "Press G for Graz" << endl;
							cout << "Press L for Linz" << endl;
							cout << "Press S for Salzburg" << endl;
							cout << "Press I for Innsbruck" << endl;
							cin >> city;

							switch (city)
							{
							case 'V':
							case 'v':
								{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
								break;}
							case 'G':
							case 'g':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							case 'L':
							case 'l':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							case 'S':
							case 's':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							case 'I':
							case 'i':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							default :
								{cout << "Wrong Value has been entered" << endl;
								break;}
							
							}
			     break;	}
					case 'L': // for finland 
					case 'l': // Helsinki, Forssa, Mikkeli, Lahti, Joensuu
						{
							cout << "YOU CHOSE FINLAND!" << endl;
							cout << "What is the capital of Finland?" << endl;
							cout << "Press H for Helsinki" << endl;
							cout << "Press F for Forssa" << endl;
							cout << "Press M for Mikkeli" << endl;
							cout << "Press L for Lahti" << endl;
							cout << "Press J for Joensuu" << endl;
							cin >> city;

							switch (city)
							{
							case 'H':
							case 'h':
								{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
								break;}
							case 'F':
							case 'f':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							case 'M':
							case 'm':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							case 'L':
							case 'l':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							case 'J':
							case 'j':
								{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
							default:
								{cout << "Wrong Choice Entered" << endl;
								break;}
							
							}
						break;}

					case 'F': //for France
					case 'f': // Bordeaux, Cannes, Limoges, Marseille, Paris
						{
							cout << "YOU CHOSE FRANCE!" << endl;
							cout << "What is the capital of France?" << endl;
							cout << "Press B for Bordeaux " << endl;
							cout << "Press M for Marseille" << endl;
							cout << "Press C for Cannes" << endl;
							cout << "Press L for Limoges" << endl;
							cout << "Press P for Paris" << endl;
							cin >> city;

							switch (city)
							{
								case 'P':
								case 'p':
									{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
							break;}
								case 'B':
								case 'b':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
								case 'C':
								case 'c':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
								case 'L':
								case 'l':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
								case 'M':
								case 'm':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
							break;}
								default:
									{cout << "Wrong Choice Entered" << endl;
							break;}
							
							}
						break;}

					case 'G': //For Germany
					case 'g': //Hamburg, Potsdam, Berlin, Munich, Dresden
						{
							cout << "YOU CHOSE GERMANY!" << endl;
							cout << "What is the Capital of Germany?" << endl;
							cout << "Press H for Hamburg" << endl;
							cout << "Press B for Berlin" << endl;
							cout << "Press M for Munich" << endl;
							cout << "Press D for Dresden" << endl;
							cout << "Press P for Postdam" << endl;
							cin >> city;

							switch (city)
							{
								case 'B':
								case 'b': 
									{cout << "YOU GOT THE RIGHT ANSWER!" << endl;
									break;}
								case 'H':
								case 'h':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
									break;}
								case 'M':
								case 'm':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
									break;}
								case 'D':
								case 'd':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
									break;}
								case 'P':
								case 'p':
									{cout << "YOU GOT THE WRONG ANSWER!" << endl;
									break;}
								default:
									{cout << "Wrong choice entered" << endl;
									break;}



							
							
							}

						break;}

						
					default :
						{
							cout << "Wrong value entered" << endl;
							break;
						}
					break;}

				
				break;	} 

				}


			

		
		}





