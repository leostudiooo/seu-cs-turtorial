#ifndef MONEY_H_
#define MONEY_H_

#include <iostream>

class Money
{
private:
	int yuan, jiao, fen;

public:
	Money();
	Money(int yuan, int jiao, int fen);
	friend std::ostream &operator<<(std::ostream &os, const Money &money);
	friend std::istream &operator>>(std::istream &is, Money &money);
	friend Money operator+(const Money &money1, const Money &money2);
	Money operator+=(const Money &money);
	Money operator=(const Money &money);
};

#endif
