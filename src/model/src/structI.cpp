// structI.cpp
#include <iostream>

#include "struct.hpp"
#include "structI.hpp"

StructI::StructI(size_t pos, size_t x, size_t y)
	: Struct(pos, x, y) {
	setPos();
}

void StructI::setPos() {
	switch (getPosition()) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
	setHeight();
	setWidth();
}

const std::array<std::array< size_t, 5>, 5> &StructI::getPos() const {
	return element;
}

void StructI::setFrstPos() {
	       Struct::element = {{{1, 1, 1, 1, 0},
      				               {0, 0, 0, 0, 0},
     				                 {0, 0, 0, 0, 0},
      				               {0, 0, 0, 0, 0},
  				                   {0, 0, 0, 0, 0},
     				                }};
}

void StructI::setScndPos() {
	       Struct::element = {{{1, 0, 0, 0, 0},     	     			            
				                     {1, 0, 0, 0, 0},
       				               {1, 0, 0, 0, 0},	
				                     {1, 0, 0, 0, 0},
				                     {0, 0, 0, 0, 0},
				                    }};
}

void StructI::setThrdPos() {
	       Struct::element = {{{1, 1, 1, 1, 0},
				                     {0, 0, 0, 0, 0},
				                     {0, 0, 0, 0, 0},
				                     {0, 0, 0, 0, 0},
				                     {0, 0, 0, 0, 0},
     				                }};
}

void StructI::setFrthPos() {
	       Struct::element = {{{1, 0, 0, 0, 0},
				                     {1, 0, 0, 0, 0},
				                     {1, 0, 0, 0, 0},
				                     {1, 0, 0, 0, 0},
				                     {0, 0, 0, 0, 0},
				                    }};
}
