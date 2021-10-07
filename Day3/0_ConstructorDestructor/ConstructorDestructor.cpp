#include <iostream>
#include "Cat.h"

int main() {
	std::cout << "Starting program ..." << std::endl;

	{
		Cat bob;
		bob.speak();
	}
	
	Cat miss(true);
	miss.speak();

	Cat mad(false);
	mad.speak();

	std::cout << "Ending program ..." << std::endl;
	return 0;
}

