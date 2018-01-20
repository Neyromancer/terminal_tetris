// structL.cpp

#include "structL.hpp"

#include <iostream>

StructL::StructL( size_t pos, size_t x, size_t y )
	: Struct( pos, x, y ) {
	setPos();
}

void StructL::setPos() {
	switch( getPosition() ) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
}

const std::array< std::array< size_t, 5 >, 5 > &StructL::getPos() const {
	return element;
}
/*
void StructL::setWidth() {
	auto w{ 0 };
	std::cout << "structL" << std::endl;
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
			std::cout << "tmp_w is " << tmp << std::endl;
			std::cout << "jt w is " << *jt << std::endl;
		}
	}
	std::cout << "w is " << w << std::endl;
	width = w;
}

void StructL::setHeight() {
	auto h{ 0 };
	for ( auto it = getPos().cbegin(); it != getPos().cend(); ++it ) {
		auto tmp{ 0 };
		auto isNmbMt{ false };
		for ( auto jt = it->cbegin(); jt != it->cend(); ++jt ) {
			if ( 1 == *jt && !isNmbMt ) {
				++tmp;
				isNmbMt = true;
			}
			std::cout << "jt h is " << *jt << std::endl;
			std::cout << "tmp h is " << tmp << std::endl;
		}
		if ( tmp > h )
			h = tmp;
	}
	height = h;
}
*/
void StructL::setFrstPos() {
	Struct::element = { { { 1, 1, 1, 0, 0 },
      			      { 1, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
    			      { 0, 0, 0, 0, 0 },
    			    } };
}

void StructL::setScndPos() {
	Struct::element = { { { 1, 0, 0, 0, 0 },
     			      { 1, 0, 0, 0, 0 },
      			      { 1, 1, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
    							 	  			   } };
}

void StructL::setThrdPos() {
	Struct::element = { { { 0, 0, 1, 0, 0 },
     			      { 1, 1, 1, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
     			      { 0, 0, 0, 0, 0 },
     			    } };
}

void StructL::setFrthPos() {
	Struct::element = { { { 0, 1, 1, 0, 0 },
      			      { 0, 0, 1, 0, 0 },
       			      { 0, 0, 1, 0, 0 },
       			      { 0, 0, 0, 0, 0 },
      			      { 0, 0, 0, 0, 0 },
     			    } };
}
