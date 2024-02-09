#include "LongLong.h"

unsigned long positten(int number) {
	long ten = 1;
	for (int i = 0; i < number; i++) {
		ten *= 10;
	}
	return ten;
}

LongLong::LongLong(const long number) {
	if (number >= 0) {
		m_posit = true;
	}
	else {
		m_posit = false;
	}
	if (abs(number) >= positten(9)) {
		m_secondarypart = abs(number) - positten(9);
		m_mainpart = 1;
		while (m_secondarypart >= positten(9)) {
			m_secondarypart -= positten(9);
			m_mainpart++;
		}
	}
	else {
		m_mainpart = 0;
		m_secondarypart = number;
	}
}

LongLong::LongLong(const unsigned long number) {
	if (number >= positten(9)) {
		m_secondarypart = number - positten(9);
		m_mainpart = 1;
		while (m_secondarypart >= positten(9)) {
			m_secondarypart -= positten(9);
			m_mainpart++;
		}
	}
	else {
		m_mainpart = 0;
		m_secondarypart = number;
	}
	m_posit = true;
}

LongLong LongLong::operator - () const {
	LongLong result(*this);
	if (result.m_posit) {
		result.m_posit = false;
	}
	else {
		result.m_posit = true;
	}
	return result;
}

LongLong& LongLong::operator ++ () {
	LongLong temporary(long(1));
	*this += temporary;
	return *this;
}

LongLong LongLong::operator ++ (int value) {
	LongLong result(*this);
	LongLong temporary(long(1));
	*this += temporary;
	return result;
}

LongLong& LongLong::operator -- () {
	LongLong temporary(long(1));
	*this -= temporary;
	return *this;
}

LongLong LongLong::operator -- (int value) {
	LongLong result(*this);
	LongLong temporary(long(1));
	*this -= temporary;
	return result;
}

LongLong LongLong::operator + (const LongLong& p_other) const {
	int temporary = 0;
	LongLong result(*this);
	if (m_posit == p_other.m_posit) {
		result.m_mainpart += p_other.m_mainpart;
		result.m_posit = m_posit;
	}
	else {
		if (m_posit) {
			if (*this >= -p_other) {
				result.m_mainpart -= p_other.m_mainpart;
				result.m_posit = true;
			}
			else {
				result.m_mainpart = p_other.m_mainpart - result.m_mainpart;
				result.m_posit = false;
			}
		}
		else {
			if (-*this <= p_other) {
				result.m_mainpart = p_other.m_mainpart - result.m_mainpart;
				result.m_posit = true;
			}
			else {
				result.m_mainpart -= p_other.m_mainpart;
				result.m_posit = false;
			}
		}
	}
	temporary = positten(9);
	if (m_posit == p_other.m_posit) {
		result.m_secondarypart = p_other.m_secondarypart + m_secondarypart;
		if (result.m_secondarypart > temporary) {
			result.m_secondarypart -= temporary;
			result.m_mainpart++;
		}
	}
	else {
		if (m_posit) {
			if (result.m_posit) {
				if (result.m_secondarypart >= p_other.m_secondarypart) {
					result.m_secondarypart = result.m_secondarypart  - p_other.m_secondarypart;
				}
				else {
					result.m_secondarypart = temporary + result.m_secondarypart - p_other.m_secondarypart;
					result.m_mainpart--;
				}
			}
			else {
				if (result.m_secondarypart >= p_other.m_secondarypart) {
					result.m_secondarypart = temporary + p_other.m_secondarypart - result.m_secondarypart;
					result.m_mainpart--;
				}
				else {
					result.m_secondarypart = p_other.m_secondarypart - result.m_secondarypart;
				}
			}
		}
		else {
			if (result.m_posit) {
				if (result.m_secondarypart >= p_other.m_secondarypart) {
					result.m_secondarypart = temporary + p_other.m_secondarypart - result.m_secondarypart;
					result.m_mainpart--;
				}
				else {
					result.m_secondarypart = p_other.m_secondarypart - result.m_secondarypart;
				}
			}
			else {
				if (p_other.m_secondarypart < result.m_secondarypart) {
					result.m_secondarypart = result.m_secondarypart - p_other.m_secondarypart;
				}
				else {
					result.m_secondarypart = temporary - p_other.m_secondarypart + result.m_secondarypart;
					result.m_mainpart--;
				}
			}
		}
	}
	return result;
}

