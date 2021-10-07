#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat() {
	std::cout << "Cat created." << std::endl;

	happy = true;
}

Cat::Cat(bool _happy):happy(_happy) {
	if(happy) {
        std::cout << "Happy Cat is created." << std::endl;
	} else {
        std::cout << "Unhappy Cat is created." << std::endl;
	}
}

Cat::~Cat() {
	std::cout << "Cat destroyed." << std::endl;
}

void Cat::speak() {
	if(happy) {
		std::cout << "Meouww!" << std::endl;
	}
	else {
		std::cout << "Tssssssss!" << std::endl;
	}
}

