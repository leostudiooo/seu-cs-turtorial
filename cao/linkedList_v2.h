
//  linkedList_v2.h
//  work
//
//  Created by air on 2024/4/10.
//  Copyright © 2024 air. All rights reserved.
//

#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <typename T>
class linkedList
{
	Node<T> *head, *tail;

public:
	linkedList();
	// void creat();
	~linkedList();
	void makeEmpty();
	int length() const;
	Node<T> *find(const T &data);		// 查找data并返回
	Node<T> *find(int i);				// 查找链表中第i个节点（不包含表头节点）
	void insertFront(const T &data);	// 将data插在链表头
	void insertRear(const T &data);		// 将data插在链表尾
	void insertOrder(const T &data);	// 将data有序插入到单链表中
	Node<T> *removeNode(const T &data); // 将数据为data的节点从链表中移去

	void inverse(); // 逆转单链表

	linkedList<T> &operator=(linkedList<T> &ls);
	//	friend ostream& operator<<(ostream& os, const linkedList<T> ls);
};

template <typename T>
linkedList<T>::linkedList()
{
	head = tail = new Node<T>;
}
/*template<typename T>
void linkedList<T>::creat() {
	T data;
	cin >> data;
	Node<T>* p = new Node<T>;
	p = head->link;
	p->info = data;
	while (cin >> data) {
		Node<T>* temp = new Node<T>;
		temp->info = data;
		p->link = temp;
		p = p->link;
	}
	tail = p;
}*/
template <typename T>
linkedList<T>::~linkedList()
{
	makeEmpty();
	delete head;
}
template <typename T>
void linkedList<T>::makeEmpty()
{
	Node<T> *p;
	while (head->link != nullptr)
	{
		p = head->link;
		head->link = p->link;
		delete p;
	}
	tail = head;
}
template <typename T>
int linkedList<T>::length() const
{
	Node<T> *p = head->link;
	int count = 0;
	while (p != nullptr)
	{
		count++;
		p = p->link;
	}
	return count;
}
template <typename T> // 查找data并返回
Node<T> *linkedList<T>::find(const T &data)
{
	Node<T> *p = head->link;
	while (p != nullptr && p->info != data)
	{
		p = p->link;
	}
	return p;
}
template <typename T>
Node<T> *linkedList<T>::find(int i)
{
	int count = 1;
	Node<T> *p = head->link;
	for (count; count < i; count++)
	{
		p = p->link;
	}
	return p;
}
template <typename T> // 将data插在链表头
void linkedList<T>::insertFront(const T &data)
{
	Node<T> *temp = new Node<T>;
	temp->info = data;
	temp->link = head->link;
	head->link = temp;
	if (tail == head)
		tail = temp;
}
template <typename T> // 将data插在链表尾
void linkedList<T>::insertRear(const T &data)
{
	Node<T> *temp = new Node<T>;
	temp->info = data;
	tail->link = temp;
	tail = temp;
	temp->link = nullptr;
}
template <typename T> // 将data有序插入到单链表中
void linkedList<T>::insertOrder(const T &data)
{
	Node<T> *p = new Node<T>;
	Node<T> *q = new Node<T>; // p的上一个节点
	p = head->link;
	while ((p != nullptr) && (data > p->info))
	{
		q = p;
		p = p->link;
	}
	p.Insert(q, data);
}
template <typename T>
// 将数据为data的节点从链表中移去
Node<T> *linkedList<T>::removeNode(const T &data)
{
	Node<T> *p = head;
	if (head == tail)
		return nullptr;
	while (p->link != nullptr && (p->link)->info != data)
	{
		p = p->link;
	}
	return p->Remove();
}
template <typename T>
// 逆转单链表
void linkedList<T>::inverse()
{
	Node<T> *p = head->link;
	Node<T> *q = p->link;
	Node<T> *r = q->link;
	while (r != nullptr)
	{ // p q r
		q->link = p;
		p = q;
		q = r;
		r = r->link;
	}
	tail = head->link;
	tail->link = nullptr;
	head->link = q;
}
template <typename T>
linkedList<T> &linkedList<T>::operator=(linkedList<T> &ls)
{
	Node<T> *p = head->link;
	Node<T> *q = ls.head->link;
	while (q != nullptr)
	{
		p->info = q->info;
		p = p->link;
		q = q->link;
	}
}
template <typename T>
ostream &operator<<(ostream &os, const linkedList<T> ls)
{
	Node<T> *p = ls.head->link;
	while (p != nullptr)
	{
		os << p->info << ' ';
		p = p->link;
	}
	os << endl;
	return os;
}