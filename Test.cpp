#include <iostream>
#include <sstream>
#include "Number.h"
#include "Fraction.h"
#include "Complex.h"

#define EXIT1 8
#define EXIT2 9

using namespace std;

int main()
{
	int menu = 0;
	Fraction a, b;
	Complex x, y;
	
	do
	{
		cout << "分数：１　　複素数：２　　終了：９\n>>>> ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cout << "x/yという形式で入力してください。\n";
			FractionTyping:
				cout << "分数１：";  cin >> a;
				cout << "分数２：";  cin >> b;

				do
				{
					cout << "加算：１　減算：２　乗算：３　除算：４　比較：５　再入力：６　戻る：８\n>>>> ";
					cin >> menu;

					switch(menu)
					{
						case 1:
							cout << a << " + " << b << " = " << a + b << '\n';
							break;

						case 2:
							cout << a << " - " << b << " = " << a - b << '\n';
							break;

						case 3:
							cout << a << " * " << b << " = " << a * b << '\n';
							break;

						case 4:
							cout << a << " / " << b << " = " << a / b << '\n';
							break;

						case 5:
							cout << a << (a == b ? " == " : " != ") << b << '\n';
							cout << a << (a < b ? " <  " : (a == b) ? " <= " : " > ") << b << '\n';
							break;

						case 6:
							goto FractionTyping;
							break;

						default:
							menu = EXIT1;
							break;
					}
					cout << '\n';
				} while(menu != EXIT1);
				
				break;

			case 2:
				
				cout << "1+2i、1-2iという形式で入力してください。\n";
			ComplexTyping:
				cout << "複素数１：";  cin >> x;
				cout << "複素数２：";  cin >> y;

				do
				{
					cout << "加算：１　減算：２　乗算：３　除算：４　比較：５　絶対値：６　再入力：７　戻る：８\n>>>> ";
					cin >> menu;

					switch(menu)
					{
						case 1:
							cout << x << " + " << y << " = " << x + y << '\n';
							break;

						case 2:
							cout << x << " - " << y << " = " << x - y << '\n';
							break;

						case 3:
							cout << x << " * " << y << " = " << x * y << '\n';
							break;

						case 4:
							cout << x << " / " << y << " = " << x / y << '\n';
							break;

						case 5:
							cout << x << (x == y ? " == " : " != ") << y << '\n';
							break;

						case 6:
							cout << '|' << x << '|' << " = " << x.Abs() << '\n';
							cout << '|' << y << '|' << " = " << y.Abs() << '\n';
							break;

						case 7:
							goto ComplexTyping;
							break;

						default:
							menu = EXIT1;
							break;
					}
					cout << '\n';
				} while(menu != EXIT1);

				break;

			default:
				menu = EXIT2;
				break;
		}

	} while(menu != EXIT2);
	

}