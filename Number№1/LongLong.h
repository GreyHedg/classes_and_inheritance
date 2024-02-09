#pragma once
#include <iostream>

class LongLong {
private:

	unsigned long m_mainpart;
	unsigned long m_secondarypart;
	bool m_posit;

protected:

	friend unsigned long positten(int number);

public:


	LongLong() = default;

	explicit LongLong(const long number);

	explicit LongLong(const unsigned long number);

	LongLong operator - () const;

	LongLong& operator ++ ();

	LongLong operator ++ (int value);

	LongLong& operator -- ();

	LongLong operator -- (int value);

	LongLong operator + (const LongLong& p_other) const;

	LongLong& operator += (const LongLong& p_other);

	LongLong operator - (const LongLong& p_other) const;

	LongLong& operator -= (const LongLong& p_other);

	LongLong operator * (const LongLong& p_other) const;

	LongLong& operator *= (const LongLong& p_other);

	LongLong operator / (const LongLong& p_other) const;

	LongLong& operator /= (const LongLong& p_other);

	LongLong operator % (const LongLong& p_other) const;

	bool operator > (const LongLong& p_other) const;

	bool operator < (const LongLong& p_other) const;

	bool operator == (const LongLong& p_other) const;

	bool operator != (const LongLong& p_other) const;

	bool operator >= (const LongLong& p_other) const;

	bool operator <= (const LongLong& p_other) const;

	friend std::istream& operator >> (std::istream& is, LongLong& p_in);

	friend std::ostream& operator << (std::ostream& os, const LongLong& p_out);

};

