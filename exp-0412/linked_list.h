#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "node.h"

template <typename T>
class LinkedList
{
	Node<T> *head, *tail;
public:
	LinkedList();
	~LinkedList();
	
	// 使链表为空
	void makeEmpty();
	
	// 返回链表长度
	int length() const;
	
	// 查找 T 类型的 data 并返回节点
	Node<T>* find(const T& data);
	// 查找索引为 i 的节点
	Node<T>* find(int i);
	
	// 将 data 插入到链表头
	void insertFront(const T& data);
	// 将 data 插入到链表尾
	void insertRear(const T& data);
	// 将 data 有序插入到单链表中
	void insertOrder(const T& data);

	// 移除数据为 data 的节点，并返回该节点
	Node<T>* removeNode(const T& data);

	// 逆转单链表
	void inverse();

	LinkedList<T>& operator=(LinkedList<T>& ls);

	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& ls);
};

template <typename T>
LinkedList<T>::LinkedList()
{
	head = tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	makeEmpty();
}

template <typename T>
void LinkedList<T>::makeEmpty()
{
	Node<T> *p;
	while (head != nullptr)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

template <typename T>
int LinkedList<T>::length() const
{
	Node<T> *p = head;
	int len = 0;
	while (p != nullptr)
	{
		len++;
		p = p->next;
	}
	return len;
}

template <typename T>
Node<T>* LinkedList<T>::find(const T& data)
{
	Node<T> *p = head;
	while (p != nullptr && p->data != data)
		p = p->next;
	return p;
}

template <typename T>
Node<T>* LinkedList<T>::find(int i)
{
	Node<T> *p = head;
	int j = 0;
	while (p != nullptr && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

template <typename T>
void LinkedList<T>::insertFront(const T& data)
{
	head = new Node<T>(data, head);
	if (tail == nullptr)
		tail = head;
}

template <typename T>
void LinkedList<T>::insertRear(const T& data)
{
	if (tail == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		tail->next = new Node<T>(data);
		tail = tail->next;
	}
}

template <typename T>
void LinkedList<T>::insertOrder(const T& data)
{
	Node<T> *p = head, *q = nullptr;
	while (p != nullptr && p->data < data)
	{
		q = p;
		p = p->next;
	}
	if (q == nullptr)
	{
		head = new Node<T>(data, head);
		if (tail == nullptr)
			tail = head;
	}
	else
	{
		q->next = new Node<T>(data, p);
		if (p == nullptr)
			tail = q->next;
	}
}

template <typename T>
Node<T>* LinkedList<T>::removeNode(const T& data)
{
	Node<T> *p = head, *q = nullptr;
	while (p != nullptr && p->data != data)
	{
		q = p;
		p = p->next;
	}
	if (p == nullptr)
		return nullptr;
	if (q == nullptr)
		head = p->next;
	else
		q->next = p->next;
	if (p == tail)
		tail = q;
	return p;
}

template <typename T>
void LinkedList<T>::inverse()
{
	Node<T> *p = head, *q = nullptr, *r = nullptr;
	while (p != nullptr)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	tail = head;
	head = q;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& ls)
{
	if (this == &ls)
		return *this;
	makeEmpty();
	Node<T> *p = ls.head;
	while (p != nullptr)
	{
		insertRear(p->data);
		p = p->next;
	}
	return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ls)
{
	Node<T> *p = ls.head;
	while (p != nullptr)
	{
		os << p->data << " ";
		p = p->next;
	}
	return os;
}

#endif // _LINKED_LIST_H