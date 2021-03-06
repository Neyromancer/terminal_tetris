// structLevelField.cpp
#include <stdexcept>

#include "structLevelField.hpp"

static const std::string FIELD_NAME = "LEVEL";

StructLevelField::StructLevelField( size_t w, size_t h, size_t lvl ) 
	: StructMainField( w, h ),
	  level( lvl ) {
}
	
void StructLevelField::setLevel( const size_t lvl ) {
	if ( lvl >= 0 )
		level = lvl;
	else
		throw
			std::invalid_argument( "Score can't be below \'0\'\n" );
}
size_t StructLevelField::getLevel() const {
	return level;
}

const std::string &StructLevelField::getFieldName() const {
	return FIELD_NAME;
}
