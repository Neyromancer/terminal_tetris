// structO.cpp
#include <iostream>

#include "structO.hpp"

StructO::StructO(size_t pos, size_t x, size_t y)
	: Struct(pos, x, y) {
	setPos();
}

void StructO::setPos() {
	switch (getPosition()) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
	setHeight();
	setWidth();
}

const std::array<std::array<size_t, 5>, 5> &StructO::getPos() const {
	return element;
}

void StructO::setFrstPos() {
	Struct::element = {{{1, 1, 0, 0, 0},
      			          {1, 1, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
  			            }};
}

void StructO::setScndPos() {
	Struct::element = {{{1, 1, 0, 0, 0},
      			          {1, 1, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
     			           }};
}

void StructO::setThrdPos() {
	Struct::element = {{{1, 1, 0, 0, 0},
    			            {1, 1, 0, 0, 0},
    			            {0, 0, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
   			             }};
}

void StructO::setFrthPos() {
	Struct::element = {{{1, 1, 0, 0, 0},
      			          {1, 1, 0, 0, 0},
       			          {0, 0, 0, 0, 0},
     			            {0, 0, 0, 0, 0},
    			            {0, 0, 0, 0, 0},
     			           }};
}
