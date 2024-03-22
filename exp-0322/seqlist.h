#ifndef SEQLIST_H_
#define SEQLIST_H_

#include <iostream>
using namespace std;

template <typename T, int size>
class Seqlist;

// Inprove readability
enum Method
{
    BUBBLE = 1,
    SELECTION = 2,
    INSERTION = 3
};

enum Type
{
    ASCENDING = 1,
    DESCENDING = 0
};

enum Order
{
    OUT_OF_ORDER = 0,
    ASCENDING_ORDER = 1,
    DESCENDING_ORDER = 2,
    ALL_EQUALS = 3
};

template <typename T, int size>
class Seqlist
{
private:
    T slist[size];
    int last;
    int maxSize;
    // 0: out-of-order; 1: ascending order; 2: descending order; 3: all equals
    Order isOrdered;

    int simpleSearch(const T &) const;
    int binarySearch(const T &) const;
    void bubbleSort(Type type);
    void selectionSort(Type type);
    void insertionSort(Type type);

public:
    Seqlist()
    {
        last = -1;
        maxSize = size;
        isOrdered = OUT_OF_ORDER;
    }

    int Length() const { return last + 1; }

    int Find(const T &x) const;

    bool IsIn(const T &x) const;

    bool Insert(const T &x, int i);

    bool Remove(const T &x);

    int Next(const T &x);

    int Prior(const T &x);

    bool IsEmpty();

    bool IsFull();

    T Get(int i);

    T &operator[](int i);

    Seqlist operator=(const Seqlist &arr);

    Order isSorted();

    /*
     * @param type: 1 for ascending order, 0 for descending order
     * @param method: 1 for bubble sort, 2 for selection sort, 3 for insertion sort
     */
    void Sort(Type type, Method method);

    // I/O
    template <typename Q, int n>
    friend istream &operator>>(istream &is, Seqlist<Q, n> &m);

    template <typename Q, int n>
    friend ostream &operator<<(ostream &os, const Seqlist<Q, n> &m);

};

template <typename Q, int n>
istream &operator>>(istream &is, Seqlist<Q, n> &m)
{
    int num;
    do
    {
        cout << "输入几个顺序表元素（不能多于表d容量" << m.maxSize << "）:" << endl;
        cin >> num;
    } while (num > m.maxSize);

    cout << "请一个个输入: " << endl;
    for (m.last = 0; m.last < num; m.last++)
    {
        is >> m.slist[m.last];
    }
    m.last--;
    return is;
}

template <typename Q, int n>
ostream &operator<<(ostream &os, const Seqlist<Q, n> &m)
{
    for (int i = 0; i <= m.last; i++)
    {
        os << m.slist[i] << endl;
    }
    return os;
}

template <typename T, int size>
void Seqlist<T, size>::Sort(Type type, Method method)
{
    switch (method)
    {
    case BUBBLE:
        bubbleSort(type);
        break;
    case SELECTION:
        selectionSort(type);
        break;
    case INSERTION:
        insertionSort(type);
        break;
    }
}

template <typename T, int size>
int Seqlist<T, size>::simpleSearch(const T &x) const
{
	for (int i = 0; i <= last; i++)
	{
		if (slist[i] == x)
			return i;
	}
	return -1;
}

