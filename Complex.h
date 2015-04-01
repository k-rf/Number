#ifndef ___CLASS_COMPLEX
#define ___CLASS_COMPLEX

#include <iostream>
#include <sstream>
#include "Number.h"

class Complex : public Number
{
	double re;  // ����
	double im;  // ����

public:
	// �R���X�g���N�^
	Complex(double r = 0, double i = 0);

	// �f�X�g���N�^
	virtual ~Complex() {}

	// �O�u���Z�q�i�����̂݁j
	Complex& operator++();
	Complex& operator--();

	// ��u���Z�q�i�����̂݁j
	Complex operator++(int);
	Complex operator--(int);

	// ���Z
	Complex& operator+=(const Number& x);
	friend Complex operator+(const Complex& x, const Complex& y);

	// ���Z
	Complex& operator-=(const Number& x);
	friend Complex operator-(const Complex& x, const Complex& y);

	// ��Z
	Complex& operator*=(const Number& x);
	friend Complex operator*(const Complex& x, const Complex& y);

	// ���Z
	Complex& operator/=(const Number& x);
	friend Complex operator/(const Complex& x, const Complex& y);

	// ��Βl
	double Abs();

	// ��r���Z�q
	friend bool operator==(const Complex& x, const Complex& y);
	friend bool operator!=(const Complex& x, const Complex& y);
	
	// �}���q
	friend std::ostream& operator<<(std::ostream& s, const Complex& x);

	// ���o�q
	// 1+2i, 1-2i�Ƃ������`���œ���
	friend std::istream& operator>>(std::istream& s, Complex& x);
};

#endif