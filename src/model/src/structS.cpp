// structS.cpp

#include "../headers/structS.hpp"

StructS::StructS( size_t pos, size_t x, size_t y ) 
	: Struct( pos, x, y ) {
}

const std::array< std::array< size_t, 5 >, 5 > &StructS::displayStruct() {
	switch( getPosition() ) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}

	return getPos();
}

const std::array< std::array< size_t, 5 >, 5 > &StructS::getPos() const {
	return element;
}

void StructS::setFrstPos() {
	Struct::element = { { { 0, 1, 1, 0, 0 },
     			      { 1, 1, 0, 0, 0 },
   			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
    			    } };
}

void StructS::setScndPos() {
	Struct::element = { { { 1, 0, 0, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
      			      { 0, 1, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
    			    } };
}

void StructS::setThrdPos() {
	Struct::element = { { { 0, 1, 1, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
    			      { 0, 0, 0, 0, 0 },
     			    } };
}

void StructS::setFrthPos() {
	Struct::element = { { { 1, 0, 0, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
      			      { 0, 1, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			    } };
}
