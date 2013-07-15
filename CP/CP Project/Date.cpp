#include "Date.h"
#include <ctime>

Date::Date() {
	Day = Month = Year = 0;
	return;
}

Date::Date(int d, int m, int y) {
	Day = d;
	Month = m;
	Year = y;
	return;
}

Date& Date::operator=(Date& obj) {
	Day = obj.Day;
	Month = obj.Month;
	Year = obj.Year;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Date& obj) {
	out << obj.Day << " - " << obj.Month << " - " << obj.Year;
	return out;
}

std::istream& operator>>(std::istream& in, Date& obj) {
	std::cout << "Enter Day : ";
	in >> obj.Day;
	std::cout << "Enter Month : ";
	in >> obj.Month;
	std::cout << "Enter Year : ";
	in >> obj.Year;
	return in;
}

void Date::CurrentDate() {
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	Day = t -> tm_mday;
	Month = t -> tm_mon + 1;
	Year = t -> tm_year + 1900;
}

int Date::GetDay() {
	return Day;
}

int Date::GetMonth() {
	return Month;
}

int Date::GetYear() {
	return Year;
}

void Date::SetDay(int d) {
	Day = d;
}

void Date::SetMonth(int m) {
	Month = m;
}

void Date::SetYear(int y) {
	Year = y;
}