#include <iostream>

using namespace std;

void RegisterSeat(SeatReservation **&);

class Time {
	public:
		Time();
		Time(int, int, int);
	int GetSecond();
	int GetMinute();
	int GetHour();
   void SetSecond(int);
   void SetMinute(int);
   void SetHour(int);
   void operator=(const Time);
	   ~Time();
	private:
		int Second;
		int Minute;
		int Hour;
};

Time::Time() {
	Second = Minute = Hour = 0;
}

Time::Time(int S, int M, int H) {
	Second = (S > 59 ? 0 : S);
	Minute = (M > 59 ? 0 : M);
	Hour   = (H > 24 ? 0 : H);
}

int Time::GetSecond() {
	return Second;
}

int Time::GetMinute() {
	return Minute;
}

int Time::GetHour() {
	return Hour;
}

void Time::SetSecond(int S) {
	Second = S;
}

void Time::SetMinute(int M) {
	Minute = M;
}

void Time::SetHour(int H) {
	Hour = H;
}

void Time::operator=(const Time T) {
	Second = T.Second; Minute = T.Minute; Hour = T.Hour;
}

Time::~Time() {
	
}

class SeatReservation {
	public:
		SeatReservation();
		void RegisterSeat(int, char *, Time, Time, int, int);
		static void SetMaxSeats(int);
		static int GetSeats();
	   ~SeatReservation();
	private:
		int ID;
		char *Name;
		Time DepartureTime;
		Time SeatReservationTime;
		int TrainID;
		int SeatNumber;
		static int NumberOfSeats;
		static int MaxSeats;
};

int SeatReservation::NumberOfSeats = 0;

SeatReservation::SeatReservation() {
	
}

void SeatReservation::RegisterSeat(int id, char *n, Time D, Time S, int Tid, int seatno) {
	ID = id;
	int size;
	for(size = 0; n[size] != NULL; size++);
	size++;
	Name = new char[size];
	strcpy(Name, n);
	DepartureTime = D;
	SeatReservationTime = S;
	TrainID = Tid;
	SeatNumber = seatno;
	NumberOfSeats++;
}

void SeatReservation::SetMaxSeats(int Seats) {
	NumberOfSeats = Seats;
}

int SeatReservation::GetSeats() {
	return NumberOfSeats;
}

SeatReservation::~SeatReservation() {
	delete[] Name;
}

int main() {
	int Size;
	cout << "How many Number of Seats you want : ";
	cin >> Size;
	SeatReservation **Persons;
	*Persons = new SeatReservation[Size];
	SeatReservation::SetMaxSeats(Size);
MENU:
	system("cls");
	int Choice;
	cout << "MAIN MENU" << endl << endl;
	cout << "[1] Register Seat" << endl;
	cout << "[2] Display Seats" << endl;
	cout << "[3] Exit the Application" << endl << endl;
	cout << "Enter Choice[1-3]: ";
	cin >> Choice;
	switch(Choice) {
		case 1:
			RegisterSeat(Persons);
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
	}
	return 0;
}

void RegisterSeat(SeatReservation **&Persons) {
	Time dTime, sTime;
	int temp;
	cout << "Enter Passenger ID : ";

}
