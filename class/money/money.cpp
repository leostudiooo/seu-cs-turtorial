#include "money.h"

Money::Money()
{
	yuan = 0;
	jiao = 0;
	fen = 0;
}

Money::Money(int yuan, int jiao, int fen)
{
	this->yuan = yuan;
	this->jiao = jiao;
	this->fen = fen;
}

std::ostream &operator<<(std::ostream &os, const Money &money)
{
	os << money.yuan << "." << money.jiao << money.fen;
	return os;
}

std::istream &operator>>(std::istream &is, Money &money)
{
	is >> money.yuan >> money.jiao >> money.fen;
	return is;
}

Money operator+(const Money &money1, const Money &money2)
{
	Money result;
	result.yuan = money1.yuan + money2.yuan;
	result.jiao = money1.jiao + money2.jiao;
	result.fen = money1.fen + money2.fen;
	if (result.fen >= 10)
	{
		result.jiao += result.fen / 10;
		result.fen %= 10;
	}
	if (result.jiao >= 10)
	{
		result.yuan += result.jiao / 10;
		result.jiao %= 10;
	}
	return result;
}

Money Money::operator+=(const Money &money)
{
	yuan += money.yuan;
	jiao += money.jiao;
	fen += money.fen;
	if (fen >= 10)
	{
		jiao += fen / 10;
		fen %= 10;
	}
	if (jiao >= 10)
	{
		yuan += jiao / 10;
		jiao %= 10;
	}
	return *this;
}

Money Money::operator=(const Money &money)
{
	yuan = money.yuan;
	jiao = money.jiao;
	fen = money.fen;
	return *this;
}