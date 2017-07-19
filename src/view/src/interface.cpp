// interface.cpp
#include <iostream>
#include <iomanip>

#include "../headers/interface.hpp"
/**
  *
  * - Rewrite code to remove hardcoding
  * - Commands will displayed via flag
  * - Fields width will be count in the program
  * - Fields height in opposite to width will be
  * entered ( can be changed maually )
  *
**/

// ====================== util functions =====================
static void displayField( const size_t index, const size_t height, const size_t width, const std::string &, bool );
static void displayTitle( const size_t, const std::string & );
static bool isEven( const size_t ); 
//static bool isEreaOqupied ( const size_t coordX, const size_t coorY );
// ===========================================================
Interface::Interface( size_t h, size_t w ) 
	: ptrEngine( std::make_unique< TetrisEngine >() ),
	  scrnH( h ), scrnW( w ),
	  mFldH( 24 ), mFldW( 10 ),
	  scrFldH( 7 ), scrFldW( 7 ),
	  lRmvdFldH( 7 ), lRmvdW( 7 ),
	  lvlFldH( 7 ), lvlFldW( 7 ),
	  nxtPcFldH( 10 ), nxtPcFldH( 10 ),
	  cmdFldH( 7 ), cmdFldW( 7 ),
	  tetroH( 5 ), tetroW( 5 ) {
	// empty body
}

void Interface::displayInterface() const {
	const size_t MAIN_FIELD_HEIGHT = 30;
	const size_t SCORE_FIELD_HEIGHT = 7;
	const size_t LEVEL_FIELD_HEIGHT = 7;
	const size_t LEVEL_FIELD_WIDTH = 7;
	const size_t NEXT_PIECE_FIELD_HEIGHT = 10;
	const size_t LINES_FIELD_HEIGHT = 7;

	for ( size_t i = 0; i < MAIN_FIELD_HEIGHT; ++i ) {
	
		if ( i < SCORE_FIELD_HEIGHT )	
			displayScoreField( i );
		else if ( ( i >= SCORE_FIELD_HEIGHT + 2 ) &&
			  ( i < SCORE_FIELD_HEIGHT + LINES_FIELD_HEIGHT + 2 ) ) {
			displayLinesRemovedField( i - ( SCORE_FIELD_HEIGHT + 2 ) ); 
//			std::cout << "&";
		}

		if ( ( i >= SCORE_FIELD_HEIGHT ) &&
		     ( i < SCORE_FIELD_HEIGHT + 2 ) ||
		     ( i >= SCORE_FIELD_HEIGHT + LINES_FIELD_HEIGHT + 2 ) ) {
			for ( size_t j = 0; j <= 6 + SCORE_FIELD_HEIGHT * 2; ++j )
				std::cout << "*";
		} else if ( ( i == SCORE_FIELD_HEIGHT - 1 ) ||
			    ( i == SCORE_FIELD_HEIGHT + LINES_FIELD_HEIGHT + 1 ) ) {
			for ( size_t j = 0; j <= 3; ++j )
				std::cout << "*";
		} 
		else {
			for ( size_t j = 0; j <= 2; ++j )
				std::cout << "*";

		}
		displayMainField( i );
		if ( ( i >= LEVEL_FIELD_HEIGHT &&
		       i <= LEVEL_FIELD_HEIGHT + 2 ) ||
		     ( i >= LEVEL_FIELD_HEIGHT + 
		       NEXT_PIECE_FIELD_HEIGHT + 3 ) ) {
			for ( size_t j = 0; j <= 3 + LEVEL_FIELD_WIDTH * 2; ++j )
				std::cout << "*";

		} else if ( ( i == LEVEL_FIELD_HEIGHT - 1 ) ||
			    ( i == LEVEL_FIELD_HEIGHT + NEXT_PIECE_FIELD_HEIGHT + 2 ) ) {
			for ( size_t j = 0; j <= 3; ++j )
				std::cout << "*";

		} 
		else {
			for ( size_t j = 0; j <= 2; ++j )
				std::cout << "*";

		}
		if ( i < LEVEL_FIELD_HEIGHT )
			displayLevelField( i );
		else if ( ( i > LEVEL_FIELD_HEIGHT + 2 ) &&
			  ( i < LEVEL_FIELD_HEIGHT + 
		       NEXT_PIECE_FIELD_HEIGHT + 3 ) ) {
			displayNextPieceField( i - ( LEVEL_FIELD_HEIGHT + 3 ) );
		}
//		displayCommandField( i );
			if ( ( i >= LEVEL_FIELD_HEIGHT ) &&
			     ( i <= LEVEL_FIELD_HEIGHT + 2 ) ||
			     ( i >= LEVEL_FIELD_HEIGHT + 
		       NEXT_PIECE_FIELD_HEIGHT + 3 ) )
			std::cout << std::endl;
	}
}

