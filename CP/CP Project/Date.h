#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
	friend std::ostream& operator<<(std::ostream& out, const Date& obj);
	friend std::istream& operator>>(std::istream& in, Date& obj);
	public:
		Date();
		Date(int d, int m, int y);
		Date& operator=(Date& obj);
		void CurrentDate();
		int GetDay();
		int GetMonth();
		int GetYear();
		void SetDay(int d);
		void SetMonth(int m);
		void SetYear(int y);
	private:
		int Day;
		int Month;
		int Year;
};

#endif
