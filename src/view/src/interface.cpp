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
Interface::Interface() 
	: ptrEngine( std::make_unique< TetrisEngine >() ) {
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

void Interface::displayMainField( size_t index ) const {
	const size_t FIELD_HEIGHT = 30;
	const size_t FIELD_WIDTH = 18;
			if ( index != FIELD_HEIGHT - 1 )
				std::cout << "<!";
			else std::cout << "  ";
		for ( size_t fw = 0; fw < FIELD_WIDTH; ++fw ) {
			if (  index < FIELD_HEIGHT - 2 ) {
				if ( !( ptrEngine->isEreaOccupied( index, fw ) ) )
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

Interface::~Interface() {
	
}
