#include "rational_library.h"

using rational_lib::Rational;
using std::cout;

int main()
{
	try
	{
		cout << Rational{ 3,8 } + Rational{ 6,10 } << '\n';
		cout << Rational{ 3,8 } - Rational{ 6,10 } << '\n';
		cout << Rational{ 3,8 } * Rational{ 6,10 } << '\n';
		cout << Rational{ 3,8 } / Rational{ 6,10 } << '\n';
		cout << Rational{ 4,10 } << '\n';
		cout << Rational{ 10 } << '\n';
		cout << Rational{ 4,0 } << '\n';
	}
	catch (std::runtime_error& e)
	{
		cout << "Runtime error: " << e.what() << '\n';
	}
	{char c; std::cin >> c;}
	return 0;
}
