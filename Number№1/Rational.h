#pragma once
#include "LongLong.h"

class Rational {

private:

	LongLong numerator;
	LongLong denominator;
	Rational reduce(Rational& p_rat);

protected:

	friend unsigned long positten(int number);

public:

	Rational() = default;

	explicit Rational(const LongLong& numer, const LongLong& demonin);

	Rational operator - () const;

	Rational operator + (const Rational& p_other);

	Rational operator - (const Rational& p_other);

	Rational operator * (const Rational& p_other);

	Rational operator / (const Rational& p_other);

	bool operator > (const Rational& p_other);

	bool operator < (const Rational& p_other);

	bool operator == (const Rational& p_other);

	bool operator != (const Rational& p_other);

	bool operator >= (const Rational& p_other);

	bool operator <= (const Rational& p_other);

	friend std::istream& operator >> (std::istream& is, Rational& p_in);

	friend std::ostream& operator << (std::ostream& os, const Rational& p_out);

};

