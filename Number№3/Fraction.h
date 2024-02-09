#pragma once
#include "Pair.h"

class Fraction : public Pair {
private:

	int positten(int stepen);

public:

	Fraction() = default;

	explicit Fraction(double number);

	bool sum(const Pair& p_other, Pair* result) override;

	bool differ(const Pair& p_other, Pair* result) override;

	bool mult(const Pair& p_other, Pair* result) override;

	bool div(const Pair& p_other, Pair* result) override;

	Fraction operator - () const;

	Fraction& operator ++ ();

	Fraction operator ++ (int value);

	Fraction& operator -- ();

	Fraction operator -- (int value);

	Fraction operator + (const Fraction& p_other);

	Fraction operator += (const Fraction& p_other);

	Fraction operator - (const Fraction& p_other);

	Fraction operator -= (const Fraction& p_other);

	Fraction operator * (const Fraction& p_other);

	Fraction operator *= (const Fraction& p_other);

	Fraction operator / (const Fraction& p_other);

	Fraction operator /= (const Fraction& p_other);

	bool operator > (const Fraction& p_other);

	bool operator < (const Fraction& p_other);

	bool operator == (const Fraction& p_other);

	bool operator != (const Fraction& p_other);

	bool operator >= (const Fraction& p_other);

	bool operator <= (const Fraction& p_other);

	friend std::istream& operator >> (std::istream& is, Fraction& p_in);

	friend std::ostream& operator << (std::ostream& os, const Fraction& p_out);

};