LongLong& LongLong::operator += (const LongLong& p_other) {
	*this = *this + p_other;
	return *this;
}

LongLong LongLong::operator - (const LongLong& p_other) const {
	return *this + -p_other;
}

LongLong& LongLong::operator -= (const LongLong& p_other) {
	*this = *this - p_other;
	return *this;
}

LongLong LongLong::operator * (const LongLong& p_other) const {
	LongLong result(long(0));
	short temp1 = 0;
	short* firstnumber = new short[18];
	short* secondnumber = new short[18];
	short* resultnumber = new short[18];
	short firstsize = 0;
	short secondsize = 0;
	for (unsigned long i = 10; i <= positten(9); i *= 10) {
		unsigned long temp = m_secondarypart % i - m_secondarypart % (i / 10);
		temp /= (i / 10);
		firstnumber[firstsize] = short(temp);
		firstsize++;
	}
	for (unsigned long i = 10; i <= positten(9); i *= 10) {
		unsigned long temp = p_other.m_secondarypart % i - p_other.m_secondarypart % (i / 10);
		temp /= (i / 10);
		secondnumber[secondsize] = short(temp);
		secondsize++;
	}
	for (unsigned long i = 10; i <= positten(9); i *= 10) {
		unsigned long temp = m_mainpart % i - m_mainpart % (i / 10);
		temp /= (i / 10);
		firstnumber[firstsize] = short(temp);
		firstsize++;
	}
	for (unsigned long i = 10; i <= positten(9); i *= 10) {
		unsigned long temp = p_other.m_mainpart % i - p_other.m_mainpart % (i / 10);
		temp /= (i / 10);
		secondnumber[secondsize] = short(temp);
		secondsize++;
	}
	for (short i = 0; i < 18; i++) {
		if (firstnumber[i] < 0) {
			firstnumber[i] = 0;
		}
	}
	for (short i = 0; i < 18; i++) {
		if (secondnumber[i] < 0) {
			secondnumber[i] = 0;
		}
	}
	for (short i = 0; i < 18; i++) {
		temp1 = 0;
		for (short j = 0; j < 18; j++) {
			short resultnumb = firstnumber[j] * secondnumber[i] + temp1;
			temp1 = 0;
			if (resultnumber[j + i] < 0) {
				resultnumber[j + i] += 12851;
			}
			while ((resultnumb + resultnumber[j + i]) >= 10) {
				resultnumb -= 10;
				temp1++;
			}
			resultnumber[j + i] = resultnumb + resultnumber[j + i];
		}
	}
	if (m_posit == p_other.m_posit) {
		result.m_posit = true;
	}
	else {
		result.m_posit = false;
	}
	for (short i = 0; i < 9; i++) {
		result.m_secondarypart += resultnumber[i] * positten(i);
	}
	for (short i = 9; i < 18; i++) {
		result.m_mainpart += resultnumber[i] * positten(i - 9);
	}
	delete[] firstnumber;
	delete[] secondnumber;
	delete[] resultnumber;
	return result;
}

LongLong& LongLong::operator *= (const LongLong& p_other) {
	*this = *this * p_other;
	return *this;
}