void Interface::displayMainField(  size_t index ) const {
	const size_t FIELD_HEIGHT = 30;
	const size_t FIELD_WIDTH = 18;
			if ( index != FIELD_HEIGHT - 1 )
				std::cout << "<!";
			else std::cout << "  ";
		for ( size_t fw = 0; fw < FIELD_WIDTH; ++fw ) {
			if (  index < FIELD_HEIGHT - 2 ) {
				if ( ptrEngine->isAreaOccupied( fw, index ) )
					std::cout << " .";
				else 
					std::cout << "[]";

			}
			else if ( index == FIELD_HEIGHT - 2 )
				std::cout << "==";
			else
				std::cout << "\\/";
		}
			if ( index != FIELD_HEIGHT - 1 )
				std::cout << "!>";
			else std::cout << " ";
}

void Interface::displayScoreField( size_t index ) const {
	static size_t score = 0;
	const size_t FIELD_HEIGHT = 7;
	const size_t FIELD_WIDTH = 7;
	std::string title = "SCORE";
	displayField( index, FIELD_HEIGHT, FIELD_WIDTH, title, false );
}

void Interface::displayLinesRemovedField( size_t index ) const {
	static size_t lines = 0;
	const size_t FIELD_HEIGHT = 7;
	const size_t FIELD_WIDTH = 7;
	std::string title = "LINES";
	displayField( index, FIELD_HEIGHT, FIELD_WIDTH, title, false );
}

void Interface::displayLevelField( size_t index ) const {
	static size_t level = 0;
	const size_t FIELD_HEIGHT = 7;
	const size_t FIELD_WIDTH = 7;
	std::string title = "LEVEL";
	displayField( index, FIELD_HEIGHT, FIELD_WIDTH, title, true );
}

void Interface::displayNextPieceField( size_t index ) const {
	const size_t FIELD_HEIGHT = 10;
	const size_t FIELD_WIDTH = 7;
	std::string title = "NEXT";
	displayField( index, FIELD_HEIGHT, FIELD_WIDTH, title, true );

}

void Interface::displayCommandField( size_t index ) const {
	const size_t FIELD_HEIGHT = 15;
	const size_t FIELD_WIDTH = 15;
	std::string title = "COMMANDS";
	displayField( index, FIELD_HEIGHT, FIELD_WIDTH, title, false );
}

static void displayField( const size_t index, const size_t height, const size_t width, const std::string &title, bool isRight ) {
	bool isTitleDispl = false;
		if( index >= 0 && index < height - 1 )
			std::cout << "||";
		else {
			if ( !isRight )
				std::cout << "  ";
			else
				std::cout << " ";
		}
		for ( size_t fw = 0; fw < width; ++fw ) {
			if ( 0 == index ) {
				if ( !isTitleDispl ) {
					displayTitle( width, title );

					isTitleDispl = true;
				}
			}
			else if ( index >= 1 && index < height - 1 ) {
					std::cout << "  ";
			}
			else if ( index == height - 1 )
				std::cout << "==";
		}
		if ( index >= 0 && index < height - 1 )
			std::cout << "||";
		else { 
				std::cout << " ";
		}
		if ( isRight )
			std::cout << std::endl;
}

static void displayTitle( const size_t width, const std::string &title ) {
	bool isTitleDispl = false;
	// amount of space between title and boreder
	// 4 stays for field border which consists of 4 '|' symbols
	size_t lNumOfSpcs = ( width * 2 - title.size() ) / 2;
	size_t rNumOfSpcs = width * 2 - ( lNumOfSpcs + title.size() );
	if ( !isEven( lNumOfSpcs ) && lNumOfSpcs != rNumOfSpcs ) {
		lNumOfSpcs = lNumOfSpcs - 1;
		rNumOfSpcs = rNumOfSpcs + 1;
	}
	for ( size_t fw = 0; fw < width * 2; ++fw ) {
		if ( fw < lNumOfSpcs )
			std::cout << "*";
		else if ( fw > lNumOfSpcs && !isTitleDispl ) {
			std::cout << title;

			isTitleDispl = true;
		}
		 if ( isTitleDispl &&
				( fw - lNumOfSpcs - 1 ) < rNumOfSpcs ) {
				std::cout << "*";
		}
	}
}
/*
static bool isEreaOqupied ( const size_t coordX, const size_t coorY ) {

	return false;
}
*/
static bool isEven( const size_t size ) {
	return ( size % 2 == 0 );
}

