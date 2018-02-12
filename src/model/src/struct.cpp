// struct.cpp
#include <iostream>

#include "struct.hpp"

Struct::Struct(size_t pos, size_t xx, size_t yy) 
	: elemPos((pos < 1 || pos > 4) ? 1 : pos),
	  coordX((xx < 0) ? 0 : xx),
	  coordY((yy < 0) ? 0 : yy),
	  width(5),
	  height(5) {
	// empty body
}

void Struct::setPosition(const size_t pos) {
	// check if pos whithin the range of possible possitions
	if (pos >= 1 && pos <= 4)
		elemPos = pos;
	else 
		throw std::invalid_argument("figure can't have this position");
}

size_t Struct::getPosition() const {
	return elemPos;
}

void Struct::setCoordX(const size_t crdX) {
	// check if coord X whithin the main field
	// take border from the main field class
	if (crdX >= 0 && crdX < 18)
		coordX = crdX;
	else
		throw std::invalid_argument("Invalid X-coord. Figure is out of the playable field");
}	

size_t Struct::getCoordX() const {
	return coordX;
}

void Struct::setCoordY(const size_t crdY) {
	// check if coord X whithin the main field
	// take border from the main field class
	if (crdY >= 0 && crdY < 24)
		coordY = crdY;	
	else
		throw std::invalid_argument("Invalid Y-coord. Figure is out of the playable field");	
}

size_t Struct::getCoordY() const {
	return coordY;
}

void Struct::setWidth(const size_t w) {
	width = w;
}

void Struct::setWidth() {
	auto w{0};
	for (auto it = getPos().cbegin(); it != getPos().cend(); ++it) {	
		auto tmp{0};
		auto isNmbMt{false};
		for (auto jt = it->cbegin(); jt != it->cend(); ++jt) {
			if (1 == *jt)
				isNmbMt = true;

			if (isNmbMt && 0 == *jt) {
				if (tmp > w)
					w = tmp;
				tmp = 0;
				isNmbMt = false;
			}
			++tmp;
		}
	}
	width = w;
}

size_t Struct::getWidth() const {
	return width;
}

void Struct::setHeight(const size_t h) {
	height = h;
}

void Struct::setHeight() {
	auto h{0};
	for (auto it = getPos().cbegin(); it != getPos().cend(); ++it) {	
		auto isNmbMt{false};
		for (auto jt = it->cbegin(); jt != it->cend(); ++jt) {
			if (1 == *jt && !isNmbMt) {
				++h;
				isNmbMt = true;
			} 
		}
	}
	height = h;
}

size_t Struct::getHeight() const {
	return height;
}

void Struct::setStructCoord(const size_t x, const size_t y) {
	setCoordX(x);
 	setCoordY(y);
}
