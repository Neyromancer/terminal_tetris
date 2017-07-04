#include <iostream>
#include "./headers/structZ.hpp"

int main( int argc, char **argv ) {
	size_t n1 = 1;
	size_t n2 = 1;
	size_t n3 = 1;
	StructZ *structZ = new StructZ( n1, n2, n3 );
	for ( auto it = structZ->scndPos().begin(); it != structZ->frstPos().end(); ++it ) {
		for ( auto jt = it->begin(); jt != it->end(); ++jt ) {		
			std::cout << *jt << " ";
		}
			std::cout << std::endl;
	}

	return 0;
}
