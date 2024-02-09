#pragma once
#include "Array.h"

class String : public Array {
private:

public:

	String() = default;

	explicit String(int size);

	bool sum(const Array& p_other, Array* result) override;

	friend short SizeOfString(const String& p_other);

	friend short SearchSubstring(const String& p_main, const String& p_substring);

	friend String DeleteSubstring(const String& p_main, const String& p_substring);

	friend String Input(const String& p_main, const String& p_substring, short index);

	friend String Unite(const String& p_main, const String& p_other);

	friend std::istream& operator >> (std::istream& is, String& p_in);

	friend std::ostream& operator << (std::ostream& os, const String& p_out);

};