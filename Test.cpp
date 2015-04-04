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
		cout << "�����F�P�@�@���f���F�Q�@�@�I���F�X\n>>>> ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cout << "x/y�Ƃ����`���œ��͂��Ă��������B\n";
			FractionTyping:
				cout << "�����P�F";  cin >> a;
				cout << "�����Q�F";  cin >> b;

				do
				{
					cout << "���Z�F�P�@���Z�F�Q�@��Z�F�R�@���Z�F�S�@��r�F�T�@�ē��́F�U�@�߂�F�W\n>>>> ";
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
				
				cout << "1+2i�A1-2i�Ƃ����`���œ��͂��Ă��������B\n";
			ComplexTyping:
				cout << "���f���P�F";  cin >> x;
				cout << "���f���Q�F";  cin >> y;

				do
				{
					cout << "���Z�F�P�@���Z�F�Q�@��Z�F�R�@���Z�F�S�@��r�F�T�@��Βl�F�U�@�ē��́F�V�@�߂�F�W\n>>>> ";
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