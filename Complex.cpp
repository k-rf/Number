#include <iostream>
#include <sstream>
#include <cmath>
#include "Complex.h"

using namespace std;

// ============================================================================
// �R���X�g���N�^
// ============================================================================
Complex::Complex(double r, double i) : re(r), im(i) {}

// ============================================================================
// �O�u���Z�q�i�����̂݁j
// ============================================================================
Complex& Complex::operator++()
{
	re++;
	return *this;
}

Complex& Complex::operator--()
{
	re--;
	return *this;
}

// ============================================================================
// ��u���Z�q�i�����̂݁j
// ============================================================================
Complex Complex::operator++(int)
{
	Complex tmp(*this);
	re++;
	return tmp;
}

Complex Complex::operator--(int)
{
	Complex tmp(*this);
	re--;
	return tmp;
}

// ============================================================================
// ���Z
// ============================================================================
Complex& Complex::operator+=(const Number& x)
{
	Complex tmp(dynamic_cast<const Complex&>(x));

	re += tmp.re;
	im += tmp.im;

	return *this;
}

Complex operator+(const Complex& x, const Complex& y)
{
	return Complex(x.re + y.re, x.im + y.im);
}

// ============================================================================
// ���Z
// ============================================================================
Complex& Complex::operator-=(const Number& x)
{
	Complex tmp(dynamic_cast<const Complex&>(x));

	re -= tmp.re;
	im -= tmp.im;

	return *this;
}

Complex operator-(const Complex& x, const Complex& y)
{
	return Complex(x.re - y.re, x.im - y.im);
}

// ============================================================================
// ��Z
// ============================================================================
Complex& Complex::operator*=(const Number& x)
{
	Complex tmp(dynamic_cast<const Complex&>(x));

	re = re * tmp.re - im * tmp.im;
	im = re * tmp.im + im * tmp.re;

	return *this;
}

Complex operator*(const Complex& x, const Complex& y)
{
	return Complex(x.re * y.re - x.im * y.im, x.re * y.im + x.im * y.re);
}

// ============================================================================
// ��Z
// ============================================================================
Complex& Complex::operator/=(const Number& x)
{
	Complex tmp(dynamic_cast<const Complex&>(x));

	re = (re * tmp.re + im * tmp.im) / (tmp.re * tmp.re + tmp.im * tmp.im);
	im = (im * tmp.re - re * tmp.im) / (tmp.re * tmp.re + tmp.im * tmp.im);

	return *this;
}

Complex operator/(const Complex& x, const Complex& y)
{
	return Complex((x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im),
		(x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im));
}

// ============================================================================
// ��Βl
// ============================================================================
double Complex::Abs()
{
	return sqrt(re * re + im * im);
}

// ============================================================================
// ��r���Z�q
// ============================================================================
bool operator==(const Complex& x, const Complex& y)
{
	return (x.re == y.re && x.im == y.im);
}

bool operator!=(const Complex& x, const Complex& y)
{
	return !(x == y);
}

// ============================================================================
// �}���q
// ============================================================================
ostream& operator<<(ostream& s, const Complex& x)
{
	return s << "{ " << x.re << ((x.im > 0) ? " + " : " - ") << ((x.im > 0) ? x.im : -x.im) << "i }";
}

// ============================================================================
// ���o�q
// 1+2i, 1-2i�Ƃ������`���œ���
// ============================================================================
istream& operator>>(istream& s, Complex& x)
{
	char i;
	s >> x.re >> x.im >> i;

	return s;
}
