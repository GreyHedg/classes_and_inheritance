#pragma once
#include "Array.h"

class Hex : public Array {
private:

	short ReadHex(unsigned char number) const;

	unsigned char WriteHex(int number);

public:

	Hex() = default;

	explicit Hex(int size);

	bool sum(const Array& p_other, Array* result) override;

	Hex& operator ++ ();

	Hex operator ++ (int value);

	Hex& operator -- ();

	Hex operator -- (int value);

	Hex operator + (const Hex& p_other);

	Hex& operator += (const Hex& p_other);

	Hex operator - (const Hex& p_other);

	Hex& operator -= (const Hex& p_other);

	Hex operator * (const Hex& p_other);

	Hex& operator *= (const Hex& p_other);

	Hex operator / (const Hex& p_other);

	Hex& operator /= (const Hex& p_other);

	bool operator > (const Hex& p_other) const;

	bool operator < (const Hex& p_other) const;

	bool operator == (const Hex& p_other) const;

	bool operator != (const Hex& p_other) const;

	bool operator >= (const Hex& p_other) const;

	bool operator <= (const Hex& p_other) const;

	friend std::istream& operator >> (std::istream& is, Hex& p_in);

	friend std::ostream& operator << (std::ostream& os, const Hex& p_out);

};