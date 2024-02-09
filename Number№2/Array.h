#pragma once
#include <iostream>

class Array {
public:

	unsigned char* m_elements;
	short m_maxsize;

public:

	Array() = default;
	
	explicit Array(int size);

	Array(const Array& p_other);

	virtual ~Array();

	Array& operator = (const Array& p_other);

	unsigned char& operator [] (int index);

	unsigned char operator [] (int index) const;

	friend short SizeofArray(const Array& p_other);

	virtual bool sum (const Array& p_other, Array* result);

	friend std::istream& operator >> (std::istream& is, Array& p_in);

	friend std::ostream& operator << (std::ostream& os, const Array& p_out);

};



