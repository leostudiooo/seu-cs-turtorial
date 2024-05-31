#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
// Use std::runtime_error instead of directly using throwing a string
#include <stdexcept>

using namespace std;

template <typename T>
class ArrayList
{
	T *elements;
	int maxCurrentIndex;
	int capacity;
	fstream file;

public:
	ArrayList(int = 2);
	~ArrayList();

	bool isFull() const
	{
		return maxCurrentIndex == capacity - 1;
	}

	void showStatus() const
	{
		cout << "maxCurrentIndex: " << maxCurrentIndex << " capacity: " << capacity << endl;
	}

	void doubleSizeRenew();

	void orderedInsert(const T &);

	template <typename U>
	friend ostream &operator<<(ostream &, const ArrayList<U> &);
};

template <typename T>
ArrayList<T>::ArrayList(int capacity)
{
	this->capacity = capacity;
	maxCurrentIndex = -1;
	T temp;
	elements = new T[capacity];
	file.open("data.txt", ios::in);
	if (!file == 0)
	{
		while (!file.eof())
		{
			file >> temp;
			if (file.eof())
				orderedInsert(temp);
		}
		file.close();
	}
	file.clear(0);
}

template <typename T>
ArrayList<T>::~ArrayList()
{
	int i;
	file.open("data.txt", ios::out);
	for (i = 0; i <= maxCurrentIndex; i++)
	{
		file << elements[i];
	}
	file.close();
	delete[] elements;
}

template <typename T>
void ArrayList<T>::doubleSizeRenew()
{
	int i;
	capacity *= 2;
	T *temp = elements;
	elements = new T[capacity];
	for (i = 0; i <= maxCurrentIndex; i++)
	{
		elements[i] = temp[i];
	}
	delete[] temp;
}

template <typename T>
void ArrayList<T>::orderedInsert(const T &element)
{
	try
	{
		if (isFull())
		{
			throw std::runtime_error("ArrayList is full");
		}

		int i;
		for (i = 0; i <= maxCurrentIndex; i++)
		{
			if (element <= elements[i])
				break;
		}
		if (!(element == elements[i]))
		{
			for (int j = maxCurrentIndex; j >= i; j--)
			{
				elements[j + 1] = elements[j];
			}
			elements[i] = element;
			maxCurrentIndex++;
		}
		else
		{
			throw std::runtime_error("Element already exists");
		}
		showStatus();
	}
	catch (const std::runtime_error &error)
	{
		if (string(error.what()) == string("ArrayList is full"))
		{
			cerr << error.what() << endl;
			doubleSizeRenew();
			orderedInsert(element);
		}
		else
		{
			cerr << error.what() << endl;
		}
	}
}

template <typename U>
ostream &operator<<(ostream &destination, const ArrayList<U> &list)
{
	for (int i = 0; i <= list.maxCurrentIndex; i++)
	{
		destination << list.elements[i];
	}
	return destination;
}