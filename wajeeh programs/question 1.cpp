#include <iostream>
#include <conio.h>

using namespace std;

int main()
{ 
	char a;
	cout << "*****ASSIGNMENT 5.1*****" << endl;

	cout << "For visitor press V " << endl;
	cout << "For university member press U" << endl;
	cin >> a;

	if ( a == 'U' || a == 'u')
		{
			cout << "YOU ARE A UNIVERSITY MEMBER" << endl;
			cout << "Press S if you are a student" << endl;
			cout << "press F if u are a faculty member" << endl;
			cout << "Press T if you are a staff member" << endl;
			cin >> a;

			if ( a == 'S' || a == 's')
				{
					
					cout << "For male press M" << endl;
					cout << "For female press F" << endl;
					cin >> a;
					if ( a == 'M' || a == 'm')
						{
							cout << "For Graduate press G" << endl;
							cout << "For Masters press M" << endl;
							cin >> a;
							if ( a == 'M' || a == 'm')
								{
									
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;

									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A MALE MASTERS STUDENT OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A MALE MASTERS STUDENT OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A MALE MASTERS STUDENT OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}
								}
							else if ( a == 'G' || a == 'g')
								{
									
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;

									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A MALE GRADUATE STUDENT OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A MALE GRADUATE STUDENT OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A MALE GRADUATE STUDENT OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}
								}
							else 
								{
									cout << "Wrong value entered" << endl;
								}
								 
						}
					else if ( a == 'F' || a == 'f')
						{
							
							cout << "For Graduate press G" << endl;
							cout << "For Masters press M" << endl;
							cin >> a;
							if ( a == 'M' || a == 'm')
								{
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;

									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A FEMALE MASTERS STUDENT OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A FEMALE MASTERS STUDENT OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A FEMALE MASTERS STUDENT OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}
								}
							else if ( a == 'G' || a == 'g')
								{
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;

									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A FEMALE GRADUATE STUDENT OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A FEMALE GRADUATE STUDENT OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A FEMALE GRADUATE STUDENT OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}
								}
							else 
								{
									cout << "Wrong value entered" << endl;
								}
						}
					else 
						{
							cout << "Wrong Value has been entered" << endl;
						}
				}
			else if ( a == 'F' || a == 'f')
				{
					cout << "For Visiting press V" << endl;
					cout << "For Permanent press P" << endl;
					cin >> a;
					if ( a == 'V' || a == 'v')
						{
							cout << "For male press M" << endl;
							cout << "For female press F" << endl;
							cin >> a;
							if ( a == 'M' || a == 'm')
								{
								
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;
									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A MALE VISITING FACULTY MEMBER OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A MALE VISITING FACULTY MEMBER OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A MALE VISITING FACULTY MEMBER OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}

								}
							else if ( a == 'F' || a =='f')
								{
								
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;
									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A FEMALE VISITING FACULTY MEMBER OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A FEMALE VISITING FACULTY MEMBER OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A FEMALE VISITING FACULTY MEMBER OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}
								}
							else 
								{
									cout << "Wrong Value Entered" << endl;
								}
						}
					else if ( a == 'P' || a == 'p')
						{
							cout << "For male press M" << endl;
							cout << "For female press F" << endl;
							cin >> a;
							if ( a == 'M' || a == 'm')
								{
									
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;
									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A MALE PERMANENT FACULTY MEMBER OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A MALE PERMANENT FACULTY MEMBER OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A MALE PERMANENT FACULTY MEMBER OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}

								}
							else if ( a == 'F' || a =='f')
								{
									cout << "For Computer Science press C" << endl;
									cout << "For Electrical press E" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin >> a;
									if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A FEMALE PERMANENT FACULTY MEMBER OF COMPUTER SCIENCE" << endl;
										}
									else if ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A FEMALE PERMANENT FACULTY MEMBER OF ELECTRICAL" << endl;
										}
									else if ( a == 'B' || a == 'b')
										{
											cout << "YOU ARE A FEMALE PERMANENT FACULTY MEMBER OF BUISNESS ADMINISTRATION" << endl;
										}
									else 
										{
											cout << "Wrong value entered" << endl;
										}
								}
							else 
								{
									cout << "Wrong Value Entered" << endl;
								}
						}
					else 
						{
							cout << "Wrong Value entered" << endl;
						}
				}
			else if ( a == 'T' || a == 't')
				{
					cout << "For Maintenance press M" << endl;
					cout << "For Administration press A" << endl;
					cout << "For Academincs press D" << endl;
					cin >> a;
					if ( a == 'D' || a == 'd' )
						{
							
							cout << "For Central press C" << endl;
							cout << "For Department Academics Press A" << endl;
							cin >> a;
							if ( a == 'M' || a == 'm') 
								{
									cout << "YOU ARE A MEMBER OF THE STAFF IN THE CENTRAL ACADEMICS DEPARTMENT" << endl;
								}
							else if ( a == 'A' || a == 'a')
								{
									
									cout << "For Electrical press E" << endl;
									cout << "For Computer Science press C" << endl;
									cout << "For Buisness Administration press B" << endl;
									cin  >> a;
									if  ( a == 'E' || a == 'e')
										{
											cout << "YOU ARE A MEMBER OF THE STAFF IN THE DEPARTMENT OF ELECTRICAL ACADEMICS" << endl;
										}
									else if ( a == 'C' || a == 'c')
										{
											cout << "YOU ARE A MEMBER OF THE STAFF IN THE DEPARTMENT OF COMPUTER SCIECNCE ACADEMICS" << endl;
										}
									else if ( a == 'B' || a == 'b') 
										{
											cout << "YOU ARE A MEMBER OF THE STAFF IN THE DEPARTMENT OF BUISNESS ADMINISTRATION ACEDEMICS" << endl;
										}
									else 
										{
											cout << "Wrong Value entered" << endl;
										}
								}
							else 
								{
									cout << "wrong value entered" << endl;
								}
						}
					else if ( a == 'M' || a == 'm') 
						{
							cout << "YOU ARE A MEMBER OF THE STAFF IN THE MAINTANENCE DEPARTMENT" << endl;
						}
					else if ( a == 'A' || a == 'a')
						{
							cout << "YOU ARE A MEMBER OF THE STAFF IN THE ADMINISTRATION DEPARTMENT" << endl;
						}
					else 
						{
							cout << "Wrong Value entered" << endl;
						}
				}
			else 
				{
					cout << "Wrong Value has been entered" << endl;
				}

		}
	else if ( a == 'V' || a == 'v') 
		{
			cout << "Press M if you are a male visitor" << endl;
			cout << "Press F if you are a female visitor" << endl;
			cin >> a;

			if (a == 'M' || a == 'm')
				{
					cout << "YOU ARE A MALE VISITOR" << endl;
				}
			else if (a == 'F' || a == 'f')
				{
					cout << "YOU ARE A FEMALE VISITOR" << endl;
				}
			else 
				{
					cout << "wrong value entered" << endl;
				}
		}
	else 
		{
			cout << "wrong value entered" << endl;
		}

	_getch();
	return 0;

}