// interface.hpp

#ifndef _INTERFACE_HPP_
#define _INTERFACE_HPP_

#include <memory>

#include "../../control/headers/tetrisEngine.hpp"

class Interface {
	public:
		Interface( size_t = 32, size_t = 30 );
		~Interface();

		void displayInterface() const;
		void displayMainField( size_t, size_t, int ) const;
		void displayScoreField( size_t ) const;
		void displayLinesRemovedField( size_t ) const;
		void displayLevelField( size_t ) const;
		void displayNextPieceField( size_t ) const;
		void displayCommandField( size_t ) const;

		void displayTetromino() const;
			
		// sizes of all widows should be found from 
		// the terminal window size
		void setScreenHeight( size_t );
		void setScreenWidth( size_t );

		void setMainFieldHeight( size_t );
		void setMainFieldWidth( size_t );

		void setScoreFieldHeight( size_t );
		void setScoreFieldWidth( size_t );

		void setLinesRemovedFieldHeight( size_t );
		void setLinesRemovedFieldWidth( size_t );

		void setLevelFieldHeight( size_t );
		void setLevelFieldWidth( size_t );

		void setNextPieceFieldHeight( size_t );
		void setNextPieceFieldWidth( size_t );

		void setCommandFieldHeight( size_t );
		void setCommandFieldWidth( size_t );

		void setTetrominoHeight( size_t );
		void setTetrominoWidth( size_t );

		enum class fieldState { OCCUPIED, FREE };
	private:
		size_t getScreenHeight() const;
		size_t getScreenWidth() const;

		size_t getMainFieldHeight() const;
		size_t getMainFieldWidth() const;

		size_t getScoreFieldHeight() const;
		size_t getScoreFieldWidth() const;

		size_t getLinesRemovedFieldHeight() const;
		size_t getLinesRemovedFieldWidth() const;

		size_t getLevelFieldHeight() const;
		size_t getLevelFieldWidth() const;

		size_t getNextPieceFieldHeight() const;
		size_t getNextPieceFieldWidth() const;

		size_t getCommandFieldHeight() const;
		size_t getCommandFieldWidth() const;

		size_t getTetrominoHeight() const;
		size_t getTetrominoWidth() const;
//-----------------------------------------------------------
		size_t scrnH;
		size_t scrnW;

		size_t mFldH;
		size_t mFldW;

		size_t scrFldH;
		size_t scrFldW;

		size_t lRmvdFldH;
		size_t lRmvdFldW;

		size_t lvlFldH;
		size_t lvlFldW;

		size_t nxtPcFldH;
		size_t nxtPcFldW;

		size_t cmdFldH;
		size_t cmdFldW;

		size_t tetroH;
		size_t tetroW;

		std::unique_ptr< tetrisEngine > ptrEngine;
};

#endif
