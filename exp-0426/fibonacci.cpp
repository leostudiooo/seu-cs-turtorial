#include "my_queue.h"
#include <iostream>

using namespace std;

// class Fibonacci to inherit MyQueue<int>
class Fibonacci: public MyQueue<int>
{
	int k, maxFibonacci;

public:
	Fibonacci(int k, int maxFib): MyQueue<int>(k), k(k), maxFibonacci(maxFib)
	{
		assert(k > 3); // k must be greater than 3, or the queue cannot calculate a Fibonacci sequence
		for (int i = 0; i < k - 1; i++)
		{
			// set to 0, 0, ..., 1
			enQueue(0);
		}
		enQueue(1);
	}

	void overwriteEnQueue(int data)
	{
		if (isFull())
		{
			deQueue();
		}
		enQueue(data);
	}

	// With fib(k, n), where fib(k, n-1) < maxFibonacci <= fib(k, n), generate a Fibonacci sequence, and print to console
	//
	void generateFibonacciAndPrint()
	{
		int n = k;

	}
};