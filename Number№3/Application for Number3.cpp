#include "Application for Number3.h"

void ApplicationNumber3::menuforNumber3() {
	short key = 0;
	ApplicationNumber3 a;
	while (true) {
		Pair* firstelement;
		Pair* secondelement;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "==================================Menu for Number 1===================================" << std::endl;
		std::cout << "Enter 1 to test Fraction" << std::endl;
		std::cout << "Enter 2 to test FazzyNumber" << std::endl;
		std::cout << "Enter 3 return program menu" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		switch (key) {
		case (1): {
			a.menuforFraction(firstelement, secondelement);
			break;
		}
		case(2): {
			a.menuforFazzyNumber(firstelement, secondelement);
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

void ApplicationNumber3::menuforFraction(Pair* firstelement, Pair* secondelement) {
	short key = 0;
	firstelement = new Fraction;
	secondelement = new Fraction;
	Fraction* firstnumber = dynamic_cast <Fraction*> (firstelement);
	Fraction* secondnumber = dynamic_cast <Fraction*> (secondelement);
	while (true) {
		std::cout << "======================================================================================" << std::endl;
		std::cout << "===================================Class Fraction=====================================" << std::endl;
		std::cout << "Enter 1 to test addition" << std::endl;
		std::cout << "Enter 2 to test subtraction" << std::endl;
		std::cout << "Enter 3 to test multiplication" << std::endl;
		std::cout << "Enter 4 to test division" << std::endl;
		std::cout << "Enter 5 to test equality" << std::endl;
		std::cout << "Enter 6 to test Fraction version of Pair addition" << std::endl;
		std::cout << "Enter 7 to test Fraction version of Pair subtraction" << std::endl;
		std::cout << "Enter 8 to test Fraction version of Pair multiplication" << std::endl;
		std::cout << "Enter 9 to test Fraction version of Pair division" << std::endl;
		std::cout << "Enter 10 to return menu for Number 3" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		switch (key) {
		case (1): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " + " << *secondnumber << " = " << *firstnumber + *secondnumber << std::endl;
			break;
		}
		case(2): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " - " << *secondnumber << " = " << *firstnumber - *secondnumber << std::endl;
			break;
		}
		case(3): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " * " << *secondnumber << " = " << *firstnumber * *secondnumber << std::endl;
			break;
		}
		case(4): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " / " << *secondnumber << " = " << *firstnumber / *secondnumber << std::endl;
			break;
		}
		case(5): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			if (*firstnumber == *secondnumber) {
				std::cout << *firstnumber << " = " << *secondnumber << std::endl;
			}
			else {
				if (*firstnumber > *secondnumber) {
					std::cout << *firstnumber << " > " << *secondnumber << std::endl;
				}
				else {
					std::cout << *firstnumber << " < " << *secondnumber << std::endl;
				}
			}
			break;
		}
		case(6): {
			Pair* result = new Fraction;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (secondelement);
			firstelement->sum(*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <Fraction*> (result) << std::endl;
			delete result;
			break;
		}
		case(7):{
			Pair* result = new Fraction;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (secondelement);
			firstelement->differ(*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <Fraction*> (result) << std::endl;
			delete result;
			break;
		}
		case(8):{
			Pair* result = new Fraction;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (secondelement);
			firstelement->mult(*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <Fraction*> (result) << std::endl;
			delete result;
			break;
		}
		case(9):{
			Pair* result = new Fraction;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <Fraction*> (secondelement);
			firstelement->div(*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <Fraction*> (result) << std::endl;
			delete result;
			break;
		}
		case(10): {
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 10) {
			break;
		}
	}
	delete firstelement;
	delete secondelement;
}

void ApplicationNumber3::menuforFazzyNumber(Pair* firstelement, Pair* secondelement) {
	short key = 0;
	firstelement = new FazzyNumber;
	secondelement = new FazzyNumber;
	FazzyNumber* firstnumber = dynamic_cast <FazzyNumber*> (firstelement);
	FazzyNumber* secondnumber = dynamic_cast <FazzyNumber*> (secondelement);
	while (true) {
		std::cout << "======================================================================================" << std::endl;
		std::cout << "=================================Class FazzyNumber====================================" << std::endl;
		std::cout << "Enter 1 to test addition" << std::endl;
		std::cout << "Enter 2 to test subtraction" << std::endl;
		std::cout << "Enter 3 to test multiplication" << std::endl;
		std::cout << "Enter 4 to test division" << std::endl;
		std::cout << "Enter 5 to find reversing number" << std::endl; 
		std::cout << "Enter 6 to test FazzyNumber version of Pair addition" << std::endl;
		std::cout << "Enter 7 to test FazzyNumber version of Pair subtraction" << std::endl;
		std::cout << "Enter 8 to test FazzyNumber version of Pair multiplication" << std::endl;
		std::cout << "Enter 9 to test FazzyNumber version of Pair division" << std::endl;
		std::cout << "Enter 10 to return menu for Number 3" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		switch (key) {
		case (1): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " + " << *secondnumber << " = " << *firstnumber + *secondnumber << std::endl;
			break;
		}
		case(2): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " - " << *secondnumber << " = " << *firstnumber - *secondnumber << std::endl;
			break;
		}
		case(3): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " * " << *secondnumber << " = " << *firstnumber * *secondnumber << std::endl;
			break;
		}
		case(4): {
			std::cout << "Enter first number" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Enter second number" << std::endl;
			std::cin >> *secondnumber;
			std::cout << "Result: " << std::endl;
			std::cout << *firstnumber << " / " << *secondnumber << " = " << *firstnumber / *secondnumber << std::endl;
			break;
		}
		case(5): {
			std::cout << "Enter Fazzynumber" << std::endl;
			std::cin >> *firstnumber;
			std::cout << "Result: " << std::endl << reverse(*firstnumber) << std::endl;
			break;
		}
		case(6): {
			Pair* result = new FazzyNumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (secondelement);
			firstelement->sum(*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <FazzyNumber*> (result) << std::endl;
			delete result;
			break;
		}
		case(7): {
			Pair* result = new FazzyNumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (secondelement);
			firstelement->differ(*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <FazzyNumber*> (result) << std::endl;
			delete result;
			break;
		}
		case(8): {
			Pair* result = new FazzyNumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (secondelement);
			firstelement->mult (*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <FazzyNumber*> (result) << std::endl;
			delete result;
			break;
		}
		case(9): {
			Pair* result = new FazzyNumber;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <FazzyNumber*> (secondelement);
			firstelement->div(*secondelement, result);
			std::cout << "Result:" << std::endl << *dynamic_cast <FazzyNumber*> (result) << std::endl;
			delete result;
			break;
		}
		case(10): {
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 10) {
			break;
		}
	}
	delete firstelement;
	delete secondelement;
}