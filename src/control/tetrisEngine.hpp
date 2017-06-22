// tetrisEngin.hpp

#ifndef _TETRIS_ENGINE_HPP_
#define _TETRIS_ENGINE_HPP

#include <memory>

#include "../view/interface.hpp"

class TetrisEngine {
	public:
		TetrisEngine();
		~TetrisEngine();

		void processMainField() const;
	private:
		struct GamePiece; 
		std::unique_ptr< GamePiece > ptrPiece;
		Interface *interface;
};

#endif
