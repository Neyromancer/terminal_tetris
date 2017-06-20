// main.cpp

#include <cstdlib>
#include <iostream>

#include "view/interface.hpp"
#include "model/structMainField.hpp"

int main( int argc, char **argv ) {
/**/	Interface interface;
	interface.displayInterface();

/*	try { 
	StructMainField mainField;
	
	std::cout << "main field width: " << mainField.getWidth() << std::endl;
	std::cout << "main field height: " << mainField.getHeight() << std::endl;
	} catch (...) {
		std::cerr << "Wrong input" << std::endl;
	}
*/
	return EXIT_FAILURE;
}
