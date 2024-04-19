//
//  linkedList_v2.h
//  work
//
//  Created by air on 2024/4/10.
//  Copyright © 2024 air. All rights reserved.
//

#ifndef linkedList_v2_h
#define linkedList_v2_h
#include <iostream>
#include "node.h"
using namespace std;

//带有表头节点的单链表
template<typename T>class Node;
template<typename T>class linkedList{
    Node<T> *head, *tail;
public:
    linkedList();
    ~linkedList();
    void makeEmpty();
    int length()const;
    Node<T>* find(const T& data);       //查找data并返回
    Node<T>* find(int i);               //查找链表中第i个节点（不包含表头节点）
    void insertFront(const T& data);    //将data插在链表头
    void insertRear(const T& data);     //将data插在链表尾
    void insertOrder(const T& data);    //将data有序插入到单链表中
    Node<T>* removeNode(const T& data); //将数据为data的节点从链表中移去
    
    void inverse(); //逆转单链表
    
    linkedList<T>& operator=(linkedList<T>& ls);
    friend ostream& operator<<(ostream& os, const linkedList<T> ls);
};

#endif /* linkedList_v2_h */
