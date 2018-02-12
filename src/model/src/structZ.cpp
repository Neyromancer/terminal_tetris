// structZ.cpp
#include <iostream>

#include "structZ.hpp"

StructZ::StructZ(size_t pos, size_t x, size_t y)
	: Struct(pos, x, y) {
	setPos();
}

void StructZ::setPos() {
	switch (getPosition()) {
		case 1: setFrstPos(); break;
		case 2: setScndPos(); break;
		case 3: setThrdPos(); break;
		case 4: setFrthPos(); break;
	}
	setHeight();
	setWidth();
}

const std::array<std::array<size_t, 5>, 5> &StructZ::getPos() const {
	return element;
}

void StructZ::setFrstPos() {
	Struct::element = {{{1, 1, 0, 0, 0},
      			          {0, 1, 1, 0, 0},
      			          {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
    			            {0, 0, 0, 0, 0},
    			           }};
}

void StructZ::setScndPos() {
	Struct::element = {{{0, 1, 0, 0, 0},
      			          {1, 1, 0, 0, 0},
    			            {1, 0, 0, 0, 0},
       			          {0, 0, 0, 0, 0},
   			              {0, 0, 0, 0, 0},
     			           }};
}

void StructZ::setThrdPos() {
	Struct::element = {{{1, 1, 0, 0, 0},
   			              {0, 1, 1, 0, 0},
  			              {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
      			          {0, 0, 0, 0, 0},
    			           }};
}

void StructZ::setFrthPos() {
	Struct::element = {{{0, 1, 0, 0, 0},
     			            {1, 1, 0, 0, 0},
       			          {1, 0, 0, 0, 0},
       			          {0, 0, 0, 0, 0},
       			          {0, 0, 0, 0, 0},
     			           }};
}
