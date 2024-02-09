#include "Fraction.h"

int Fraction::positten(int stepen) {
	int number = 1;
	for (int i = 0; i < stepen; i++) {
		number *= 10;
	}
	return number;
}

Fraction::Fraction(double number) {
	if (number < 0) {
		m_posit = false;
	}
	else {
		m_posit = true;
	}
	double temporary1 = abs(number);
	int counter = 0;
	firstnumber = 0;
	secondnumber = 0;
	for (short i = 10; i > 0; i--) {
		while (temporary1 > positten(i)) {
			temporary1 -= positten(i);
			firstnumber += positten(i);
		}
	}
	while (temporary1 > 0.999999) {
		--temporary1;
		firstnumber++;
	}
	while (temporary1 != 0) {
		secondnumber *= 10;
		temporary1 *= 10;
		if (temporary1 < 10.000001 && temporary1 > 9.999999) {
			break;
		}
		while (temporary1 > 0.999999) {
			--temporary1;
			secondnumber++;
		}
		counter++;
		if (temporary1 < 0.000001) {
			break;
		}
	}
	m_sizefractional = counter;
	if (secondnumber == 0) {
		m_sizefractional = 1;
	}
}

bool Fraction::sum(const Pair& p_other, Pair* result) {
	const Fraction& other = dynamic_cast <const Fraction&>(p_other);
	Fraction* temp = dynamic_cast <Fraction*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp + other;
	return true;
}

bool Fraction::differ(const Pair& p_other, Pair* result) {
	const Fraction& other = dynamic_cast <const Fraction&>(p_other);
	Fraction* temp = dynamic_cast <Fraction*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp - other;
	return true;
}

bool Fraction::mult(const Pair& p_other, Pair* result) {
	const Fraction& other = dynamic_cast <const Fraction&>(p_other);
	Fraction* temp = dynamic_cast <Fraction*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp * other;
	return true;
}

bool Fraction::div(const Pair& p_other, Pair* result) {
	const Fraction& other = dynamic_cast <const Fraction&>(p_other);
	Fraction* temp = dynamic_cast <Fraction*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp / other;
	return true;
}


Fraction Fraction::operator - () const {
	Fraction result(*this);
	if (result.m_posit) {
		result.m_posit = false;
	}
	else {
		result.m_posit = true;
	}
	return result;
}

Fraction& Fraction::operator ++ () {
	if (firstnumber == 0 && !m_posit) {
		m_posit = true;
		secondnumber = positten(m_sizefractional + 1) - secondnumber;
		return *this;
	}
	++firstnumber;
	return *this;
}

Fraction Fraction::operator ++ (int value) {
	Fraction result(*this);
	if (firstnumber == 0 && !m_posit) {
		m_posit = true;
		secondnumber = positten(m_sizefractional + 1) - secondnumber;
		return result;
	}
	++firstnumber;
	return result;
}

Fraction& Fraction::operator -- () {
	if (firstnumber == 0 && m_posit) {
		m_posit = false;
		secondnumber = positten(m_sizefractional + 1) - secondnumber;
		return *this;
	}
	--firstnumber;
	return *this;
}

Fraction Fraction::operator -- (int value) {
	Fraction result(*this);
	if (firstnumber == 0 && m_posit) {
		m_posit = false;
		secondnumber = positten(m_sizefractional + 1) - secondnumber;
		return *this;
	}
	--this->firstnumber;
	return result;
}

