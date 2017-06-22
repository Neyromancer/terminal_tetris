// structScoreField.hpp
#ifndef _STRUCT_SCORE_FIELD_HPP_
#define _STRUCT_SCORE_FIELD_HPP_

#include <string>

#include "structMainField.hpp"

class StructScoreField: public StructMainField {
	public:
		StructScoreField( size_t = 7, size_t = 7, size_t = 0 );
		~StructScoreField();
	
		void setScore( const size_t );
		size_t getScore() const;

		const std::string &getFieldName() const;	
	private:
		size_t score;
		static const std::string FIELD_NAME;
};

#endif
