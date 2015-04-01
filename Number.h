#ifndef ___CLASS_NUMBER
#define ___CLASS_NUMBER

#include <iostream>
#include <sstream>

class Number
{
public:
	// �O�u���Z�q
	virtual Number& operator++() = 0;
	virtual Number& operator--() = 0;

	// �l�����Z���
	virtual Number& operator+=(const Number&) = 0;
	virtual Number& operator-=(const Number&) = 0;
	virtual Number& operator*=(const Number&) = 0;
	virtual Number& operator/=(const Number&) = 0;
};
 
#endif