size_t Interface::getScreenHeight() const {
	return screenHeight;
}

void Interface::setScreenHeight( size_t h ) {
	if ( h >= 32 )
		screenHeight = h;
	else {
		std::cout << "Screen height is to small for the game."
			  << "\nResize it appropriately" << std::endl;
		screenHeight = 32;
	}
}

size_t Interface::getScreenWidth() const {
	return screenWidth;
}

void Interface::setScreenWidth( size_t w ) {
	if ( w >= 30 )
		screenWidth = w;
	else {
		std::cout << "Screen width is to small for the game."
			  << "\nResize it appropriately" << std::endl;
		screenWidth = 18;
	}

}

void Interface::setMainFieldHeight( size_t h ) {
	if ( h >= 24 )
		mFldH = h;
	else
		mFld = 24;
}

size_t Interface::getMainFieldHeight() const {
	return mFldH;
}

void Interface::setMainFieldWidth( size_t w ) {
	if ( w >= 10 )
		mFldW = w;
	else
		mFldW = 10;
}

size_t Interface::getMainfFieldWidth() const {
	return mFldW;
}

void Interface::setScoreFieldHeight( size_t h ) {
	if ( h >= 7 )
		scrFldH = h
	else
		scrFldH = 7;
}

size_t Interface::getScoreFieldHeight() const {
	return scrFldH;
}

void Interface::setScoreFieldWidth( size_t w ) {
	if ( w >= 7 )
		scrFldW = w;
	else
		scrFldW = 7;
}

size_t Interface::getScoreFieldWidth() const {
	return scrFldW;
}

void Interface::setLinesFieldHeight( size_t h ) {
	if ( h >= 7 )
		lRmvdFldH = h;
	else
		lRmvdFldH = 7;
}

size_t Interface::getLinesFieldHeight() const {
	return lRmvdFldH;
}

void Interface::setLinesFieldWidth( size_t w ) {
	if ( w >= 7 )
		lRmvdFldW = w;
	else
		lRmvdFldW = 7;
}

size_t Interface::getLinesFieldWidth() const {
	return lRmvdFldW;
}

void Interface::setLevelFieldHeight( size_t h ) {
	if ( h >= 7 )
		lvlFldH = h;
	else
		lvlFldH = 7;
}

size_t Interface::getLevelFieldHeight() const {
	return lvlFldH;
}

void Interface::setLevelFieldWidth( size_t w ) {
	if ( w >= 7 )
		lvlFldW = w;
	else
		lvlFldW = 7;
}

size_t Interface::getLevelFieldWidth() const {
	return lvlFldW;
}

void Interface::setNextPieceFieldHeight( size_t h ) {
	if ( h >= 10 )
		nxtPcFldH = h;
	else
		nxtPcFldH = 10;
}

size_t Interface::getNextPieceFieldHeight() const {
	return nxtPcFldH;
}

void Interface::setNextPieceFieldWidth( size_t w ) {
	if ( w >= 10 )
		nxtPcFldW = w;
	else
		nxtPcFldW = 10;
}

size_t Interface::getNextPieceFieldWidth() const {
	return nxtPcFldW;
}

void Interface::setCommandFieldHeight( size_t h ) {
	if ( h >= 7 )
		cmdFldH = h;
	else
		cmdFldH = 7;
}

size_t Interface::getCommandFieldHeight() const {
	return cmdFldH;
}

void Interface::setCommandFieldWidth( size_t w ) {
	if ( w >= 7 )
		cmdFldW = w;
	else
		cmdFldW = 7;
}

size_t Interface::getCommandFieldWidth() const {
	return cmdFldW;
}

void Interface::setTetrominoHeight( size_t h ) {
	if ( h >= 5 )
		tetroH = h;
	else
		tetroH = 5;
}

size_t Interface::getTetrominoHeight() const {
	return tetroH;
}

void Interface::setTetrominoWidth( size_t w ) {
	if ( w >= 5 )
		tetroW = w;
	else
		tetroW = 5;
}

size_t Interface::getTetrominoWidth() const {
	return tetroW;
}

Interface::~Interface() {
	
}
