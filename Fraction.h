#ifndef ___CLASS_FRACTION
#define ___CLASS_FRACTION

#include <iostream>
#include <sstream>
#include "Number.h"

class Fraction : public Number
{
	int a;  // ���q
	int b;  // ����

	// ���[�N���b�h�ݏ��@
	int Euclid(int x, int y);

	// ��
	Fraction& Red(Fraction& x);

	// ����ɕ��̐�������Ε��ꕪ�q��-1��������
	Fraction& vain(Fraction& x);

public:
	// �R���X�g���N�^
	Fraction(int x = 0, int y = 1);

	// �f�X�g���N�^
	virtual ~Fraction() {}
	
	// �O�u���Z�q
	Fraction& operator++();
	Fraction& operator--();

	// ��u���Z�q
	Fraction operator++(int);
	Fraction operator--(int);

	// ���Z
	Fraction& operator+=(const Number& x);
	Fraction& operator+=(const double& x);
	friend Fraction operator+(const Fraction& x, const Fraction& y);
	
	// ���Z
	Fraction& operator-=(const Number& x);
	Fraction& operator-=(const double& x);
	friend Fraction operator-(const Fraction& x, const Fraction& y);
	
	// ��Z
	Fraction& operator*=(const Number& x);
	Fraction& operator*=(const double& x);
	friend Fraction operator*(const Fraction& x, const Fraction& y);
	
	// ���Z
	Fraction& operator/=(const Number& x);
	Fraction& operator/=(const double& x);
	friend Fraction operator/(const Fraction& x, const Fraction& y);

	// ��Βl
	Fraction Abs();

	// ��r���Z�q
	friend bool operator==(const Fraction& x, const Fraction& y);
	friend bool operator!=(const Fraction& x, const Fraction& y);
	friend bool operator>(const Fraction& x, const Fraction& y);
	friend bool operator>=(const Fraction& x, const Fraction& y);
	friend bool operator<(const Fraction& x, const Fraction& y);
	friend bool operator<=(const Fraction& x, const Fraction& y);

	// �}���q
	friend std::ostream& operator<<(std::ostream& s, const Fraction& x);
	
	// ���o�q
	// 1/2, -1/3�Ƃ������`���œ���
	friend std::istream& operator>>(std::istream& s, Fraction& x);
};

#endif