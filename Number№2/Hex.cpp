#include "Hex.h"

short Hex::ReadHex(unsigned char number) const {
	if (static_cast<char>(number) > 47 && static_cast<char>(number) < 58) {
		char temporary[1];
		temporary[0] = static_cast<char>(number);
		return atoi(temporary);
	}
	if (static_cast<char>(number) == 65) {
		return 10;
	}
	if (static_cast<char>(number) == 66) {
		return 11;
	}
	if (static_cast<char>(number) == 67) {
		return 12;
	}
	if (static_cast<char>(number) == 68) {
		return 13;
	}
	if (static_cast<char>(number) == 69) {
		return 14;
	}
	if (static_cast<char>(number) == 70) {
		return 15;
	}
}

unsigned char Hex::WriteHex(int number) {
	if (number >= 0 && number <= 9) {
		return static_cast<unsigned char>(48 + number);
	}
	if (number == 10) {
		return 'A';
	}
	if (number == 11) {
		return 'B';
	}
	if (number == 12) {
		return 'C';
	}
	if (number == 13) {
		return 'D';
	}
	if (number == 14) {
		return 'E';
	}
	if (number == 15) {
		return 'F';
	}
}

//Hex::Hex() = default;

Hex::Hex(int size) {
	if (size >= 100) {
		std::cout << "Error, too large size" << std::endl;
	}
	m_maxsize = size;
	m_elements = new unsigned char[size];
	for (int i = 0; i < m_maxsize; i++) {
		m_elements[i] = WriteHex(0);
	}
}

bool Hex::sum(const Array& p_other, Array* result) {
	const Hex& other = dynamic_cast <const Hex&>(p_other);
	Hex* temp = dynamic_cast <Hex*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp + other;
	return true;
}

Hex& Hex::operator ++ () {
	bool flag = true;
	int counter = 0;
	while (flag && counter <= SizeofArray(*this)) {
		int resultnumber = ReadHex((*this)[counter]) + 1;
		if (resultnumber == 16) {
			(*this)[counter] = WriteHex(resultnumber - 16);
		}
		else {
			(*this)[counter] = WriteHex(resultnumber);
			flag = false;
		}
		counter++;
	}
	if (counter > SizeofArray(*this)) {
		Hex temporary(*this);
		m_elements = new unsigned char[++m_maxsize];
		for (int i = 0; i < SizeofArray(temporary); i++) {
			(*this)[i] = temporary[i];
		}
		(*this)[SizeofArray(temporary)] = WriteHex(1);
	}
	return *this;
}

Hex Hex::operator ++ (int value) {
	Hex temp(*this);
	++* this;
	return temp;
}

Hex& Hex::operator -- () {
	bool flag = true;
	int counter = 0;
	while (flag) {
		int resultnumber = ReadHex((*this)[counter]) - 1;
		if (resultnumber < 0) {
			(*this)[counter] = WriteHex(resultnumber + 16);
		}
		else {
			(*this)[counter] = WriteHex(resultnumber);
			flag = false;
		}
		counter++;
	}
	while ((*this)[SizeofArray(*this) - 1] == 0) {
		Hex temporary(*this);
		this->m_elements = new unsigned char[--m_maxsize];
		for (int i = 0; i < SizeofArray(*this); i++) {
			(*this)[i] = temporary[i];
		}
	}
	return *this;
}

Hex Hex::operator -- (int value) {
	Hex temp(*this);
	--* this;
	return temp;
}

