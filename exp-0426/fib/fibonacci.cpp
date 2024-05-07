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
		assert(!(k > 3 && maxFibonacci >= k)); // k must be greater than 3, or the queue cannot calculate a Fibonacci sequence
		for (int i = 0; i < k - 1; i++)
		{
			// set to 0, 0, ..., 1
			enQueue(0);
		}
		overwriteEnQueue(1);
	}

	void overwriteEnQueue(int data)
	{
		if (isFull())
		{
			deQueue();
		}
		enQueue(data);
	}

	// With fib(k, n), where fib(k, n-1) < maxFibonacci <= fib(k, n), generate a Fibonacci sequence, and print the sequence to console
	// f0 = 0,  f1 = 0, ..., fk-2 = 0, fk-1 = 1; fn = fn-1 + fn-2 + … + fn-k , n = k , k + 1, ...
	void generateFibonacciAndPrint()
	{
		int sum = 0;
		for (int i = 0; i < maxFibonacci; i++)
		{
			// sum = f0 + f1 + ... + fk-1
			sum = 0;
			for (int j = 0; j < k; j++)
			{
				sum += readQueue(j);
			}
			overwriteEnQueue(sum);
			cout << sum << " ";
		}
		cout << endl;
	}
};

int main()
{
	Fibonacci fib(3, 20);
	fib.generateFibonacciAndPrint();
	return 0;
}

/*
Output:
1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 10609 19513 35890 66012 121415 
*/