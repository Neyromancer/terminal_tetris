// tetrisEngin.hpp

#ifndef _TETRIS_ENGINE_HPP_
#define _TETRIS_ENGINE_HPP

#include <memory>

class TetrisEngine {
	public:
		TetrisEngine();
		~TetrisEngine();

		void processMainField() const;
		bool isEreaOccupied( size_t coordX, size_t coordY );

	private:
		struct GamePiece; 
		std::unique_ptr< GamePiece > ptrPiece;
		struct GameField; 
		std::unique_ptr< GameField > ptrField;
};

#endif
