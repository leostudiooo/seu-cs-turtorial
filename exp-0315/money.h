#ifndef MONEY_H_
#define MONEY_H_

#include <iostream>
#include <iomanip>
#include <cmath>

class Money
{
private:
	int yuan, jiao, fen;

public:
	// Conversion (to double)
	operator double() const;

	// Constructor, copy costructor, and destructor
	Money();
	Money(int yuan, int jiao, int fen);
	Money(double amount);
	Money(const Money &other);
	~Money();

	// Reload operators
	Money &operator=(const Money &other);
	Money &operator=(double amount);
	// Plus
	friend Money operator+(const Money &money1, const Money &money2);
	friend Money operator+(const Money &money, double number);
	friend Money operator+(double number, const Money &money);
	// Minus
	friend Money operator-(const Money &money1, const Money &money2);
	friend Money operator-(const Money &money, double number);
	friend Money operator-(double number, const Money &money);
	// Multiplication: number * money or money * number
	friend Money operator*(double number, const Money &money);
	friend Money operator*(const Money &money, double number);
	// Division: money / number
	friend Money operator/(const Money &money, double number);
	// Comparison: eq, ne, lt, le, gt, ge
	friend bool operator==(const Money &money1, const Money &money2);
	friend bool operator!=(const Money &money1, const Money &money2);
	friend bool operator<(const Money &money1, const Money &money2);
	friend bool operator<=(const Money &money1, const Money &money2);
	friend bool operator>(const Money &money1, const Money &money2);
	friend bool operator>=(const Money &money1, const Money &money2);
	// I/O
	friend std::ostream &operator<<(std::ostream &os, const Money &money);
	friend std::istream &operator>>(std::istream &is, Money &money);
};

Money::Money()
{
	yuan = jiao = fen = 0;
}

Money::Money(int yuan, int jiao, int fen)
{
	this->yuan = yuan;
	this->jiao = jiao;
	this->fen = fen;
}

Money::Money(double amount)
{
	int temp = round(amount * 100);
	yuan = temp / 100;
	jiao = (temp - yuan * 100) / 10;
	fen = temp - yuan * 100 - jiao * 10;
}

Money::Money(const Money &other)
{
	yuan = other.yuan;
	jiao = other.jiao;
	fen = other.fen;
}

Money::~Money()
{
}

Money::operator double() const
{
	return yuan + jiao / 10.0 + fen / 100.0;
}

Money &Money::operator=(const Money &other)
{
	yuan = other.yuan;
	jiao = other.jiao;
	fen = other.fen;
	return *this;
}

Money &Money::operator=(double amount)
{
	int temp = round(amount * 100);
	yuan = temp / 100;
	jiao = (temp - yuan * 100) / 10;
	fen = temp - yuan * 100 - jiao * 10;
	return *this;
}

Money operator+(const Money &money1, const Money &money2)
{
	Money result;
	result = double(money1) + double(money2);
	return result;
}

Money operator+(const Money &money, double number)
{
	Money result;
	result = double(money) + number;
	return result;
}

Money operator+(double number, const Money &money)
{
	Money result;
	result = number + double(money);
	return result;
}

Money operator-(const Money &money1, const Money &money2)
{
	Money result;
	result = double(money1) - double(money2);
	return result;
}

Money operator-(const Money &money, double number)
{
	Money result;
	result = double(money) - number;
	return result;
}

Money operator-(double number, const Money &money)
{
	Money result;
	result = number - double(money);
	return result;
}

Money operator*(double number, const Money &money)
{
	Money result;
	result = number * double(money);
	return result;
}

Money operator*(const Money &money, double number)
{
	Money result;
	result = double(money) * number;
	return result;
}

Money operator/(const Money &money, double number)
{
	Money result;
	result = double(money) / number;
	return result;
}

bool operator==(const Money &money1, const Money &money2)
{
	return double(money1) == double(money2);
}

bool operator!=(const Money &money1, const Money &money2)
{
	return double(money1) != double(money2);
}

bool operator<(const Money &money1, const Money &money2)
{
	return double(money1) < double(money2);
}

bool operator<=(const Money &money1, const Money &money2)
{
	return double(money1) <= double(money2);
}

bool operator>(const Money &money1, const Money &money2)
{
	return double(money1) > double(money2);
}

bool operator>=(const Money &money1, const Money &money2)
{
	return double(money1) >= double(money2);
}

std::ostream &operator<<(std::ostream &os, const Money &money)
{
	os << "CNY " << double(money);
	return os;
}

std::istream &operator>>(std::istream &is, Money &money)
{
	std::cout << "(CNY in decimal): ";
	double amount;
	is >> amount;
	money = amount;
	return is;
}

#endif
