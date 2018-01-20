// structJ.cpp
#include "struct.hpp"
#include "structJ.hpp"

#include <iostream>

StructJ::StructJ( size_t pos, size_t x, size_t y )
	: Struct( pos, x, y ) {
	setPos();
}

void StructJ::setPos() {
	switch( getPosition() ) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
}

const std::array< std::array< size_t, 5 >, 5 > &StructJ::getPos() const {
	return element;
}
/*
void StructJ::setWidth() {
	auto w{ 0 };
	std::cout << "struct J" << std::endl;
	for ( auto it = getPos().cbegin(); it != getPos().cend(); ++it ) {
		auto tmp{ 0 };
		auto isNmbMt{ false };
		for ( auto jt = it->cbegin(); jt != it->cend();	++jt ) {
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
		}
	}
	width = w;
}

void StructJ::setHeight() {
	auto h{ 0 };
	for ( auto it = getPos().cbegin(); it != getPos().cend(); ++it ) {
		auto tmp{ 0 };
		auto isNmbMt{ false };
		for ( auto jt = it->cbegin(); jt != it->cend(); ++jt ) {
			if ( 1 == *jt && !isNmbMt ) {
				++tmp;
				isNmbMt = true;
			}
		}
		if ( tmp > h)
			h = tmp;
	}
	height = h;

}
*/
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
