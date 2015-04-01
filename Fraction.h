#ifndef ___CLASS_FRACTION
#define ___CLASS_FRACTION

#include <iostream>
#include <sstream>
#include "Number.h"

class Fraction : public Number
{
	int a;  // 分子
	int b;  // 分母

	// ユークリッド互除法
	int Euclid(int x, int y);

	// 約分
	Fraction& Red(Fraction& x);

	// 分母に負の数があれば分母分子に-1をかける
	Fraction& vain(Fraction& x);

public:
	// コンストラクタ
	Fraction(int x = 0, int y = 1);

	// デストラクタ
	virtual ~Fraction() {}
	
	// 前置演算子
	Fraction& operator++();
	Fraction& operator--();

	// 後置演算子
	Fraction operator++(int);
	Fraction operator--(int);

	// 加算
	Fraction& operator+=(const Number& x);
	Fraction& operator+=(const double& x);
	friend Fraction operator+(const Fraction& x, const Fraction& y);
	
	// 減算
	Fraction& operator-=(const Number& x);
	Fraction& operator-=(const double& x);
	friend Fraction operator-(const Fraction& x, const Fraction& y);
	
	// 乗算
	Fraction& operator*=(const Number& x);
	Fraction& operator*=(const double& x);
	friend Fraction operator*(const Fraction& x, const Fraction& y);
	
	// 除算
	Fraction& operator/=(const Number& x);
	Fraction& operator/=(const double& x);
	friend Fraction operator/(const Fraction& x, const Fraction& y);

	// 絶対値
	Fraction Abs();

	// 比較演算子
	friend bool operator==(const Fraction& x, const Fraction& y);
	friend bool operator!=(const Fraction& x, const Fraction& y);
	friend bool operator>(const Fraction& x, const Fraction& y);
	friend bool operator>=(const Fraction& x, const Fraction& y);
	friend bool operator<(const Fraction& x, const Fraction& y);
	friend bool operator<=(const Fraction& x, const Fraction& y);

	// 挿入子
	friend std::ostream& operator<<(std::ostream& s, const Fraction& x);
	
	// 抽出子
	// 1/2, -1/3といった形式で入力
	friend std::istream& operator>>(std::istream& s, Fraction& x);
};

#endif