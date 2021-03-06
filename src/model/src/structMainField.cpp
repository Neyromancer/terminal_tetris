// structMainField.cpp

#include <stdexcept>

#include "structMainField.hpp"

StructMainField::StructMainField( size_t w, size_t h ) 
	: width( w ),
	  height( h ) {
	fillField();
}
		
const std::array< std::array< size_t, 24 >, 11 > &StructMainField::getField() const {
	return element;
}

// set main fields cells to 0 if they are free or to 1 if
// a figure there
void StructMainField::setField( size_t row, size_t cell, size_t value /* = 0 or 1 */ ) {
	if ( value != 0 && value != 1 )
		throw 
			std::invalid_argument( "Something went wrong\n Field's value can't exceed \'1\' and be lower than \'0\'\n" );

	if ( ( row >= 0 && row <= getWidth() ) &&
	     ( cell >= 0 && cell <= getHeight() ) ) {
		element[ row ][ cell ] = value;
		/*for ( size_t i = 0; i < getHeight(); ++i ) {
			for ( auto j = 0; j < getWidth();++j ) {
				if ( i == row && j == cell )
					element[ i ][ j ] = value;
			}
		} */
	} else 
		throw 
			std::invalid_argument( "element out of the field" );
}

// set main field width
void StructMainField::setWidth( const size_t w ) {
	if ( w >= 11 )
		width = w;
	else
		throw 
			std::invalid_argument( "field is too narrow\n" );
}

// get main field width
size_t StructMainField::getWidth() const {
	return element.size();
}

// set main field height
void StructMainField::setHeight( const size_t h ) {
	if ( h >= 24 )
		height = h;
	else
		throw 
			std::invalid_argument( "field is too short\n" );

}

// get main field height
size_t StructMainField::getHeight() const {
	return element.at( 0 ).size();
}

// initial filling the main field with 0
void StructMainField::fillField() {
	for ( auto it = element.begin(); it != element.end(); ++it )
		it->fill( 0 );
}

bool StructMainField::isAreaOccupied( size_t x, size_t y ) const {
	return getField().at( y ).at( x ) == 1;
}
