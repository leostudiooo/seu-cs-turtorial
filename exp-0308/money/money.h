#ifndef MONEY_H_
#define MONEY_H_

#include <iostream>

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

#endif
