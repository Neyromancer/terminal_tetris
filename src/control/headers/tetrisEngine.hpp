// tetrisEngin.hpp

#ifndef _TETRIS_ENGINE_HPP_
#define _TETRIS_ENGINE_HPP

#include <memory>

class TetrisEngine {
	public:
		TetrisEngine();
		~TetrisEngine();

		// set the curr game in accordance
		// with the settings
		void initGame(); 
		
		void processMainField() const;
		void processNextPieceField() const;
		void processLevelField() const;
		void processScoreField() const;
		void processLinesRemovedField() const;

		void displayScene() const;
		void sotreTetrominoToField( std::unique_ptr< Struct > const & ) const;
		void createTetromino();

		bool isAreaOccupied( const size_t coordX, const size_t coordY ) const;
		bool isCollisionDetected( size_t, size_t, std::unique_ptr< Struct > const & ) const;
		bool isGameOver() const;

		void checkLinesToDelete() const;
		void deleteLine( size_t );

		// add function to change gaps
		// between game fields

		// add function for saving
		// add function for pausing the game
		// add function for changin level
		// which will also change game
		// difficulties

	private:
		struct GamePiece; 
		std::unique_ptr< GamePiece > ptrPiece;
		struct GameField; 
		std::unique_ptr< GameField > ptrField;
//		std::unique_ptr< Interface > ptrInterface;
};

#endif
