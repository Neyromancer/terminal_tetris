#include <iostream>
#include "./headers/structZ.hpp"
#include "./headers/structMainField.hpp"

int main( int argc, char **argv ) {
	StructMainField mainField( 18, 30 );
	std::cout << mainField.getWidth();
	std::cout << " " << mainField.getHeight() << std::endl;
/*
	size_t n1 = 1;
	size_t n2 = 1;
	size_t n3 = 1;
	StructZ structZ( n1, n2, n3 );
	structZ.setScndPos();
	for ( auto it = structZ.getPos().begin(); it != structZ.getPos().end(); ++it ) {
		for ( auto jt = it->begin(); jt != it->end(); ++jt ) {		
			std::cout << *jt << " ";
		}
			std::cout << std::endl;
	}
*/
	return 0;
}
