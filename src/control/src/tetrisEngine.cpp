// tetrisEngine.hpp

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "../headers/tetrisEngine.hpp"
#include "../../model/headers/struct.hpp"
#include "../../model/headers/structI.hpp"
#include "../../model/headers/structJ.hpp"
#include "../../model/headers/structL.hpp"
#include "../../model/headers/structO.hpp"
#include "../../model/headers/structS.hpp"
#include "../../model/headers/structZ.hpp"
#include "../../model/headers/structT.hpp"
#include "../../model/headers/struct.hpp"
#include "../../model/headers/structMainField.hpp"
#include "../../model/headers/structLevelField.hpp"
#include "../../model/headers/structLinesRemovedField.hpp"
#include "../../model/headers/structNextPieceField.hpp"
#include "../../model/headers/structScoreField.hpp"

struct TetrisEngine::GamePiece {
	std::unique_ptr< Struct >  ptrBaseStruct;
	StructI *structI;
	StructJ *structJ;
	StructL *structL;
	StructS *structS;
	StructO *structO;
	StructT *structT;
	StructZ *structZ;
};

struct TetrisEngine::GameField {
	std::unique_ptr< StructMainField > ptrMainField;
	StructLevelField *levelField;
	StructLinesRemovedField *lineField;
	StructNextPieceField *nextField;
	std::unique_ptr< StructScoreField > ptrScoreField;
};
//---------------- util func ------------------------------
static bool isRowOccupied( size_t );
static size_t realCoordX( std::unique_ptr< Struct > const & );
static size_t realCoordY( std::unique_ptr< Struct > const & );
//===========================================================
TetrisEngine::TetrisEngine() 
	: ptrPiece( std::make_unique< GamePiece >() ),
	  ptrField( std::make_unique< GameField >() ) {
	ptrField->ptrMainField = std::make_unique< StructMainField >();
}

void TetrisEngine::processMainField() const {
}

void TetrisEngine::processNextPieceField() const {}

void TetrisEngine::processLevelField() const {}

void TetrisEngine::processScoreField() const {}

void TetrisEngine::processLinesRemovedField const {}

void displayScene() const {}

void storeTetrominoToField() const 

// x and y are eqaul to coordX and coordY
// of tetromino whicl represent
// top-left corner of the appropriate array
bool TetrisEngine::isCollisionDetected( size_t x, size_t y, std::unique_ptr< Struct > const &strc ) const {
	if ( ( ( x - realCoordX() ) >= 0 && ( x + strc->getWidth() - realCoordX() ) <= ptrField->ptrMainField->getWidth() ) && ( ( y - realCoordY() ) >= 0 && ( y + strc->getHeight() - realCoordY() ) <= ptrField->ptrMainField->getHeight() ) ) {
		//  add some magic here 
		// method is not implemented yet
	}
	
}

bool TetrisEngine::isGameOver() const {
	for ( size_t i = 0; i < ptrField->ptrMainField->getWidth(); ++i ) {
		if ( !ptrField->ptrMainField->isAreaOccupied( i, 0 ) ) 
			return false;
	}

	return true;
}

void TetrisEngine::checkLinesToDelete() {
	for ( auto it = ptrField->ptrMainField->getField().cbegin(); it != ptrField->ptrMainField->getField().cend(); ++it)  {
		for ( auto jt = it->cbegin(); jt != it->cend(); ++jt ) {
			if ( !ptrField->ptrMainField->isAreaOccupied( *jt, *it ) )
				break;
		}
		deleteLine( *it );
	}
}

void TetrisEngine::deleteLine( size_t row ) {
	for ( size_t i = 0; i < ptrField->ptrMainField->getWidth(); ++i ) {
		ptrField->ptrMainField->setField( row, j, ptrField->ptrMainField->getField().at( row - 1 ).at( i ) )
	}
}

bool TetrisEngine::isAreaOccupied( const size_t coordX, const size_t coordY ) {
	size_t x = 0;
	size_t y = 0;
	if ( coordX > ptrField->ptrScoreField->getWidth() &&
	     coordX <= ( ptrField->ptrScoreField->getWidth() +
			 ptrField->ptrMainField->getWidth() ) {
		x = coordX - ptrField->ptrScoreField->getWidth();
		ptrField->scoreMainField->isAreaOccupied( x, coordY ); 
	} else if () {

	}

}

static bool isRowOccupied( size_t row ) {
	
}

// method find the first, i.e. the leftmost occupied 
// cell
static size_t realCoordX( std::unique_ptr< Struct > const &strc ) {
	
}

// method find the first, i.e. the topmost occupied
// cell
static size_t realCoordY( std::unique_ptr< Struct > const &strc ) {

}

TetrisEngine::~TetrisEngine() = default;