Fraction Fraction::operator + (const Fraction& p_other) {
	Fraction result(*this);
	int temporary(p_other.m_sizefractional);
	if (result.m_sizefractional > p_other.m_sizefractional) {
		temporary = result.m_sizefractional;
	}
	else {
		result.secondnumber *= positten(p_other.m_sizefractional - result.m_sizefractional);
		result.m_sizefractional = p_other.m_sizefractional;
	}
	if (m_posit == p_other.m_posit) {
		result.firstnumber += p_other.firstnumber;
		result.m_posit = m_posit;
	}
	else {
		if (m_posit) {
			if (*this >= -p_other) {
				result.firstnumber -= p_other.firstnumber;
				result.m_posit = true;
			}
			else {
				result.firstnumber = p_other.firstnumber - result.firstnumber;
				result.m_posit = false;
			}
		}
		else {
			if (-*this <= p_other) {
				result.firstnumber = p_other.firstnumber - result.firstnumber;
				result.m_posit = true;
			}
			else {
				result.firstnumber -= p_other.firstnumber;
				result.m_posit = false;
			}
		}
	}
	temporary = positten(temporary);
	if (m_posit == p_other.m_posit) {
		result.secondnumber = p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional) + secondnumber * positten(p_other.m_sizefractional - m_sizefractional);
		if (result.secondnumber > temporary) {
			result.secondnumber -= temporary;
			result.firstnumber++;
		}
	}
	else {
		if (m_posit) {
			if (result.m_posit) {
				if (result.secondnumber >= p_other.secondnumber) {
					result.secondnumber = result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional) - p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional);
				}
				else {
					result.secondnumber = temporary + result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional) - p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional);
					result.firstnumber--;
				}
			}
			else {
				if (result.secondnumber >= p_other.secondnumber) {
					result.secondnumber = temporary + p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional) - result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional);
					result.firstnumber--;
				}
				else {
					result.secondnumber = p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional) - result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional);
				}
			}
		}
		else {
			if (result.m_posit) {
				if (result.secondnumber >= p_other.secondnumber) {
					result.secondnumber = temporary + p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional) - result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional);
					result.firstnumber--;
				}
				else {
					result.secondnumber = p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional) - result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional);
				}
			}
			else {
				if (p_other.secondnumber < result.secondnumber) {
					result.secondnumber = result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional) - p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional);
				}
				else {
					result.secondnumber = temporary - p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional) + result.secondnumber * positten(p_other.m_sizefractional - m_sizefractional);
					result.firstnumber--;
				}
			}
		}
	}
	return result;
}

Fraction Fraction::operator += (const Fraction& p_other) {
	*this = *this + p_other;
	return *this;
}

Fraction Fraction::operator - (const Fraction& p_other) {
	return *this + -p_other;
}

Fraction Fraction::operator -= (const Fraction& p_other) {
	*this = *this - p_other;
	return *this;
}

Fraction Fraction::operator * (const Fraction& p_other) {
	Fraction result(*this);
	double temporary3, temporary4;
	unsigned short temporary = p_other.secondnumber;
	if (result.m_posit == p_other.m_posit) {
		result.m_posit = true;
	}
	else {
		result.m_posit = false;
	}
	result.firstnumber *= p_other.firstnumber;
	result.secondnumber = p_other.secondnumber * result.secondnumber;
	int counter = 0;
	result.m_sizefractional = p_other.m_sizefractional + m_sizefractional;
	if (result.m_sizefractional > 5) {
		for (int i = 4; i < result.m_sizefractional; i++) {
			result.secondnumber /= 10;
		}
		result.m_sizefractional = 4;
	}
	temporary3 = firstnumber * p_other.secondnumber;
	temporary4 = p_other.firstnumber * secondnumber;
	temporary3 /= positten(p_other.m_sizefractional);
	temporary4 /= positten(m_sizefractional);
	temporary3 += temporary4;
	Fraction temp(temporary3);
	if (result < Fraction(0)) {
		result += -temp;
	}
	else {
		result += temp;
	}
	while (result.secondnumber % 10 == 0 && result.m_sizefractional != 1) {
		result.secondnumber /= 10;
		result.m_sizefractional--;
	}
	return result;
}

Fraction Fraction::operator *= (const Fraction& p_other) {
	*this = *this * p_other;
	return *this;
}

