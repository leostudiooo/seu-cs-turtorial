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
};

#endif
