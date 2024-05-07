// Example 3: the four color theorem

#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
	int top;	 // 栈顶指针(下标)
	T *elements; // 动态建立的数值
	int maxSize; // 栈最大能容纳的元素个数

public:
	Stack(int = 20); // 栈的默认大小为 20 个元素
	~Stack()
	{
		delete[] elements;
	}
	void Push(const T &data); // 压栈
	T Pop();				  // 出栈, top 减 1
	T GetElem(int i);		  // 取数据, top 不变
	void StackFull();		  // 堆栈加倍
	void MakeEmpty()
	{
		top = -1;
	} // 清空栈
	bool IsEmpty() const
	{
		return top == -1;
	} // 判栈空
	bool IsFull() const
	{
		return top == maxSize - 1;
	}				   // 判栈满
	void PrintStack(); // 输出栈内所有数据
};

template <typename T>
Stack<T>::Stack(int maxs)
{
	maxSize = maxs;			   // 栈的最大容量
	top = -1;				   // 栈顶指针
	elements = new T[maxSize]; // 建立栈空间
	assert(elements != 0);	   // 分配不成功, 结束程序
}

// 输出栈内所有数据
template <typename T>
void Stack<T>::PrintStack()
{
	for (int i = 0; i <= top; i++)
		cout << elements[i] << '\t';
	cout << endl;
}

// push
template <typename T>
void Stack<T>::Push(const T &data)
{
	if (IsFull())
	{
		cout << "栈满" << endl;
		StackFull(); // 栈满则堆栈加倍
	}
	elements[++top] = data; // 栈顶指针先加 1, 元素再进栈, top指向栈顶元素
}

// pop, top -= 1
template <typename T>
T Stack<T>::Pop()
{
	assert(!IsEmpty());		// 栈已空则不能退栈,退出程序
	return elements[top--]; // 返回栈顶元素,同时栈顶指针减 1
}

// 读取数据, top 不变
template <typename T>
T Stack<T>::GetElem(int i)
{
	assert(i <= top && i >= 0); // 超出栈的有效数据范围, 退出程序
	return elements[i];			// 返回栈顶元素, top 不变
}

template <typename T>
void Stack<T>::StackFull()
{ // 堆栈加倍
	T *el = elements;
	int i = maxSize, j;
	maxSize *= 2;
	elements = new T[maxSize]; // 建立栈空间
	assert(elements != 0);	   // 分配不成功, 结束程序
	for (j = 0; j < i; j++)
		elements[j] = el[j];
	delete[] el;
	cout << "堆栈空间已加倍, 空间为:" << maxSize << endl;
}

const int n = 8;

int main()
{
	int r[n][n] = {
		0, 0, 1, 0, 1, 0, 0, 0,
		0, 0, 1, 1, 0, 0, 0, 0,
		1, 1, 0, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 1, 1, 0, 0,
		1, 0, 1, 1, 0, 1, 1, 0,
		0, 0, 0, 1, 1, 0, 1, 0,
		0, 0, 0, 0, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
	};

	Stack<int> sk;

	int i = 1, j = 1, k; // i 为行政区号,从 0 开始; j 为着色号, 取 1~4
	sk.Push(j); // 第一个着色号

	while (i < n) // 从第二个行政区开始
	{
		while (i < n && j <= 4) // 从第二个行政区开始, 且着色号小于等于 4
		{
			for (k = 0; k < i; k++)
			{
				if (r[i][k] * sk.GetElem(k) == j) // 若与相邻行政区着色号相同，则换下一个着色号
					break;
			}
			if (k < i)
				j++;
			else
			{
				sk.Push(j);
				i++;
				j = 1;
			}
		}
		if (j > 4)
		{
			i--;
			j = sk.Pop() + 1;
		}
	}
	for (i = 0; i < n; i++)
		cout << sk.GetElem(i) << '\t';
	cout << endl;
	return 0;
}