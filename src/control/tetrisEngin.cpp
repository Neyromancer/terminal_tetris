// tetrisEngine.hpp

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "tetrisEngine.hpp"
#include "../model/structI.hpp"
#include "../model/structJ.hpp"
#include "../model/structL.hpp"
#include "../model/structO.hpp"
#include "../model/structS.hpp"
#include "../model/structT.hpp"
#include "../model/struct.hpp"

struct TetrisEngine::GamePiece {
	StructI *structI;
	StructJ *structJ;
	StructL *structL;
	StructS *structS;
	StructO *structO;
	StructT *structT;
	StructZ *structZ;
};

TetrisEngine::TetrisEngine() {
	// empty body
}

void TetrisEngine::processMainField() const {
	
}

TetrisEngine::~TetrisEngine() {

}
