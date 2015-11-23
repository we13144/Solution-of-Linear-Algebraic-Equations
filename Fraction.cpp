#include "Fraction.h"
#include <cmath>
#include <iostream>

inline
long long Fraction::gcd(const long long numerator, const long long denominator)  //method of successive division
{
	if (numerator < denominator)
		return gcd(denominator, numerator);
	if (numerator % denominator != 0)
		return gcd(denominator, numerator % denominator);
	else
		return denominator;
}

inline
void Fraction::rof()
{
	if (numerator) {
		int g = gcd(abs(numerator), denominator);  // The g is greatest common divisor of two numbers.
		numerator /= g;
		denominator /= g;
	}
	else {
		denominator = 1;
	}
}

Fraction operator + (Fraction &frac1, Fraction &frac2) {
	return Fraction(frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator, frac2.denominator * frac1.denominator);
}

Fraction operator - (Fraction &frac1, Fraction &frac2) {
	return Fraction(frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator, frac2.denominator * frac1.denominator);
}

Fraction operator * (Fraction &frac1, Fraction &frac2) {
	return Fraction(frac1.numerator * frac2.numerator, frac2.denominator * frac1.denominator);
}

Fraction operator / (Fraction &frac1, Fraction &frac2) {
	return Fraction(frac1.numerator * frac2.denominator, frac2.numerator * frac1.denominator);
}

std::ostream& operator<< (std::ostream& os, Fraction& frac) {
	os << frac.numerator << "/" << frac.denominator;
	return os;
}

bool operator == (Fraction &frac1, Fraction &frac2) {
	return (frac1.numerator * frac2.denominator) == (frac2.numerator * frac1.denominator);
}

bool operator != (Fraction &frac1, Fraction &frac2) {
	return !(frac1 == frac2);
}

bool operator < (Fraction &frac1, Fraction &frac2) {
	return (frac1.numerator * frac2.denominator) < (frac2.numerator * frac1.denominator);
}

bool operator <= (Fraction &frac1, Fraction &frac2) {
	return (frac1 < frac2) || (frac1 == frac2);
}

bool operator > (Fraction &frac1, Fraction &frac2) {
	return !(frac1 <= frac2);
}

bool operator >= (Fraction &frac1, Fraction &frac2) {
	return !(frac1 < frac2);
}