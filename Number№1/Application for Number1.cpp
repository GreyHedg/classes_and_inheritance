#include "Application for Number1.h"

void ApplicationNumber1::menuforNumber1() {
	short key = 0;
	while (true) {
		ApplicationNumber1 a;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "==================================Menu for Number 1===================================" << std::endl;
		std::cout << "Enter 1 to test LongLong" << std::endl;
		std::cout << "Enter 2 to test Rational" << std::endl;
		std::cout << "Enter 3 return program menu" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		switch (key) {
		case (1): {
			a.menuforLongLong();
			break;
		}
		case(2): {
			a.menuforRational();
			break;
		}
		case(3): {
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 3) {
			break;
		}
	}
}

void ApplicationNumber1::menuforLongLong() {
	short key = 0;
	while (true) {
		std::cout << "======================================================================================" << std::endl;
		std::cout << "===================================Class LongLong=====================================" << std::endl;
		std::cout << "Enter 1 to test addition" << std::endl;
		std::cout << "Enter 2 to test subtraction" << std::endl;
		std::cout << "Enter 3 to test multiplication" << std::endl;
		std::cout << "Enter 4 to test division" << std::endl;
		std::cout << "Enter 5 to test equality" << std::endl;
		std::cout << "Enter 6 to return menu for Number 1" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		std::cin.ignore();
		switch (key) {
		case (1): {
			LongLong firstnumber;
			LongLong secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " + " << secondnumber << " = " << firstnumber + secondnumber << std::endl;
			break;
		}
		case(2): {
			LongLong firstnumber;
			LongLong secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " - " << secondnumber << " = " << firstnumber - secondnumber << std::endl;
			break;
		}
		case(3): {
			LongLong firstnumber;
			LongLong secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " * " << secondnumber << " = " << firstnumber * secondnumber << std::endl;
			break;
		}
		case(4): {
			LongLong firstnumber;
			LongLong secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " / " << secondnumber << " = " << firstnumber / secondnumber << std::endl;
			break;
		}
		case(5): {
			LongLong firstnumber;
			LongLong secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			if (firstnumber == secondnumber) {
				std::cout << firstnumber << " = " << secondnumber << std::endl;
			}
			else {
				if (firstnumber > secondnumber) {
					std::cout << firstnumber << " > " << secondnumber << std::endl;
				}
				else {
					std::cout << firstnumber << " < " << secondnumber << std::endl;
				}
			}
			break;
		}
		case(6): {
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 6) {
			break;
		}
	}
}

void ApplicationNumber1::menuforRational() {
	short key = 0;
	while (true) {
		std::cout << "======================================================================================" << std::endl;
		std::cout << "===================================Class Rational=====================================" << std::endl;
		std::cout << "Enter 1 to test addition" << std::endl;
		std::cout << "Enter 2 to test subtraction" << std::endl;
		std::cout << "Enter 3 to test multiplication" << std::endl;
		std::cout << "Enter 4 to test division" << std::endl;
		std::cout << "Enter 5 to test equality" << std::endl;
		std::cout << "Enter 6 to return menu for Number 1" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		std::cin.ignore();
		switch (key) {
		case (1): {
			Rational firstnumber;
			Rational secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " + " << secondnumber << " = " << firstnumber + secondnumber << std::endl;
			break;
		}
		case(2): {
			Rational firstnumber;
			Rational secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " - " << secondnumber << " = " << firstnumber - secondnumber << std::endl;
			break;
		}
		case(3): {
			Rational firstnumber;
			Rational secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " * " << secondnumber << " = " << firstnumber * secondnumber << std::endl;
			break;
		}
		case(4): {
			Rational firstnumber;
			Rational secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << firstnumber << " / " << secondnumber << " = " << firstnumber / secondnumber << std::endl;
			break;
		}
		case(5): {
			Rational firstnumber;
			Rational secondnumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> secondnumber;
			if (firstnumber == secondnumber) {
				std::cout << firstnumber << " = " << secondnumber << std::endl;
			}
			else {
				if (firstnumber > secondnumber) {
					std::cout << firstnumber << " > " << secondnumber << std::endl;
				}
				else {
					std::cout << firstnumber << " < " << secondnumber << std::endl;
				}
			}
			break;
		}
		case(6): {
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 6) {
			break;
		}
	}
}