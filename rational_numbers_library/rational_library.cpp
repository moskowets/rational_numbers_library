#include "rational_library.h"

namespace rational_lib
{
	Rational::Rational(int numerator_input)
	{
		set_value(numerator_input, 1);
	}
	Rational::Rational(int numerator_input, int denominator_input)
	{
		set_value(numerator_input, denominator_input);
	}
	Rational Rational::operator()(int numerator_input, int denominator_input)
	{
		set_value(numerator_input, denominator_input);
		return Rational{ numerator_input , denominator_input };
	}
	Rational::operator bool() const
	{
		if (numerator == 0) return false;
		else return true;
	}
	double Rational::get_double() const
	{
		return double(numerator) / double(denominator);
	}
	void Rational::set_value(int numerator_input, int denominator_input)
	{
		if (denominator_input == 0) throw std::runtime_error("Denominator can not be equal to zero");
		if (numerator_input == 0)
		{
			numerator = numerator_input;
			denominator = denominator_input;
		}
		int min_value = (abs(numerator_input) > abs(denominator_input))? abs(denominator_input): abs(numerator_input);
		for (int i = min_value; i > 0; --i)
		{
			if ((numerator_input%i == 0) && (denominator_input%i == 0))
			{
				numerator = numerator_input / i;
				denominator = denominator_input / i;
				break;
			}
		}
	}
	Rational operator*(const Rational & arg1, const Rational & arg2)
	{
		return Rational(arg1.numerator*arg2.numerator, arg1.denominator*arg2.denominator);
	}
	Rational operator/(const Rational & arg1, const Rational & arg2)
	{
		return Rational(arg1.numerator*arg2.denominator, arg1.denominator*arg2.numerator);
	}
	Rational operator+(const Rational & arg1, const Rational & arg2)
	{
		return Rational(arg1.numerator*arg2.denominator + arg1.denominator*arg2.numerator, arg1.denominator*arg2.denominator);
	}
	Rational operator-(const Rational & arg1, const Rational & arg2)
	{
		return Rational(arg1.numerator*arg2.denominator - arg1.denominator*arg2.numerator, arg1.denominator*arg2.denominator);
	}
	std::ostream & operator<<(std::ostream & out, const Rational & arg1)
	{
		out << arg1.numerator << '/' << arg1.denominator;
		return out;
	}
}