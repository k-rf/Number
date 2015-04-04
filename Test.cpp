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
		cout << "•ª”F‚P@@•¡‘f”F‚Q@@I—¹F‚X\n>>>> ";
		cin >> menu;

		switch(menu)
		{
			case 1:
				cout << "x/y‚Æ‚¢‚¤Œ`Ž®‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n";
			FractionTyping:
				cout << "•ª”‚PF";  cin >> a;
				cout << "•ª”‚QF";  cin >> b;

				do
				{
					cout << "‰ÁŽZF‚P@Œ¸ŽZF‚Q@æŽZF‚R@œŽZF‚S@”äŠrF‚T@Ä“ü—ÍF‚U@–ß‚éF‚W\n>>>> ";
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
				
				cout << "1+2iA1-2i‚Æ‚¢‚¤Œ`Ž®‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n";
			ComplexTyping:
				cout << "•¡‘f”‚PF";  cin >> x;
				cout << "•¡‘f”‚QF";  cin >> y;

				do
				{
					cout << "‰ÁŽZF‚P@Œ¸ŽZF‚Q@æŽZF‚R@œŽZF‚S@”äŠrF‚T@â‘Î’lF‚U@Ä“ü—ÍF‚V@–ß‚éF‚W\n>>>> ";
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