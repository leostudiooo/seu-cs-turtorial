#pragma once // time.h

#include <iostream>

using namespace std;

class Time
{
	int hour, minute, second;
public:
	Time();
	Time(int, int, int);
	Time(int);
	Time(Time &);

	int to_seconds();
	
	friend istream& operator>>(istream &, Time &);
	friend ostream& operator<<(ostream &, Time &);

	bool operator<(Time &t) { return to_seconds() < t.to_seconds(); }
	bool operator>(Time &t) { return to_seconds() > t.to_seconds(); }
	bool operator==(Time &t) { return to_seconds() == t.to_seconds(); }
	bool operator!=(Time &t) { return to_seconds() != t.to_seconds(); }
};

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

Time::Time(int s)
{
	hour = s / 3600;
	minute = (s % 3600) / 60;
	second = s % 60;
}

Time::Time(Time &t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
}

int Time::to_seconds()
{
	return hour * 3600 + minute * 60 + second;
}

istream& operator>>(istream &is, Time &t)
{
	is >> t.hour >> t.minute >> t.second;
	return is;
}

ostream& operator<<(ostream &os, Time &t)
{
	os << t.hour << ":" << t.minute << ":" << t.second;
	return os;
}