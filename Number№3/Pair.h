#pragma once
#include <iostream>

class Pair {
protected:

	double firstnumber;
	int secondnumber;
	unsigned int m_sizefractional;
	bool m_posit;
	double upperbound;

public:

	Pair() = default;

	virtual bool sum (const Pair& p_other, Pair* result) = 0;

	virtual bool differ (const Pair& p_other, Pair* result) = 0;

	virtual bool mult (const Pair& p_other, Pair* result) = 0;

	virtual bool div (const Pair& p_other, Pair* result) = 0;

	virtual ~Pair();
};
