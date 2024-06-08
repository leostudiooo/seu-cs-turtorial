// 在此添加所需头文件5分
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;
class Goods
{ // 商品类
private:
	int id;			   // 商品代号
	string goods_name; // 商品名称
	float price;	   // 价格
	int num;		   // 库存数量
	float value;	   // 商品总价
public:
	enum SortType
	{
		by_id,
		by_price,
		by_num,
		by_value
	}; // 用于实现比较的枚举类型
	static SortType sort_type;						  // 静态数据成员，可用于改变比较模式
	Goods(int = 0, string = "#", float = 0, int = 0); // 缺省构造函数
	bool operator>(const Goods &);
	friend ostream &operator<<(ostream &, const Goods &);
};

Goods::SortType Goods::sort_type = Goods::by_id; // 注意SortType是在Goods类中定义的，默认比较模式为按商品代号比较

Goods::Goods(int i, string gn, float pr, int n)
{
	id = i;
	goods_name = gn, price = pr;
	num = n;
	value = price * num;
}

bool Goods::operator>(const Goods &x)
{ // 在此补充本段代码,根据静态数据成员sort_type的值，实现各种比较模式下>运算符重载（10分）
	switch (sort_type)
	{
	case by_id:
		if (id > x.id)
			return true;
		else
			return false;
		break;

	case by_num:
		if (num > x.num)
			return true;
		else
			return false;
		break;

	case by_price:
		if (price > x.price)
			return true;
		else
			return false;
		break;

	case by_value:
		if (value > x.value)
			return true;
		else
			return false;
		break;

	default:
		return false;
		break;
	}
}

ostream &operator<<(ostream &out, const Goods &x)
{ // 在此补充本段代码，实现插入运算符<<重载（10分）
	out << right << setw(6) << "id:" << setw(6) << x.id << setw(12) << "goods_name:" << setw(10) << x.goods_name << setw(10) << "price:" << setw(10) << x.price << setw(10) << "num:" << setw(10) << x.num << setw(10) << "value:" << setw(10) << x.value;
	return out;
}

template <typename T>
class Manage
{ // 管理类
private:
	T *g;		 // 管理堆区数组
	int num;	 // 堆区数组元素有效个数
	int maxsize; // 最大容纳的元素个数
public:
	Manage(int n = 20);					  // 默认构造函数,如不指定大小，设有20个元素
	void add_data(const T &);			  // 向堆区数组中添加元素
	Manage(const Manage &);				  // 实现深拷贝
	Manage &operator=(const Manage &);	  // =重载
	~Manage();							  // 析构函数
	void sort();						  // 对堆区数组进行降序排序
	void list();						  // 屏幕打印库存商品清单和商品种类数
	void save_file(const char *filename); // 将堆区数组的信息保存到磁盘文件中
};

// 在此补充默认构造函数的函数头（5分）
template <typename T>
Manage<T>::Manage(int n)
{
	maxsize = n;
	g = new T[maxsize];
	num = 0;
}

template <typename T>
void Manage<T>::add_data(const T &x)
{
	// 在此补充本段代码，实现向堆区数组中添加一个元素，如果堆区空间满时，扩大堆区空间，并添加新元素（15分）
	if (num == maxsize)
	{
		maxsize *= 2;
		T *temp = new T[maxsize];
		for (int i = 0; i < num; i++)
		{
			temp[i] = g[i];
		}
		delete[] g;
		g = temp;
	}
	g[num++] = x;
}

template <typename T>
Manage<T>::Manage(const Manage<T> &x) //
{

	if (&x == this)
		return;
	// 在此补充本段代码，实现深拷贝（10分）
	num = x.num;
	maxsize = x.maxsize;
	g = new T[maxsize];
	for (int i = 0; i < num; i++)
	{
		g[i] = x.g[i];
	}
}

template <typename T>
Manage<T> &Manage<T>::operator=(const Manage<T> &x)
{
	// 在此补充本段代码，实现=重载（10分）
	if (this == &x)
	{
		return *this;
	}
	else
	{
		delete[] g;
		num = x.num;
		maxsize = x.maxsize;
		g = new T[maxsize];
		for (int i = 0; i < num; i++)
		{
			g[i] = x.g[i];
		}
		return *this;
	}
}

template <typename T>
Manage<T>::~Manage() // 析构函数
{
	if (g)
		delete[] g;
}

template <typename T>
void Manage<T>::sort()
{
	// 在此补充本段代码，实现对堆区数组进行降序排序（15分）
	for (int i = 0; i < num; i++)
	{
		T maximum = g[i];
		int maxIndex = i;
		for (int j = i + 1; j < num; j++)
		{
			if (g[j] > maximum)
			{
				maximum = g[j];
				maxIndex = j;
			}
		}
		swap(g[i], g[maxIndex]);
	}
}

template <typename T>
void Manage<T>::list()
{ // 在此补充本段代码，实现屏幕打印库存商品清单和商品种类数（10分）
	for (int i = 0; i < num; i++)
	{
		cout << g[i] << endl;
	}
}

template <typename T>
void Manage<T>::save_file(const char *filename)
{
	// 在此补充本段代码，实现将堆区数组的信息保存到磁盘文件中（10分）
	ofstream out(filename, ios::app);
	for (int i = 0; i < num; i++)
	{
		out << g[i] << endl;
	}
	for(int i = 0; i < 10; i++)
	{
		out << ".";
	}
	out << "分割线" << endl;
	out.close();
}

int main()
{
	Goods x1(1001, "方便面", 9.8, 2000);
	Goods x2(1002, "暖水瓶", 19.9, 4000);
	Goods x3(1003, "充电器", 39.9, 3000);
	Goods x4(1004, "保温杯", 88.8, 1500);
	Goods x5(1000, "台灯", 29.8, 1000);
	Manage<Goods> m(4);
	m.add_data(x1);
	m.add_data(x2);
	m.add_data(x3);
	m.add_data(x4);
	m.add_data(x5);
	cout << "按输入顺序打印清单：" << endl;
	m.list();
	cout << "按商品代号顺序打印清单：" << endl;
	m.sort();
	m.list();
	cout << "按商品价格顺序打印清单：" << endl;
	Goods::sort_type = Goods::by_price;
	m.sort();
	m.list();
	m.save_file("menu_sort.out");
	Manage<Goods> m1(m);
	cout << "按商品数量顺序打印清单：" << endl;
	Goods::sort_type = Goods::by_num;
	m1.sort();
	m1.list();
	m1.save_file("menu_sort.out");
	return 0;
}
