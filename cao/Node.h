#pragma once
template <typename T>
class linkedList;
template <typename T>
class Node
{
	T info;
	Node<T> *link;

public:
	Node();
	Node(const T data);
	void Insert(const T &data);
	Node<T> *Remove();
	friend class linkedList<T>;
};

template <typename T>
Node<T>::Node()
{
	link = nullptr;
}

template <typename T>
Node<T>::Node(const T data)
{
	info = data;
	link = nullptr;
}

template <typename T>
void Node<T>::Insert(const T &data)
{
	Node<T> *temp = new Node<T>;
	temp->info = data;
	temp->link = link;
	link = temp;
}

template <typename T>
Node<T> *Node<T>::Remove()
{
	Node<T> *temp = link;
	link = temp->link;
	return temp;
}