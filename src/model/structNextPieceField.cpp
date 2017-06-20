// structNextPieceField.cpp

#include "structNextPieceField.hpp"

StructNextPieceField::StructNextPieceField( size_t w, size_t h, std::array< std::array< char >, 4 >, 4 > &pcs )
	 : StructMainField( w, h ) {
		setPiece( pcs );
}
	
void StructNextPieceField::setPiece( const std::array< std::array< char >, 4 >, 4 > &pcs ) {
	if ( !pcs[ 0 ].empty() && pcs[ 0 ].size() == piece[ 0 ].size() )
		for ( size_t i = 0; i < piece.size(); ++i )
			piece.at( i ).swap( pcs.at( i ) );
}

const std::array< std::array< char >, 4 >, 4 > &StructNextPieceField::getPice() const {
	return piece;
}

const std::string &StructNextPieceField::getFieldName() const {
	return fieldName;
}
	
	private:
		std::array< std::array< char >, 4 >, 4 > piece;
		static const std::string fieldName = "NEXT";

StructNextPieceField::~StructNextPieceField() {

}
