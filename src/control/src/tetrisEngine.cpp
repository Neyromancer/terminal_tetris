// tetrisEngine.hpp

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "tetrisEngine.hpp"
#include "structI.hpp"
#include "structJ.hpp"
#include "structL.hpp"
#include "structO.hpp"
#include "structS.hpp"
#include "structZ.hpp"
#include "structT.hpp"
#include "structMainField.hpp"
#include "structLevelField.hpp"
#include "structLinesRemovedField.hpp"
#include "structNextPieceField.hpp"
#include "structScoreField.hpp"

struct TetrisEngine::GamePiece {
	std::unique_ptr< Struct > ptrBaseStruct;
	std::unique_ptr< StructI > ptrStructI;
	StructJ *structJ;
	StructL *structL;
	StructS *structS;
	StructO *structO;
	StructT *structT;
	std::unique_ptr< StructZ > ptrStructZ;
};

struct TetrisEngine::GameField {
	std::unique_ptr< StructMainField > ptrMainField;
	StructLevelField *levelField;
	StructLinesRemovedField *lineField;
	StructNextPieceField *nextField;
	std::unique_ptr< StructScoreField > ptrScoreField;
};
//---------------- util func ------------------------------
static bool isRowOccupied( const std::unique_ptr< StructMainField > &ptrMainField,const size_t crdXBgn, const size_t crdXEnd, const size_t crdY );
static size_t realCoordX( std::unique_ptr< Struct > const & );
static size_t realCoordY( std::unique_ptr< Struct > const & );
//===========================================================
TetrisEngine::TetrisEngine() 
	: ptrPiece( std::make_unique< GamePiece >() ),
	  ptrField( std::make_unique< GameField >() ) {
	ptrField->ptrMainField = std::make_unique< StructMainField >();
	ptrPiece->ptrStructI = std::make_unique< StructI >();
	ptrPiece->ptrStructZ = std::make_unique< StructZ >();
}

std::unique_ptr< Struct > TetrisEngine::rndPcGenerator() {
	srand( time( nullptr ) );
	auto rndNmb = rand() % 7;
	
	switch( rndNmb ) {
		case 0: return std::make_unique< StructI >();
		case 1: return std::make_unique< StructJ >();
		case 2: return std::make_unique< StructL >();
		case 3: return std::make_unique< StructO >();
		case 4: return std::make_unique< StructS >();
		case 5: return std::make_unique< StructT >();
	}
	return std::make_unique< StructZ >();
}

void TetrisEngine::processMainField() {
	srand( time( nullptr ) );
	static auto h{ 0 };
	static auto tmp{ 0 };
	
	if ( h == 0 ) {
		ptrPiece->ptrBaseStruct = rndPcGenerator();
		ptrPiece->ptrBaseStruct->setHeight();
		ptrPiece->ptrBaseStruct->setWidth();
		auto rndCrdX = 1 + rand() % ( 8 - ptrPiece->ptrBaseStruct->getWidth() );
		ptrPiece->ptrBaseStruct->setCoordX( rndCrdX );
	} 
		ptrPiece->ptrBaseStruct->setCoordY( h++ );
		if /* ( ptrPiece->ptrBaseStruct->getCoordY() <= ptrField->ptrMainField->getHeight() - ptrPiece->ptrBaseStruct->getHeight() - 2 */ /*ptrField->ptrMainField->getHeight() */ /*  &&  
		!isCollisionDetected( ptrPiece->ptrBaseStruct, ptrField->ptrMainField ) ) */ ( ptrPiece->ptrBaseStruct->getCoordY() <= ptrField->ptrMainField->getHeight() - ptrPiece->ptrBaseStruct->getHeight() - 2 ) {

		if ( ptrPiece->ptrBaseStruct->getCoordY() - tmp != 0 ) {

		for ( auto pcCrdY = 0; pcCrdY < ptrPiece->ptrBaseStruct->getHeight(); ++pcCrdY )
			for ( auto pcCrdX = 0; pcCrdX < ptrPiece->ptrBaseStruct->getWidth(); ++pcCrdX ) {
				ptrField->ptrMainField->setField( ( pcCrdX + ptrPiece->ptrBaseStruct->getCoordX() ), ( pcCrdY + tmp ), 0 );
			}
		}

		for ( auto pcCrdY = 0; pcCrdY < ptrPiece->ptrBaseStruct->getHeight(); ++pcCrdY )
			for ( auto pcCrdX = 0; pcCrdX < ptrPiece->ptrBaseStruct->getWidth(); ++pcCrdX ) {
				if ( 1 == ptrPiece->ptrBaseStruct->getPos().at( pcCrdY ).at( pcCrdX ) ) {
				ptrField->ptrMainField->setField( ( pcCrdX + ptrPiece->ptrBaseStruct->getCoordX() ), ( pcCrdY + ptrPiece->ptrBaseStruct->getCoordY() ), ptrPiece->ptrBaseStruct->getPos().at( pcCrdY ).at( pcCrdX ) );
				}
			}

		tmp = ptrPiece->ptrBaseStruct->getCoordY();
	} /* else { */
	if ( ptrPiece->ptrBaseStruct->getCoordY() > ptrField->ptrMainField->getHeight() - ptrPiece->ptrBaseStruct->getHeight() - 2 /*ptrField->ptrMainField->getHeight() */||  
		isCollisionDetected( ptrPiece->ptrBaseStruct, ptrField->ptrMainField ) ) {
		h = 0;
		tmp = 0;
	}
}

