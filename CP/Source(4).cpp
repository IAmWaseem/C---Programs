#include <iostream>

using namespace std;

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
		SeatReservation(int, char *, Time, Time, int, int);
	   ~SeatReservation();
	private:
		int ID;
		char *Name;
		Time DepartureTime;
		Time SeatReservationTime;
		int TrainID;
		int SeatNumber;
		static int NumberOfSeats;
};

int SeatReservation::NumberOfSeats = 0;

SeatReservation::SeatReservation() {
	
}

SeatReservation::SeatReservation(int id, char *n, Time D, Time S, int Tid, int seatno) {
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

SeatReservation::~SeatReservation() {
	delete[] Name;
}

int main() {
	
	return 0;
}