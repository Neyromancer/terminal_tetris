// tetrisEngine.hpp

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "../headers/tetrisEngine.hpp"
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
	StructScoreField *scoreField;
};
//===========================================================
TetrisEngine::TetrisEngine() 
	: ptrPiece( std::make_unique< GamePiece >() ),
	  ptrField( std::make_unique< GameField >() ) {
	ptrField->ptrMainField = std::make_unique< StructMainField >();
}

void TetrisEngine::processMainField() const {
	ptrPiece->structO = new StructO;
	
}

bool TetrisEngine::isEreaOccupied( /*const*/ size_t coordX,/* const*/ size_t coordY ) {
	if ( ptrField->ptrMainField->getField().at( coordX ).at( coordY ) == 1 ) return true;
 
	return false;
}
TetrisEngine::~TetrisEngine() = default;
