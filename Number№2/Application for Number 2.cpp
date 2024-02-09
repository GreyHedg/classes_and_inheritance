#include "Application for Number2.h"

void ApplicationNumber2::menuforNumber2() {
	short key = 0;
	ApplicationNumber2 a;
	while (true) {
		Array* firstelement;
		Array* secondelement;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "==================================Menu for Number 2===================================" << std::endl;
		std::cout << "Enter 1 to test Hex" << std::endl;
		std::cout << "Enter 2 to test String" << std::endl;
		std::cout << "Enter 3 return program menu" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		switch (key) {
		case (1): {
			a.menuforHex(firstelement, secondelement);
			break;
		}
		case(2): {
			a.menuforString(firstelement, secondelement);
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

void ApplicationNumber2::menuforHex(Array* firstelement, Array* secondelement) {
	short key = 0;
	firstelement = new Hex;
	secondelement = new Hex;
	Hex* firstnumber = dynamic_cast <Hex*> (firstelement);
	Hex* secondnumber = dynamic_cast <Hex*> (secondelement);
	while (true) {
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================Class Hex=======================================" << std::endl;
		std::cout << "Enter 1 to test addition" << std::endl;
		std::cout << "Enter 2 to test subtraction" << std::endl;
		std::cout << "Enter 3 to test multiplication" << std::endl;
		std::cout << "Enter 4 to test division" << std::endl;
		std::cout << "Enter 5 to test equality" << std::endl;
		std::cout << "Enter 6 to test Hex version of Array addition" << std::endl;
		std::cout << "Enter 7 to return menu for Number 2" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		std::cin.ignore();
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
			Array* result = new Hex;
			std::cout << "Enter first number" << std::endl;
			std::cin >> *dynamic_cast <Hex*> (firstelement);
			std::cout << "Enter second number" << std::endl;
			std::cin >> *dynamic_cast <Hex*> (secondelement);
			firstelement->sum(*secondelement, result);
			std::cout << "Result: " << std::endl;
			std::cout << *dynamic_cast <Hex*> (result) << std::endl;
			delete result;
			break;
		}
		case(7): {
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 7) {
			break;
		}
	}
	delete firstelement;
	delete secondelement;
}

void ApplicationNumber2::menuforString(Array* firstelement, Array* secondelement) {
	short key = 0;
	while (true) {
		std::cout << "Enter String, which you want to test" << std::endl;
		firstelement = new String;
		String* TestString = dynamic_cast <String*> (firstelement);
		secondelement = new String;
		String* Temporary = dynamic_cast <String*> (secondelement);
		std::cin.ignore();
		std::cin >> *TestString;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "====================================Class String======================================" << std::endl;
		std::cout << "Enter 1 to get size of your String" << std::endl;
		std::cout << "Enter 2 to find substring of your String" << std::endl;
		std::cout << "Enter 3 to input substring to your String" << std::endl;
		std::cout << "Enter 4 to unite Strings" << std::endl;
		std::cout << "Enter 5 to delete substring in your String" << std::endl;
		std::cout << "Enter 6 to test String version of Array addition" << std::endl;
		std::cout << "Enter 7 to return menu for Number 2" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		std::cin.ignore();
		switch (key) {
		case (1): {
			std::cout << "Size of your String: " << SizeOfString(*TestString) << std::endl;
			break;
		}
		case(2): {
			std::cout << "Enter substring which you want find" << std::endl;
			std::cin >> *Temporary;
			std::cout << "Index of substring in your String: " << SearchSubstring(*TestString, *Temporary) << std::endl;
			break;
		}
		case(3): {
			std::cout << "Enter substring which you want add" << std::endl;
			std::cin >> *Temporary;
			std::cout << "Enter index of element after which you want add substring" << std::endl;
			int index;
			std::cin >> index;
			String result(Input(*TestString, *Temporary, index));
			std::cout << "Result: " << std::endl << result << std::endl;
			break;
		}
		case(4): {
			std::cout << "Enter second String" << std::endl;
			std::cin >> *Temporary;
			std::cout << "Result: " << std::endl << Unite(*TestString, *Temporary) << std::endl;
			break;
		}
		case(5): {
			std::cout << "Enter substring which you want delete" << std::endl;
			std::cin >> *Temporary;
			std::cout << "Result: " << std::endl << DeleteSubstring(*TestString, *Temporary) << std::endl;
			break;
		}
		case(6): {
			Array* result = new Hex;
			std::cout << "Enter first string" << std::endl;
			std::cin >> *dynamic_cast<String*>(firstelement);
			std::cout << "Enter second string" << std::endl;
			std::cin >> *dynamic_cast<String*>(secondelement);
			firstelement->sum(*secondelement, result);
			std::cout << "Result: " << std::endl;
			std::cout << *dynamic_cast<String*>(result) << std::endl;
			delete result;
			break;
		}
		case(7): {
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 7) {
			break;
		}
	}
	delete firstelement;
	delete secondelement;
}