#pragma once
#include <iostream>

namespace rational_lib
{
	class Rational
	{
	public:
		Rational();
		Rational(int numerator_input);
		Rational(int numerator_input, int denominator_input);
		Rational& operator()(int numerator_input, int denominator_input);
		operator bool() const;
		double get_double() const;
	private:
		void set_value(int numerator_input, int denominator_input);
		friend Rational operator*(const Rational& arg1, const Rational& arg2);
		friend Rational operator+(const Rational& arg1, const Rational& arg2);
		friend Rational operator-(const Rational& arg1, const Rational& arg2);
		friend Rational operator/(const Rational& arg1, const Rational& arg2);
		friend std::ostream& operator<<(std::ostream& out, const Rational& arg1);
		int numerator;
		int denominator;
	};
}