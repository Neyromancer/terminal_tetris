// structO.cpp

#include "structO.hpp"

#include <iostream>

StructO::StructO( size_t pos, size_t x, size_t y )
	: Struct( pos, x, y ) {
	setPos();
}

void StructO::setPos() {
	switch( getPosition() ) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
}

const std::array< std::array< size_t, 5 >, 5 > &StructO::getPos() const {
	return element;
}
/*
void StructO::setWidth() {
	auto w{ 0 };
	std::cout << "structO" << std::endl;
	for ( auto it = getPos().cbegin(); it != getPos().cend(); ++it ) {
		auto tmp{ 0 };
		auto isNmbMt{ false };
		for ( auto jt = it->cbegin(); jt != it->cend(); ++jt ) {
			if ( 1 == *jt ) {
				++tmp;
				isNmbMt = true;
			}

			if ( isNmbMt && 0 == *jt ) {
				if ( tmp > w )
					w = tmp;
				tmp = 0;
				isNmbMt = false;
			}
			std::cout << "tmp w is " << tmp << std::endl;
			std::cout << "jt w is " << *jt << std::endl;
		}
	}
	std::cout << "w is " << w << std::endl;
	width = w;
}

void StructO::setHeight() {
	auto h{ 0 };
	for ( auto it = getPos().cbegin(); it != getPos().cend(); ++it ) {
		auto tmp{ 0 };
		auto isNmbMt{ false };
		for ( auto jt = it->cbegin(); jt != it->cend(); ++jt ) {
			if ( 1 == *jt && !isNmbMt ) {
				++tmp;
				isNmbMt == true;
			}
		}
		if ( tmp > h )
			h = tmp;

	}
	std::cout << "h is " << h << std::endl;
	height = h;

}
*/
void StructO::setFrstPos() {
	Struct::element = { { { 1, 1, 0, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
  			    } };
}

void StructO::setScndPos() {
	Struct::element = { { { 1, 1, 0, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
     			    } };
}

void StructO::setThrdPos() {
	Struct::element = { { { 1, 1, 0, 0, 0 },
    			      { 1, 1, 0, 0, 0 },
    			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
   			    } };
}

void StructO::setFrthPos() {
	Struct::element = { { { 1, 1, 0, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
       			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
    			      { 0, 0, 0, 0, 0 },
     			    } };
}
