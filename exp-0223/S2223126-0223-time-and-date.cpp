#include <iostream>
#include <iomanip>

using namespace std;

enum Month
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

class Time
{
private:
	int year, day, hour, minute, second;
	Month month;

public:
	// Default set to UNIX epoch
	Time()
	{
		year = 1970;
		month = JANUARY;
		day = 1;
		hour = 0;
		minute = 0;
		second = 0;
	}

	Time(int y, Month m, int d, int h, int min, int s)
	{
		year = y;
		month = m;
		day = d;
		hour = h;
		minute = min;
		second = s;
	}

	void setDateTime(int y, Month m, int d, int h, int min, int s)
	{
		year = y;
		month = m;
		day = d;
		hour = h;
		minute = min;
		second = s;
	}

	void display()
	{
		cout
			<< year << "-"
			<< setw(2) << setfill('0') << month << "-"
			<< setw(2) << setfill('0') << day << " "
			<< setw(2) << setfill('0') << hour << ":"
			<< setw(2) << setfill('0') << minute << ":"
			<< setw(2) << setfill('0') << second
			<< endl;
	}
};

int main()
{
	Time t1;
	t1.display();

	Time t2(2023, FEBRUARY, 13, 8, 0, 0);
	t2.display();

	t2.setDateTime(2024, FEBRUARY, 23, 13, 46, 59);
	t2.display();

	return 0;
}

/*
Output:
1970-01-01 00:00:00
2023-02-13 08:00:00
2024-02-23 13:46:59
*/