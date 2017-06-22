// structNextPieceField.hpp
#ifndef _STRUCT_NEXT_PIECE_FIELD_HPP_
#define _STRUCT_NEXT_PIECE_FIELD_HPP_

#include <array>
#include <string>

#include "structMainField.hpp"

class StructNextPieceField: public StructMainField {
	public:
		StructNextPieceField( size_t = 7, size_t = 7 /*,  std::array< std::array< char, 4 >, 4 > const &*/ );
		~StructNextPieceField();
	
		void setPiece( const std::array< std::array< char, 4 >, 4 > & );
		const std::array< std::array< char, 4 >, 4 > &getPice() const;	

		const std::string &getFieldName() const;
	
	private:
		std::array< std::array< char, 4 >, 4 > piece;
		static const std::string FIELD_NAME;
};

#endif
