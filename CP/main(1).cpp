#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
using namespace std;
const int capacity_of_airplane = 3;
class Time 
{
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int , int , int);
	void set_value(int, int , int);
	void display_time();
};

class reservation
{
	char *name;
	int id;
	Time departure_of_flight;
	Time reservation_time;
	static int seat;
	int flight_no;
public:
	reservation();
	reservation(char *,int,Time,Time,int);
	bool check_seat();
	void display();
	void set_value1(char *, int,Time,Time,int); 
	static int get_seat_no();
	~reservation();
};

int reservation::seat = 0; //intialize static object

void main()
{	
	reservation calling;
	reservation call;
	//char name[30];
	int flight_no=368,hour=14,minute=0,second=0,hour1=11,minute1=10,second1=50;
	Time departure_time;
	Time reservation_time;
	int choice;
	do 
	{
	cout << "Welcome to Airplane Passenger Reservation System\n"
		 << "\tPress 1 To Reserve a Seat\n\tPress 2 to display the details of all passengers\n\tPress 3 to quit from system\n\n";
	cin  >> choice;
	cout << endl;
	system("cls");
	switch (choice)
	{
	case 1:	
		char name[30];
		int id;
		departure_time.set_value(hour,minute,second);
		reservation_time.set_value(hour1,minute1,second1);
		cout << "You have selected to reserve a seat\n";
		cout << "Please Enter the name of a passenger\n";
		cin.ignore();
		cin.getline(name,30,'\n');
		cout << "Please enter you id no\n";
		cin  >> id;
		cout << endl;
		calling.set_value1(name,id,departure_time,reservation_time,flight_no);
		break;
	case 2:
		
		cout << "You have selected to display the passenger list\n";
		call.display();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "Wrong value entered\n";
	}

	}while(1);

	getch();
}

//---------------------------------------Definition---------------------
Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}
Time::Time(int hr, int min, int sec)
{
	hour = (hr>0 && hr<24)?hr:0;
	minute  = (min>0 && min<60)?min:0;
	second  = (sec>0 && min<60)?sec:0;
}
void Time::set_value(int hr, int min, int sec)
{
	hour = (hr>0 && hr<24)?hr:0;
	minute  = (min>0 && min<60)?min:0;
	second  = (sec>0 && min<60)?sec:0;
}
reservation::reservation()
{
	name = NULL;
	id = 0;
	flight_no = 0;
	departure_of_flight;
	reservation_time;
	seat = 0;
	//++seat;
}
reservation::reservation(char *name1, int id1, Time departure, Time reservation1, int no)
{
	if (check_seat() == true)
	{
		name = new char [strlen(name1) + 1];
		strcpy(name,name1);
		id = id1;
		departure_of_flight = departure;
		reservation_time = reservation1;
		flight_no = no;
		++seat;
	}
	else
		cout << "Sorry,You cannot do reservation as the plane is full\n";
}
int reservation::get_seat_no()
{
	return seat;
}
void reservation::set_value1(char *name1, int id1, Time departure, Time reservation1, int no)
{
	name = new char [strlen(name1) + 1];
	strcpy(name,name1);
	id = id1;
	departure_of_flight = departure;
	reservation_time = reservation1;
	flight_no = no;
	++seat;
}
reservation::~reservation()
{
	delete name;
}
bool reservation::check_seat()
{
	if (seat <= capacity_of_airplane)
	{
		return true;
	}
	else
		return false;
}
void reservation::display()
{
	cout << "DETAILS OF PASSENGER \n";
	for (int i=0; i<seat; i++)
	{
		cout << "The detail of passenger is " << i+1 << endl;
		cout << "YOur seat no is " << seat << endl;
		cout << "The name of passenger " << i+1 << "is" <<setw(4) << name[i] << endl;
		cout << "The ID of passenger " << i+1 << "is" <<setw(4) << id << endl;
		cout << "The TIme of departure of flight is " << i+1 << "is" <<setw(4);
		departure_of_flight.display_time();
		cout << endl;
		cout << "The time of reservation is " << i+1 << "is" <<setw(4);
		reservation_time.display_time();
		cout << endl;
		cout << "The flight no is " << setw(4) << flight_no << endl;
	}
}
void Time::display_time()
{
	cout << ((hour == 0 || hour == 24)?24:hour%24) << ":" << ((minute<10)?"0":"") << minute << ":" << ((second <10)?"0":"") << second << endl;
}