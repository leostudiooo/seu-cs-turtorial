#pragma once // my_queue.h
#include <cassert>

template <typename T>
class MyQueue
{
	int front, rear, maxSize;
	T* elements;

public:
	MyQueue(int size)
	{
		maxSize = size;
		elements = new T[maxSize];
		front = rear = 0;
		assert(elements != nullptr);
	}
	
	~MyQueue()
	{
		delete[] elements;
	}

	bool isEmpty() const
	{
		return front == rear;
	}

	bool isFull() const
	{
		return (rear + 1) % maxSize == front;
	}

	int getLength() const
	{
		return (rear - front + maxSize) % maxSize;
	}

	void enQueue(const T& data)
	{
		assert(!isFull());
		elements[rear] = data;
		rear = (rear + 1) % maxSize;
	}

	T deQueue()
	{
		assert(!isEmpty());
		T data = elements[front];
		front = (front + 1) % maxSize;
		return data;
	}
};