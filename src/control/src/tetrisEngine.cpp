// tetrisEngine.cpp
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
	std::unique_ptr<Struct> ptrBaseStruct;
	std::unique_ptr<StructI> ptrStructI;
	StructJ *structJ;
	StructL *structL;
	StructS *structS;
	StructO *structO;
	StructT *structT;
	std::unique_ptr<StructZ> ptrStructZ;
};

struct TetrisEngine::GameField {
	std::unique_ptr<StructMainField> ptrMainField;
	StructLevelField *levelField;
	StructLinesRemovedField *lineField;
	StructNextPieceField *nextField;
	std::unique_ptr<StructScoreField> ptrScoreField;
};
//---------------- util func ------------------------------
static size_t realCoordX(std::unique_ptr<Struct> const &);
static size_t realCoordY(std::unique_ptr<Struct> const &);
//===========================================================
TetrisEngine::TetrisEngine() 
	: ptrPiece(std::make_unique<GamePiece>()),
	  ptrField(std::make_unique<GameField>()),
	  control('0') {
	ptrField->ptrMainField = std::make_unique<StructMainField>();
	ptrPiece->ptrStructI = std::make_unique<StructI>();
	ptrPiece->ptrStructZ = std::make_unique<StructZ>();
}

std::unique_ptr<Struct> TetrisEngine::rndPcGenerator() {
	srand(time(nullptr));
	auto rndNmb = rand() % 7;
	
	switch (rndNmb) { 
		case 0: return std::make_unique< StructI >();
		case 1: return std::make_unique< StructJ >();
		case 2: return std::make_unique< StructL >();
		case 3: return std::make_unique< StructO >();
		case 4: return std::make_unique< StructS >();
		case 5: return std::make_unique< StructT >(); 
	}
	return std::make_unique< StructZ >();
//	return std::make_unique< StructO >();
}

void TetrisEngine::processMainField() {
	srand( time(nullptr));
	static auto h{0};
	static auto tmpCoordY{0};
	static auto tmpCoordX{0};
//	static auto tmpHeight{ 0 };
//	static auto tmpWidth{ 0 };
//	static std::unique_ptr< Struct > tmpTetromino;
	
	if (0 == h) {
		ptrPiece->ptrBaseStruct = rndPcGenerator();
		auto rndCrdX = 1 + rand() % (8 - ptrPiece->ptrBaseStruct->getWidth());
		ptrPiece->ptrBaseStruct->setCoordX(rndCrdX);
		tmpCoordX = ptrPiece->ptrBaseStruct->getCoordX();
	} 
  ptrPiece->ptrBaseStruct->setCoordY(h++);
	static auto tmpHeight{ptrPiece->ptrBaseStruct->getHeight()};
	static auto tmpWidth{ptrPiece->ptrBaseStruct->getWidth()};
	if (ptrPiece->ptrBaseStruct->getCoordY() <= ptrField->ptrMainField->getHeight() - ptrPiece->ptrBaseStruct->getHeight() - 2) {
		if (0 != ptrPiece->ptrBaseStruct->getCoordY() - tmpCoordY || 
		    0 != ptrPiece->ptrBaseStruct->getCoordX() - tmpCoordX) {
		  for (auto pcCrdY = 0; pcCrdY < tmpHeight; ++pcCrdY) {
			  for (auto pcCrdX = 0; pcCrdX < tmpWidth; ++pcCrdX) {
				  ptrField->ptrMainField->setField((pcCrdX + tmpCoordX), (pcCrdY + tmpCoordY), 0);
			  }
      }
		}

		for (auto pcCrdY = 0; pcCrdY < ptrPiece->ptrBaseStruct->getHeight(); ++pcCrdY) {
			for (auto pcCrdX = 0; pcCrdX < ptrPiece->ptrBaseStruct->getWidth(); ++pcCrdX) {
				if (1 == ptrPiece->ptrBaseStruct->getPos().at(pcCrdY).at(pcCrdX)) {
				  ptrField->ptrMainField->setField((pcCrdX + ptrPiece->ptrBaseStruct->getCoordX()), (pcCrdY + ptrPiece->ptrBaseStruct->getCoordY()), ptrPiece->ptrBaseStruct->getPos().at(pcCrdY).at(pcCrdX));
				}
			}
    }
		
		if (ptrPiece->ptrBaseStruct->getCoordX() <= ptrField->ptrMainField->getWidth() && ptrPiece->ptrBaseStruct->getCoordX() >= 0)
		  tmpCoordX = ptrPiece->ptrBaseStruct->getCoordX();
		  tmpCoordY = ptrPiece->ptrBaseStruct->getCoordY();
	  } 

	  if (ptrPiece->ptrBaseStruct->getCoordY() > ptrField->ptrMainField->getHeight() - ptrPiece->ptrBaseStruct->getHeight() - 2 ||  
		    isCollisionDetected(ptrPiece->ptrBaseStruct, ptrField->ptrMainField)) {
		  h = 0;
		  tmpCoordY = 0;
		  checkLinesToDelete();
	  }
	  tmpHeight = ptrPiece->ptrBaseStruct->getHeight();
	  tmpWidth = ptrPiece->ptrBaseStruct->getWidth();
}

