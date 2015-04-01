#ifndef ___CLASS_COMPLEX
#define ___CLASS_COMPLEX

#include <iostream>
#include <sstream>
#include "Number.h"

class Complex : public Number
{
	double re;  // 実部
	double im;  // 虚部

public:
	// コンストラクタ
	Complex(double r = 0, double i = 0);

	// デストラクタ
	virtual ~Complex() {}

	// 前置演算子（実部のみ）
	Complex& operator++();
	Complex& operator--();

	// 後置演算子（実部のみ）
	Complex operator++(int);
	Complex operator--(int);

	// 加算
	Complex& operator+=(const Number& x);
	friend Complex operator+(const Complex& x, const Complex& y);

	// 減算
	Complex& operator-=(const Number& x);
	friend Complex operator-(const Complex& x, const Complex& y);

	// 乗算
	Complex& operator*=(const Number& x);
	friend Complex operator*(const Complex& x, const Complex& y);

	// 除算
	Complex& operator/=(const Number& x);
	friend Complex operator/(const Complex& x, const Complex& y);

	// 絶対値
	double Abs();

	// 比較演算子
	friend bool operator==(const Complex& x, const Complex& y);
	friend bool operator!=(const Complex& x, const Complex& y);
	
	// 挿入子
	friend std::ostream& operator<<(std::ostream& s, const Complex& x);

	// 抽出子
	// 1+2i, 1-2iといった形式で入力
	friend std::istream& operator>>(std::istream& s, Complex& x);
};

#endif