// tetrisEngin.hpp

#ifndef _TETRIS_ENGINE_HPP_
#define _TETRIS_ENGINE_HPP

#include <memory>

#include "../view/interface.hpp"

struct GamePiece;

class TetrisEngine {
	public:
		TetrisEngine();
		~TetrisEngine();

		void processMainField() const;
	private:
		Interface *interface;
		std::unique_ptr< GamePiece > piece;
};

#endif
