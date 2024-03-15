#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class Complex {
	private:
		double real;
		double imag;
	public:
		Complex();
		Complex(double real, double imag);
		Complex(const Complex &);
		~Complex();
		
		void Print() const;
		
		Complex operator+(const Complex &) const;
		Complex operator+(double) const;
		Complex operator+=(const Complex &);
		
		Complex operator-(const Complex &) const;
		Complex operator-(double) const;
		Complex operator-=(const Complex &);

		Complex operator*(const Complex &) const;
		Complex operator*(double) const;

		Complex operator/(const Complex &) const;
		Complex operator/(double) const;

		Complex &operator=(const Complex &);

		double magnitude() const;

		bool operator>(const Complex &) const;
		bool operator<(const Complex &) const;
		bool operator==(const Complex &) const;

		friend std::ostream &operator<<(std::ostream &, const Complex &);

};

#endif // COMPLEX_H_