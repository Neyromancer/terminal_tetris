// structScoreField.cpp
#include <stdexcept>

#include "structScoreField.hpp"

const std::string StructScoreField::FIELD_NAME = "SCORE";

StructScoreField::StructScoreField( size_t w, size_t h, size_t scr ) : StructMainField( w, h ),
	score( scr ) {
}
	
void StructScoreField::setScore( const size_t scr ) {
	if ( scr >= 0 )
		score = scr;
	else
		throw
			std::invalid_argument( "Score can't be below \'0\'\n" );
}
size_t StructScoreField::getScore() const {
	return score;
}

const std::string &StructScoreField::getFieldName() const {
	return FIELD_NAME;
}

StructScoreField::~StructScoreField() {

}