LongLong LongLong::operator / (const LongLong& p_other) const {
	if (*this < p_other) {
		LongLong result(long(0));
		return result;
	}
	LongLong temporary(*this);
	LongLong result(long(0));
	LongLong other(p_other);
	other.m_posit = true;
	if (*this > positten(9)) {
		for (short i = 17; i >= 9; i--) {
			short counter = 0;
			LongLong del;
			del.m_mainpart = positten(i - 9);
			del.m_secondarypart = 0;
			del.m_posit = true;
			while (temporary >= (del * other)) {
				temporary -= del * other;
				counter++;
			}
			result.m_mainpart += counter * positten(i - 9);

		}
	}
	for (short i = 8; i >= 0; i--) {
		short counter = 0;
		LongLong del;
		del.m_mainpart = 0;
		del.m_secondarypart = positten(i);
		del.m_posit = true;
		while (temporary >= (del * other)) {
			temporary -= del * other;
			counter++;
		}
		result.m_secondarypart += counter * positten(i);
	}
	if (m_posit == p_other.m_posit) {
		result.m_posit = true;
	}
	else {
		result.m_posit = false;
	}
	return result;
}

LongLong& LongLong::operator /= (const LongLong& p_other) {
	*this = *this / p_other;
	return *this;
}

LongLong LongLong::operator % (const LongLong& p_other) const {
	LongLong result(*this);
	result = *this - (*this / p_other) * p_other;
	return result;
}

bool LongLong::operator > (const LongLong& p_other) const {
	if (m_posit && !p_other.m_posit) {
		return true;
	}
	if (m_posit && p_other.m_posit) {
		if (m_mainpart > p_other.m_mainpart) {
			return true;
		}
		if ((m_mainpart == p_other.m_mainpart) && (m_secondarypart > p_other.m_secondarypart)) {
			return true;
		}
	}
	if (!m_posit && !p_other.m_posit) {
		if (m_mainpart < p_other.m_mainpart) {
			return true;
		}
		if ((m_mainpart == p_other.m_mainpart) && (m_secondarypart < p_other.m_secondarypart)) {
			return true;
		}
	}
	return false;
}

bool LongLong::operator < (const LongLong& p_other) const {
	return p_other > *this;
}

bool LongLong::operator == (const LongLong& p_other) const {
	if ((m_mainpart == p_other.m_mainpart) && (m_secondarypart == p_other.m_secondarypart) && (m_posit == p_other.m_posit)) {
		return true;
	}
	return false;
}

bool LongLong::operator != (const LongLong& p_other) const {
	return !(*this==p_other);
}

bool LongLong::operator >= (const LongLong& p_other) const {
	return !(*this < p_other);
}

bool LongLong::operator <= (const LongLong& p_other) const {
	return !(*this > p_other);
}

std::istream& operator >> (std::istream& is, LongLong& p_in) {
	char temp[18];
	gets_s(temp);
	short size = 0;
	while (temp[size]) {
		size++;
	}
	p_in.m_mainpart = 0;
	p_in.m_secondarypart = 0;
	if (temp[0] == '-') {
		p_in.m_posit = false;
	}
	else {
		p_in.m_posit = true;
	}
	for (short i = 0; i < 9; i++) {
		if (size - i < 0) {
			break;
		}
		char temporary[1];
		temporary[0] = temp[size - i - 1];
		p_in.m_secondarypart += atoi(temporary) * positten(i);
	}
	if (size > 9) {
		for (short i = 0; i < size - 9; i++) {
			char temporary[1];
			temporary[0] = temp[size - i - 10];
			p_in.m_mainpart += atoi(temporary) * positten(i);
		}
	}
	return is;
}

std::ostream& operator << (std::ostream& os, const LongLong& p_out) {
	if (!p_out.m_posit) {
		os << '-';
	}
	if (p_out.m_mainpart != 0) {
		os << p_out.m_mainpart;
		short flag = 0;
		for (short i = 9; i >= 0; i--) {
			if (p_out.m_secondarypart % positten(i) - p_out.m_secondarypart % positten(i - 1) != 0) {
				flag = i;
				break;
			}
		}
		for (short i = 9; i > flag; i--) {
			os << 0;
		}
		os << p_out.m_secondarypart;
	}
	else {
		os << p_out.m_secondarypart;
	}
	return os;
}

