#include <iostream>
#include <sstream>
#include <cmath>
#include "Fraction.h"

using namespace std;

// ============================================================================
// ユークリッド互除法
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
// 約分
// ============================================================================
Fraction& Fraction::Red(Fraction& x)
{
	int tmp = Euclid(x.a, x.b);
	x.a /= tmp;
	x.b /= tmp;
	
	return x;
}

// ============================================================================
// 分母に負の数があれば分母分子に-1をかける
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
// コンストラクタ
// ============================================================================
Fraction::Fraction(int x, int y) : a(x), b(y)
{}

// ============================================================================
// 前置演算子
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
// 後置増分
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
// 加算
// ============================================================================
Fraction& Fraction::operator+=(const Number& x)
{
	int hcf;  // 最大公約数
	int lcm;  // 最小公倍数

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
// 減算
// ============================================================================
Fraction& Fraction::operator-=(const Number& x)
{
	int hcf;  // 最大公約数
	int lcm;  // 最小公倍数

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
// 乗算
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
// 除算
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
// 絶対値
// ============================================================================
Fraction Fraction::Abs()
{
	return ((this->a < 0) ? *this * -1 : *this);
}

// ============================================================================
// 比較演算子
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
// 挿入子
// ============================================================================
ostream& operator<<(ostream& s, const Fraction& x)
{
	s << "{ " << x.a << " / " << x.b << " }";
	return s;
}

// ============================================================================
// 抽出子
// 1/2, -1/3といった形式で入力
// ============================================================================
istream& operator>>(istream& s, Fraction& x)
{
	char tmp;
	s >> x.a >> tmp >> x.b;

	return s;
}