// structI.cpp
#include "struct.hpp"
#include "structI.hpp"

#include <iostream>

StructI::StructI( size_t pos, size_t x, size_t y )
	: Struct( pos, x, y ) {
	setPos();
}

void StructI::setPos() {
	switch( getPosition() ) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
}

const std::array< std::array< size_t, 5 >, 5 > &StructI::getPos() const {
	return element;
}
/*
void StructI::setWidth() {
	auto w{ 0 };
	std::cout << "struct I" << std::endl;
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
		std::cout << "tmp is " << tmp << std::endl;
		std::cout << "jt is " << *jt << std::endl;
		}
	}
	width = w;
}

void StructI::setHeight() {
	auto h{ 0 };
	for ( auto it = getPos().cbegin(); it != getPos().cend(); ++it ) {
			auto tmp{ 0 };
			auto isNmbMt{ false };
			for ( auto jt = it->cbegin(); jt != it->cend(); ++jt ) {
				if ( 1 == *jt && !isNmbMt ) {
					++tmp;
					isNmbMt = true;
				}
				std::cout << "h tmp is " << tmp << std::endl;
				std::cout << "h jt is " << *jt << std::endl;
			}
			if ( tmp > h )
				h = tmp;
		}
	std::cout << "h is " << h << std::endl;
	height = h;
}
*/
void StructI::setFrstPos() {
	       Struct::element = { { { 1, 1, 1, 1, 0 },
      				     { 0, 0, 0, 0, 0 },
     				     { 0, 0, 0, 0, 0 },
      				     { 0, 0, 0, 0, 0 },
  				     { 0, 0, 0, 0, 0 },
     								   				  } };
}

void StructI::setScndPos() {
	       Struct::element = { { { 1, 0, 0, 0, 0 },     	     			            { 1, 0, 0, 0, 0 },
       				     { 1, 0, 0, 0, 0 },	
				     { 1, 0, 0, 0, 0 },
				     { 0, 0, 0, 0, 0 },
				   } };
}

void StructI::setThrdPos() {
	       Struct::element = { { { 1, 1, 1, 1, 0 },
				     { 0, 0, 0, 0, 0 },
				     { 0, 0, 0, 0, 0 },
				     { 0, 0, 0, 0, 0 },
				     { 0, 0, 0, 0, 0 },
     				   } };
}

void StructI::setFrthPos() {
	       Struct::element = { { { 1, 0, 0, 0, 0 },
				     { 1, 0, 0, 0, 0 },
				     { 1, 0, 0, 0, 0 },
				     { 1, 0, 0, 0, 0 },
				     { 0, 0, 0, 0, 0 },
				   } };
}
