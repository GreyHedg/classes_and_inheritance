#include "Application.h"

void Application::Programmenu() {
	short key = 0;
	while (true) {
		std::cout << "======================================================================================" << std::endl;
		std::cout << "====================================Programm menu=====================================" << std::endl;
		std::cout << "Enter 1 to test classes from Number 1" << std::endl;
		std::cout << "Enter 2 to test classes from Number 2" << std::endl;
		std::cout << "Enter 3 to test classes from Number 3" << std::endl;
		std::cout << "Enter 4 to exit from programm" << std::endl;
		std::cout << "======================================================================================" << std::endl;
		std::cout << "======================================================================================" << std::endl << std::endl << std::endl;
		std::cin >> key;
		switch (key) {
		case (1): {
			ApplicationNumber1 a;
			a.menuforNumber1();
			break;
		}
		case(2): {
			ApplicationNumber2 a;
			a.menuforNumber2();
			break;
		}
		case(3): {
			ApplicationNumber3 a;
			a.menuforNumber3();
			break;
		}
		case(4): {
			std::cout << "Good Bye" << std::endl;
			break;
		}
		default: {
			std::cout << "Error, uncorrect number" << std::endl;
			break;
		}
		}
		if (key == 4) {
			break;
		}
	}
}