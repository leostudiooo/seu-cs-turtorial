#include "money.h"
#include <iomanip>
#include <cmath>

Money::Money()
{
	std::cout << "Default constructor called" << std::endl;
	yuan = jiao = fen = 0;
}

Money::Money(int yuan, int jiao, int fen)
{
	std::cout << "Constructor yuan, jiao, fen called" << std::endl;
	this->yuan = yuan;
	this->jiao = jiao;
	this->fen = fen;
}

Money::Money(double amount)
{
	std::cout << "Constructor double called" << std::endl;
	int temp = round(amount * 100);
	yuan = temp / 100;
	jiao = (temp - yuan * 100) / 10;
	fen = temp - yuan * 100 - jiao * 10;
}

Money::Money(const Money &other)
{
	std::cout << "Copy constructor called" << std::endl;
	yuan = other.yuan;
	jiao = other.jiao;
	fen = other.fen;
}

Money::~Money()
{
	std::cout << "Destructor called" << std::endl;
}

Money::operator double() const
{
	std::cout << "Operator double called" << std::endl;
	return yuan + jiao / 10.0 + fen / 100.0;
}

Money &Money::operator=(const Money &other)
{
	std::cout << "Operator = called" << std::endl;
	yuan = other.yuan;
	jiao = other.jiao;
	fen = other.fen;
	return *this;
}

Money &Money::operator=(double amount)
{
	std::cout << "Operator = double called" << std::endl;
	int temp = round(amount * 100);
	yuan = temp / 100;
	jiao = (temp - yuan * 100) / 10;
	fen = temp - yuan * 100 - jiao * 10;
	return *this;
}

Money operator+(const Money &money1, const Money &money2)
{
	std::cout << "Operator + called" << std::endl;
	Money result;
	result = double(money1) + double(money2);
	return result;
}

Money operator+(const Money &money, double number)
{
	std::cout << "Operator + double called" << std::endl;
	Money result;
	result = double(money) + number;
	return result;
}

Money operator+(double number, const Money &money)
{
	std::cout << "Operator double + called" << std::endl;
	Money result;
	result = number + double(money);
	return result;
}

Money operator-(const Money &money1, const Money &money2)
{
	std::cout << "Operator - called" << std::endl;
	Money result;
	result = double(money1) - double(money2);
	return result;
}

Money operator-(const Money &money, double number)
{
	std::cout << "Operator - double called" << std::endl;
	Money result;
	result = double(money) - number;
	return result;
}

Money operator-(double number, const Money &money)
{
	std::cout << "Operator double - called" << std::endl;
	Money result;
	result = number - double(money);
	return result;
}

Money operator*(double number, const Money &money)
{
	std::cout << "Operator double * called" << std::endl;
	Money result;
	result = number * double(money);
	return result;
}

Money operator*(const Money &money, double number)
{
	std::cout << "Operator * double called" << std::endl;
	Money result;
	result = double(money) * number;
	return result;
}

Money operator/(const Money &money, double number)
{
	std::cout << "Operator / double called" << std::endl;
	Money result;
	result = double(money) / number;
	return result;
}

bool operator==(const Money &money1, const Money &money2)
{
	std::cout << "Operator == called" << std::endl;
	return double(money1) == double(money2);
}

bool operator!=(const Money &money1, const Money &money2)
{
	std::cout << "Operator != called" << std::endl;
	return double(money1) != double(money2);
}

bool operator<(const Money &money1, const Money &money2)
{
	std::cout << "Operator < called" << std::endl;
	return double(money1) < double(money2);
}

bool operator<=(const Money &money1, const Money &money2)
{
	std::cout << "Operator <= called" << std::endl;
	return double(money1) <= double(money2);
}

bool operator>(const Money &money1, const Money &money2)
{
	std::cout << "Operator > called" << std::endl;
	return double(money1) > double(money2);
}

bool operator>=(const Money &money1, const Money &money2)
{
	std::cout << "Operator >= called" << std::endl;
	return double(money1) >= double(money2);
}

std::ostream &operator<<(std::ostream &os, const Money &money)
{
	os << "CNY" << double(money);
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