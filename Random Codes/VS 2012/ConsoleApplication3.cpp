#include<iostream>

using namespace std;

void main()
{
	char temp;
	cout<<"Press A for Asia OR E for europe : ";
	cin>>temp;

	switch ( temp )
	{
		case 'A':
		{
			cout<<"\nPress P for Pakistan OR I for india OR B for bangladesh OR S for srilanka : ";
			cin>>temp;

			switch ( temp )

			{
				case 'P':
				{ 
					cout<<"\nPress I for Islamabad OR L for Lahore OR K for Karachi OR P for peshawar OR R for rawalpindi :";
					cin>>temp;

					switch( temp )
					{
						case 'I':
							cout<<"\nYes, Islamabad is the capital of Pakistan "<<endl;
							break;
						default:
							cout<<"\nThis is not the capital of Pakistan. "<<endl;
					}
					break;
				}
				case 'I':
				{
					cout<<"\nPress M for Mumbai OR D for Delhi OR B for Bangalore OR H for Hyderabad OR A for Ahmedabad :";
					cin>>temp;
					switch( temp )
					{
						case 'D':
							cout<<"\nYes, Delhi is the capital of India "<<endl;
							break;
						default:
							cout<<"\n This is not the capital of India."<<endl;
					}
					break;
				}
				case 'B':
				{
					cout<<"\nPress D for Dahka OR C for chittagong OR B for Barisal OR K for Khulna OR R for rangpur :";
					cin>>temp;
					switch( temp )
					{
						case 'D':
							cout<<"\nYes, Dhaka is the capital of Bangladesh "<<endl;
							break;
						default:
							cout<<"\nThis is not the capital of Bangladesh. "<<endl;
					}
					break;
				}
				case 'S':
				{
					cout<<"\nPress C for Colombo OR G for Galle OR K for Kandy OR D for dumbulla OR M for Matra :";
					cin>>temp;
					switch( temp )
					{
						case 'C':
							cout<<"\nYes, Colombo is the capital of Srilanka "<<endl;
							break;
						default:
							cout<<"\nThis is not the capital of Srilanka "<<endl;
					}
					break;
				}
			}
			break;
		}

		case 'E':
		{
			cout<<"\nPress A for Australia OR F for Finland OR R for France OR G for Germany : ";
			cin>>temp;

			switch ( temp )

			{
				case 'A':
				{ 
					cout<<"\nPress O for Orange OR S for Sydney OR A for Alburry OR P for perth OR G for Grafton :";
					cin>>temp;

					switch( temp )
					{
						case 'S':
							cout<<"\nYes, Sydney is the capital of Australia "<<endl;
							break;
						default:
							cout<<"\nThis is not the capital of Australia "<<endl;
					}
					break;
				}
				case 'F':
				{
					cout<<"\nPress H for Helsinki OR E for Espoo OR T for Tampere OR V for Vanta OR T for Turku :";
					cin>>temp;
					switch( temp )
					{
						case 'H':
							cout<<"\nYes, Helsinki is the capital of Finland "<<endl;
							break;
						default:
							cout<<"\nThis is not the capital of Finland "<<endl;
					}
					break;
				}
				case 'R':
				{
					cout<<"\nPress P for Paris OR L for Lyon OR N for Nice OR S for Strasbourge OR N for Nantes :";
					cin>>temp;
					switch( temp )
					{
						case 'P':
							cout<<"\nYes, Paris is the capital of France "<<endl;
							break;
						default:
							cout<<"\nThis is not the capital of France "<<endl;
					}
					break;
				}
				case 'G':
				{
					cout<<"\nPress B for Berlin OR S for Sttutgart OR M for Munich OR H for Hamburg OR R for Essen :";
					cin>>temp;
					switch( temp )
					{
						case 'B':
							cout<<"\nYes, Berlin is the capital of Germany "<<endl;
							break;
						default:
							cout<<"\nThis is not the capital of Germany "<<endl;
					}
					break;
				}
			}
		}
	}

}