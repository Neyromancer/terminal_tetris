// structJ.cpp
#include "../headers/struct.hpp"
#include "../headers/structJ.hpp"

StructJ::StructJ( size_t pos, size_t x, size_t y )
	: Struct( pos, x, y ) {
}

const std::array< std::array< size_t, 5 >, 5 > &StructJ::displayStruct() {
	switch( getPosition() ) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}

	return getPos();
}

const std::array< std::array< size_t, 5 >, 5 > &StructJ::getPos() const {
	return element;
}

void StructJ::setFrstPos() {
	 Struct::element = { { { 1, 1, 1, 0, 0 },
			       { 0, 0, 1, 0, 0 },
			       { 0, 0, 0, 0, 0 },
			       { 0, 0, 0, 0, 0 },
			       { 0, 0, 0, 0, 0 },
			     } };
}

void StructJ::setScndPos() {
	Struct::element = { { { 1, 1, 0, 0, 0 },
			      { 1, 0, 0, 0, 0 },
			      { 1, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
     			    } };
}

void StructJ::setThrdPos() {
	Struct::element = { { { 1, 0, 0, 0, 0 },
			      { 1, 1, 1, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
     			    } };
}

void StructJ::setFrthPos() {
	Struct::element = { { { 0, 0, 1, 0, 0 },
     			      { 0, 0, 1, 0, 0 },
 			      { 0, 1, 1, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
   			      { 0, 0, 0, 0, 0 },
    			    } };
}