template <typename T, int size>
int Seqlist<T, size>::binarySearch(const T &x) const
{
	if (isOrdered == OUT_OF_ORDER)
    {
        cout << "The list is not ordered." << endl;
        return -1;
    }
    else if (isOrdered == ALL_EQUALS)
    {
        cout << "All elements are equal." << endl;
        return -1;
    }
    else if (isOrdered == ASCENDING_ORDER)
	{
		int low = 0, high = last, mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (slist[mid] == x)
				return mid;
			else if (slist[mid] < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	else if (isOrdered == DESCENDING_ORDER)
	{
		int low = 0, high = last, mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (slist[mid] == x)
				return mid;
			else if (slist[mid] > x)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return -1;
}

template <typename T, int size>
int Seqlist<T, size>::Find(const T &x) const
{
	if (isOrdered == OUT_OF_ORDER || isOrdered == ALL_EQUALS)
		return simpleSearch(x);
	else
		return binarySearch(x);
}

template <typename T, int size>
bool Seqlist<T, size>::IsIn(const T &x) const
{
	if (Find(x) == -1)
		return false;
	else
		return true;
}

template <typename T, int size>
bool Seqlist<T, size>::Insert(const T &x, int i)
{
	if (i < 0 || i > last + 1 || last == maxSize - 1)
		return false;
	for (int j = last; j >= i; j--)
		slist[j + 1] = slist[j];
	slist[i] = x;
	last++;
	return true;
}

template <typename T, int size>
bool Seqlist<T, size>::Remove(const T &x)
{
    int i = Find(x);
    if (i == -1)
        return false;
    for (int j = i; j < last; j++)
        slist[j] = slist[j + 1];
    last--;
    return true;
}

template <typename T, int size>
int Seqlist<T, size>::Next(const T &x)
{
    int i = Find(x);
    if (i == -1 || i == last)
        return -1;
    else
        return i + 1;
}

template <typename T, int size>
int Seqlist<T, size>::Prior(const T &x)
{
    int i = Find(x);
    if (i == -1 || i == 0)
        return -1;
    else
        return i - 1;
}

template <typename T, int size>
bool Seqlist<T, size>::IsEmpty()
{
    return last == -1;
}

template <typename T, int size>
bool Seqlist<T, size>::IsFull()
{
    return last == maxSize - 1;
}

template <typename T, int size>
T Seqlist<T, size>::Get(int i)
{
    if (i < 0 || i > last)
    {
        cout << "The index is out of range." << endl;
        return slist[0];
    }
    return slist[i];
}

template <typename T, int size>
T &Seqlist<T, size>::operator[](int i)
{
    if (i < 0 || i > last)
    {
        cout << "The index is out of range." << endl;
        return slist[0];
    }
    return slist[i];
}

template <typename T, int size>
Seqlist<T, size> Seqlist<T, size>::operator=(const Seqlist &arr)
{
    last = arr.last;
    for (int i = 0; i <= last; i++)
        slist[i] = arr.slist[i];
    return *this;
}

template <typename T, int size>
Order Seqlist<T, size>::isSorted()
{
    if (last == -1)
    {
        cout << "The list is empty." << endl;
        return -1;
    }
    else
    {
        int i = 0;
        while (i < last && slist[i] == slist[i + 1])
            i++;
        if (i == last)
            isOrdered = ALL_EQUALS;
        else if (slist[i] < slist[i + 1])
            isOrdered = ASCENDING_ORDER;
        else
            isOrdered = DESCENDING_ORDER;
        return isOrdered;
    }
}

template <typename T, int size>
void Seqlist<T, size>::bubbleSort(Type type)
{
    if (last == -1)
    {
        cout << "The list is empty." << endl;
        return;
    }
    if (type == ASCENDING)
    {
        for (int i = 0; i < last; i++)
        {
            for (int j = 0; j < last - i; j++)
            {
                if (slist[j] > slist[j + 1])
                    swap(slist[j], slist[j + 1]);
            }
        }
    }
    else
    {
        for (int i = 0; i < last; i++)
        {
            for (int j = 0; j < last - i; j++)
            {
                if (slist[j] < slist[j + 1])
                    swap(slist[j], slist[j + 1]);
            }
        }
    }
}

template <typename T, int size>
void Seqlist<T, size>::selectionSort(Type type)
{
    if (last == -1)
    {
        cout << "The list is empty." << endl;
        return;
    }
    if (type == ASCENDING)
    {
        for (int i = 0; i < last; i++)
        {
            int min = i;
            for (int j = i + 1; j <= last; j++)
            {
                if (slist[j] < slist[min])
                    min = j;
            }
            if (min != i)
                swap(slist[i], slist[min]);
        }
    }
    else
    {
        for (int i = 0; i < last; i++)
        {
            int max = i;
            for (int j = i + 1; j <= last; j++)
            {
                if (slist[j] > slist[max])
                    max = j;
            }
            if (max != i)
                swap(slist[i], slist[max]);
        }
    }
}

template <typename T, int size>
void Seqlist<T, size>::insertionSort(Type type)
{
    if (last == -1)
    {
        cout << "The list is empty." << endl;
        return;
    }
    if (type == ASCENDING)
    {
        for (int i = 1; i <= last; i++)
        {
            T temp = slist[i];
            int j = i - 1;
            while (j >= 0 && slist[j] > temp)
            {
                slist[j + 1] = slist[j];
                j--;
            }
            slist[j + 1] = temp;
        }
    }
    else
    {
        for (int i = 1; i <= last; i++)
        {
            T temp = slist[i];
            int j = i - 1;
            while (j >= 0 && slist[j] < temp)
            {
                slist[j + 1] = slist[j];
                j--;
            }
            slist[j + 1] = temp;
        }
    }
}

#endif /* SEQLIST_H_ */