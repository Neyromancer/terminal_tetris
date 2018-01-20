// structT.cpp

#include "structT.hpp"

#include <iostream>

StructT::StructT( size_t pos, size_t x, size_t y ) 		: Struct( pos, x, y ) {
	setPos();
}

void StructT::setPos() {
	switch( getPosition() ) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
}
/*
void StructT::setHeight() {
	std::cout << "StructT" << std::endl;
}

void StructT::setWidth() {
	std::cout << "structT" << std::endl;
}
*/
const std::array< std::array< size_t, 5 >, 5 > &StructT::getPos() const {
	return element;
}

void StructT::setFrstPos() {
	Struct::element = { { { 1, 1, 1, 0, 0 },
			      { 0, 1, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
			    } };
}

void StructT::setScndPos() {
	Struct::element = { { { 1, 0, 0, 0, 0 },
			      { 1, 1, 0, 0, 0 },
			      { 1, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
			    } };
}

void StructT::setThrdPos() {
	Struct::element = { { { 0, 1, 0, 0, 0 },
			      { 1, 1, 1, 0, 0 },
			      { 0, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
			      { 0, 0, 0, 0, 0 },
			    } };
}

void StructT::setFrthPos() {
	Struct::element = { { { 0, 1, 0, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
      			      { 0, 1, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
    			    } };
}
