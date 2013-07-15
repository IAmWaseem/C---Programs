#include<iostream>
#include<conio.h>
using namespace std;
class time 
{
private:
	int sec,min,hour;
public:
	time();
	time(int,int,int);
	void display();
	~time();
};
time::time()
{
	hour=0;
	min=0;
	sec=0;
}
time::time(int h, int m, int s)
{
	hour=( h>=0 && h<24 ) ? h : 0;
	min=( m>=0 && m<60 ) ? m : 0;
	sec=( s>=0 && s<60 ) ? s : 0;
}
void time::display()
{
	cout<<"\nTIME:";
	cout<<hour<<":"<<min<<":"<<sec;
}
class seat_reservation
{
	int pid;
	char *pname;
	time departure,seat_reserve;
	int train_id;
	int seat_no;
	static int count;
public:
	seat_reservation();
	seat_reservation(int a,int b,int c,char *d,int h,int m, int s,int h1,int m1,int s1);
	void checkseats();
};
int seat_reservation::count=0;
seat_reservation::seat_reservation(int a,int b,int c,char *d,int h,int m, int s,int h1,int m1,int s1) : seat_reserve(h,m,s),departure(h1,m1,s1)
	{
		pid=a;
		train_id=b;
		seat_no=c;
		pname=d;
		count++;
	}
void seat_reservation::checkseats()
{
	if(count<=10)
	{
		return;
	}
	else
	{
		cout<<"All seats are reserved ."<<endl;
	}
}

int main() {
	char *Name = new char[30];
	int id, tid, seatno;
	cout << "Enter Name : ";
	fflush(stdin);
	cin.getline(Name,30);
	cout << "Enter Passenger ID : ";
	cin >> id;
	cout << "Enter Train ID : ";
	cin >> tid;
	cout << "Enter Seat Number : ";
	cin >> seatno;
	int h1,h2,m1,m2,s1,s2;
	cout << "Enter Time of Departure" << endl << endl;
	cout << "Enter Seconds : ";
	cin >> s1;
	cout << "Enter Minutes : ";
	cin >> m1;
	cout << "Enter Hours : ";
	cin >> h1;
	cout << "Enter Time of Reservation" << endl << endl;
	cout << "Enter Seconds : ";
	cin >> s2;
	cout << "Enter Minutes : ";
	cin >> m2;
	cout << "Enter Hours : ";
	cin >> h2;
	seat_reservation Person(id,tid,seatno,Name,h1,m1,s1,h2,m2,s2);
	return 0;
}
