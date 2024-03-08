#include "money.h"
#include <iostream>

int main()
{
	Money m1;
	Money m2(1, 2, 3);
	Money m3(4.56);
	Money m4 = m3;

	std::cout << m1 << std::endl
			  << m2 << std::endl
			  << m3 << std::endl
			  << m4 << std::endl;
	
	// Plus
	m1 = m2 + m3;
	std::cout << m1 << std::endl;
	m1 = m2 + 1;
	std::cout << m1 << std::endl;
	m1 = 1 + m2;
	std::cout << m1 << std::endl;
	// Minus
	m1 = m2 - m3;
	std::cout << m1 << std::endl;
	m1 = m2 - 1;
	std::cout << m1 << std::endl;
	m1 = 1 - m2;
	std::cout << m1 << std::endl;
	// Multiplication
	m1 = 2 * m2;
	std::cout << m1 << std::endl;
	m1 = m2 * 2;
	std::cout << m1 << std::endl;
	// Division
	m1 = m2 / 2;
	std::cout << m1 << std::endl;
	// Comparison
	std::cout << (m2 == m3) << std::endl;
	std::cout << (m2 != m3) << std::endl;
	std::cout << (m2 < m3) << std::endl;
	std::cout << (m2 <= m3) << std::endl;
	std::cout << (m2 > m3) << std::endl;
	std::cout << (m2 >= m3) << std::endl;
	// I/O
	std::cin >> m1;
	std::cout << m1 << std::endl;

	return 0;
}
/*
$ make && ./main
g++ **.cpp -o main

Default constructor called
Constructor yuan, jiao, fen called
Constructor double called
Copy constructor called
CNYOperator double called
0
CNYOperator double called
1.23
CNYOperator double called
4.56
CNYOperator double called
4.56
Operator + called
Default constructor called
Operator double called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
5.79
Operator + double called
Default constructor called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
2.23
Operator double + called
Default constructor called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
2.23
Operator - called
Default constructor called
Operator double called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
-3.33
Operator - double called
Default constructor called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
0.23
Operator double - called
Default constructor called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
-0.23
Operator double * called
Default constructor called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
2.46
Operator * double called
Default constructor called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
2.46
Operator / double called
Default constructor called
Operator double called
Operator = double called
Operator = called
Destructor called
CNYOperator double called
0.62
Operator == called
Operator double called
Operator double called
0
Operator != called
Operator double called
Operator double called
1
Operator < called
Operator double called
Operator double called
1
Operator <= called
Operator double called
Operator double called
1
Operator > called
Operator double called
Operator double called
0
Operator >= called
Operator double called
Operator double called
0
(CNY in decimal): 1.14
Operator = double called
CNYOperator double called
1.14
Destructor called
Destructor called
Destructor called
Destructor called
*/