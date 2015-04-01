#include <iostream>
#include <sstream>
#include <cmath>
#include "Fraction.h"

using namespace std;

// ============================================================================
// ���[�N���b�h�ݏ��@
// ============================================================================
int Fraction::Euclid(int x, int y)
{
	x = abs(x);
	y = abs(y);

	if(x < y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	
	if(y == 0)
		return x;

	int r = x % y;
	if(r == 0)
		return y;
	return Euclid(y, r);
}

// ============================================================================
// ��
// ============================================================================
Fraction& Fraction::Red(Fraction& x)
{
	int tmp = Euclid(x.a, x.b);
	x.a /= tmp;
	x.b /= tmp;
	
	return x;
}

// ============================================================================
// ����ɕ��̐�������Ε��ꕪ�q��-1��������
// ============================================================================
Fraction& Fraction::vain(Fraction& x)
{
	if(x.b < 0)
	{
		x.a *= -1;
		x.b *= -1;
	}

	return x;
}

// ============================================================================
// �R���X�g���N�^
// ============================================================================
Fraction::Fraction(int x, int y) : a(x), b(y)
{}

// ============================================================================
// �O�u���Z�q
// ============================================================================

Fraction& Fraction::operator++()
{
	*this += 1;
	return *this;
}

Fraction& Fraction::operator--()
{
	*this -= 1;
	return *this;
}

// ============================================================================
// ��u����
// ============================================================================
Fraction Fraction::operator++(int)
{
	Fraction tmp(*this);
	++(*this);
	return tmp;
}

Fraction Fraction::operator--(int)
{
	Fraction tmp(*this);
	--(*this);
	return tmp;
}

// ============================================================================
// ���Z
// ============================================================================
Fraction& Fraction::operator+=(const Number& x)
{
	int hcf;  // �ő����
	int lcm;  // �ŏ����{��

	Fraction tmp(dynamic_cast<const Fraction&>(x));

	hcf = Euclid(b, tmp.b);
	lcm = b * tmp.b / hcf;

	a = (a * tmp.b / hcf) + (b * tmp.a / hcf);
	b = lcm;

	return vain(Red(*this));
}

Fraction& Fraction::operator+=(const double& x)
{
	*this = *this + x;
	return *this;
}

Fraction operator+(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x);
	tmp += y;

	return tmp;
}

// ============================================================================
// ���Z
// ============================================================================
Fraction& Fraction::operator-=(const Number& x)
{
	int hcf;  // �ő����
	int lcm;  // �ŏ����{��

	Fraction tmp(dynamic_cast<const Fraction&>(x));

	hcf = Euclid(b, tmp.b);
	lcm = b * tmp.b / hcf;

	a = (a * tmp.b / hcf) - (b * tmp.a / hcf);
	b = lcm;

	return vain(Red(*this));
}

Fraction& Fraction::operator-=(const double& x)
{
	*this = *this - x;
	return *this;
}

Fraction operator-(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x);
	tmp -= y;

	return tmp;
}

// ============================================================================
// ��Z
// ============================================================================
Fraction& Fraction::operator*=(const Number& x)
{
	Fraction tmp(dynamic_cast<const Fraction&>(x));

	a *= tmp.a;
	b *= tmp.b;

	return vain(Red(*this));
}

Fraction& Fraction::operator*=(const double& x)
{
	*this = *this * x;
	return *this;
}

Fraction operator*(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x);
	tmp *= y;

	return tmp;
}

// ============================================================================
// ���Z
// ============================================================================
Fraction& Fraction::operator/=(const Number& x)
{
	Fraction tmp(dynamic_cast<const Fraction&>(x));

	a *= tmp.b;
	b *= tmp.a;

	return vain(Red(*this));
}

Fraction& Fraction::operator/=(const double& x)
{
	*this = *this / x;
	return *this;
}

Fraction operator/(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x);
	tmp /= y;

	return tmp;
}

// ============================================================================
// ��Βl
// ============================================================================
Fraction Fraction::Abs()
{
	return ((this->a < 0) ? *this * -1 : *this);
}

// ============================================================================
// ��r���Z�q
// ============================================================================
bool operator==(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x - y);
	return (tmp.a == 0) ? true : false;
}

bool operator!=(const Fraction& x, const Fraction& y)
{
	return !(x == y);
}

bool operator>(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x - y);
	return (tmp.a > 0) ? true : false;
}

bool operator>=(const Fraction& x, const Fraction& y)
{
	return (x > y || x == y);
}

bool operator<(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x - y);
	return (tmp.a < 0) ? true : false;
}

bool operator<=(const Fraction& x, const Fraction& y)
{
	return (x < y || x == y);
}

// ============================================================================
// �}���q
// ============================================================================
ostream& operator<<(ostream& s, const Fraction& x)
{
	s << "{ " << x.a << " / " << x.b << " }";
	return s;
}

// ============================================================================
// ���o�q
// 1/2, -1/3�Ƃ������`���œ���
// ============================================================================
istream& operator>>(istream& s, Fraction& x)
{
	char tmp;
	s >> x.a >> tmp >> x.b;

	return s;
}