Hex Hex::operator + (const Hex& p_other) {
	int minsize;
	int maxsize;
	if (SizeofArray(*this) < SizeofArray(p_other)) {
		minsize = SizeofArray(*this);
		maxsize = SizeofArray(p_other);
	}
	else {
		minsize = SizeofArray(p_other);
		maxsize = SizeofArray(*this);
	}
	int temp = 0;
	Hex result(maxsize);
	for (int i = 0; i < minsize; i++) {
		int resultnumber = ReadHex((*this)[i]) + ReadHex(p_other[i]) + temp;
		if (resultnumber >= 16) {
			result[i] = WriteHex(resultnumber - 16);
			temp = 1;
		}
		else {
			result[i] = WriteHex(resultnumber);
			temp = 0;
		}
	}
	if (SizeofArray(*this) < SizeofArray(p_other)) {
		for (short i = minsize; i < SizeofArray(p_other); i++) {
			int resultnumber = ReadHex(p_other[i]) + temp;
			if (resultnumber >= 16) {
				result[i] = WriteHex(resultnumber - 16);
				temp = 1;
			}
			else {
				result[i] = WriteHex(resultnumber);
				temp = 0;
			}
		}
	}
	else {
		for (short i = minsize; i < SizeofArray(*this); i++) {
			int resultnumber = ReadHex((*this)[i]) + temp;
			if (resultnumber >= 16) {
				result[i] = WriteHex(resultnumber - 16);
				temp = 1;
			}
			else {
				result[i] = WriteHex(resultnumber);
				temp = 0;
			}
		}
	}
	if (temp == 1) {
		Hex temporary(result);
		result.m_elements = new unsigned char[++result.m_maxsize];
		for (int i = 0; i < temporary.m_maxsize; i++) {
			result[i] = temporary[i];
		}
		result[SizeofArray(temporary)] = WriteHex(1);
	}
	return result;
}

Hex& Hex::operator += (const Hex& p_other) {
	*this = *this + p_other;
	return *this;
}

Hex Hex::operator - (const Hex& p_other) {
	if (*this >= p_other) {
		int temp = 0;
		Hex result(*this);
		for (int i = 0; i < SizeofArray(p_other); i++) {
			int resultnumber = ReadHex((*this)[i]) - ReadHex(p_other[i]) - temp;
			if (resultnumber < 0) {
				result[i] = WriteHex(resultnumber + 16);
				temp = 1;
			}
			else {
				result[i] = WriteHex(resultnumber);
				temp = 0;
			}
		}
		int counter = 0;
		while (temp == 1) {
			int resultnumber = ReadHex((*this)[SizeofArray(p_other) + counter]) - temp;
			if (resultnumber < 0) {
				result[SizeofArray(p_other) + counter] = WriteHex(resultnumber + 16);
				temp = 1;
			}
			else {
				result[SizeofArray(p_other) + counter] = WriteHex(resultnumber);
				temp = 0;
			}
			counter++;
		}
		while (result[SizeofArray(result) - 1] == WriteHex(0)) {
			Hex temporary(result);
			result.m_elements = new unsigned char[--result.m_maxsize];
			for (int i = 0; i < SizeofArray(result); i++) {
				result[i] = temporary[i];
			}
		}
		return result;
	}
	std::cout << "Error, the reduced is less than the subtracted" << std::endl;
	return Hex(1);
}

Hex& Hex::operator -= (const Hex& p_other) {
	*this = *this - p_other;
	return *this;
}

Hex Hex::operator * (const Hex& p_other) {
	if ((SizeofArray(p_other) == 1 && p_other[0] == WriteHex(0)) || (SizeofArray(*this) == 1 && (*this)[0] == WriteHex(0))) {
		return Hex(1);
	}
	int temp1 = 0;
	int temp2 = 0;
	Hex result(SizeofArray(*this) + SizeofArray(p_other));
	for (int i = 0; i < SizeofArray(result); i++) {
		result[i] = WriteHex(0);
	}
	int flag = 0;
	for (int i = 0; i < SizeofArray(p_other); i++) {
		temp1 = 0;
		for (int j = 0; j < SizeofArray(*this); j++) {
			int resultnumber = ReadHex((*this)[j]) * ReadHex(p_other[i]) + temp1;
			if ((i + j) == (flag + 1)) {
				resultnumber += temp2;
				temp2 = 0;
				flag = 0;
			}
			temp1 = 0;
			while ((resultnumber + ReadHex(result[j + i])) >= 16) {
				resultnumber -= 16;
				temp1++;
			}
			result[j + i] = WriteHex(resultnumber + ReadHex(result[j + i]));
			if (j == SizeofArray(*this) - 1) {
				temp2 = temp1;
				flag = i + j;
			}
		}
	}
	if (temp1 != 0) {
		result[SizeofArray(result) - 1] = WriteHex(temp1);
	}
	while (result[SizeofArray(result) - 1] == WriteHex(0)) {
		Hex temporary(result);
		result.m_elements = new unsigned char[--result.m_maxsize];
		for (int i = 0; i < SizeofArray(result); i++) {
			result[i] = temporary[i];
		}
	}
	return result;
}

