// struct.cpp

#include "../headers/struct.hpp"

Struct::Struct( size_t pos, size_t xx, size_t yy ) 
	: elemPos( ( pos < 1 || pos > 4 ) ? 1 : pos ),
	  coordX(  ( xx < 0 ) ? 0 : xx ),
	  coordY(  ( yy < 0 ) ? 0 : yy ) {
	// empty body
}

void Struct::setPosition( const size_t pos ) {
	// check if pos whithin the range of possible possitions
	if ( pos >= 1 && pos <= 4 )
		elemPos = pos;
	else 
		throw std::invalid_argument( "figure can't have this position" );
}

size_t Struct::getPosition() const {
	return elemPos;
}

void Struct::setCoordX( const size_t crdX ) {
	// check if coord X whithin the main field
	// take border from the main field class
	if ( crdX > 0 && crdX < 18 )
		coordX = crdX;
	else
		throw std::invalid_argument( "figure is out of the playable field" );
}	

size_t Struct::getCoordX() const {
	return coordX;
}

void Struct::setCoordY( const size_t crdY ) {
	// check if coord X whithin the main field
	// take border from the main field class
	if ( crdY > 0 && crdY < 18 )
		coordY = crdY;	
	else
		throw std::invalid_argument( "figure is out of the playable field" );	
}

size_t Struct::getCoordY() {
	return coordY;
}

void Struct::setWidth( const size_t w ) {
	width = w;
}

size_t Struct::getWidth() const {
	return width;
}

void Struct::setHeight( const size_t h ) {
	height = h;
}

size_t Struct::getHeight() const {
	return height;
}

void Struct::setStructCoord( const size_t x, const size_t y ) {
	setCoordX( x );
 	setCoordY( y );
}

void Struct::mvStructLeft() {
	setCoordX( --coordX );
}

void Struct::mvStructRight() {
	setCoordX( ++coordX );
}

void Struct::mvStructUp() {
	setCoordY( --coordY );
}

void Struct::mvStructDown() {
	setCoordY( ++coordY );
}
/*
virtual const std::array< std::array< char, 5 >, 5 > &Struct::displayStruct() const {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}
*/
/*
Struct::~Struct() {

}
*/
		
