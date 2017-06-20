// main.cpp

#include <cstdlib>
#include <iostream>

//#include "structField.hpp"
#include "structScoreField.hpp"

int main( int argc, char **argv ) {

	try { 
		StructScoreField scoreField( 7, 7, 10 );

		std::cout << "score field width: " << scoreField.getWidth() << std::endl;
		std::cout << "score field height: " << scoreField.getHeight() << std::endl;
		std::cout << "score displayed on the score field " << scoreField.getScore() << std::endl;
	} catch (...) {
		std::cerr << "Wrong input" << std::endl;
	}

	return EXIT_FAILURE;
}