Hex& Hex::operator *= (const Hex& p_other) {
	*this = *this * p_other;
	return *this;
}

Hex Hex::operator / (const Hex& p_other) {
	if (SizeofArray(p_other) == 1 && p_other[0] == WriteHex(0)) {
		std::cout << "Error, division by 0" << std::endl;
		return Hex(1);
	}
	if (*this < p_other) {
		return Hex(1);
	}
	if (SizeofArray(*this) == SizeofArray(p_other)) {
		int counter = 0;
		Hex temporary(*this);
		while (temporary >= p_other) {
			temporary -= p_other;
			counter++;
		}
		Hex result(1);
		result[0] = WriteHex(counter);
		return result;
	}
	Hex result(SizeofArray(*this) - SizeofArray(p_other) + 1);
	Hex temporarythis(*this);
	for (int i = (SizeofArray(*this) - SizeofArray(p_other)); i >= 0; i--) {
		Hex temporaryother(SizeofArray(p_other) + i);
		for (int j = 0; j < i; j++) {
			temporaryother[j] = 0;
		}
		for (int j = i; j < SizeofArray(temporaryother); j++) {
			temporaryother[j] = p_other[j - i];
		}
		int counter = 0;
		while (temporarythis >= temporaryother) {
			temporarythis -= temporaryother;
			counter++;
		}
		result[i] = WriteHex(counter);
	}
	while (result[SizeofArray(result) - 1] == WriteHex(0)) {
		Hex temporary(result);
		result.m_elements = new unsigned char[--result.m_maxsize];
		for (int i = 0; i < SizeofArray(result); i++) {
			result[i] = temporary[i];
		}
	}
	return result;
}

Hex& Hex::operator /= (const Hex& p_other) {
	*this = *this / p_other;
	return *this;
}

bool Hex::operator > (const Hex& p_other) const {
	if (SizeofArray(*this) > SizeofArray(p_other)) {
		return true;
	}
	if (SizeofArray(*this) < SizeofArray(p_other)) {
		return false;
	}
	for (int i = SizeofArray(p_other) - 1; i >= 0; i--) {
		if (ReadHex((*this)[i]) > ReadHex(p_other[i])) {
			return true;
		}
		if (ReadHex((*this)[i]) < ReadHex(p_other[i])) {
			return false;
		}
	}
	return false;
}

bool Hex::operator < (const Hex& p_other) const {
	return (p_other > *this);
}

bool Hex::operator != (const Hex& p_other) const {
	return !(*this == p_other);
}

bool Hex::operator == (const Hex& p_other) const {
	if (SizeofArray(*this) != SizeofArray(p_other)) {
		return false;
	}
	for (int i = SizeofArray(p_other) - 1; i >= 0; i--) {
		if ((*this)[i] != p_other[i]) {
			return false;
		}
	}
	return true;
}

bool Hex::operator >= (const Hex& p_other) const {
	return !(*this < p_other);
}

bool Hex::operator <= (const Hex& p_other) const {
	return !(*this > p_other);
}

std::istream& operator >> (std::istream& is, Hex& p_in) {
	Array input;
	is >> input;
	p_in.m_maxsize = SizeofArray(input);
	delete[] p_in.m_elements;
	p_in.m_elements = new unsigned char[p_in.m_maxsize];
	unsigned char* temp = new unsigned char[p_in.m_maxsize];
	for (short i = 0; i < p_in.m_maxsize; i++) {
		temp[i] = input[i];
	}
	for (short i = 0; i < p_in.m_maxsize; i++) {
		p_in[i] = temp[p_in.m_maxsize - i - 1];
	}
	delete[] temp;
	return is;
}

std::ostream& operator << (std::ostream& os, const Hex& p_out) {
	Array temporary(p_out);
	unsigned char* temp = new unsigned char[p_out.m_maxsize];
	for (short i = 0; i < p_out.m_maxsize; i++) {
		temp[i] = p_out[i];
	}
	for (short i = 0; i < p_out.m_maxsize; i++) {
		temporary[i] = temp[p_out.m_maxsize - i - 1];
	}
	delete[] temp;
	os << temporary;
	return os;

}