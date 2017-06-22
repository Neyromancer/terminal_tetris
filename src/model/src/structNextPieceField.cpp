// structNextPieceField.cpp

#include "../headers/structNextPieceField.hpp"

const std::string StructNextPieceField::FIELD_NAME = "NEXT";

StructNextPieceField::StructNextPieceField( size_t w, size_t h/*, const std::array< std::array< char, 4 >, 4 > &pcs */)
	 : StructMainField( w, h ) {
//		setPiece( pcs );
}
	
void StructNextPieceField::setPiece( const std::array< std::array< char, 4 >, 4 > &pcs ) {
	if ( !pcs[ 0 ].empty() && pcs[ 0 ].size() == piece[ 0 ].size() ) {
		// loop starts from 1 and ends with size -1
		// because field 2 cells wider and heigher
		// than the piece's( pcs ) array
		for ( size_t i = 1; i < piece.size() - 1; ++i ) {
//			piece.at( i ).swap( pcs.at( i ) );
			for ( size_t j = 1; j < piece.at( i ).size() - 1; ++j ) {
				piece.at( i ).at( j ) = pcs.at( i ).at( j );
			}
		}
	}
}

const std::array< std::array< char, 4 >, 4 > &StructNextPieceField::getPice() const {
	return piece;
}

const std::string &StructNextPieceField::getFieldName() const {
	return FIELD_NAME;
}

StructNextPieceField::~StructNextPieceField() {

}
