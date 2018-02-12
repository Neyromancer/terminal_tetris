// structL.cpp
#include <iostream>

#include "structL.hpp"

StructL::StructL(size_t pos, size_t x, size_t y)
	: Struct(pos, x, y) {
	setPos();
}

void StructL::setPos() {
	switch (getPosition()) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
	setHeight();
	setWidth();
}

const std::array<std::array<size_t, 5>, 5> &StructL::getPos() const {
	return element;
}

void StructL::setFrstPos() {
	Struct::element = {{{1, 1, 1, 0, 0},
      			          {1, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
    			            {0, 0, 0, 0, 0},
    			          }};
}

void StructL::setScndPos() {
	Struct::element = {{{1, 0, 0, 0, 0},
     			            {1, 0, 0, 0, 0},
      			          {1, 1, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
    							 	 }};
}

void StructL::setThrdPos() {
	Struct::element = {{{0, 0, 1, 0, 0},
     			            {1, 1, 1, 0, 0},
      			          {0, 0, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
     			           }};
}

void StructL::setFrthPos() {
	Struct::element = {{{0, 1, 1, 0, 0},
      			          {0, 0, 1, 0, 0},
       			          {0, 0, 1, 0, 0},
       			          {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
     			          }};
}
