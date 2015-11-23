#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
public:
	friend Fraction operator+ (Fraction&, Fraction&);
	friend Fraction operator- (Fraction&, Fraction&);
	friend Fraction operator* (Fraction&, Fraction&);
	friend Fraction operator/ (Fraction&, Fraction&);
	friend std::ostream& operator<< (std::ostream&, Fraction&);
	friend bool operator== (Fraction&, Fraction&);
	friend bool operator!= (Fraction&, Fraction&);
	friend bool operator< (Fraction&, Fraction&);
	friend bool operator<= (Fraction&, Fraction&);
	friend bool operator> (Fraction&, Fraction&);
	friend bool operator>= (Fraction&, Fraction&);

public:
	Fraction() = default;  // constructor function: numerator = 0, denominator = 1
	Fraction(long long temp_a) : numerator(temp_a) { }  // constructor function: numerator = temp_a, denominator = 1.
	Fraction(long long temp_a, long long temp_b) : numerator(temp_a), denominator(temp_b) {  // constructor function: numerator = temp_a, denominator = 1 and reduction of a fraction.
		rof();
	}
	~Fraction() { };

private:
	long long numerator = 0;
	long long denominator = 1;

	long long gcd(const long long, const long long);  // greatest common divisor
	void rof();  // reduction of a fraction
};

#endif