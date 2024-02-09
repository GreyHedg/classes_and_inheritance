#pragma once
#include "Pair.h"

class FazzyNumber : public Pair {
private:

	//double lowerbound;
	//double average;

public:

	FazzyNumber() = default;

	explicit FazzyNumber(double first, double second, double third);

	bool sum(const Pair& p_other, Pair* result) override;

	bool differ(const Pair& p_other, Pair* result) override;

	bool mult(const Pair& p_other, Pair* result) override;

	bool div(const Pair& p_other, Pair* result) override;

	FazzyNumber operator + (const FazzyNumber& p_other);

	FazzyNumber operator - (const FazzyNumber& p_other);

	FazzyNumber operator * (const FazzyNumber& p_other);

	FazzyNumber operator / (const FazzyNumber& p_other);

	friend FazzyNumber reverse(const FazzyNumber& p_other);

	friend std::istream& operator >> (std::istream& is, FazzyNumber& p_in);

	friend std::ostream& operator << (std::ostream& os, const FazzyNumber& p_out);

};