#include "String.h"

String::String(int size) {
	m_elements = new unsigned char[size + 1];
	m_elements[0] = size;
}

bool String::sum(const Array& p_other, Array* result) {
	const String& other = dynamic_cast <const String&>(p_other);
	String* temp = dynamic_cast <String*>(this);
	if (!temp) {
		return false;
	}
	*result = Unite(*temp, other);
	return true;
}

short SizeOfString(const String& p_other) {
	return p_other[0];
}

short SearchSubstring(const String& p_main, const String& p_substring) {
	short lengmain = p_main[0];
	short lengsub = p_substring[0];
	for (short i = 1; i <= lengmain - lengsub; i++) {
		bool flag = true;
		for (int j = 1; j <= lengsub; j++) {
			if (p_main[i + j - 1] != p_substring[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return i;
		}
	}
	std::cout << "Not found this substring" << std::endl;
	return -1;
}

String DeleteSubstring(const String& p_main, const String& p_substring) {
	short index = SearchSubstring(p_main, p_substring);
	if (index != -1) {
		short lengmain = p_main[0];
		short lengsub = p_substring[0];
		String result(lengmain - lengsub);
		for (short i = 1; i < index; i++) {
			result[i] = p_main[i];
		}
		for (short i = index + lengsub; i <= lengmain; i++) {
			result[i - lengsub] = p_main[i];
		}
		return result;
	}
}

String Input(const String& p_main, const String& p_substring, short index) {
	if (index > 0 && index < 256) {
		short lengmain = SizeOfString(p_main);
		short lengsub = SizeOfString(p_substring);
		String result(lengmain + lengsub);
		for (short i = 1; i <= index; i++) {
			result[i] = p_main[i];
		}
		for (short i = index + 1; i <= index + lengsub; i++) {
			result[i] = p_substring[i - index];
		}
		for (short i = index + lengsub + 1; i <= lengmain + lengsub; i++) {
			result[i] = p_main[i - lengsub];
		}
		return result;
	}
}

String Unite(const String& p_main, const String& p_other) {
	return Input(p_main, p_other, p_main[0]);
}

std::istream& operator >> (std::istream& is, String& p_in) {
	Array temp;
	is >> temp;
	p_in = String(SizeofArray(temp) + 1);
	p_in[0] = SizeofArray(temp);
	for (short i = 1; i <= p_in[0]; i++) {
		p_in[i] = temp[i - 1];
	}
	return is;
}

std::ostream& operator << (std::ostream& os, const String& p_out) {
	for (short i = 1; i <= p_out[0]; i++) {
		os << p_out[i];
	}
	return os;
}