// structLevelField.hpp
#ifndef _STRUCT_LEVEL_FIELD_HPP_
#define _STRUCT_LEVEL_FIELD_HPP_

#include <string>

#include "structMainField.hpp"

class StructLevelField: public StructMainField {
	public:
		StructLevelField( size_t = 7, size_t = 7, size_t = 0 );
		~StructLevelField();
	
		void setScore( const size_t );
		size_t getScore() const;

		const std::string &getFieldName() const;	
	private:
		size_t level;
		static const std::string fieldName = "LEVEL";
};

#endif