Fraction Fraction::operator / (const Fraction& p_other) {
	bool flag;
	if (m_posit == p_other.m_posit) {
		flag = true;
	}
	else {
		flag = false;
	}
	Fraction temporary(*this);
	Fraction tempother(p_other);
	temporary.m_posit = true;
	tempother.m_posit = true;
	if (secondnumber != 0) {
		Fraction ten(10);
		temporary *= ten;
		tempother *= ten;
	}
	for (int i = 0; i < m_sizefractional + 1; i++) {
		Fraction ten(10);
		temporary *= ten;
		tempother *= ten;
	}
	double temp = positten(9);
	Fraction nol(0);
	Fraction result(0);
	for (double i = 0.0001; i < temp; temp /= 10) {
		Fraction ten(temp);
		Fraction other(ten * tempother);
		int counter = 0;
		while (temporary >= other) {
			temporary -= other;
			counter++;
		}
		Fraction del(counter * temp);
		result += del;
		if (temporary == Fraction(0)) {
			break;
		}
	}
	if (!flag) {
		result.m_posit = false;
	}
	return result;
}

Fraction Fraction::operator /= (const Fraction& p_other) {
	*this = *this / p_other;
	return *this;
}

bool Fraction::operator > (const Fraction& p_other) {
	if (m_posit && !p_other.m_posit) {
		return true;
	}
	if (m_posit && p_other.m_posit) {
		if (firstnumber > p_other.firstnumber) {
			return true;
		}
		if ((firstnumber == p_other.firstnumber) && ((secondnumber * positten(p_other.m_sizefractional - m_sizefractional)) > (p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional)))) {
			return true;
		}
	}
	if (!m_posit && !p_other.m_posit) {
		if (firstnumber < p_other.firstnumber) {
			return true;
		}
		if ((firstnumber == p_other.firstnumber) && ((secondnumber * positten(p_other.m_sizefractional - m_sizefractional)) < (p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional)))) {
			return true;
		}
	}
	return false;
}

bool Fraction::operator < (const Fraction& p_other) {
	if (!m_posit && p_other.m_posit) {
		return true;
	}
	if (m_posit && p_other.m_posit) {
		if (firstnumber < p_other.firstnumber) {
			return true;
		}
		if ((firstnumber == p_other.firstnumber) && ((secondnumber * positten(p_other.m_sizefractional - m_sizefractional)) < (p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional)))) {
			return true;
		}
	}
	if (!m_posit && !p_other.m_posit) {
		if (firstnumber > p_other.firstnumber) {
			return true;
		}
		if ((firstnumber == p_other.firstnumber) && ((secondnumber * positten(p_other.m_sizefractional - m_sizefractional)) > (p_other.secondnumber * positten(m_sizefractional - p_other.m_sizefractional)))) {
			return true;
		}
	}
	return false;
}

bool Fraction::operator == (const Fraction& p_other) {
	if ((firstnumber == p_other.firstnumber) && (secondnumber == p_other.secondnumber) && (m_sizefractional == p_other.m_sizefractional) && (m_posit == p_other.m_posit)) {
		return true;
	}
	return false;
}

bool Fraction::operator != (const Fraction& p_other) {
	return !(*this == p_other);
}

bool Fraction::operator >= (const Fraction& p_other) {
	return !(*this < p_other);
}

bool Fraction::operator <= (const Fraction& p_other) {
	return !(*this > p_other);
}

std::istream& operator >> (std::istream& is, Fraction& p_in) {
	double number;
	is >> number;
	Fraction temp(number);
	p_in = temp;
	return is;
}

std::ostream& operator << (std::ostream& os, const Fraction& p_out) {
	if (!p_out.m_posit) {
		os << '-';
	}
	os << p_out.firstnumber << '.';
	unsigned short temp = p_out.secondnumber;
	short counter = 0;
	int ten = 1;
	while (temp / ten != 0) {
		ten *= 10;
		counter++;
	}
	for (short i = 0; i < p_out.m_sizefractional - counter; i++) {
		os << 0;
	}
	os << p_out.secondnumber;
	return os;
}