inline bool TetrisEngine::isAreaOccupied(const size_t coordX, const size_t coordY) const {
	return (1 == ptrField->ptrMainField->getField().at(coordX).at(coordY));
}

bool TetrisEngine::isRowFree(const std::unique_ptr<StructMainField> &ptrMainField, const size_t crdXBgn, const size_t crdXEnd, const size_t crdY) const {
	for (auto x = crdXBgn; x < crdXEnd - 1; ++x)
		if (isAreaOccupied(x, crdY))
			return false; 
	
	return true;
}

bool TetrisEngine::isRowOccupied(const std::unique_ptr<StructMainField> &ptrMainField, const size_t crdXBgn, const size_t crdXEnd, const size_t crdY) const {
	for (auto x = crdXBgn; x < crdXEnd - 1; ++x)
		if (!isAreaOccupied(x, crdY))
			return false;
	
	return true;
}

void TetrisEngine::checkLinesToDelete() {
  for (auto i = 0; i < ptrField->ptrMainField->getHeight() - 2;++i) { 
			if (isRowOccupied(ptrField->ptrMainField, 0, ptrField->ptrMainField->getWidth(), i)) {
				movePrvLines(i);
			}
		}
}

void TetrisEngine::movePrvLines(size_t row) {
	if (row > 0) {
    while (!isRowFree(ptrField->ptrMainField, 0, ptrField->ptrMainField->getWidth(), row) && row > 0) {
      for (auto x = 0; x < ptrField->ptrMainField->getWidth() - 1; ++x) {
			  ptrField->ptrMainField->setField(x, row, ptrField->ptrMainField->getField().at(x).at(row - 1));
			}
			--row;
		}
	}
}

void TetrisEngine::processNextPieceField() const {}

void TetrisEngine::processLevelField() const {}

void TetrisEngine::processScoreField() const {}

void TetrisEngine::processLinesRemovedField() const {}

void TetrisEngine::displayScene() const {}

void TetrisEngine::storeTetrominoToField() {
}

void TetrisEngine::readInputFromConsole() {
	system("stty -echo");
	system("stty cbreak");
	while (true) {
		std::cin.get(control);
	}
	system("stty echo");
	system("stty -cbreak");
}

void TetrisEngine::processControlInput() {
	auto tmpCoordX = ptrPiece->ptrBaseStruct->getCoordX();
	auto tmpPsPos = ptrPiece->ptrBaseStruct->getPosition();
	switch (control) {
		case 'A':
		case 'a':
			ptrPiece->ptrBaseStruct->setCoordX(tmpCoordX = (tmpCoordX > 1) ? --tmpCoordX : 0);
			control = '0';
			break;
		case 'D':
		case 'd':
			ptrPiece->ptrBaseStruct->setCoordX(tmpCoordX = (tmpCoordX < ptrField->ptrMainField->getWidth() - ptrPiece->ptrBaseStruct->getWidth() - 1) ? ++tmpCoordX : ptrField->ptrMainField->getWidth() - ptrPiece->ptrBaseStruct->getWidth() - 1);
			control = '0';
			break;
		case ',':		// turn piece anti-clockwise
			ptrPiece->ptrBaseStruct->setPosition(tmpPsPos = (ptrPiece->ptrBaseStruct->getPosition() > 1) ? --tmpPsPos : 4);
			ptrPiece->ptrBaseStruct->setPos();
			control = '0';
			break;
		case '.':		// turn piece clockwise
			ptrPiece->ptrBaseStruct->setPosition(tmpPsPos = (ptrPiece->ptrBaseStruct->getPosition() < 4) ? ++tmpPsPos : 1);
			ptrPiece->ptrBaseStruct->setPos();
			control = '0';
			break;	
	}
}

// x and y are eqaul to coordX and coordY
// of tetromino whicl represent
// top-left corner of the appropriate array
bool TetrisEngine::isCollisionDetected(const std::unique_ptr< Struct > &ptrBaseStruct, const std::unique_ptr<StructMainField> &ptrMainField) const {
	for (auto y = 0; y < ptrBaseStruct->getHeight(); ++y) {
		for (auto x = 0; x < ptrBaseStruct->getWidth(); ++x) {
			if ((1 == (ptrBaseStruct->getPos().at(y).at(x))) && (0 == ptrBaseStruct->getPos().at(y + 1).at(x)))
				if ((ptrMainField->getField().at(x + ptrBaseStruct->getCoordX()).at(ptrBaseStruct->getCoordY() + y + 1) == ptrBaseStruct->getPos().at(y).at(x)))
				return true;
		}
	}
	return false;	
}

bool TetrisEngine::isGameOver() const {
}



void TetrisEngine::deleteLine( const size_t row ) {
	for ( size_t i = 0; i < ptrField->ptrMainField->getWidth(); ++i )
		ptrField->ptrMainField->setField( row, i, 0 );

	movePrvLines( row );
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
