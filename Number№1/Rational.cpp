#include "Rational.h"

unsigned long positten(int number) {
	long ten = 1;
	for (int i = 0; i < number; i++) {
		ten *= 10;
	}
	return ten;
}

Rational::Rational(const LongLong& numer, const LongLong& denomin) : numerator(numer), denominator(denomin) {
	*this = reduce(*this);
}

Rational Rational::reduce(Rational& p_rat) {
	bool flag = true;
	LongLong temp1(p_rat.numerator);
	LongLong temp2(p_rat.denominator);
	LongLong temp3;
	if ((temp1 > LongLong(long(0))) && (temp2 < LongLong(long(0)))) {
		temp2 = -temp2;
		p_rat.denominator = -p_rat.denominator;
		flag = false;
	}
	else {
		if ((temp1 < LongLong(long(0))) && (temp2 > LongLong(long(0)))) {
			temp1 = -temp1;
			p_rat.numerator = -p_rat.numerator;
			flag = false;
		}
		else {
			if ((temp1 < LongLong(long(0))) && (temp2 < LongLong(long(0)))) {
				temp1 = -temp1;
				temp2 = -temp2;
				p_rat.denominator = -p_rat.denominator;
				p_rat.numerator = -p_rat.numerator;
			}
		}
	}
	while (temp2 != LongLong(long(0))) {
		temp3 = temp1 % temp2;
		temp1 = temp2;
		temp2 = temp3;
	}
	p_rat.numerator /= temp1;
	p_rat.denominator /= temp1;
	if (!flag) {
		p_rat.numerator = -p_rat.numerator;
	}
	return p_rat;
}

Rational Rational::operator - () const {
	Rational result(*this);
	result.numerator = -numerator;
	return result;
}

Rational Rational::operator + (const Rational& p_other) {
	Rational result(numerator * p_other.denominator + denominator * p_other.numerator, denominator * p_other.denominator);
	result = reduce(result);
	return result;
}

Rational Rational::operator - (const Rational& p_other) {
	Rational result(numerator * p_other.denominator - denominator * p_other.numerator, denominator * p_other.denominator);
	result = reduce(result);
	return result;
}

Rational Rational::operator * (const Rational& p_other) {
	Rational result(numerator * p_other.numerator, denominator * p_other.denominator);
	result = reduce(result);
	return result;
}

Rational Rational::operator / (const Rational& p_other) {
	Rational result(numerator * p_other.denominator, denominator * p_other.numerator);
	result = reduce(result);
	return result;
}

bool Rational::operator > (const Rational& p_other) {
	Rational temporary = *this - p_other;
	LongLong nol(long(0));
	if (temporary.numerator > nol) {
		return true;
	}
	return false;
}

bool Rational::operator < (const Rational& p_other) {
	Rational temporary = *this - p_other;
	LongLong nol(long(0));
	if (temporary.numerator < nol) {
		return true;
	}
	return false;
}

bool Rational::operator == (const Rational& p_other) {
	if (numerator == p_other.numerator && denominator == p_other.denominator) {
		return true;
	}
	return false;
}

bool Rational::operator != (const Rational& p_other) {
	return !(*this == p_other);
}

bool Rational::operator >= (const Rational& p_other) {
	Rational temporary = *this - p_other;
	return !(*this < p_other);
}

bool Rational::operator <= (const Rational& p_other) {
	return !(*this > p_other);
}

std::istream& operator >> (std::istream& is, Rational& p_in) {
	char temp[37];
	int flag = 0;
	char numer[18];
	char demon[18];
	short counter = 0;
	gets_s(temp);
	while (temp[flag] != '/') {
		flag++;
	}
	for (short i = 0; i < flag; i++) {
		numer[i] = temp[i];
	}
	while (temp[counter + flag + 1]) {
		demon[counter] = temp[counter + flag + 1];
		counter++;
	}
	p_in.numerator = LongLong(long(0));
	p_in.denominator = LongLong(long(0));
	for (short i = 0; i < flag; i++) {
		char temporary[1];
		temporary[0] = numer[flag - i - 1];
		p_in.numerator += LongLong((positten(i) * atoi(temporary)));
	}
	for (short i = 0; i < counter; i++) {
		char temporary[1];
		temporary[0] = demon[counter - i - 1];
		p_in.denominator += LongLong((positten(i) * atoi(temporary)));
	}
	if (p_in.numerator < LongLong(long(0))) {
		p_in.numerator = -p_in.numerator;
	}
	if (p_in.denominator < LongLong(long(0))) {
		p_in.denominator = -p_in.denominator;
	}
	if (numer[0] == '-') {
		p_in.numerator = -p_in.numerator;
	}
	if (demon[0] == '-') {
		p_in.denominator = -p_in.denominator;
	}
	return is;
}

std::ostream& operator << (std::ostream& os, const Rational& p_out) {
	os << p_out.numerator << '/' << p_out.denominator;
	return os;
}