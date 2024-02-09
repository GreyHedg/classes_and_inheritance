#include "Array.h"

Array::Array(int size) {
	m_maxsize = size;
	m_elements = new unsigned char[m_maxsize];
}

Array::Array(const Array& p_other) {
	m_maxsize = p_other.m_maxsize;
	m_elements = new unsigned char[m_maxsize];
	for (short i = 0; i < m_maxsize; i++) {
		m_elements[i] = p_other.m_elements[i];
	}
}

Array::~Array() {
	delete[] m_elements;
}

Array& Array::operator = (const Array& p_other) {
	if (this == &p_other) {
		return *this;
	}
	if (m_maxsize != p_other.m_maxsize) {
		delete[] m_elements;
		m_maxsize = p_other.m_maxsize;
		m_elements = new unsigned char[m_maxsize];
	}
	for (short i = 0; i < m_maxsize; i++) {
		m_elements[i] = p_other.m_elements[i];
	}
	return *this;
}

unsigned char& Array::operator[] (int index) {
	return m_elements[index];
}

unsigned char Array::operator[] (int index) const {
	return m_elements[index];
}

short SizeofArray(const Array& p_other) {
	return p_other.m_maxsize;
}

bool Array::sum(const Array& p_other, Array* result) {
	if ((p_other.m_maxsize + m_maxsize) == result->m_maxsize) {
		delete[] result->m_elements;
		result->m_maxsize = p_other.m_maxsize + m_maxsize;
		result->m_elements = new unsigned char[result->m_maxsize];
	}
	for (short i = 0; i < temp.m_maxsize; i++) {
		(*result)[i] = (*this)[i];
	}
	for (short i = 0; i < p_other.m_maxsize; i++) {
		(*result)[i + m_maxsize] = p_other[i];
	}
}

std::istream& operator >> (std::istream& is, Array& p_in) {
	char temp[256];
	gets_s(temp);
	short counter = 0;
	while (temp[counter]) {
		counter++;
	}
	if (p_in.m_elements) {
		delete[] p_in.m_elements;
	}
	p_in.m_elements = new unsigned char[counter];
	for (short i = 0; i < counter; i++) {
		p_in.m_elements[i] = temp[i];
	}
	p_in.m_maxsize = counter;
	return is;
}

std::ostream& operator << (std::ostream& os, const Array& p_out) {
	for (short i = 0; i < p_out.m_maxsize; i++) {
		os << p_out.m_elements[i];
	}
	return os;
}

