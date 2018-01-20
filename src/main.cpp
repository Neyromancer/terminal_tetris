// main.cpp

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ctime>

#include "interface.hpp"

int main( int argc, char **argv ) {
	std::shared_ptr< TetrisEngine > tetrisEngine = std::make_shared< TetrisEngine >();
	Interface interface;
	interface.setTetrisEngine( tetrisEngine );
	interface.displayInterface();

	time_t crntT{ time( nullptr ) };
	time_t pstT{ crntT };
	while( true ) {
		if ( ( difftime( pstT, crntT ) ) >= 1 ) {
			crntT = pstT;
			std::cout << std::endl; 
			tetrisEngine->processMainField();
			interface.setTetrisEngine( tetrisEngine );
			interface.displayInterface();
			tetrisEngine->processControlInput();
		}
		pstT = time( nullptr );
	}
/*	try { 
	StructMainField mainField;
	
	std::cout << "main field width: " << mainField.getWidth() << std::endl;
	std::cout << "main field height: " << mainField.getHeight() << std::endl;
	} catch (...) {
		std::cerr << "Wrong input" << std::endl;
	}
*/
	return EXIT_SUCCESS;
}
