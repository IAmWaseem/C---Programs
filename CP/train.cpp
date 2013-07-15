#include<iostream>
#include<string>
using namespace std;
static int a=1;

class time
{
	int hours,minutes,seconds;
public:
	time()
	{
		hours=0;
		minutes=0;
		seconds=0;
	}
	~time()
	{
		cout<<"deleted";
	}
	void setter();
	void display();
};


class seat_reservation
{
	int pid;
	string passenger_name;
	time time_departure;
	time time_seat_reservation;
	int seat_no;
	int train_id;;

public:
	seat_reservation()
	{
	}
	void input();
	void seatcheck();
	void display();
};

void seat_reservation::input()
{
	cout<<"Enter passenger's id: ";
	cin>>pid;
	cout<<"Enter passenger's name: ";
	fflush(stdin);
	getline(cin,passenger_name);
	cout<<"Enter seat number: ";
	cin>>seat_no;
	cout<<"Enter train id: ";
	cin>>train_id;
	cout << "Enter time of reservation" << endl;
	time_seat_reservation.setter();
	cout << "Enter time of departure" << endl;
	time_departure.setter();
}
void time::display()
{
	cout<<"Hours: "<<hours<<endl;
	cout<<"Minutes: "<<minutes<<endl;
	cout<<"Seconds: "<<seconds<<endl;
}


void time::setter()
{
	cout<<"Enter hours: " ;
	cin>>hours;

	if(hours>12 || hours<1)
	{
		cout<<"Wrong value\n";
	}
	cout<<"Enter minutes: ";
	cin>>minutes;


	if(minutes>60 || minutes<1)
	{
		cout<<"Wrong value \n";
	}


	cout<<"Enter seconds: ";
	cin>>seconds;


	if( seconds<0 || seconds>60)
	{
		cout<<"Wrong value entered \n";
	}
}

void  seat_reservation::seatcheck()
{

	if(a==10)
	{
		exit(0);
	}
	a++;

}

void seat_reservation::display()
{
	cout<<"Passenger's id : " << pid<< endl;
	cout<<"Passenger's name: "<<passenger_name<<endl;
	cout<<"Seat number: "<< seat_no <<endl;
	cout<<"Time of seat reservation ";
	time_seat_reservation.display();
	cout<<"Time of departure: ";
	time_seat_reservation.display();
}

int main()
{
	seat_reservation obj;
	obj.input();
	obj.display();

}