bool TetrisEngine::isAreaOccupied( const size_t coordX, const size_t coordY ) const {
	size_t x = 0;
	size_t y = 0;
	if( 1 == ptrField->ptrMainField->getField().at( coordX ).at( coordY ) ) return true; 

	return false;
}

static bool isRowOccupied( const std::unique_ptr< StructMainField > &ptrMainField, const size_t crdXBgn, const size_t crdXEnd, const size_t crdY ) {
	for ( auto x = crdXBgn; x < crdXEnd; ++x ) 
		if( 1 == ptrMainField->getField().at( x ).at( crdY ) ) return true; 

	return false;
}

void TetrisEngine::processNextPieceField() const {}

void TetrisEngine::processLevelField() const {}

void TetrisEngine::processScoreField() const {}

void TetrisEngine::processLinesRemovedField() const {}

void TetrisEngine::displayScene() const {}

void TetrisEngine::storeTetrominoToField() {
}

void TetrisEngine::processControlInput() {
}

// x and y are eqaul to coordX and coordY
// of tetromino whicl represent
// top-left corner of the appropriate array
bool TetrisEngine::isCollisionDetected( const std::unique_ptr< Struct > &ptrBaseStruct, const std::unique_ptr< StructMainField > &ptrMainField ) const {
	for ( auto y = 0; y < ptrBaseStruct->getHeight(); ++y ) {
		for ( auto x = 0; x < ptrBaseStruct->getWidth(); ++x ) {
			if ( ( 1 == ( ptrBaseStruct->getPos().at( y ).at( x ) ) ) && ( 0 == ptrBaseStruct->getPos().at( y + 1 ).at( x ) ) )
				if ( ( ptrMainField->getField().at( x + ptrBaseStruct->getCoordX() ).at( ptrBaseStruct->getCoordY() + y + 1 ) == ptrBaseStruct->getPos().at( y ).at( x ) ) )
				return true;
		}
	}
	return false;	
}

bool TetrisEngine::isGameOver() const {
	/*for ( size_t i = 0; i < ptrField->ptrMainField->getWidth(); ++i ) {
		if ( !ptrField->ptrMainField->isAreaOccupied( i, 0 ) ) 
			return false;
	}

	return true;
*/

}

void TetrisEngine::checkLinesToDelete() const {
/*	for ( auto it = ptrField->ptrMainField->getField().cbegin(); it != ptrField->ptrMainField->getField().cend(); ++it)  {
		for ( auto jt = it->cbegin(); jt != it->cend(); ++jt ) {
			if ( !ptrField->ptrMainField->tsAreaOccupied( *jt, *it ) )
				break;
		}
		deleteLine( *it );
	}*/
}

void TetrisEngine::deleteLine( size_t row ) {
/*	for ( size_t i = 0; i < ptrField->ptrMainField->getWidth(); ++i ) {
		ptrField->ptrMainField->setField( row, j, ptrField->ptrMainField->getField().at( row - 1 ).at( i ) )
	}*/
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
