#include "FazzyNumber.h"

FazzyNumber::FazzyNumber(double first, double second, double third) {
	firstnumber = first;
	secondnumber = second;
	upperbound = third;
}

bool FazzyNumber::sum(const Pair& p_other, Pair* result) {
	const FazzyNumber& other = dynamic_cast <const FazzyNumber&>(p_other);
	FazzyNumber* temp = dynamic_cast <FazzyNumber*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp + other;
	return true;
}

bool FazzyNumber::differ(const Pair& p_other, Pair* result) {
	const FazzyNumber& other = dynamic_cast <const FazzyNumber&>(p_other);
	FazzyNumber* temp = dynamic_cast <FazzyNumber*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp - other;
	return true;
}

bool FazzyNumber::mult(const Pair& p_other, Pair* result) {
	const FazzyNumber& other = dynamic_cast <const FazzyNumber&>(p_other);
	FazzyNumber* temp = dynamic_cast <FazzyNumber*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp * other;
	return true;
}

bool FazzyNumber::div(const Pair& p_other, Pair* result) {
	const FazzyNumber& other = dynamic_cast <const FazzyNumber&>(p_other);
	FazzyNumber* temp = dynamic_cast <FazzyNumber*>(this);
	if (!temp) {
		return false;
	}
	*result = *temp / other;
	return true;
}

FazzyNumber FazzyNumber::operator + (const FazzyNumber& p_other) {
	FazzyNumber result(firstnumber + p_other.firstnumber, secondnumber + p_other.secondnumber, upperbound + p_other.upperbound);
	return result;
}

FazzyNumber FazzyNumber::operator - (const FazzyNumber& p_other) {
	FazzyNumber result(firstnumber + p_other.firstnumber - 2 * p_other.secondnumber, secondnumber - p_other.secondnumber, upperbound + p_other.upperbound - 2 * p_other.secondnumber);
	return result;
}

FazzyNumber FazzyNumber::operator * (const FazzyNumber& p_other) {
	FazzyNumber result(firstnumber * p_other.firstnumber, secondnumber * p_other.secondnumber, upperbound * p_other.upperbound);
	return result;
}

FazzyNumber FazzyNumber::operator / (const FazzyNumber& p_other) {
	if (p_other.secondnumber <= 0) {
		std::cout << "Error" << std::endl;
	}
	FazzyNumber result(firstnumber / p_other.upperbound, secondnumber / p_other.secondnumber, upperbound / p_other.firstnumber);
	return result;
}

FazzyNumber reverse(const FazzyNumber& p_other) {
	if (p_other.secondnumber <= 0) {
		std::cout << "Error" << std::endl;
	}
	FazzyNumber result(1 / p_other.upperbound, 1 / p_other.secondnumber, 1 / p_other.firstnumber);
	return result;
}

std::istream& operator >> (std::istream& is, FazzyNumber& p_in) {
	char symbol;
	is >> symbol;
	is >> p_in.firstnumber;
	is >> symbol;
	is >> p_in.secondnumber;
	is >> symbol;
	is >> p_in.upperbound;
	is >> symbol;
	return is;
}

std::ostream& operator << (std::ostream& os, const FazzyNumber& p_out) {
	os << '(' << p_out.firstnumber << ',' << p_out.secondnumber << ',' << p_out.upperbound << ')';
	return os;
}