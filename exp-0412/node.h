#ifndef _NODE_H
#define _NODE_H

#include <iostream>

template <typename T>
class Node
{
public:
	T data;
	Node<T> *next;
	
	Node() { next = nullptr; }
	Node(const T& data) { this->data = data; next = nullptr; }
	Node(const T& data, Node<T> *next) { this->data = data; this->next = next; }
	~Node() { next = nullptr; }
	
	T getData() const;
	Node<T>* getNext() const;
	
	void setData(const T& data);
	void setNext(Node<T> *next);

	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const Node<U>& node);
};

#endif // _NODE_H