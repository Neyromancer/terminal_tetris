// structLinesRemovedField.cpp
#include "structLinesRemovedField.hpp"

StructLinesRemovedField::StructLinesRemovedField( size_t w, size_t h, size_t rmLines )
	 : StructMainField( w, h ),
	  removedLines( rmLines )  {

}
	
void StructLinesRemovedField::setRemovedLines( const size_t rmLines ) {
	if ( rmLines > 0 )
		removedLines = rmLines;
}

size_t StructLinesRemovedField::getRemovedLines() const {
	return removedLines;
}

const std::string &StructLinesRemovedField::getFieldName() const {
	return fieldName;
}

StructLinesRemovedField::~StructLinesRemovedField() {

}
